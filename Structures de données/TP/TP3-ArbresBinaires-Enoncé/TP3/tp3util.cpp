/*************************************************************/
/***  L'3 - SDD - TP3  Arbres binaires - tp3util.cpp       ***/
/*************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "tp3util.h"

using namespace std;

/*****************************************************************************
 1- MANIPULATION D'ARBRES BINAIRES
 *****************************************************************************/

static arbre a2(int n, const int t[], int i) {
	if (i >= n || t[i] < 0) {
		return NULL;
	}
	noeud* c = new noeud;
	c->info = t[i];
	c->sag = a2(n, t, 2*i+1);
	c->sad = a2(n, t, 2*i+2);
	return c;
}

static void ta(arbre a, noeud** t, int n, int i) {
	if (i >= n) {
		return;
	}
	t[i] = a;
	ta(a == NULL ? NULL : a->sag, t, n, 2*i+1);
	ta(a == NULL ? NULL : a->sad, t, n, 2*i+2);
}

static int oa(arbre a) {
	if (a == NULL) {
		return -1;
	}
	if (a->sag == NULL && a->sad == NULL) {
		return 0;
	}
	int hg = oa(a->sag);
	int hd = oa(a->sad);
	return 1 + max(hg, hd);
}

#define NBAPROF(p)		((p) < 0 ? - 1 : 1 << (p))
#define NBTPROF(p)		((p) < 0 ? - 1 : (1 << ((p)+1)) - 1)

#define AFFICH(s, v)	{ if (ISOP(v)) s << V2O(v); else s << v; }

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
arbre arbret(unsigned int n, const int t[]) {
	if (n == 0) {
		return NULL;
	}
	return a2(n, t, 0);
}

/**
 * Représente un arbre sous la forme d'une chaine de caractères, une ligne par
 * niveau de profondeur.
 *
 * Parametre p : pile à représenter.
 *
 * Retourne : la chaîne représentant p.
 */
#define FWIDTH 4
string chainea(arbre a) {
	// si l'arbre est vide
	if (a == NULL) {
		return ".";
	}
	// convertir l'arbre en tableau
	int h = oa(a);
	int n = NBTPROF(h);
	noeud** t = new noeud*[n];
	ta(a, t, n, 0);
	// préparer les espaces entre noeuds
	int e1 = NBAPROF(h) - 1;
	int e2 = 0;
	// parcourir le tableau couche par couche
	ostringstream s;
	s << string(e1 * FWIDTH, ' ');
	for (int i = 0, p = 0; i < n; i++) {
		if (i == NBTPROF(p)) {
			p += 1;
			e2 = e1;
			e1 = e2 / 2;
			s << endl << string(e1 * FWIDTH, ' ');
		}
		if (t[i] == NULL) {
			s << string(1 * FWIDTH, ' ');
		} else {
			s << setw(FWIDTH);
			//AFFICH(s, t[i]->info);
			s << t[i]->info;
		}
		s << string(e2 * FWIDTH, ' ');
	}
	delete[] t;
	return s.str();
}

/**
 * Constitue un arbre composé d'un unique noeud portant la valeur donnée.
 *
 * Paramètre v : valeur à donner au noeud.
 *
 * Retourne : l'arbre constitué.
 */
arbre singleton(int v) {
	noeud* r = new noeud;
	r->info = v;
	r->sag = NULL;
	r->sad = NULL;
	return r;
}

/*****************************************************************************
 2- MANIPULATION DE LISTES
 *****************************************************************************/

/**
 * Représente une liste sous forme d'une chaîne de caractères. La liste peut
 * être linéaire ou circulaire.
 *
 * Parametre l : liste a représenter.
 *
 * Retourne : la chaîne représentant l.
 */
string chainel(liste l) {
	if (l == NULL) {
		return ".";
	}
	ostringstream r;
	maillon* c = l;
	do {
		r << "[" << c->info->info << "]";
		if (c->succ == NULL || c->succ == l) {
		    break;
		}
		r << "->";
		c = c->succ;
	} while (true);
	r << (c->succ == NULL ? "|" : ">");
	return r.str();
}

