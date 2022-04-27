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
arbre arbret(unsigned int n, const int t[]) {
	if (n == 0) {
		return NULL;
	}
	return a2(n, t, 0);
}

/**
 * Repr�sente un arbre sous la forme d'une chaine de caract�res, une ligne par
 * niveau de profondeur.
 *
 * Parametre p : pile � repr�senter.
 *
 * Retourne : la cha�ne repr�sentant p.
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
	// pr�parer les espaces entre noeuds
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
 * Constitue un arbre compos� d'un unique noeud portant la valeur donn�e.
 *
 * Param�tre v : valeur � donner au noeud.
 *
 * Retourne : l'arbre constitu�.
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
 * Repr�sente une liste sous forme d'une cha�ne de caract�res. La liste peut
 * �tre lin�aire ou circulaire.
 *
 * Parametre l : liste a repr�senter.
 *
 * Retourne : la cha�ne repr�sentant l.
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
 * Concat�ne deux listes simplement chain�es lineaires entre elles.
 *
 * Param�tre l1 : liste � laquelle concat�ner l2.
 * Param�tre l2 : liste � concat�ner a l1.
 *
 * Retourne : 1 si succes et 0 sinon.
 */
int concatener(liste* l1, liste l2) {
    // si un param�tre est incorrect
    if (l1 == NULL) {
        return 0;
    }
    // si l2 est vide : rien � faire
    if (l2 == NULL) {
        return 1;
    }
    // si l1 est vide : la concat�nation est l2
    if (*l1 == NULL) {
        *l1 = l2;
        return 1;
    }
    // cas g�n�ral : trouver le dernier maillon de l1
    maillon* c = *l1;
    while (c->succ != NULL) {
        c = c->succ;
    }
    // et y chainer l2
    c->succ = l2;
    return 1;
}

/**
 * Constitue une liste compos�e d'un maillon portant la valeur donn�e.
 *
 * Param�tre v : valeur du maillon.
 *
 * Retourne : la liste constitu�e.
 */
liste singleton(T v) {
	maillon* r = new maillon;
	r->info = v;
	r->succ = NULL;
	return r;
}

/**
 * Cherche un �l�ment dans une liste.
 *
 * Param�tre l : liste � examiner.
 * Param�tre v : valeur � chercher.
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
 * Repr�sente une pile sous la forme d'une chaine de caract�res. Le premier
 * �l�ment list� est le sommet de la pile, le dernier le fond.
 *
 * Parametre p : pile � repr�senter.
 *
 * Retourne : la cha�ne repr�sentant p.
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
	// pile � RECONSTRUIRE juste apres
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
 * Sert � initialiser une variable de type pile � "pile vide".
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
 * D�termine la taille d'une pile.
 *
 * Param�tre p : pile � examiner.
 *
 * Retourne : la taille de p.
 */
int taillePile(pile p) {
	return p.taille;
}

/**
 * D�termine si une pile est vide.
 *
 * Param�tre p : pile � tester.
 *
 * Retourne : 1 si p est vide et 0 sinon.
 */
int estPileVide(pile p) {
	return taillePile(p) == 0;
}

/**
 * D�termine l'�l�ment au sommet d'une pile.
 *
 * Param�tre p : pile � examiner.
 * Param�tre e : sommet de la pile retourn�.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int sommet(pile p, T* e) {
	// si un param�tre ou l'�tat est incorrect
	if (e == NULL || estPileVide((p))) {
		return 0;
	}
	*e = p.elements->info;
	return 1;
}

/**
 * Empile un �l�ment sur une pile.
 *
 * Param�tre p : pile sur laquelle empiler.
 * Param�tre e : �l�ment � empiler.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int empiler(pile* p, T e) {
	// si un param�tre est incorrect
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
 * D�pile un �l�ment d'une pile.
 *
 * Param�tre p : pile de laquelle d�piler.
 * Param�tre e : �l�ment d�pil�.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int depiler(pile* p, T* e) {
	// si un param�tre ou l'�tat est incorrect
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
 * Repr�sente une file sous la forme d'une chaine de caract�res. Le premier
 * �l�ment list� est le d�but de la file, le dernier la fin.
 *
 * Parametre f : file � repr�senter.
 *
 * Retourne : la cha�ne repr�sentant f.
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
 * Sert � initialiser une variable de type file � "file vide".
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
 * D�termine la taille d'une file.
 *
 * Param�tre f : file � examiner.
 *
 * Retourne : la taille de f.
 */
int tailleFile(file f) {
	return f.taille;
}

/**
 * D�termine si une file est vide.
 *
 * Param�tre f : file � tester.
 *
 * Retourne : 1 si f est vide et 0 sinon.
 */
int estFileVide(file f) {
	return tailleFile(f) == 0;
}

/**
 * D�termine l'�l�ment au d�but d'une file.
 *
 * Param�tre f : file � examiner.
 * Param�tre e : d�but de la file retourn�.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int debut(file f, T* e) {
	// si un param�tre ou l'�tat est incorrect
	if (e == NULL || estFileVide((f))) {
		return 0;
	}
	*e = f.debut->info;
	return 1;
}

/**
 * D�termine l'�l�ment � la fin d'une file.
 *
 * Param�tre f : file � examiner.
 * Param�tre e : fin de la file retourn�.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int fin(file f, T* e) {
	// si un param�tre ou l'�tat est incorrect
	if (e == NULL || estFileVide((f))) {
		return 0;
	}
	*e = f.fin->info;
	return 1;
}

/**
 * Enfile un �l�ment dans une pile.
 *
 * Param�tre f : file dans laquelle enfiler.
 * Param�tre e : �l�ment � enfiler.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int enfiler(file* f, T e) {
	// si un param�tre est incorrect
	if (f == NULL) {
		return 0;
	}
	// cr�er le maillon � ajouter
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
 * D�file un �l�ment d'une file.
 *
 * Param�tre f : file de laquelle d�filer.
 * Param�tre e : �l�ment d�fil�.
 *
 * Retourne : 1 si succ�s et 0 sinon.
 */
int defiler(file* f, T* e) {
	// si un param�tre ou l'�tat est incorrect
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
