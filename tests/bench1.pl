

% NONDET benchmark

n(1).
n(2).
n(3).
n(4).
n(5).
n(6).
n(7).
n(8).
n(9).
n(10).

% 5重のバックトラック
test_nondet :-
    n(_A),
    n(_B),
    n(_C),
    n(_D),
    n(_E),
    fail.
test_nondet.


% Float
f(1.0).
f(2.0).
f(3.0).
f(4.0).
f(5.0).
f(6.0).
f(7.0).
f(8.0).
f(9.0).
f(10.0).

% Atom
a(d1).
a(d2).
a(d3).
a(d4).
a(d5).
a(d6).
a(d7).
a(d8).
a(d9).
a(d10).

% Float benchmark
test_float :-
    f(_A),
    f(_B),
    f(_C),
    f(_D),
    f(_E),
    fail.
test_float.

% Atom benchmark
test_atom :-
    a(_A),
    a(_B),
    a(_C),
    a(_D),
    a(_E),
    fail.
test_atom.
