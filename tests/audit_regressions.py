"""Regression checks for the compiled runtime and its real CLI consumers.

Run on Linux after building scbm. Python's standard library is sufficient.
"""

import itertools
import json
import os
from pathlib import Path
import re
import signal
import subprocess
import sys
import tempfile
import unittest


ROOT = Path(__file__).resolve().parents[1]


def atom(value):
    return "'" + str(value).replace('\\', '\\\\').replace("'", "''") + "'"


class SCBMTest(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory(prefix='audit-', dir=ROOT)
        self.addCleanup(self.directory.cleanup)
        self.folder = Path(self.directory.name)

    def process(self, command, query=None, timeout=20, env=None):
        settings = dict(os.environ, SCBM_HOME=str(ROOT),
                        UBSAN_OPTIONS='halt_on_error=1:print_stacktrace=1')
        settings.update(env or {})
        with subprocess.Popen(command, cwd=ROOT, env=settings, text=True,
                              stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                              stderr=subprocess.STDOUT, start_new_session=True) as child:
            try:
                output, _ = child.communicate(query, timeout=timeout)
            except subprocess.TimeoutExpired:
                os.killpg(child.pid, signal.SIGKILL)
                output, _ = child.communicate()
                self.fail(f'Timed out: {command}\n{output[-4000:]}')
        return subprocess.CompletedProcess(command, child.returncode, output)

    def run_prolog(self, query, modules=(), **options):
        loads = ''.join('use_module(compiler).\n' if m == ROOT / 'library/compiler.pl'
                        else f'consult({atom(self.relative(m))}).\n' for m in modules)
        return self.process([str(ROOT / 'scbm'), '-r'], loads + query, **options)

    def relative(self, path):
        return './' + str(Path(path).relative_to(ROOT))

    def succeeded(self, result):
        self.assertEqual(result.returncode, 0, result.stdout[-6000:])
        self.assertNotIn('runtime error:', result.stdout)

    def expect_ok(self, goal, modules=()):
        result = self.run_prolog(f'({goal}),write(audit_ok),nl,halt.\n', modules)
        self.succeeded(result)
        self.assertEqual(result.stdout.count('audit_ok'), 1, result.stdout)
        return result

    def answers(self, goal, expected, modules=(), template='X'):
        result = self.run_prolog(
            f'findall({template},({goal}),R),write(\'RESULT:\'),write(R),nl,halt.\n',
            modules)
        self.succeeded(result)
        matches = re.findall(r'RESULT:([^\r\n]+)', result.stdout)
        self.assertEqual(matches, [expected], result.stdout)

    def source(self, text, name='program'):
        path = self.folder / (name + '.pl')
        path.write_text(text)
        return path

    def compile(self, source, sanitize=False):
        if Path(source).parent != self.folder:
            source = self.source(Path(source).read_text(), Path(source).stem)
        self.expect_ok(f'compile_file({atom(self.relative(source))},c)',
                       [ROOT / 'library/compiler.pl'])
        c_file = source.with_suffix('.c')
        self.assertTrue(c_file.exists())
        obj = source.with_suffix('.o')
        flags = ['-O1', '-g', '-fsanitize=undefined'] if sanitize else ['-O3', '-flto']
        result = self.process(['gcc', *flags, '-Werror=return-type', '-shared', '-fPIC', '-I', str(ROOT),
                               '-o', str(obj), str(c_file)], timeout=60)
        self.succeeded(result)
        self.assertTrue(obj.exists())
        return obj


class BuildSmokeTests(SCBMTest):
    def test_interpreter(self):
        self.answers('pair(X,Y)', '[[a,1],[a,2],[b,1],[b,2]]',
                     [ROOT / 'tests/stress1.pl'], template='[X,Y]')

    def test_deterministic_compilation(self):
        obj = self.compile(self.source('twice(X,Y) :- Y is X*2.\n'))
        self.expect_ok('twice(3,Y),Y==6', [obj])

    def test_compiled_positive(self):
        obj = self.compile(ROOT / 'tests/stress1.pl')
        self.answers('pair(X,Y)', '[[a,1],[a,2],[b,1],[b,2]]', [obj], '[X,Y]')

    def test_debug_compilation(self):
        source = self.source('p(a).\np(b).\ntwice(X,Y) :- Y is X*2.\n')
        obj = self.compile(source)
        result = self.expect_ok('p(a),twice(3,6)', [obj])
        self.assertNotIn('rp=', result.stdout)
        self.expect_ok(f'compile_file({atom(self.relative(source))},d)',
                       [ROOT / 'library/compiler.pl'])
        result = self.expect_ok('p(a),twice(3,6)', [obj])
        self.assertIn('rp=', result.stdout)


class MemoryTests(SCBMTest):
    def test_registration_bounds(self):
        checks = ''.join(f'assert(init{i}(-1,stub)==NO);'
                         f'assert(init{i}(NUM_FN{i}S,stub)==NO);'
                         f'assert(init{i}(0,NULL)==NO);'
                         f'assert(init{i}(0,stub)==YES);' for i in range(8))
        source = self.folder / 'bounds.c'
        source.write_text('#include <assert.h>\n#include "jump.h"\n'
                          '_Static_assert(__builtin_types_compatible_p(tpred, '
                          '__typeof__(&defcompiled)), "predicate initializer type");\n'
                          '_Static_assert(__builtin_types_compatible_p(tuser, '
                          '__typeof__(&definfixcomp)), "operator initializer type");\n'
                          'static void stub(void) {}\nint main(void) {' + checks + 'return 0;}\n')
        binary = self.folder / 'bounds'
        self.succeeded(self.process(['gcc', '-O1', '-g', '-fsanitize=undefined',
                                     '-I', str(ROOT), '-o', str(binary), str(source)]))
        self.succeeded(self.process([str(binary)]))

    def test_module_registration(self):
        obj = self.compile(self.source('value(a).\nvalue(b).\n'), sanitize=True)
        self.answers('value(X)', '[a,b]', [obj])
        self.answers('value(X)', '[a,b]', [obj, obj, obj])

    def test_depth_limit(self):
        obj = self.compile(ROOT / 'tests/stress2.pl', sanitize=True)
        for count in [32, 4094, 4095, 4096, 4100]:
            with self.subTest(count=count):
                values = '[' + ','.join(['a'] * count) + ']'
                result = self.run_prolog(
                    f'findall(X,mem(X,{values}),R),length(R,N),write(N),nl,halt.\n', [obj])
                self.assertNotIn('runtime error:', result.stdout, result.stdout)
                self.assertNotEqual(result.returncode, -signal.SIGSEGV, result.stdout)
                if count < 4095:
                    self.succeeded(result)
                    self.assertRegex(result.stdout, rf'\b{count}\b')
                else:
                    self.assertIn('Resource error', result.stdout)

    def test_missing_initializer(self):
        c_file = self.folder / 'invalid.c'
        c_file.write_text('#include "mpl.h"\n'
                          'int scbm_abi_version(void) { return SCBM_ABI_VERSION; }\n')
        obj = c_file.with_suffix('.o')
        self.succeeded(self.process(['gcc', '-shared', '-fPIC', '-I', str(ROOT),
                                     '-o', str(obj), str(c_file)]))
        result = self.run_prolog('halt.\n', [obj])
        self.assertGreaterEqual(result.returncode, 0, result.stdout)
        self.assertRegex(result.stdout, r'(?i)(error|missing|invalid)')

    def test_cps_scope_limit(self):
        obj = self.compile(self.source(
            'walk(0).\nwalk(N) :- N>0,N1 is N-1,call(walk(N1)),!.\n'), sanitize=True)
        self.expect_ok('walk(4096)', [obj])
        self.expect_ok('catch((walk(4097),fail),error(resource_error(_),_),true),walk(32)',
                       [obj])
        self.expect_ok('catch(n_cps_cut(-1),_,true),catch(n_cps_cut(0),_,true)', [obj])
        self.expect_ok('catch(n_catch_rest(-1,true),_,true),'
                       'catch(n_catch_rest(10,true),_,true)', [obj])

    def test_local_variable_limit(self):
        variables = ','.join(f'V{i}' for i in range(254))
        source = self.source(f'many(f({variables})) :- pick(a).\n'
                             'many(done).\npick(a).\npick(b).\n')
        obj = self.compile(source, sanitize=True)
        self.expect_ok('many(done)', [obj])
        variables = ','.join(f'V{i}' for i in range(255))
        source = self.source(f'many(f({variables})) :- pick(a).\n'
                             'many(done).\npick(a).\npick(b).\n')
        result = self.run_prolog(
            f'compile_file({atom(self.relative(source))},c),write(unexpected_success),halt.\n',
            [ROOT / 'library/compiler.pl'])
        self.assertGreaterEqual(result.returncode, 0, result.stdout)
        self.assertIn('SCBM local variable limit', result.stdout)
        self.assertNotIn('unexpected_success', result.stdout)

    def test_numeric_registration(self):
        obj = self.compile(self.source(
            'numbers(I,A,R) :- I is integer(3.75), A is abs(-5), R is random.\n'),
            sanitize=True)
        self.expect_ok('numbers(I,A,R),I==3,A==5,R>=0,R=<1', [obj])

    def test_old_abi(self):
        c_file = self.folder / 'old.c'
        c_file.write_text('int scbm_abi_version(void) { return 1; }\n')
        obj = c_file.with_suffix('.o')
        self.succeeded(self.process(['gcc', '-shared', '-fPIC', '-o', str(obj), str(c_file)]))
        result = self.run_prolog('halt.\n', [obj])
        self.assertGreaterEqual(result.returncode, 0, result.stdout)
        self.assertIn('incompatible module', result.stdout)


class SearchTests(SCBMTest):
    def test_external_conjunction(self):
        obj = self.compile(ROOT / 'tests/stress1.pl')
        colors = ['red', 'green', 'blue']
        expected = '[' + ','.join(f'[{a},{b}]' for a in colors for b in colors) + ']'
        self.answers('color(X),color(Y)', expected, [obj], '[X,Y]')

    def test_findall_rollback(self):
        obj = self.compile(ROOT / 'tests/stress1.pl')
        self.expect_ok('findall(X,color(X),R),R==[red,green,blue],var(X)', [obj])
        self.expect_ok('findall(X,(color(X),fail),R),R==[],var(X)', [obj])
        self.expect_ok('\\+ findall(X,color(X),[red])', [obj])

    def test_composition(self):
        first = self.compile(self.source('p(a).\np(b).\n', 'first'), sanitize=True)
        second = self.compile(self.source('q(1).\nq(2).\n', 'second'), sanitize=True)
        self.answers('p(X),q(Y)', '[[a,1],[a,2],[b,1],[b,2]]', [first, second], '[X,Y]')
        self.answers('p(X),call(p(Y))', '[[a,a],[a,b],[b,a],[b,b]]', [first], '[X,Y]')
        caller = self.compile(self.source('via(X) :- p(X).\n', 'caller'), sanitize=True)
        self.answers('via(X)', '[a,b]', [first, caller])
        self.answers('via(X),X=b', '[b]', [first, caller])

    def test_cut_scope(self):
        obj = self.compile(self.source(
            'p(a).\np(b).\nq(1).\nq(2).\n'
            'pick(X) :- p(X),!.\npick(other).\n'
            'pairs(X,Y) :- p(X),!,q(Y).\npairs(other,other).\n'
            'branch(X) :- (p(X),!;X=c).\n'), sanitize=True)
        self.answers('pick(X)', '[a]', [obj])
        self.answers('pairs(X,Y)', '[[a,1],[a,2]]', [obj], '[X,Y]')
        self.answers('branch(X)', '[a]', [obj])
        self.answers('p(X),pick(Y)', '[[a,a],[b,a]]', [obj], '[X,Y]')

    def test_compiled_meta_continuation(self):
        source = self.source(
            'p(a).\np(b).\n'
            'direct(X) :- call(p(X)).\n'
            'via(X) :- p(a),call(p(X)).\n'
            'filtered(X) :- p(a),call(p(X)),X=b.\n'
            'variable(G) :- p(a),call(G).\n'
            'caught(X) :- p(a),catch(p(X),_,fail).\n'
            'outer(X) :- p(a),via(X),X=b.\n'
            'cutmeta(X) :- p(a),call(p(X)),!.\ncutmeta(other).\n'
            'first(X) :- second(X).\nsecond(X) :- third(X).\n'
            'third(X) :- call(p(X)).\n'
            'chosen(X) :- select(X,[a,b],_).\n'
            'condition(X) :- (true->p(X);X=c).\n'
            'repeatstop :- repeat,!.\n'
            'choice(a).\nchoice(_) :- throw(stop).\n')
        for sanitize in [False, True]:
            obj = self.compile(source, sanitize=sanitize)
            for goal, expected in [('direct(X)', '[a,b]'), ('via(X)', '[a,b]'),
                                   ('filtered(X)', '[b]'), ('variable(p(X))', '[a,b]'),
                                   ('caught(X)', '[a,b]'), ('outer(X)', '[b]'),
                                   ('cutmeta(X)', '[a]'), ('first(X)', '[a,b]'),
                                   ('chosen(X)', '[a,b]'), ('condition(X)', '[a,b]')]:
                with self.subTest(sanitize=sanitize, goal=goal):
                    self.answers(goal, expected, [obj])
            self.answers('catch(throw(stop),stop,p(X))', '[a,b]', [obj])
            self.answers('catch(choice(X),stop,X=recovered),catch(true,_,true)',
                         '[a,recovered]', [obj])
            self.expect_ok('catch((catch(p(_),outside,fail),throw(outside)),outside,true)',
                           [obj])
            self.answers('p(Y),cutmeta(X)', '[[a,a],[b,a]]', [obj], '[Y,X]')
            self.answers('repeatstop,X=ok', '[ok]', [obj])

    def test_exception_cleanup(self):
        obj = self.compile(self.source(
            'p(a).\np(b).\nboom :- p(_),throw(stop).\n'
            'bound(X) :- p(X),throw(stop).\n'
            'bad :- p(_),_ is 1//0.\n'), sanitize=True)
        self.expect_ok('catch(boom,stop,true),findall(X,p(X),R),R==[a,b]', [obj])
        self.answers('p(X),catch(boom,stop,true)', '[a,b]', [obj])
        self.expect_ok('catch(bound(X),stop,true),var(X)', [obj])
        self.expect_ok('catch(catch(boom,other,true),stop,true),p(a)', [obj])
        self.expect_ok('catch(bad,_,true),findall(X,p(X),R),R==[a,b]', [obj])

    def test_meta_cut_scope(self):
        source = self.source(
            'p(a).\np(b).\nq(1).\nq(2).\n'
            'protected(X) :- catch((!,fail),tag,true),X=bad.\nprotected(ok).\n'
            'recovery(X) :- catch(throw(tag),tag,(!,fail)),X=bad.\nrecovery(ok).\n'
            'opaque(X) :- call((!,fail)),X=bad.\nopaque(ok).\n'
            'branch(X,Y) :- p(X),(call(q(Y)),!;Y=3).\n'
            'after(X,Y) :- p(X),call(true),!,q(Y).\n'
            'nested(X,Y) :- p(X),(call(q(Y)),(!;fail);Y=3).\n'
            'guard(X) :- ((p(Y),(Y=a,!,fail;true)) -> X=then;X=else).\n'
            'guardonly(X) :- ((p(Y),(Y=a,!,fail;true)) -> X=then).\n'
            'guardonly(else).\n'
            'ops(W,S) :- current_op(W,S,+).\n')
        for sanitize in [False, True]:
            obj = self.compile(source, sanitize=sanitize)
            for predicate in ['protected', 'recovery', 'opaque']:
                self.answers(f'{predicate}(X)', '[ok]', [obj])
            self.answers('branch(X,Y)', '[[a,1]]', [obj], '[X,Y]')
            self.answers('nested(X,Y)', '[[a,1]]', [obj], '[X,Y]')
            self.answers('after(X,Y)', '[[a,1],[a,2]]', [obj], '[X,Y]')
            self.answers('p(Z),branch(X,Y)', '[[a,a,1],[b,a,1]]', [obj], '[Z,X,Y]')
            self.answers('ops(W,S)', '[[200,fy],[500,yfx]]', [obj], '[W,S]')
            self.answers('guard(X)', '[else]', [obj])
            self.answers('guardonly(X)', '[else]', [obj])
            self.expect_ok('findall(X,call((p(X),!,fail)),R),R==[],var(X)', [obj])
            self.expect_ok('findall(X,catch((p(X),!,fail),_,true),R),R==[],var(X)',
                           [obj])
            self.expect_ok('catch((branch(_,_),throw(tag)),tag,true),'
                           'findall(X,protected(X),R),R==[ok]', [obj])

    def test_typed_unification(self):
        for sanitize in [False, True]:
            obj = self.compile(self.source('same(X,X).\nempty([]).\npair([a]).\n'), sanitize=sanitize)
            self.expect_ok('same(X,X),var(X)', [obj])
            self.expect_ok('findall(X,empty(X),L),L==[[]],var(X)', [obj])
            self.expect_ok('X=[b],\\+ pair(X),X==[b]', [obj])

    def test_disjunction(self):
        obj = self.compile(self.source('p(a).\np(b).\nq(X) :- (p(X);X=c).\n'
            'left(X) :- (fail;p(X)).\nright(X) :- (p(X);fail).\n'
            'nested(X) :- ((p(X);X=c);(X=d;fail)).\n'
            'suffix(X) :- (p(X);X=c),X\\=b.\n'
            'prefix(X,Y) :- p(X),(Y=1;Y=2).\n'
            'filter(X,Y) :- p(X),X\\=b,p(Y).\n'), sanitize=True)
        self.answers('q(X)', '[a,b,c]', [obj])
        self.answers('left(X)', '[a,b]', [obj])
        self.answers('right(X)', '[a,b]', [obj])
        self.answers('nested(X)', '[a,b,c,d]', [obj])
        self.answers('suffix(X)', '[a,c]', [obj])
        self.answers('prefix(X,Y)', '[[a,1],[a,2],[b,1],[b,2]]', [obj], '[X,Y]')
        self.answers('filter(X,Y)', '[[a,a],[a,b]]', [obj], '[X,Y]')

    def test_sorting(self):
        obj = self.compile(ROOT / 'tests/stress4.pl')
        self.expect_ok('\\+ (ordered([1,2]),fail)', [obj])
        for values in itertools.permutations([1, 2, 3]):
            with self.subTest(values=values):
                self.answers(f'sort_test({list(values)},X)', '[[1,2,3]]', [obj])

    def test_permutations(self):
        obj = self.compile(ROOT / 'tests/stress4.pl')
        for count in [3, 4]:
            values = list(range(1, count + 1))
            expected = json.dumps(list(itertools.permutations(values)), separators=(',', ':'))
            self.answers(f'perm1({values},X)', expected, [obj])

    def test_queens(self):
        obj = self.compile(ROOT / 'tests/queens.pl')
        for count in [4, 9]:
            values = list(range(1, count + 1))
            expected = [p for p in itertools.permutations(values)
                        if all(abs(p[i] - p[j]) != j - i
                               for i in range(count) for j in range(i + 1, count))]
            self.assertEqual(len(expected), {4: 2, 9: 352}[count])
            self.answers(f'queen({values},X)', json.dumps(expected, separators=(',', ':')), [obj])


class CompilerTests(SCBMTest):
    def compile_cli(self, source, env=None):
        return self.process([sys.executable, str(Path(__file__).resolve()), '--compile', str(source)],
                            env=env)

    def test_gcc_failure(self):
        source = self.source('cdeclare("#error AUDIT_EXPECTED_FAILURE").\np(a).\np(b).\n')
        result = self.run_prolog(
            f'compile_file({atom(self.relative(source))}),write(unexpected_success),nl,halt.\n',
            [ROOT / 'library/compiler.pl'])
        self.assertIn('AUDIT_EXPECTED_FAILURE', result.stdout)
        self.assertNotIn('unexpected_success', result.stdout)
        self.assertTrue(source.with_suffix('.c').exists(), 'Failed build must retain generated C')
        self.assertFalse(source.with_suffix('.o').exists())
        result = self.compile_cli(source)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn('AUDIT_EXPECTED_FAILURE', result.stdout)

    def test_preserve_object(self):
        source = self.source('p(a).\np(b).\n')
        self.succeeded(self.compile_cli(source))
        obj = source.with_suffix('.o')
        before = obj.read_bytes()
        source.write_text('cdeclare("#error FAILED_REBUILD").\np(c).\np(d).\n')
        result = self.compile_cli(source)
        self.assertNotEqual(result.returncode, 0, result.stdout)
        self.assertIn('FAILED_REBUILD', result.stdout)
        self.assertEqual(before, obj.read_bytes())
        self.answers('p(X)', '[a,b]', [obj])
        self.assertEqual(list(self.folder.glob('*.o.*')), [])

    def test_path_characters(self):
        source = self.source('p(a).\np(b).\n', "space's;touch AUDIT_PWN;v1.program")
        self.succeeded(self.compile_cli(source))
        self.answers('p(X)', '[a,b]', [source.with_suffix('.o')])
        self.assertFalse((ROOT / 'AUDIT_PWN').exists())

    def test_missing_source(self):
        result = self.compile_cli(self.folder / 'missing.pl')
        self.assertNotEqual(result.returncode, 0)
        self.assertNotIn('SIGSEGV', result.stdout)
        self.assertRegex(result.stdout, r'(?i)(exist|open)')

    def test_invalid_paths(self):
        for name, message in [('', "Can't open"), ('x' * 2040, 'file path length')]:
            with self.subTest(length=len(name)):
                result = self.run_prolog(f'consult({atom(name)}),write(unexpected_success),halt.\n')
                self.assertGreaterEqual(result.returncode, 0, result.stdout)
                self.assertIn(message, result.stdout)
                self.assertNotIn('unexpected_success', result.stdout)

    def test_compiler_process_failures(self):
        source = self.source('p(a).\np(b).\n')
        self.succeeded(self.compile_cli(source))
        before = source.with_suffix('.o').read_bytes()
        bin_dir = self.folder / 'bin'
        bin_dir.mkdir()
        for script, message in [(None, 'Cannot run GCC'),
                                ('kill -TERM $$', 'GCC terminated by signal'),
                                ('exit 0', 'GCC produced no object')]:
            with self.subTest(script=script):
                if script:
                    gcc = bin_dir / 'gcc'
                    gcc.write_text('#!/bin/sh\n' + script + '\n')
                    gcc.chmod(0o755)
                result = self.compile_cli(source, env={'PATH': str(bin_dir)})
                self.assertNotEqual(result.returncode, 0)
                self.assertIn(message, result.stdout)
                self.assertEqual(source.with_suffix('.o').read_bytes(), before)
                self.assertTrue(source.with_suffix('.c').exists())
                self.assertEqual(list(self.folder.glob('*.o.*')), [])

    def test_installed_compiler(self):
        destination = self.folder / 'install area'
        self.succeeded(self.process(['make', 'install', f'DESTDIR={destination}'], timeout=60))
        share = destination / 'usr/local/share/scbm'
        binary = destination / 'usr/local/bin/scbm'
        source = self.source('p(a).\np(b).\n')
        query = (f'use_module(compiler).\ncompile_file({atom(source)}).\n'
                 f'consult({atom(source.with_suffix(".o"))}).\n'
                 'findall(X,p(X),R),R==[a,b],write(audit_ok),nl,halt.\n')
        result = self.process([str(binary), '-r'], query, env={'SCBM_HOME': str(share)})
        self.succeeded(result)
        self.assertIn('audit_ok', result.stdout)
        before = source.with_suffix('.o').read_bytes()
        (share / 'jump.h').unlink()
        failure_query = (f'use_module(compiler).\ncompile_file({atom(source)}),'
                         'write(unexpected_success),halt.\n')
        result = self.process([str(binary), '-r'], failure_query, env={'SCBM_HOME': str(share)})
        self.succeeded(result)
        self.assertIn('jump.h', result.stdout)
        self.assertNotIn('unexpected_success', result.stdout)
        self.assertEqual(source.with_suffix('.o').read_bytes(), before)

    def test_absolute_path(self):
        source = self.source('p(a).\np(b).\n')
        self.expect_ok(f'compile_file({atom(source)})', [ROOT / 'library/compiler.pl'])
        self.answers('p(X)', '[a,b]', [source.with_suffix('.o')])


class GateTests(SCBMTest):
    def test_identity_and_negation(self):
        for goal in ['X==X', '\\+ (X==2)', '\\+ (X==Y)',
                     '\\+ (X==X,fail)', '\\+ (X\\=2),var(X)',
                     '\\+ (X=2,fail),var(X)']:
            with self.subTest(goal=goal):
                self.expect_ok(goal)

    def test_failing_test_copy(self):
        runner = self.folder / 'negative.py'
        source = Path(__file__).read_text()
        needle = 'twice(3,Y),Y==' + '6'
        self.assertEqual(source.count(needle), 1)
        runner.write_text(source.replace(needle, 'twice(3,Y),Y==99'))
        result = self.process([sys.executable, str(runner),
                               'BuildSmokeTests.test_deterministic_compilation'])
        self.assertNotEqual(result.returncode, 0, result.stdout)
        self.assertIn('FAILED', result.stdout)
        runner.write_text(source.replace('    def test_deterministic_compilation(self):',
                         '    @unittest.skip("gate negative")\n'
                         '    def test_deterministic_compilation(self):', 1))
        result = self.process([sys.executable, str(runner),
                               'BuildSmokeTests.test_deterministic_compilation'])
        self.assertNotEqual(result.returncode, 0, result.stdout)
        self.assertIn('skipped: 1', result.stdout)

    def test_legacy_failure(self):
        text = (ROOT / 'verify/all.pl').read_text().replace('verify(3 @> 2.1)', 'verify(2 @> 3)')
        source = self.source(text)
        result = self.expect_ok('\\+ main', [source])
        self.assertIn('wrong ', result.stdout)
        self.assertIn('failed test atmark', result.stdout)
        self.assertNotIn('All tests are done', result.stdout)

    def test_legacy_suite(self):
        result = self.run_prolog('halt.\n', [ROOT / 'verify/all.pl'])
        self.succeeded(result)
        self.assertNotIn('wrong ', result.stdout, result.stdout)
        self.assertIn('All tests are done', result.stdout)

    def test_harness_negatives(self):
        setup = (f'import runpy,sys; ns=runpy.run_path({str(Path(__file__).resolve())!r}); '
                 'test=ns["SCBMTest"](); test.setUp(); ')
        for body, diagnostic in [
            ('test.expect_ok("fail")', 'AssertionError'),
            ('test.process([sys.executable,"-c","import time;time.sleep(1)"],timeout=0.03)',
             'Timed out'),
            ('test.succeeded(test.process([sys.executable,"-c",'
             '"import os,signal,resource;resource.setrlimit(resource.RLIMIT_CORE,(0,0));'
             'print(\\\"audit_ok\\\",flush=True);os.kill(os.getpid(),signal.SIGSEGV)"]))',
             'AssertionError'),
        ]:
            with self.subTest(body=body):
                result = self.process([sys.executable, '-c', setup + body])
                self.assertNotEqual(result.returncode, 0, result.stdout)
                self.assertIn(diagnostic, result.stdout)


if __name__ == '__main__':
    if len(sys.argv) == 3 and sys.argv[1] == '--compile':
        check = SCBMTest()
        check.expect_ok(f'compile_file({atom(Path(sys.argv[2]).resolve())})',
                        [ROOT / 'library/compiler.pl'])
    else:
        program = unittest.main(verbosity=2, exit=False)
        result = program.result
        print(f'Executed: {result.testsRun - len(result.skipped)}; skipped: {len(result.skipped)}; '
              f'failures: {len(result.failures)}; errors: {len(result.errors)}; '
              f'expected failures: {len(result.expectedFailures)}')
        sys.exit(0 if result.wasSuccessful() and result.testsRun > 0 and
                 not result.skipped and not result.expectedFailures else 1)
