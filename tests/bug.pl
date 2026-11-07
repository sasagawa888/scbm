


color(red).
color(green).
color(blue).

foo(X) :- write(X).


likes(kim,robin).
likes(sandy,lee).
likes(sandy,kim).
likes(robin,cats).
likes(sandy,X) :- likes(X,cats).
likes(kim,X) :- likes(X,lee),likes(X,kim).
likes(X,X).

fact(0,1).
fact(N,X) :-
        N1 is N-1,
        fact(N1,X1),
        X is N*X1.


select1(X,[X|Xs],Xs).
select1(X,[Y|Ys],[Y|Zs]) :-
    select1(X,Ys,Zs).


perm1([],[]).
perm1(Xs,[X|Ys]) :-
    select1(X,Xs,Zs),
    perm1(Zs,Ys).


%9queens
test :- queen([1,2,3,4,5,6,7,8,9],X),write(X),nl,fail.
test1 :- queen([1,2,3,4,5,6,7,8,9],X),fail.


queen(Data, Out) :-
    queen2(Data, [], Out).

queen2([], _, []).
queen2([H|T], History, [Q|M]) :-
    qdelete(Q, H, T, L1),
    nodiag(History, Q, 1),
    queen2(L1, [Q|History], M).


qdelete(A, A, L, L).
qdelete(X, A, [H|T], [A|R]) :-
    qdelete(X, H, T, R).


nodiag([], _, _).
nodiag([N|L], B, D) :-
    D =\= N - B,
    D =\= B - N,
    D1 is D + 1,
    nodiag(L, B, D1).

append1([], Ys, Ys).
append1([X|Xs], Ys, [X|Zs]) :-
    append1(Xs, Ys, Zs).


between1(L, H, L) :-
    L =< H.

between1(L, H, X) :-
    L < H,
    L1 is L + 1,
    between1(L1, H, X).

nat(0).
nat(s(X)) :- nat(X).

plus(0, Y, Y).
plus(s(X), Y, s(Z)) :- plus(X, Y, Z).

times(0, _, 0).
times(s(X), Y, Z) :- times(X, Y, Z1), plus(Z1, Y, Z).

le(X, Y) :- plus(X, _, Y).

lt(X, Y) :- le(s(X), Y).

quot(X, Y, 0, X) :- lt(X, Y).
quot(X, Y, s(Q), R) :- plus(Y, X1, X), quot(X1, Y, Q, R).

prime(s(X)) :- df(X, s(X)).

df(s(0), _).
df(s(s(M)), N) :- dnd(s(s(M)), N), df(s(M), N).

dnd(M, N) :- quot(N, M, _, s(_)).
