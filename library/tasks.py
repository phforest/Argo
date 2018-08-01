from invoke import task, Collection, call, exceptions
import os
import pathlib
import re
import shutil
import sys

THIS_DIR = pathlib.Path(__file__).parent.resolve()
ROOT_DIR = pathlib.Path(THIS_DIR).parent.resolve()
BUILDS_DIR = pathlib.Path(THIS_DIR, '..', 'builds').resolve()
BUILDS_DIR.mkdir(exist_ok = True)

class CompilerConfig(object):
    def __init__(self, debug, rtc, debug_info, header_only):
        super(CompilerConfig, self).__init__()
        self.debug = debug
        self.rtc = rtc
        self._debug_info = debug_info
        self.header_only = header_only

    @classmethod
    def from_vars(cls, debug, rtc, debug_info, header_only):
        return CompilerConfig(debug, rtc, debug_info, header_only)
    @classmethod
    def from_string(cls, string):
        debug = None
        rtc = None
        debug_info = None
        header_only = None
        parts = string.split('-')
        if 'reldeb' in parts:
            debug = False
            debug_info = True
        elif 'release' in parts:
            debug = False
            debug_info = False
        elif 'debug' in parts:
            debug = True
            debug_info = True
        if 'rtc' in parts: rtc = True
        else: rtc = False
        if 'ho' in parts: header_only = True
        else: header_only = False
        assert(debug is not None)
        assert(rtc is not None)
        assert(debug_info is not None)
        assert(header_only is not None)
        return cls.from_vars(debug, rtc, debug_info, header_only)

    @property
    def release(self): return not self.debug
    @property
    def debug_info(self):
        return True if self.debug else self._debug_info
    @property
    def cmake_build_type(self):
        if self.release: return 'RelWithDebInfo' if self.debug_info else 'Release'
        else: return "Debug"
    @property
    def build_dir_name(self):
        parts = []
        if self.release and self.debug_info: parts.append('reldeb')
        elif self.release: parts.append('release')
        elif self.debug: parts.append('debug')
        if self.rtc: parts.append('rtc')
        parts.append('ho' if self.header_only else 'static')
        return '-'.join(parts)
    @property
    def build_dir(self):
        path = pathlib.Path(BUILDS_DIR, self.build_dir_name)
        path.mkdir(parents = True, exist_ok = True)
        return path
    def __str__(self): return self.build_dir_name

@task
def config(context, debug = True, rtc = False, debug_info = True, release = False, static = False):
    """
    Configures a build with the given configuration. This will create a builds/<config> folder.
    """
    if release:
        debug = False
        rtc = False
        debug_info = False
    cfg = CompilerConfig.from_vars(debug, rtc, debug_info, not static)
    print("Compiler configuration: {} ".format(cfg))
    print("Build directory: {}".format(cfg.build_dir))
    with context.cd(str(cfg.build_dir)):
        options = []
        options.append('-DCMAKE_BUILD_TYPE={}'.format(cfg.cmake_build_type))
        if cfg.rtc: options.append('-DENABLE_SANITIZERS=ON')
        if not cfg.header_only: options.append('-DARGO_STATIC_LIBRARY:BOOL=TRUE')
        context.run('cmake ../.. {options}'.format(options = ' '.join(options)))

