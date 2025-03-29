% FACTS

% Male members
male(ernesto_improgo_i).
male(gerardo_palarpalar).
male(ernel_improgo).
male(eugene_improgo).
male(nelson_malabarbas).
male(ernesto_improgo_ii).
male(erlie_improgo).
male(pacito_palarpalar).
male(mario_palarpalar).
male(julius_basanes).
male(jack_palarpalar).

% Female members
female(marvie_dar).
female(elgie_malabarbas).
female(nicole_malabarbas).
female(nellie_improgo).
female(segunda_palarpalar).
female(eillen_palarpalar).
female(rose_basanes).
female(aritas_lastimado).
female(lhema_campugan).
female(cherlie_palarpalar).
female(sheena_palarpalar).
female(chillen_palarpalar).
female(julirose_basanes).

% Grandparent-child relationships
grandparent(nellie_improgo, nicole_malabarbas).
grandparent(nellie_improgo, cherlie_palarpalar).
grandparent(nellie_improgo, sheena_palarpalar).
grandparent(nellie_improgo, chillen_palarpalar).
grandparent(nellie_improgo, jack_palarpalar).
grandparent(ernesto_improgo_i, nicole_malabarbas).
grandparent(ernesto_improgo_i, cherlie_palarpalar).
grandparent(ernesto_improgo_i, sheena_palarpalar).
grandparent(ernesto_improgo_i, chillen_palarpalar).
grandparent(ernesto_improgo_i, jack_palarpalar).
grandparent(segunda_palarpalar, cherlie_palarpalar).
grandparent(segunda_palarpalar, sheena_palarpalar).
grandparent(segunda_palarpalar, chillen_palarpalar).
grandparent(segunda_palarpalar, jack_palarpalar).
grandparent(segunda_palarpalar, julirose_basanes).
grandparent(gerardo_palarpalar, cherlie_palarpalar).
grandparent(gerardo_palarpalar, sheena_palarpalar).
grandparent(gerardo_palarpalar, chillen_palarpalar).
grandparent(gerardo_palarpalar, jack_palarpalar).
grandparent(gerardo_palarpalar, julirose_basanes).

% Parent-child relationships
parent(nellie_improgo, ernel_improgo).
parent(nellie_improgo, marvie_dar).
parent(nellie_improgo, elgie_malabarbas).
parent(nellie_improgo, eillen_palarpalar).
parent(nellie_improgo, eugene_improgo).
parent(nellie_improgo, ernesto_improgo_ii).
parent(nellie_improgo, erlie_improgo).
parent(ernesto_improgo_i, ernel_improgo).
parent(ernesto_improgo_i, marvie_dar).
parent(ernesto_improgo_i, elgie_malabarbas).
parent(ernesto_improgo_i, eillen_palarpalar).
parent(ernesto_improgo_i, eugene_improgo).
parent(ernesto_improgo_i, ernesto_improgo_ii).
parent(ernesto_improgo_i, erlie_improgo).
parent(segunda_palarpalar, pacito_palarpalar).
parent(segunda_palarpalar, mario_palarpalar).
parent(segunda_palarpalar, rose_basanes).
parent(segunda_palarpalar, aritas_lastimado).
parent(segunda_palarpalar, lhema_campugan).
parent(gerardo_palarpalar, pacito_palarpalar).
parent(gerardo_palarpalar, mario_palarpalar).
parent(gerardo_palarpalar, rose_basanes).
parent(gerardo_palarpalar, aritas_lastimado).
parent(gerardo_palarpalar, lhema_campugan).
parent(gerardo_palarpalar, pacito_palarpalar).
parent(elgie_malabarbas, nicole_malabarbas).
parent(nelson_malabarbas, nicole_malabarbas).
parent(eillen_palarpalar, cherlie_palarpalar).
parent(eillen_palarpalar, sheena_palarpalar).
parent(eillen_palarpalar, chillen_palarpalar).
parent(eillen_palarpalar, jack_palarpalar).
parent(pacito_palarpalar, cherlie_palarpalar).
parent(pacito_palarpalar, sheena_palarpalar).
parent(pacito_palarpalar, chillen_palarpalar).
parent(pacito_palarpalar, jack_palarpalar).
parent(rose_basanes, julirose_basanes).
parent(julius_basanes, julirose_basanes).

% RULES

% Grandparent rules
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).
granpa(X, Y) :- grandparent(X, Y), male(X).
granma(X, Y) :- grandparent(X, Y), female(X).

% Father and mother
father(X, Y) :- parent(X, Y), male(X).
mother(X, Y) :- parent(X, Y), female(X).

% Son and daughter
son(X, Y) :- parent(Y, X), male(X).
daughter(X, Y) :- parent(Y, X), female(X).

% Sibling rule
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

% Aunt and Uncle rules
aunt(X, Y) :- female(X), parent(Z, Y), sibling(X, Z).
uncle(X, Y) :- male(X), parent(Z, Y), sibling(X, Z).

% Cousin rule
cousin(X, Y) :- parent(A, X), parent(B, Y), sibling(A, B).