
CREATE TABLE Artiste (
   Nom varchar(20) NOT NULL,
   Prenom varchar(15),
   Annee_naissance decimal(4,0),
   PRIMARY KEY (Nom)
);


INSERT INTO Artiste VALUES( 'Allen', 'Woody', '1938');
INSERT INTO Artiste VALUES( 'Lynch', 'David', '1946');
INSERT INTO Artiste VALUES( 'Kusturica', 'Emir', '1959');
INSERT INTO Artiste VALUES( 'Lang', 'Fritz', '1899');
INSERT INTO Artiste VALUES( 'Eastwood', 'Clint', '1932');
INSERT INTO Artiste VALUES( 'Hitchcock', 'Alfred', '1898');
INSERT INTO Artiste VALUES( 'Kubrick', 'Stanley', '1935');
INSERT INTO Artiste VALUES( 'Curtis', 'Michael', '1902');
INSERT INTO Artiste VALUES( 'Stewart', 'James', '1911');
INSERT INTO Artiste VALUES( 'Novak', 'Kim', NULL);
INSERT INTO Artiste VALUES( 'Hunt', 'Greg', '1950');
INSERT INTO Artiste VALUES( 'Tarantino', 'Quentin', '1948');
INSERT INTO Artiste VALUES( 'Willis', 'Bruce', '1952');
INSERT INTO Artiste VALUES( 'Spielberg', 'Steven', '1943');
INSERT INTO Artiste VALUES( 'Hudson', 'Hugh', NULL);
INSERT INTO Artiste VALUES( 'Gillian', 'Terry', '1944');
INSERT INTO Artiste VALUES( 'Truffaut', 'Francois', '1938');
INSERT INTO Artiste VALUES( 'Lambert', 'Christophe', '1953');
INSERT INTO Artiste VALUES( 'Keitel', 'Harvey', '1940');
INSERT INTO Artiste VALUES( 'Woo', 'John', '1951');
INSERT INTO Artiste VALUES( 'Travolta', 'John', '1953');
INSERT INTO Artiste VALUES( 'Cage', 'Nicolas', '1954');
INSERT INTO Artiste VALUES( 'DiCaprio', 'Leonardo', '1973');
INSERT INTO Artiste VALUES( 'Cameron', 'James', '1943');
INSERT INTO Artiste VALUES( 'Cruise', 'Tom', '1960');
INSERT INTO Artiste VALUES( 'De Palma', 'Brian', '1953');
INSERT INTO Artiste VALUES( 'Depp', 'Johnny', '1967');
INSERT INTO Artiste VALUES( 'Ricci', 'Christina', '1974');
INSERT INTO Artiste VALUES( 'Burton', 'Tim', '1958');



CREATE TABLE Cinema (
   Nom_cinema varchar(10) NOT NULL,
   Arrondissement decimal(2,0),
   Adresse varchar(30),
   PRIMARY KEY (Nom_cinema)
);




INSERT INTO Cinema VALUES( 'Rex', '2', '22 Bd Poissoniere');
INSERT INTO Cinema VALUES( 'Kino', '15', '3 Bd Raspail');
INSERT INTO Cinema VALUES( 'Nations', '12', '3 Rue de Reuilly');
INSERT INTO Cinema VALUES( 'Halles', '1', 'Forum des Halles');



CREATE TABLE Film (
   ID_film decimal(10,0) DEFAULT '0' NOT NULL,
   Titre varchar(30),
   Annee decimal(4,0),
   Nom_Realisateur varchar(20),
   PRIMARY KEY (ID_film)
);