@task
def publish(context, verbose = False):
    """
    Publishes all deliverables: single include, forwarding header.
    """
    #Single include
    fn_argo = pathlib.Path(ROOT_DIR, 'single_include', 'argo', 'Argo.hpp')
    def add_license():
        with open(fn_argo, 'w') as fout:
            fn_license = pathlib.Path(ROOT_DIR, 'license.txt')
            with open(fn_license, 'r') as fin:
                fout.write('/*\n')
                fout.write(fin.read())
                fout.write('*/\n\n')
    include_expression = r"#include \"(argo/[a-zA-Z\/_\.]+)\""
    level = 0
    def log(msg):
        if not verbose: return
        log_idx = 0
        while log_idx < level:
            sys.stdout.write('  ')
            log_idx += 1
        sys.stdout.write(msg)
        sys.stdout.write('\n')
    fn_processed = set()
    def process(fn):
        nonlocal level
        log("Processing {}".format(fn))
        if fn in fn_processed:
            log("Skipping: already processed {}".format(fn))
            return []
        fn_processed.add(fn)
        lines_out = []
        with open(fn, 'r') as fin:
            lines_in = fin.readlines()
            for line in lines_in:
                matches = re.match(include_expression, line)
                if matches:
                    fn_sub = pathlib.Path(THIS_DIR, 'inc', matches.group(1))
                    if not fn_sub.exists(): raise RuntimeError("Missing file {} included from {}".format(fn_sub, fn))
                    level += 1
                    lines_out.extend(process(fn_sub))
                    level -= 1
                else: lines_out.append(line)
        return lines_out
    def add(fns):
        idx = 0
        while idx < len(fns):
            fn = fns[idx]
            idx += 1
            lines = process(fn)
            with open(fn_argo, 'a') as fout: fout.writelines(lines)

    add_license()
    fn_sources = [fn for fn in pathlib.Path(THIS_DIR, 'src', 'argo').glob('**/*.cpp')]
    add(fn_sources)
    fn_headers = [fn for fn in pathlib.Path(THIS_DIR, 'inc', 'argo').glob('**/*.hpp')]
    add(fn_headers)
    print("Published {} files to the single include header {}".format(len(fn_processed), fn_argo))

    #Forwarding header
    fn_fwd = pathlib.Path(THIS_DIR, 'inc', 'argo', 'Argo.hpp')
    with open(fn_fwd, 'w') as fout:
        def blacklisted(fn):
            fn = str(fn)
            return 'details' in fn or 'utility' in fn or 'Argo.hpp' in fn
        prefix = str(pathlib.Path(THIS_DIR, 'inc')) + '/'
        includes = [str(fn).replace(prefix, '') for fn in fn_headers if not blacklisted(fn)]
        fout.writelines(['#include "{}"\n'.format(include) for include in includes])
    print("Published {} includes to the forwarding header {}".format(len(includes), fn_fwd))

def glob_build_tasks():
    configs = [str(dir.stem) for dir in BUILDS_DIR.glob('*') if dir.is_dir()]
    for config in configs:
        template = """
@task(name = 'build/{config}', pre = [publish], incrementable = ['verbose'])
def build_{func_name}(context, target = 'all', verbose = 0):
    \"\"\"
    Builds the {config} configuration.
    \"\"\"
    with context.cd({build_dir}):
        cmd = 'make -j1 ' + target
        if verbose > 0: cmd += ' VERBOSE=' + str(verbose)
        print("Building in", context.cwd, ":", cmd)
        context.run(cmd)
ns.add_task(build_{func_name})

@task(name = 'clean/{config}')
def clean_{func_name}(context, verbose = 0):
    \"\"\"
    Cleans the {config} configuration.
    \"\"\"
    with context.cd({build_dir}):
        context.run('make clean')
ns.add_task(clean_{func_name})

@task(name = 'test/{config}', pre = [build_{func_name}])
def test_{func_name}(context, tag = '', verbose = False, run = True):
    \"\"\"
    Runs the unit-tests of the {config} configuration.
    \"\"\"
    exes = [exe for exe in pathlib.Path({build_dir}).glob('**/*-tests')]
    if not run:
        print("There are " + str(len(exes)) + " test executables:")
        for exe in exes: print("- " + str(exe))
        return
    nr_failed = 0
    catch_tag = "".join(['[' + t + ']' for t in tag.split(':')])
    for exe in exes:
        cmd = str(exe)
        if 0 != len(tag): cmd += " " + catch_tag
        print("Running test executable: " + cmd)
        try: context.run(cmd, pty = True)
        except exceptions.UnexpectedExit as err: nr_failed += 1
    if 0 != nr_failed:
        print("Error: " + str(nr_failed) + " out of " + str(len(exes)) + " test executables contain failed test cases.")
        exit(1)

ns.add_task(test_{func_name})

@task(name = 'remove/{config}')
def remove_{func_name}(context, verbose = 0):
    \"\"\"
    Removes the {config} configuration from the builds directory. This will disable any related tasks.
    \"\"\"
    shutil.rmtree({build_dir})
ns.add_task(remove_{func_name})
        """
        func_name = config.replace('-', '_')
        build_dir = pathlib.Path(BUILDS_DIR, config)
        code = template.format(config = config, func_name = func_name, build_dir = "\"{}\"".format(build_dir))
        exec(code)

ns = Collection(config, publish)
glob_build_tasks()

