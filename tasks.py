from invoke import task, Collection
import pathlib
if __package__ is None or __package__ == '':
    from docker import tasks as docker
    from docs import tasks as docs
    from library import tasks as library
else:
    from .docker import tasks as docker
    from .docs import tasks as docs
    from .library import tasks as library

THIS_DIR = pathlib.Path(__file__).parent.resolve()
SINGLE_INCLUDE_DIR = pathlib.Path(THIS_DIR, 'single_include')
RELEASES_DIR = pathlib.Path(THIS_DIR, 'releases')
RELEASES_DIR.mkdir(exist_ok = True)

@task
def version(context, format = '{major}.{minor}.{patch}', verbose = True):
    """
    Prints the version number in the given format.
    """
    import re
    fn_cmakelists = pathlib.Path(THIS_DIR, 'CMakeLists.txt')
    with open(str(fn_cmakelists), 'r') as fin:
        version_line = [line for line in fin.readlines() if 'project(' in line]
        assert(1 == len(version_line))
        version_line = version_line[0]
        regex = "(\d)\.(\d)\.(\d)"
        matches = re.search(regex, version_line)
        if not matches: raise RuntimeError("Missing from line '{}' from {}".format(version_line, fn_cmakelists))
        numbers = [matches.groups()[idx] for idx in range(0, 3)]
    if verbose: print(format.format(major = numbers[0], minor = numbers[1], patch = numbers[2]))
    return numbers

@task(pre = [library.publish])
def test(context):
    print("> Running unit-tests")
    context.run('invoke library.config')
    context.run('invoke library.test/debug-ho')
    print("> Running platform tests")
    context.run('invoke docker.test')

@task(pre = [library.publish])
def package(context):
    import tarfile
    version_nr = '.'.join(version(context))
    fn_package = pathlib.Path(RELEASES_DIR, 'Argo-{}.tar.gz'.format(version_nr))
    fn_header = pathlib.Path(SINGLE_INCLUDE_DIR, 'argo', 'Argo.hpp')
    fn_readme = pathlib.Path(THIS_DIR, 'readme.md')
    if fn_package.exists(): print("Overwriting {}".format(fn_package))
    with tarfile.open(fn_package, 'w:gz') as ftar:
        ftar.add(fn_header, arcname = 'single_include/argo/Argo.hpp')
        ftar.add(fn_readme, arcname = 'readme.md')
    print("Created package {}".format(fn_package))

#TODO: make sure the docs are pushed to the correct branch
@task(pre = [library.publish, docs.publish, package])
def publish(context):
    pass


#TODO: add deploy: publish, package, push

ns = Collection(version, test, package, publish)
ns.add_collection(Collection.from_module(docker, 'docker'))
ns.add_collection(Collection.from_module(docs, 'docs'))
ns.add_collection(Collection.from_module(library, 'library'))