INSERT INTO Film VALUES( '10', 'Annie Hall', '1977', 'Allen');
INSERT INTO Film VALUES( '57', 'Brazil', '1984', 'Gillian');
INSERT INTO Film VALUES( '5', 'Underground', '1995', 'Kusturica');
INSERT INTO Film VALUES( '38', 'Metropolis', '1926', 'Lang');
INSERT INTO Film VALUES( '45', 'Impitoyable', '1992', 'Eastwood');
INSERT INTO Film VALUES( '65', 'Vertigo', '1958', 'Hitchcock');
INSERT INTO Film VALUES( '7', 'Shining', '1980', 'Kubrick');
INSERT INTO Film VALUES( '6', 'Psychose', '1960', 'Hitchcock');
INSERT INTO Film VALUES( '3', 'Twin Peaks', '1990', 'Lynch');
INSERT INTO Film VALUES( '90', 'Casablanca', '1942', 'Curtis');
INSERT INTO Film VALUES( '85', 'Greystocke', '1984', 'Hudson');
INSERT INTO Film VALUES( '89', 'Le dernier metro', '1980', 'Truffaut');
INSERT INTO Film VALUES( '1', 'Reservoir Dogs', '1992', 'Tarantino');
INSERT INTO Film VALUES( '43', 'Manhattan', '1979', 'Allen');
INSERT INTO Film VALUES( '11', 'Jurassic Park', '1992', 'Spielberg');
INSERT INTO Film VALUES( '32', 'Rencontres du 3eme type', '1978', 'Spielberg');
INSERT INTO Film VALUES( '33', 'Piege de cristal', '1990', 'Hunt');
INSERT INTO Film VALUES( '34', 'Une journee en enfer', '1994', 'Hunt');
INSERT INTO Film VALUES( '35', '48 minutes pour vivre', '1992', 'Hunt');
INSERT INTO Film VALUES( '73', 'Pulp Fiction', '1995', 'Tarantino');
INSERT INTO Film VALUES( '101', 'Broken Arrow', '1996', 'Woo');
INSERT INTO Film VALUES( '102', 'Volte-Face', '1997', 'Woo');
INSERT INTO Film VALUES( '104', 'Titanic', '1998', 'Cameron');
INSERT INTO Film VALUES( '135', 'Mission Impossible 2', '2000', 'Woo');
INSERT INTO Film VALUES( '136', 'Mission Impossible', '1997', 'De Palma');
INSERT INTO Film VALUES( '142', 'Edward scissorhands', '1990', 'Burton');
INSERT INTO Film VALUES( '141', 'Sleepy Hollow', '1999', 'Burton');




CREATE TABLE Role (
   Nom_Role varchar(20) NOT NULL,
   ID_film decimal(10,0) DEFAULT '0' NOT NULL,
   Nom_acteur varchar(20) NOT NULL,
   PRIMARY KEY (ID_film, Nom_acteur)
);




INSERT INTO Role VALUES( 'Bernard', '32', 'Truffaut');
INSERT INTO Role VALUES( 'Davis', '43', 'Allen');
INSERT INTO Role VALUES( 'Tarzan', '85', 'Lambert');
INSERT INTO Role VALUES( 'Ferguson', '65', 'Stewart');
INSERT INTO Role VALUES( 'Elster', '65', 'Novak');
INSERT INTO Role VALUES( 'Jonas', '10', 'Allen');
INSERT INTO Role VALUES( 'McLane', '33', 'Willis');
INSERT INTO Role VALUES( 'McLane', '34', 'Willis');
INSERT INTO Role VALUES( 'McLane', '35', 'Willis');
INSERT INTO Role VALUES( 'Mr Brown', '1', 'Tarantino');
INSERT INTO Role VALUES( 'Munny', '45', 'Eastwood');
INSERT INTO Role VALUES( 'Mr White', '1', 'Keitel');
INSERT INTO Role VALUES( 'Wolf', '73', 'Keitel');
INSERT INTO Role VALUES( 'Coolidge', '73', 'Willis');
INSERT INTO Role VALUES( 'Vega', '73', 'Travolta');
INSERT INTO Role VALUES( 'Deakins', '101', 'Travolta');
INSERT INTO Role VALUES( 'Archer', '102', 'Travolta');
INSERT INTO Role VALUES( 'Troy', '102', 'Cage');
INSERT INTO Role VALUES( 'Dowson', '104', 'DiCaprio');
INSERT INTO Role VALUES( 'Howard', '135', 'Cruise');
INSERT INTO Role VALUES( 'Howard', '136', 'Cruise');
INSERT INTO Role VALUES( 'Crane', '141', 'Depp');
INSERT INTO Role VALUES( 'Edward', '142', 'Depp');
INSERT INTO Role VALUES( 'Van Tassel', '141', 'Ricci');




CREATE TABLE Salle (
   Nom_cinema varchar(10) NOT NULL,
   No_salle decimal(2,0) DEFAULT '0' NOT NULL,
   Climatise char(1),
   Capacite decimal(4,0),
   PRIMARY KEY (Nom_cinema, No_salle)
);




INSERT INTO Salle VALUES( 'Rex', '1', 'O', '150');
INSERT INTO Salle VALUES( 'Rex', '2', 'O', '100');
INSERT INTO Salle VALUES( 'Rex', '3', 'N', '80');
INSERT INTO Salle VALUES( 'Rex', '4', 'N', '80');
INSERT INTO Salle VALUES( 'Kino', '1', 'N', '280');
INSERT INTO Salle VALUES( 'Kino', '2', 'O', '120');
INSERT INTO Salle VALUES( 'Kino', '3', 'O', '130');
INSERT INTO Salle VALUES( 'Nations', '1', 'O', '130');
INSERT INTO Salle VALUES( 'Nations', '2', 'N', '90');
INSERT INTO Salle VALUES( 'Nations', '3', 'N', '60');
INSERT INTO Salle VALUES( 'Halles', '1', 'O', '75');
INSERT INTO Salle VALUES( 'Halles', '2', 'N', '60');
INSERT INTO Salle VALUES( 'Halles', '3', 'N', '60');




