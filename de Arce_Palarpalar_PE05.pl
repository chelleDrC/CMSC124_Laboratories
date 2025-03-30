/*
   Program: Ancestor Identification System
   Description: This Prolog program determines the relationships between family members.
   Programmers: Richelle de Arce and Cherlie Palarpalar
   Task Division:
      - Richelle de Arce: Implemented facts for family relationships and defined rules for grandparents and parents.
      - Cherlie Palarpalar: Created the ancestree and defined rules for siblings, aunts, uncles, and cousins.
      - Both: Collaborated on the overall structure and logic of the program.
*/

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
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).   % X is a grandparent of Y if X is a parent of Z and Z is a parent of Y.
granpa(X, Y) :- grandparent(X, Y), male(X).         % X is a grandfather of Y if X is a grandparent of Y and X is male.
granma(X, Y) :- grandparent(X, Y), female(X).       % X is a grandmother of Y if X is a grandparent of Y and X is female.

% Father and mother
father(X, Y) :- parent(X, Y), male(X).              % X is the father of Y if X is a parent of Y and X is male.
mother(X, Y) :- parent(X, Y), female(X).            % X is the mother of Y if X is a parent of Y and X is female.

% Son and daughter
son(X, Y) :- parent(Y, X), male(X).                 % X is the son of Y if Y is a parent of X and X is male.
daughter(X, Y) :- parent(Y, X), female(X).          % X is the daughter of Y if Y is a parent of X and X is female.

% Sibling rule
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y. % X and Y are siblings if they share a parent Z and X is not equal to Y.

% Aunt and Uncle rules
aunt(X, Y) :- female(X), parent(Z, Y), sibling(X, Z). % X is an aunt of Y if X is female, Z is a parent of Y, and X is a sibling of Z.
uncle(X, Y) :- male(X), parent(Z, Y), sibling(X, Z).  % X is an uncle of Y if X is male, Z is a parent of Y, and X is a sibling of Z.

% Cousin rule
cousin(X, Y) :- parent(A, X), parent(B, Y), sibling(A, B). % X and Y are cousins if their parents A and B are siblings.