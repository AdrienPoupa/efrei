DROP TABLE IF EXISTS Eleve ;
CREATE TABLE Eleve (nom VARCHAR(255)  AUTO_INCREMENT NOT NULL,
prenom VARCHAR(255),
naissance DATE,
sexe VARCHAR(1),
inscription DATE,
etablissement_precedent VARCHAR(255),
photo BLOB,
num_rue VARCHAR(255),
cp INT(5),
ville VARCHAR(255),
tel_domicile VARCHAR(10),
tel_mobile VARCHAR(10),
id_eleve INT(8) NOT NULL,
documents_id_eleve3 VARCHAR(255) NOT NULL,
PRIMARY KEY (nom) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Responsable ;
CREATE TABLE Responsable (id_eleve INT(8)  AUTO_INCREMENT NOT NULL,
nom_responsable VARCHAR(255),
prenom_responsable VARCHAR(255),
tel_responsable INTEGER(10),
email_responsable VARCHAR(255),
num_rue_responsable VARCHAR(255),
cp_responsable BIGINT(5),
ville_responsable VARCHAR(255),
PRIMARY KEY (id_eleve) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Sante ;
CREATE TABLE Sante (id_eleve2 INT(8)  AUTO_INCREMENT NOT NULL,
nom_medecin VARCHAR(255),
prenom_medecin VARCHAR(255),
tel_medecin INT(10),
PRIMARY KEY (id_eleve2) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Documents ;
CREATE TABLE Documents (id_eleve3 INT(8)  AUTO_INCREMENT NOT NULL,
convocation BLOB,
bulletin_notes BLOB,
eleve_nom INT(8) NOT NULL,
PRIMARY KEY (id_eleve3) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Professeur ;
CREATE TABLE Professeur (id_professeur INT(10)  AUTO_INCREMENT NOT NULL,
nom_professeur VARCHAR(255),
prenom_professeur VARCHAR(255),
PRIMARY KEY (id_professeur) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Groupe_eleve ;
CREATE TABLE Groupe_eleve (id_eleve4 INT(8)  AUTO_INCREMENT NOT NULL,
id_groupe INT(10),
PRIMARY KEY (id_eleve4) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Cours ;
CREATE TABLE Cours (id_cours BIGINT(10)  AUTO_INCREMENT NOT NULL,
nom_cours VARCHAR(255),
id_groupe2 INT(10),
PRIMARY KEY (id_cours) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS Coefficient ;
CREATE TABLE Coefficient (id_note_cours INT(10)  AUTO_INCREMENT NOT NULL,
type_note VARCHAR(3),
id_cours3 INT(10),
coefficient FLOAT(3),
PRIMARY KEY (id_note_cours) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS est_soigne_par ;
CREATE TABLE est_soigne_par (nom VARCHAR(255)  AUTO_INCREMENT NOT NULL,
id_eleve2 INT(8) NOT NULL,
vaccinations TEXT,
allergies TEXT,
remarques_medicales TEXT,
PRIMARY KEY (nom,
 id_eleve2) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS a_pour_professeurs ;
CREATE TABLE a_pour_professeurs (id_eleve4 INT(8)  AUTO_INCREMENT NOT NULL,
id_professeur INT(10) NOT NULL,
PRIMARY KEY (id_eleve4,
 id_professeur) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS suit_le_cours ;
CREATE TABLE suit_le_cours (id_cours BIGINT(10)  AUTO_INCREMENT NOT NULL,
id_eleve4 INT(8) NOT NULL,
PRIMARY KEY (id_cours,
 id_eleve4) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS a_comme_coefficients ;
CREATE TABLE a_comme_coefficients (id_cours BIGINT(10)  AUTO_INCREMENT NOT NULL,
id_note_cours INT(10) NOT NULL,
PRIMARY KEY (id_cours,
 id_note_cours) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS a_comme_groupe ;
CREATE TABLE a_comme_groupe (id_eleve4 INT(8)  AUTO_INCREMENT NOT NULL,
nom VARCHAR(255) NOT NULL,
id_professeur INT(10) NOT NULL,
PRIMARY KEY (id_eleve4,
 nom,
 id_professeur) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS enseigne_le_cours ;
CREATE TABLE enseigne_le_cours (id_professeur INT(10)  AUTO_INCREMENT NOT NULL,
id_cours BIGINT(10) NOT NULL,
PRIMARY KEY (id_professeur,
 id_cours) ) ENGINE=InnoDB;

DROP TABLE IF EXISTS a_comme_note_pour_le_cours ;
CREATE TABLE a_comme_note_pour_le_cours (nom VARCHAR(255)  AUTO_INCREMENT NOT NULL,
id_cours BIGINT(10) NOT NULL,
note FLOAT(4),
PRIMARY KEY (nom,
 id_cours) ) ENGINE=InnoDB;

ALTER TABLE Eleve ADD CONSTRAINT FK_Eleve_id_eleve FOREIGN KEY (id_eleve) REFERENCES Responsable (id_eleve);

ALTER TABLE Eleve ADD CONSTRAINT FK_Eleve_documents_id_eleve3 FOREIGN KEY (documents_id_eleve3) REFERENCES Documents (id_eleve3);
ALTER TABLE Documents ADD CONSTRAINT FK_Documents_eleve_nom FOREIGN KEY (eleve_nom) REFERENCES Eleve (nom);
ALTER TABLE est_soigne_par ADD CONSTRAINT FK_est_soigne_par_nom FOREIGN KEY (nom) REFERENCES Eleve (nom);
ALTER TABLE est_soigne_par ADD CONSTRAINT FK_est_soigne_par_id_eleve2 FOREIGN KEY (id_eleve2) REFERENCES Sante (id_eleve2);
ALTER TABLE a_pour_professeurs ADD CONSTRAINT FK_a_pour_professeurs_id_eleve4 FOREIGN KEY (id_eleve4) REFERENCES Groupe_eleve (id_eleve4);
ALTER TABLE a_pour_professeurs ADD CONSTRAINT FK_a_pour_professeurs_id_professeur FOREIGN KEY (id_professeur) REFERENCES Professeur (id_professeur);
ALTER TABLE suit_le_cours ADD CONSTRAINT FK_suit_le_cours_id_cours FOREIGN KEY (id_cours) REFERENCES Cours (id_cours);
ALTER TABLE suit_le_cours ADD CONSTRAINT FK_suit_le_cours_id_eleve4 FOREIGN KEY (id_eleve4) REFERENCES Groupe_eleve (id_eleve4);
ALTER TABLE a_comme_coefficients ADD CONSTRAINT FK_a_comme_coefficients_id_cours FOREIGN KEY (id_cours) REFERENCES Cours (id_cours);
ALTER TABLE a_comme_coefficients ADD CONSTRAINT FK_a_comme_coefficients_id_note_cours FOREIGN KEY (id_note_cours) REFERENCES Coefficient (id_note_cours);
ALTER TABLE a_comme_groupe ADD CONSTRAINT FK_a_comme_groupe_id_eleve4 FOREIGN KEY (id_eleve4) REFERENCES Groupe_eleve (id_eleve4);
ALTER TABLE a_comme_groupe ADD CONSTRAINT FK_a_comme_groupe_nom FOREIGN KEY (nom) REFERENCES Eleve (nom);
ALTER TABLE a_comme_groupe ADD CONSTRAINT FK_a_comme_groupe_id_professeur FOREIGN KEY (id_professeur) REFERENCES Professeur (id_professeur);
ALTER TABLE enseigne_le_cours ADD CONSTRAINT FK_enseigne_le_cours_id_professeur FOREIGN KEY (id_professeur) REFERENCES Professeur (id_professeur);
ALTER TABLE enseigne_le_cours ADD CONSTRAINT FK_enseigne_le_cours_id_cours FOREIGN KEY (id_cours) REFERENCES Cours (id_cours);
ALTER TABLE a_comme_note_pour_le_cours ADD CONSTRAINT FK_a_comme_note_pour_le_cours_nom FOREIGN KEY (nom) REFERENCES Eleve (nom);
ALTER TABLE a_comme_note_pour_le_cours ADD CONSTRAINT FK_a_comme_note_pour_le_cours_id_cours FOREIGN KEY (id_cours) REFERENCES Cours (id_cours);