CREATE TABLE Seance (
   Nom_cinema varchar(10) NOT NULL,
   No_salle decimal(2,0) DEFAULT '0' NOT NULL,
   No_seance decimal(2,0) DEFAULT '0' NOT NULL,
   Heure_debut decimal(4,2),
   Heure_fin decimal(4,2),
   ID_film decimal(10,0) DEFAULT '0' NOT NULL,
   PRIMARY KEY (Nom_cinema, No_salle, No_seance)
);



INSERT INTO Seance VALUES( 'Rex', '1', '3', '9.99', '9.99', '1');
INSERT INTO Seance VALUES( 'Rex', '1', '4', '9.99', '9.99', '6');
INSERT INTO Seance VALUES( 'Rex', '2', '1', '9.99', '9.99', '34');
INSERT INTO Seance VALUES( 'Rex', '2', '2', '9.99', '9.99', '34');
INSERT INTO Seance VALUES( 'Rex', '2', '3', '9.99', '9.99', '7');
INSERT INTO Seance VALUES( 'Rex', '2', '4', '9.99', '9.99', '65');
INSERT INTO Seance VALUES( 'Rex', '3', '1', '9.99', '9.99', '11');
INSERT INTO Seance VALUES( 'Rex', '3', '2', '9.99', '9.99', '11');
INSERT INTO Seance VALUES( 'Rex', '3', '3', '9.99', '9.99', '11');
INSERT INTO Seance VALUES( 'Rex', '4', '1', '9.99', '9.99', '38');
INSERT INTO Seance VALUES( 'Rex', '4', '2', '9.99', '9.99', '38');
INSERT INTO Seance VALUES( 'Rex', '4', '3', '9.99', '9.99', '38');
INSERT INTO Seance VALUES( 'Kino', '1', '1', '9.99', '9.99', '34');
INSERT INTO Seance VALUES( 'Kino', '1', '2', '9.99', '9.99', '73');
INSERT INTO Seance VALUES( 'Kino', '1', '3', '9.99', '9.99', '34');
INSERT INTO Seance VALUES( 'Kino', '2', '1', '9.99', '9.99', '43');
INSERT INTO Seance VALUES( 'Kino', '2', '2', '9.99', '9.99', '7');
INSERT INTO Seance VALUES( 'Kino', '2', '3', '9.99', '9.99', '43');
INSERT INTO Seance VALUES( 'Kino', '3', '1', '9.99', '9.99', '101');
INSERT INTO Seance VALUES( 'Kino', '3', '2', '9.99', '9.99', '102');
INSERT INTO Seance VALUES( 'Kino', '3', '3', '9.99', '9.99', '104');
INSERT INTO Seance VALUES( 'Kino', '3', '4', '9.99', '9.99', '104');
INSERT INTO Seance VALUES( 'Nations', '1', '1', '9.99', '9.99', '65');
INSERT INTO Seance VALUES( 'Nations', '1', '2', '9.99', '9.99', '65');
INSERT INTO Seance VALUES( 'Nations', '1', '3', '9.99', '9.99', '65');
INSERT INTO Seance VALUES( 'Nations', '2', '1', '9.99', '9.99', '43');
INSERT INTO Seance VALUES( 'Nations', '2', '2', '9.99', '9.99', '43');
INSERT INTO Seance VALUES( 'Nations', '2', '3', '9.99', '9.99', '43');
INSERT INTO Seance VALUES( 'Nations', '3', '1', '9.99', '9.99', '7');
INSERT INTO Seance VALUES( 'Nations', '3', '2', '9.99', '9.99', '7');
INSERT INTO Seance VALUES( 'Nations', '3', '3', '9.99', '9.99', '7');
INSERT INTO Seance VALUES( 'Halles', '1', '1', '9.99', '9.99', '32');
INSERT INTO Seance VALUES( 'Halles', '1', '2', '9.99', '9.99', '32');
INSERT INTO Seance VALUES( 'Halles', '1', '3', '9.99', '9.99', '32');
INSERT INTO Seance VALUES( 'Halles', '2', '1', '9.99', '9.99', '5');
INSERT INTO Seance VALUES( 'Halles', '2', '2', '9.99', '9.99', '5');
INSERT INTO Seance VALUES( 'Halles', '2', '3', '9.99', '9.99', '45');
INSERT INTO Seance VALUES( 'Halles', '3', '1', '9.99', '9.99', '3');
INSERT INTO Seance VALUES( 'Halles', '3', '2', '9.99', '9.99', '3');
INSERT INTO Seance VALUES( 'Halles', '3', '3', '9.99', '9.99', '3');


