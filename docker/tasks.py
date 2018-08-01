from invoke import task
import pathlib

THIS_DIR = pathlib.Path(__file__).parent.resolve()
fn_dockers = sorted([fn for fn in THIS_DIR.glob('*.dockerfile')])

def fmt(name):
    parts = name.split('-')
    title = parts[0].title()
    version = '.'.join(parts[1:])
    return "{}-{}".format(title, version)

@task
def list(context):
    """
    Lists the platforms on which the library is verified.
    """
    with context.cd(str(THIS_DIR)):
        for fn in fn_dockers:
            name = fn.stem
            parts = name.split('_')
            system = fmt(parts[0])
            compiler = fmt(parts[1])
            print("* {} / {}".format(system, compiler))

@task
def test(context, platform = None):
    """
    Tests the library on different platforms.
    """
    with context.cd(str(THIS_DIR)):
        for fn in fn_dockers:
            name = fn.stem
            if platform is not None and fmt(name) != platform: continue
            tag = 'argo/{}'.format(name)
            print("Verifying {}".format(name))
            print("> Building...")
            cmd = 'docker build -t {} -f {} ..'.format(tag, fn)
            context.run(cmd, pty = True)
            cmd = 'docker run -t {}'.format(tag)
            print("> Runnning...")
            context.run(cmd, pty = True)
