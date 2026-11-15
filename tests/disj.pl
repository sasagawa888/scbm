:- use_module(stdlib).


a(1).
a(2).

b(3).
b(4).

test(X) :- a(X) ; b(X).