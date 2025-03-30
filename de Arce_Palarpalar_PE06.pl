/*
   Program: Slayer Identification System
   Description: This Prolog program determines the attributes of individuals based on their location and costumes. 
                It also identifies the 'slayer' based on their eyebrow color.
   Programmers: Richelle de Arce and Cherlie Palarpalar
   Task Division:
      - Richelle de Arce: Implemented location and costume rules, structured the database.
      - Cherlie Palarpalar: Defined eyebrow color rules, implemented the slayer identification logic.
*/

% Defining locations of specific individuals
location(nobita, 25).  % Nobita is at location 25
location(kudo, 29).    % Kudo is at location 29
location(conan, 23).   % Conan is at location 23

% A rule to determine location based on costume
location(X, 27) :- costume(X, gshock).  % If someone wears a gshock, they are at location 27

% Defining what costumes each person wears
costume(nobita, pendant).  % Nobita wears a pendant
costume(pope, gshock).     % Pope wears a gshock

% A rule to assign a fancy bracelet based on location
costume(X, fancy_bracelet) :- location(X, 23).  % Anyone at location 23 wears a fancy bracelet

% Conditional costume assignment
costume(conan, shades) :- costume(kudo, fancy_bracelet).  % Conan wears shades if Kudo wears a fancy bracelet
costume(kudo, shades) :- costume(conan, fancy_bracelet).  % Kudo wears shades if Conan wears a fancy bracelet

% Rules for determining eyebrow colors based on costume and location
eyebrows(X, pink) :- costume(X, shades).            % If someone wears shades, their eyebrows are pink
eyebrows(X, yellow) :- costume(X, fancy_bracelet).  % If someone wears a fancy bracelet, their eyebrows are yellow
eyebrows(X, brown) :- location(X, 27).              % If someone is at location 27, their eyebrows are brown
eyebrows(X, silver) :- location(X, 25).             % If someone is at location 25, their eyebrows are silver

% Identifying the slayer based on eyebrow color
slayer(X) :- eyebrows(X, pink).  % A person is a slayer if their eyebrows are pink


