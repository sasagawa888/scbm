
fib(0,0).
fib(1,1).
fib(N,X) :-
        N1 is N-1,
        fib(N1,X1),
        N2 is N-2,
        fib(N2,X2),
        X is X1+X2.


color(red).
color(green).
color(blue).



likes(kim,robin).
likes(sandy,lee).
likes(sandy,kim).
likes(robin,cats).
likes(sandy,X) :- likes(X,cats).
likes(kim,X) :- likes(X,lee),likes(X,kim).
likes(X,X).


select1(X,[X|Xs],Xs).
select1(X,[Y|Ys],[Y|Zs]) :-
    select1(X,Ys,Zs).


perm1([],[]).
perm1(Xs,[X|Ys]) :-
    select1(X,Xs,Zs),
    perm1(Zs,Ys).
