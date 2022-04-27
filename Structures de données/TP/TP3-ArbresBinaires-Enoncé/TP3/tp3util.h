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
 * Convertit un tableau d'entiers en un arbre. L'�l�ment d'indice 0 du tableau
 * est la racine de l'arbre. Pour un �l�ment d'indice n :
 * - l'�l�ment d'indice 2*i+1 est son fils gauche,
 * - l'�l�ment d'indice 2*i+2 est son fils droit.
 * Une valeur n�gative dans le tableau signale l'absence de noeud. Du fait de
 * cette convention, la fonction ne peut construire d'arbre contenant des
 * valeurs n�gatives.
 *
 * Param�tre n : le nombre d'�l�ments de t.
 * Param�tre t : tableau d'entiers � convertir.
 *
 * Retourne : l'arbre �quivalent � t.
 */
arbre arbret(unsigned int n, const int t[]);

/**
 * Repr�sente un arbre sous la forme d'une chaine de caract�res, une ligne par
 * niveau de profondeur.
 *
 * Parametre a : arbre � repr�senter.
 *
 * Retourne : la cha�ne repr�sentant p.
 */
std::string chainea(arbre a);

/**
 * Constitue un arbre compos� d'un unique noeud portant la valeur donn�e.
 *
 * Param�tre v : valeur � donner au noeud.
 *
 * Retourne : l'arbre constitu�.
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
 * Repr�sente une liste sous forme d'une cha�ne de caract�res. La liste peut
 * �tre lin�aire ou circulaire.
 *
 * Parametre l : liste a repr�senter.
 *
 * Retourne : la cha�ne repr�sentant l.
 */
std::string chainel(liste l);

/**
 * Concat�ne deux listes simplement chain�es lin�aires.
 *
 * Param�tre l1 : liste � laquelle concat�ner l2.
 * Param�tre l2 : liste � concat�ner � l1.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int concatener(liste* l1, liste l2);

/**
 * Constitue une liste compos�e d'un maillon portant la valeur donn�e.
 *
 * Param�tre v : valeur du maillon.
 *
 * Retourne : la liste constitu�e.
 */
liste singleton(T v);

/**
 * Cherche un �l�ment dans une liste.
 *
 * Param�tre l : liste � examiner.
 * Param�tre v : valeur � chercher.
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
 * Repr�sente une pile sous la forme d'une chaine de caract�res. Le premier
 * �l�ment list� est le sommet de la pile, le dernier le fond.
 *
 * Parametre p : pile � repr�senter.
 *
 * Retourne : la cha�ne repr�sentant p.
 */
std::string chainep(pile* p);

/**
 * Sert � initialiser une variable de type pile � "pile vide".
 *
 * Retourne : la valeur d'initialisation d'une pile vide.
 */
pile initPile();

/**
 * D�termine la taille d'une pile.
 *
 * Param�tre p : pile � examiner.
 *
 * Retourne : la taille de p.
 */
int taillePile(pile p);

/**
 * D�termine si une pile est vide.
 *
 * Param�tre p : pile � tester.
 *
 * Retourne : 1 si p est vide et 0 sinon.
 */
int estPileVide(pile p);

/**
 * D�termine l'�l�ment au sommet d'une pile.
 *
 * Param�tre p : pile � examiner.
 * Param�tre e : sommet de la pile retourn�.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int sommet(pile p, T* e);

/**
 * Empile un �l�ment sur une pile.
 *
 * Param�tre p : pile sur laquelle empiler.
 * Param�tre e : �l�ment � empiler.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int empiler(pile* p, T e);

/**
 * D�pile un �l�ment d'une pile.
 *
 * Param�tre p : pile de laquelle d�piler.
 * Param�tre e : �l�ment d�pil�.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int depiler(pile* p, T* e);


/*****************************************************************************
 4- DEFINITION ET MANIPULATION DE FILES D'ADRESSES DE MAILLONS
 *****************************************************************************/

typedef struct file {
	maillon* debut; 		// �l�ment de d�but de file
	maillon* fin; 			// �l�ment de fin de file
	unsigned int taille;
} file;

/**
 * Repr�sente une file sous la forme d'une chaine de caract�res. Le premier
 * �l�ment list� est le d�but de la file, le dernier la fin.
 *
 * Parametre f : file � repr�senter.
 *
 * Retourne : la cha�ne repr�sentant f.
 */
std::string chainef(file* f);

/**
 * Sert � initialiser une variable de type file � "file vide".
 *
 * Retourne : la valeur d'initialisation d'une file vide.
 */
file initFile();

/**
 * D�termine la taille d'une file.
 *
 * Param�tre f : file � examiner.
 *
 * Retourne : la taille de f.
 */
int tailleFile(file f);

/**
 * D�termine si une file est vide.
 *
 * Param�tre f : file � tester.
 *
 * Retourne : 1 si f est vide et 0 sinon.
 */
int estFileVide(file f);

/**
 * D�termine l'�l�ment au d�but d'une file.
 *
 * Param�tre f : file � examiner.
 * Param�tre e : d�but de la file retourn�.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int debut(file f, T* e);

/**
 * D�termine l'�l�ment � la fin d'une file.
 *
 * Param�tre f : file � examiner.
 * Param�tre e : fin de la file retourn�.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int fin(file f, T* e);

/**
 * Enfile un �l�ment dans une pile.
 *
 * Param�tre f : file dans laquelle enfiler.
 * Param�tre e : �l�ment � enfiler.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int enfiler(file* f, T e);

/**
 * D�file un �l�ment d'une file.
 *
 * Param�tre f : file de laquelle d�filer.
 * Param�tre e : �l�ment d�fil�.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int defiler(file* f, T* e);

#endif /* TP3UTIL_H_ */
