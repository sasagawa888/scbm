:- use_module(stdlib).
% test call/1

a(1).
a(2).
a(3).

test1(X) :- call(a(X)).

test2 :- call(true).

test3 :- call(fail).

test4(X) :- call(a(X)), X > 1.