/**
 * Concatène deux listes simplement chainées lineaires entre elles.
 *
 * Paramètre l1 : liste à laquelle concaténer l2.
 * Paramètre l2 : liste à concaténer a l1.
 *
 * Retourne : 1 si succes et 0 sinon.
 */
int concatener(liste* l1, liste l2) {
    // si un paramètre est incorrect
    if (l1 == NULL) {
        return 0;
    }
    // si l2 est vide : rien à faire
    if (l2 == NULL) {
        return 1;
    }
    // si l1 est vide : la concaténation est l2
    if (*l1 == NULL) {
        *l1 = l2;
        return 1;
    }
    // cas général : trouver le dernier maillon de l1
    maillon* c = *l1;
    while (c->succ != NULL) {
        c = c->succ;
    }
    // et y chainer l2
    c->succ = l2;
    return 1;
}

/**
 * Constitue une liste composée d'un maillon portant la valeur donnée.
 *
 * Paramètre v : valeur du maillon.
 *
 * Retourne : la liste constituée.
 */
liste singleton(T v) {
	maillon* r = new maillon;
	r->info = v;
	r->succ = NULL;
	return r;
}

/**
 * Cherche un élément dans une liste.
 *
 * Paramètre l : liste à examiner.
 * Paramètre v : valeur à chercher.
 *
 * Retourne : l'adresse du premier maillon portant la valeur v, NULL si aucun
 * maillon ne porte cette valeur.
 */
maillon* chercher(liste l, T v) {
	while (l != NULL) {
		if (l->info == v) {
			return l;
		}
		l = l->succ;
	}
	return NULL;
}



/*****************************************************************************
 3- MANIPULATION DE PILES
 *****************************************************************************/

/**
 * Représente une pile sous la forme d'une chaine de caractères. Le premier
 * élément listé est le sommet de la pile, le dernier le fond.
 *
 * Parametre p : pile à représenter.
 *
 * Retourne : la chaîne représentant p.
 */
string chainep(pile* p) {
	if (estPileVide(*p)) {
		return "<|";
	}
	ostringstream s;
	pile t = initPile();
	s << "<";
	// parcours DESTRUCTIF de la pile
	while (!estPileVide(*p)) {
		T e;
		depiler(p, &e);
		empiler(&t, e);
		s << e->info << ", ";
	}
	// pile à RECONSTRUIRE juste apres
	while (!estPileVide(t)) {
		T e;
		depiler(&t, &e);
		empiler(p, e);
	}
	// remplacer le dernier ", " par "|" (fond de pile)
	string r = s.str();
	return r.replace(r.size() - 2, r.size(), "|");
}

/**
 * Sert à initialiser une variable de type pile à "pile vide".
 *
 * Retourne : la valeur d'initialisation d'une pile vide.
 */
pile initPile() {
	pile r;
	r.elements = NULL;
	r.taille = 0;
	return r;
}

/**
 * Détermine la taille d'une pile.
 *
 * Paramètre p : pile à examiner.
 *
 * Retourne : la taille de p.
 */
int taillePile(pile p) {
	return p.taille;
}

/**
 * Détermine si une pile est vide.
 *
 * Paramètre p : pile à tester.
 *
 * Retourne : 1 si p est vide et 0 sinon.
 */
int estPileVide(pile p) {
	return taillePile(p) == 0;
}

/**
 * Détermine l'élément au sommet d'une pile.
 *
 * Paramètre p : pile à examiner.
 * Paramètre e : sommet de la pile retourné.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int sommet(pile p, T* e) {
	// si un paramètre ou l'état est incorrect
	if (e == NULL || estPileVide((p))) {
		return 0;
	}
	*e = p.elements->info;
	return 1;
}

/**
 * Empile un élément sur une pile.
 *
 * Paramètre p : pile sur laquelle empiler.
 * Paramètre e : élément à empiler.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int empiler(pile* p, T e) {
	// si un paramètre est incorrect
	if (p == NULL) {
		return 0;
	}
	maillon* n = new maillon;
	n->info = e;
	n->succ = p->elements;
	p->elements = n;
	p->taille += 1;
	return 1;
}

/**
 * Dépile un élément d'une pile.
 *
 * Paramètre p : pile de laquelle dépiler.
 * Paramètre e : élément dépilé.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int depiler(pile* p, T* e) {
	// si un paramètre ou l'état est incorrect
	if (p == NULL || e == NULL || estPileVide(*p)) {
		return 0;
	}
	maillon* d = p->elements;
	*e = d->info;
	p->elements = p->elements->succ;
	p->taille -= 1;
	delete d;
	return 1;
}


/*****************************************************************************
 4- MANIPULATION DE FILES
 *****************************************************************************/

