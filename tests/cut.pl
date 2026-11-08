
% SCBM-Prolog cut test
% tests/cut.pl

% Test 1: Cut in the second clause
cut1(1).
cut1(2) :- !.
cut1(3).

% Test 2: Remove choices before cut
color(red).
color(green).
color(blue).

cut2(X) :-
    color(X),
    !.

% Test 3: Preserve choices after cut
left(a).
left(b).

right(1).
right(2).

cut3(X,Y) :-
    left(X),
    !,
    right(Y).

% Test 4: Failure after cut
cut4(X) :-
    color(X),
    !,
    fail.

cut4(other).


% Expected results:
%
% ?- cut1(X).
% X = 1 ;
% X = 2 ;
% no
%
% ?- cut2(X).
% X = red ;
% no
%
% ?- cut3(X,Y).
% X = a, Y = 1 ;
% X = a, Y = 2 ;
% no
%
% ?- cut4(X).
% no
