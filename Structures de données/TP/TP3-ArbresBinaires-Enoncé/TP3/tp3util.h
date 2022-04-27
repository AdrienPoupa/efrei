/*************************************************************/
/***  L'3 - SDD - TP3  Arbres binaires - tp3util.h         ***/
/*************************************************************/

#ifndef TP3UTIL_H_
#define TP3UTIL_H_

#include <string>


/*****************************************************************************
 1- DEFINITION ET MANIPULATION D'ARBRES BINAIRES D'ENTIERS
 *****************************************************************************/

typedef struct noeud {
	int info;
	struct noeud* sag;
	struct noeud* sad;
} noeud;

typedef noeud* arbre;

/**
 * Convertit un tableau d'entiers en un arbre. L'élément d'indice 0 du tableau
 * est la racine de l'arbre. Pour un élément d'indice n :
 * - l'élément d'indice 2*i+1 est son fils gauche,
 * - l'élément d'indice 2*i+2 est son fils droit.
 * Une valeur négative dans le tableau signale l'absence de noeud. Du fait de
 * cette convention, la fonction ne peut construire d'arbre contenant des
 * valeurs négatives.
 *
 * Paramètre n : le nombre d'éléments de t.
 * Paramètre t : tableau d'entiers à convertir.
 *
 * Retourne : l'arbre équivalent à t.
 */
arbre arbret(unsigned int n, const int t[]);

/**
 * Représente un arbre sous la forme d'une chaine de caractères, une ligne par
 * niveau de profondeur.
 *
 * Parametre a : arbre à représenter.
 *
 * Retourne : la chaîne représentant p.
 */
std::string chainea(arbre a);

/**
 * Constitue un arbre composé d'un unique noeud portant la valeur donnée.
 *
 * Paramètre v : valeur à donner au noeud.
 *
 * Retourne : l'arbre constitué.
 */
arbre singleton(int v);


/*****************************************************************************
 2- DEFINITION ET MANIPULATION DE LISTES D'ADRESSES DE NOEUDS
 *****************************************************************************/

typedef noeud* T;

typedef struct maillon {
	T info;
	struct maillon* succ;
} maillon;

typedef maillon* liste;

/**
 * Représente une liste sous forme d'une chaîne de caractères. La liste peut
 * être linéaire ou circulaire.
 *
 * Parametre l : liste a représenter.
 *
 * Retourne : la chaîne représentant l.
 */
std::string chainel(liste l);

/**
 * Concatène deux listes simplement chainées linéaires.
 *
 * Paramètre l1 : liste à laquelle concaténer l2.
 * Paramètre l2 : liste à concaténer à l1.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int concatener(liste* l1, liste l2);

/**
 * Constitue une liste composée d'un maillon portant la valeur donnée.
 *
 * Paramètre v : valeur du maillon.
 *
 * Retourne : la liste constituée.
 */
liste singleton(T v);

/**
 * Cherche un élément dans une liste.
 *
 * Paramètre l : liste à examiner.
 * Paramètre v : valeur à chercher.
 *
 * Retourne : l'adresse du premier maillon portant la valeur v, NULL si aucun
 * maillon ne porte cette valeur.
 */
maillon* chercher(liste l, T v);


/*****************************************************************************
 3- DEFINITION ET MANIPULATION DE PILES D'ADRESSES DE MAILLONS
 *****************************************************************************/

typedef struct pile {
	liste elements;
	unsigned int taille;
} pile;

/**
 * Représente une pile sous la forme d'une chaine de caractères. Le premier
 * élément listé est le sommet de la pile, le dernier le fond.
 *
 * Parametre p : pile à représenter.
 *
 * Retourne : la chaîne représentant p.
 */
std::string chainep(pile* p);

/**
 * Sert à initialiser une variable de type pile à "pile vide".
 *
 * Retourne : la valeur d'initialisation d'une pile vide.
 */
pile initPile();

/**
 * Détermine la taille d'une pile.
 *
 * Paramètre p : pile à examiner.
 *
 * Retourne : la taille de p.
 */
int taillePile(pile p);

/**
 * Détermine si une pile est vide.
 *
 * Paramètre p : pile à tester.
 *
 * Retourne : 1 si p est vide et 0 sinon.
 */
int estPileVide(pile p);

/**
 * Détermine l'élément au sommet d'une pile.
 *
 * Paramètre p : pile à examiner.
 * Paramètre e : sommet de la pile retourné.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int sommet(pile p, T* e);

/**
 * Empile un élément sur une pile.
 *
 * Paramètre p : pile sur laquelle empiler.
 * Paramètre e : élément à empiler.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int empiler(pile* p, T e);

/**
 * Dépile un élément d'une pile.
 *
 * Paramètre p : pile de laquelle dépiler.
 * Paramètre e : élément dépilé.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int depiler(pile* p, T* e);


/*****************************************************************************
 4- DEFINITION ET MANIPULATION DE FILES D'ADRESSES DE MAILLONS
 *****************************************************************************/

typedef struct file {
	maillon* debut; 		// élément de début de file
	maillon* fin; 			// élément de fin de file
	unsigned int taille;
} file;

/**
 * Représente une file sous la forme d'une chaine de caractères. Le premier
 * élément listé est le début de la file, le dernier la fin.
 *
 * Parametre f : file à représenter.
 *
 * Retourne : la chaîne représentant f.
 */
std::string chainef(file* f);

/**
 * Sert à initialiser une variable de type file à "file vide".
 *
 * Retourne : la valeur d'initialisation d'une file vide.
 */
file initFile();

/**
 * Détermine la taille d'une file.
 *
 * Paramètre f : file à examiner.
 *
 * Retourne : la taille de f.
 */
int tailleFile(file f);

/**
 * Détermine si une file est vide.
 *
 * Paramètre f : file à tester.
 *
 * Retourne : 1 si f est vide et 0 sinon.
 */
int estFileVide(file f);

/**
 * Détermine l'élément au début d'une file.
 *
 * Paramètre f : file à examiner.
 * Paramètre e : début de la file retourné.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int debut(file f, T* e);

/**
 * Détermine l'élément à la fin d'une file.
 *
 * Paramètre f : file à examiner.
 * Paramètre e : fin de la file retourné.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int fin(file f, T* e);

/**
 * Enfile un élément dans une pile.
 *
 * Paramètre f : file dans laquelle enfiler.
 * Paramètre e : élément à enfiler.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int enfiler(file* f, T e);

/**
 * Défile un élément d'une file.
 *
 * Paramètre f : file de laquelle défiler.
 * Paramètre e : élément défilé.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int defiler(file* f, T* e);

#endif /* TP3UTIL_H_ */
