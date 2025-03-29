
location(nobita, 25).
location(kudo, 29).
location(conan, 23).
location(X, 27) :- costume(X, gshock).

costume(nobita, pendant).
costume(pope, gshock).
costume(X, fancy_bracelet) :- location(X, 23).
costume(conan, shades) :- costume(kudo, fancy_bracelet).
costume(kudo, shades) :- costume(conan, fancy_bracelet).

% Rules for eyebrows based on conditions
eyebrows(X, pink) :- costume(X, shades).
eyebrows(X, yellow) :- costume(X, fancy_bracelet).
eyebrows(X, brown) :- location(X, 27).
eyebrows(X, silver) :- location(X, 25).

% Identifying the slayer
slayer(X) :- eyebrows(X, pink).