/**
 * Représente une file sous la forme d'une chaine de caractères. Le premier
 * élément listé est le début de la file, le dernier la fin.
 *
 * Parametre f : file à représenter.
 *
 * Retourne : la chaîne représentant f.
 */
string chainef(file* f) {
	if (estFileVide(*f)) {
		return "<<";
	}
	ostringstream s;
	int t = tailleFile(*f);
	s << "<";
	// parcours reconstructif de la file
	for (int i = 0; i < t; i++) {
		T e;
		defiler(f, &e);
		enfiler(f, e);
		s << e->info << ", ";
	}
	// remplacer le dernier ", " par "<" (fin de file)
	string r = s.str();
	return r.replace(r.size() - 2, r.size(), "<");
}

/**
 * Sert à initialiser une variable de type file à "file vide".
 *
 * Retourne : la valeur d'initialisation d'une file vide.
 */
file initFile() {
	file r;
	r.debut = NULL;
	r.taille = 0;
	return r;
}

/**
 * Détermine la taille d'une file.
 *
 * Paramètre f : file à examiner.
 *
 * Retourne : la taille de f.
 */
int tailleFile(file f) {
	return f.taille;
}

/**
 * Détermine si une file est vide.
 *
 * Paramètre f : file à tester.
 *
 * Retourne : 1 si f est vide et 0 sinon.
 */
int estFileVide(file f) {
	return tailleFile(f) == 0;
}

/**
 * Détermine l'élément au début d'une file.
 *
 * Paramètre f : file à examiner.
 * Paramètre e : début de la file retourné.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int debut(file f, T* e) {
	// si un paramètre ou l'état est incorrect
	if (e == NULL || estFileVide((f))) {
		return 0;
	}
	*e = f.debut->info;
	return 1;
}

/**
 * Détermine l'élément à la fin d'une file.
 *
 * Paramètre f : file à examiner.
 * Paramètre e : fin de la file retourné.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int fin(file f, T* e) {
	// si un paramètre ou l'état est incorrect
	if (e == NULL || estFileVide((f))) {
		return 0;
	}
	*e = f.fin->info;
	return 1;
}

/**
 * Enfile un élément dans une pile.
 *
 * Paramètre f : file dans laquelle enfiler.
 * Paramètre e : élément à enfiler.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int enfiler(file* f, T e) {
	// si un paramètre est incorrect
	if (f == NULL) {
		return 0;
	}
	// créer le maillon à ajouter
	maillon* n = new maillon;
	n->info = e;
	n->succ = NULL;
	// si premier maillon de la file
	if (f->debut == NULL) {
		// initialiser debut, fin et taille
		f->debut = n;
		f->fin = n;
		f->taille = 1;
		return 1;
	}
	// sinon, ne modifier que fin et taille
	f->fin->succ = n;
	f->fin = n;
	f->taille += 1;
	return 1;
}

/**
 * Défile un élément d'une file.
 *
 * Paramètre f : file de laquelle défiler.
 * Paramètre e : élément défilé.
 *
 * Retourne : 1 si succès et 0 sinon.
 */
int defiler(file* f, T* e) {
	// si un paramètre ou l'état est incorrect
	if (f == NULL || e == NULL || estFileVide(*f)) {
		return 0;
	}
	maillon* d = f->debut;
	*e = d->info;
	f->debut = d->succ;
	f->taille -= 1;
	delete d;
	// note : pas besoin de modifier f->fin
	return 1;
}
