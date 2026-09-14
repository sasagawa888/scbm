# Build and Regression Checks

The regression gate uses Python's standard library, GNU Make, GCC, and Linux.
It has been exercised on Ubuntu 24.04 aarch64 with GCC 13.3 and Python 3.12.
The executable also requires ncurses development headers. SWI-Prolog is not
required: permutation and queens reference answers are generated independently
with Python's `itertools`.

```sh
sudo apt install build-essential libncurses-dev python3 cppcheck
export SCBM_HOME="$PWD"
make -j2
make test
make check
```

`make test` builds both executables and runs `tests/audit_regressions.py`.
Every required case runs by default. The summary reports executed, skipped,
failed, errored, and expected-failure counts. Skips, expected failures, empty
runs, child crashes, timeouts, and failed assertions make the gate nonzero.
Negative checks exercise a deliberately failing test copy, the legacy assertion
aggregator, a timed-out child, and a crashed child that printed a success marker.

The gate covers compiled search composition, rollback, cut and disjunction,
typed unification, all six three-element sorting inputs, exact 6/24 permutation
sequences, exact 2/352 queens sequences, compiler failure and installation paths,
ABI validation, local-slot limits, and recursion boundaries. Instrumented modules
are loaded by the real executable with `-O1 -g -fsanitize=undefined` and
`UBSAN_OPTIONS=halt_on_error=1:print_stacktrace=1`. Other module checks use
`-O3 -flto`; every test compilation rejects missing return paths.

`make check` checks the C translation units used by the executables, with
Cppcheck warnings and performance diagnostics treated as failures. Existing
inline suppressions are honored. Historical generated C files under `tests/`
and `example/` are not build inputs; fresh generated modules are compiled and
executed by the regression gate instead. A broader portability survey can use
`cppcheck --enable=portability .`; existing `localtime` calls are not a claim of
thread safety. GCC's serial-LTO notice is informational. The older `Jcar`
implicit-int and OpenGL `Jexec_all` declaration warnings are outside the search
fixes; test compilation does not suppress them.

## Compilation and Installation

```sh
python3 tests/audit_regressions.py --compile ./tests/stress1.pl
sudo make install
export SCBM_HOME=/usr/local/share/scbm
scbm
```

The default installation places `compiler.pl` and other Prolog libraries under
`$SCBM_HOME/library`, with `jump.h` and `mpl.h` under `$SCBM_HOME`. For a custom
prefix, set `SCBM_HOME` to its `share/scbm` directory. `HOME` need not change.
Without `SCBM_HOME`, the legacy `$HOME/scbm` lookup remains available.

`compile_file/1` invokes GCC with an argument vector, not shell interpolation.
Source and output names may contain spaces and shell metacharacters. Library
options use POSIX word expansion with command substitution disabled. They are
compiler options, not a shell script. GCC writes a unique temporary object in
the destination directory. Only a successful, nonempty result replaces the
target; failures retain generated C, diagnostics, and any previous object.
`compile_file(File,c)` retains generated C without invoking GCC;
`compile_file(File,o)` builds existing C and retains it. `shell/1` is unchanged.

For automation, use the Python compilation entrypoint above or `make prolog`.
The interactive REPL can return process status zero after reporting an error;
that status alone is not evidence of a successful compilation. Load a newly
compiled module and issue its query as separate REPL goals.

## Compatibility and Limits

Recompile existing modules with the matching compiler and headers. The loader
rejects modules without the current ABI version and required initializers rather
than calling missing functions. Live continuation chains are retained until
their choice points are discarded; each invocation restores the caller's cursor
bases, while catch and REPL recovery restore shared cursors across modules.

Storage remains bounded by `RECURSIZE` (4096 slots, with slot zero reserved).
Exhaustion produces a resource error before writing outside a stack. A generated
clause supports at most 254 saved local variables; the other continuation slots
hold its cut boundary and argument list. Retained working terms are not reclaimed
by blindly resetting the working pointer during compiled backtracking.

These tests establish specific regression properties, not full ISO compliance,
unbounded search, all foreign-library configurations, concurrent-query safety,
or production certification. General engine redesign and performance claims are
outside this change.
