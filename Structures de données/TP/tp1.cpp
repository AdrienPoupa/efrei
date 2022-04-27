/*************************************************************/
/***  L'3 - SDD - TP 1 - Listes chaînées                   ***/
/*************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;


/******************************************************************************
 DEFINITION D'UNE LISTE D'ENTIERS
 ******************************************************************************/

typedef struct maillon {
	int info;
	struct maillon* succ;
	struct maillon* pred;
} maillon;

typedef maillon* liste;

#define NUTIL ((maillon*)(-1))

/******************************************************************************
 FONCTIONS UTILITAIRES ET EXEMPLE
 ******************************************************************************/

/**
 * Convertit un tableau d'entiers en une liste simplement ou doublement
 * chaînée, linéaire ou circulaire.
 *
 * Paramètre n : le nombre d'éléments de t.
 * Paramètre t : tableau d'entiers à convertir.
 * Paramètre d : vrai si la liste doit être doublement chaînée; défaut : faux.
 * Paramètre c : vrai si la liste doit être circulaire; défaut : faux.
 *
 * Retourne : la liste équivalente à t.
 */
liste listet(int n, const int t[], bool d = false, bool c = false) {
	if (t == NULL || n == 0) {
		return NULL;
	}
	maillon* m = new maillon;
	m->info = t[0];
	liste l = m;
	for (int i = 1; i < n; i++) {
		m->succ = new maillon;
		m->succ->info = t[i];
		m->succ->pred = (d ? m : NUTIL);
		m = m->succ;
	}
	m->succ = (c ? l : NULL);
	l->pred = (d ? (c ? m : NULL) : NUTIL);
	return l;
}

/**
 * Représente une liste sous forme d'une chaîne de caractères. La liste peut
 * être simplement ou doublement chaînée, linéaire ou circulaire.
 *
 * Paramètre l : liste à représenter.
 *
 * Retourne : la chaîne représentant l.
 */
string chainel(liste l) {
	if (l == NULL) {
		return ".";
	}
	ostringstream r;
	if (l->pred != NUTIL) {
	    r << (l->pred == NULL ? "|" : "<");
	}
	maillon* c = l;
	do {
		r << "[" << c->info << "]";
		if (c->succ == NULL || c->succ == l) {
		    break;
		}
        if (c->succ->pred != NUTIL) {
            r << (c->succ->pred == c ? "<" : "");
		}
		r << "->";
		c = c->succ;
	} while (true);
	r << (c->succ == NULL ? "|" : ">");
	return r.str();
}

/**
 * Détermine la longueur d'une liste linéaire ou circulaire.
 *
 * Paramètre l : liste à examiner.
 *
 * Retourne : la longueur de l.
 */
int longueur(liste l) {
	if (l == NULL) {
		return 0;
	}
	int n = 0;
	maillon* m = l;
	do {
		n += 1;
		m = m->succ;
	} while (m != NULL && m != l);
	return n;
}


/******************************************************************************
 1- FONCTIONS A DEVELOPPER - Parcours de listes
 ******************************************************************************/

/**
 * Détermine le nombre d'occurrences d'un élément dans une liste linéaire.
 *
 * La fonction doit être implémentée en itératif et en récursif.
 *
 * Paramètre l : liste à examiner.
 * Paramètre e : élément à compter.
 *
 * Retourne : le nombre d'occurrences de e dans l.
 */
int occurrences(liste l, int e) {
    // Liste nulle = pas d'occurrences
	if (l == NULL) {
		return 0;
	}

	// Compteur initialisé
	int n = 0;

	do {
        if (l->info == e) {
            n += 1;
        }
		l = l->succ;
	} while (l != NULL);

	return n;
}

int occurrences_rec(liste l, int e) {
    // Liste nulle = pas d'occurrences
    // Condition d'arrêt de la fonction
	if (l == NULL) {
		return 0;
	}

    // Création du premier maillon
	maillon* m = l;

    // Suivant si on a une occurrence ou pas, on retourne la fonctionne elle-même
    // ou la fonction +1
    if (m->info == e) {
        return 1 + occurrences_rec(m->succ, e);
    }
    else {
        return occurrences_rec(m->succ, e);
    }
}

/**
 * Détermine la position de la première occurrence d'un élément dans une liste
 * linéaire. La position du maillon de tête est 1.
 *
 * La fonction doit être implémentée en itératif et en récursif.
 *
 * Paramêtre l : liste à examiner.
 * Paramêtre e : élément à trouver.
 *
 * Retourne : la position de la première occurrence de e dans l ou 0 si e n'est
 * pas dans l.
 */
int position(liste l, int e) {
    // Liste vide = 0 (inutile en soit mais + efficace)
	if (l == NULL) {
		return 0;
	}

	// Initialisation du compteur position
	int n = 0;

	do {
        n += 1;
        if (l->info == e) {
            // On sort de la boucle en retournant n si on a une occurrence
            return n;
        }
		l = l->succ;
	} while (l != NULL);

	// Sinon on retourne 0
	return n;
}

// Version avec paramètre supplémentaire
/*int position_rec(liste l, int e, int compteur = 0) {
    // Liste nulle = fin de la liste
    // Condition d'arrêt de la fonction
	if (l == NULL) {
		return 0;
	}

    // Suivant si on a une occurrence ou pas, on retourne la fonctionne elle-même
    // ou la fonction +1
    if (l->info == e) {
        return compteur+1;
    }
    else {
        return position_rec(l->succ, e, compteur+1);
    }
}*/

int position_rec(liste l, int e) {
    // Liste nulle = fin de la liste
    // Condition d'arrêt de la fonction
	if (l == NULL)
    {
		return 0;
	}
    if (l->info == e)
    {
        return 1;
    }
    else if (l != NULL)
    {
        int n = position_rec(l->succ, e);

        if (n != 0)
        {
            return n+1;
        }
    }
}

/**
 * Détermine si une liste simplement chaînée linéaire est triée par ordre
 * croissant de ses éléments.
 *
 * La fonction doit être implémentée en itératif et en récursif.
 *
 * Paramêtre l : liste à examiner.
 *
 * Retourne : 1 si la liste est triée par ordre croissant de ses éléments et
 * 0 sinon.
 */
int estTriee(liste l) {
    // Liste vide = 0 (inutile en soit mais + efficace)
	if (l == NULL || l->succ == NULL) {
		return 1;
	}

	do {
        if (l->info > l->succ->info) {
            // On sort de la boucle en retournant n si on a une occurrence
            return 0;
        }
		l = l->succ;
	} while (l->succ != NULL);

	return 1;
}

int estTriee_rec(liste l) {
	if (l == NULL || l->succ == NULL) {
		return 1;
	}

    if (l->info > l->succ->info) {
        // On sort de la boucle en retournant n si on a une occurrence
        return 0;
    }
    estTriee_rec(l->succ);
}


/******************************************************************************
 2- FONCTIONS A DEVELOPPER - Modifications de listes
 ******************************************************************************/

/**
 * Insère un élément dans une liste doublement chaînée linéaire après une
 * position donnée. Si la position spécifiée est 0, l'insertion se fait en
 * tête de liste.
 *
 * Paramêtre l : liste à modifier.
 * Paramêtre p : position après laquelle Insèrer.
 * Paramêtre e : élément à Insèrer.
 *
 * Retourne : 1 si succès ou 0 sinon (un paramêtre est incorrect).
 */
int inserer(liste* l, int p, int e) {

    maillon *pnv = new maillon;
    pnv->succ = NULL;
    pnv->pred = NULL;
    pnv->info = e;

    // Insertion en tête de liste
	if (p <= 1) {
        pnv->succ = *l;
        *l = pnv;

        return 1;
	}

    // Si la longueur est correcte
    else if (longueur(*l) >= p) {
        //int inserer[longueur(*l)+1];
        //int compteur = 0;

        liste pa = *l;
        liste ps = pa->succ;

        while (ps != NULL && p > 2) {
            pa = ps;
            ps = ps->succ;
            p = p-1;
        }

        pnv->succ = ps;
        pa->succ = pnv;
        pa->pred = pnv->pred;

        return 1;
    }

	return 0;
}

/**
 * Supprime d'une liste doublement chaînée linéaire l'élément situé à une
 * position donnée. Si la position est supérieure à la longueur de la liste,
 * le dernier maillon est supprimé.
 *
 * Paramêtre l : liste à modifier.
 * Paramêtre p : position de l'élément à supprimer.
 *
 * Retourne : 1 si succès ou 0 sinon (un paramêtre est incorrect).
 */
int supprimer(liste* l, int p) {
    // On veut supprimer 1 élément et la liste n'a qu'un élément: on renvoie la liste nulle
	if (p <= 1 && longueur(*l) == 1) {
        *l = listet(0, NULL);

        return 1;
	}

    // Si la longueur est correcte
    else if (longueur(*l) >= p) {
        liste pa = *l;

        while (pa->succ != NULL && p > 2) {
            pa = pa->succ;
            p = p-1;
        }

        pa->succ = pa->succ->succ;

        return 1;
    }

	return 0;
}

/**
 * Supprime toutes les occurrences d'un élément dans une liste simplement
 * chaînée linéaire.
 *
 * La fonction doit être implémentée en itératif et en récursif.
 *
 * Paramêtre l : liste dans laquelle supprimer e.
 * Paramêtre e : élément à supprimer dans l.
 *
 * Retourne : 1 si succès ou 0 sinon (un paramêtre est incorrect).
 */
int supprimero(liste* l, int e) {
	throw "non traite";
}

int supprimero_rec(liste* l, int e) {
	throw "non traite";
}

/**
 * Inverse l'ordre des éléments d'une liste simplement chaînée linéaire.
 * L'inversion se fait en place, sans recopie des maillons de la liste.
 *
 * La fonction doit être implémentée en itératif et en récursif.
 *
 * Paramêtre l : liste à inverser.
 *
 * Retourne : 1 si succès ou 0 sinon (un paramêtre est incorrect).
 */
int inverser(liste* l) {
	throw "non traite";
}

int inverser_rec(liste* l) {
	throw "non traite";
}

/**
 * Crée une liste doublement chaînée linéaire, copie inversée d'une liste
 * simplement chaînée linéaire. La liste initiale n'est pas modifiée.
 *
 * Paramêtre l : liste à inverser.
 *
 * Retourne : la liste doublement chaînée linéaire copie inversée de l.
 */
liste copierInverser(liste l) {
	throw "non traite";
}

/**
 * Concatène deux listes simplement chaînées linéaires entre elles.
 *
 * Paramêtre l1 : liste à laquelle concatener l2.
 * Paramêtre l2 : liste à concatener à l1.
 *
 * Retourne : 1 si succès ou 0 sinon (un paramêtre est incorrect).
 */
int concatener(liste* l1, liste l2) {
	throw "non traite";
}

/**
 * Détruit une liste chaînée linéaire. L'ensemble de ses maillons est libéré.
 *
 * La fonction doit être implémentée en itératif et en récursif.
 *
 * Paramêtre l : liste à détruire.
 *
 * Retourne : 1 si succès ou 0 sinon (un paramêtre est incorrect).
 */
int detruire(liste* l) {
	throw "non traite";
}

int detruire_rec(liste* l) {
	throw "non traite";
}


/******************************************************************************
 PROGRAMME DE TEST - Tester ici chaque fonction developpée
 ******************************************************************************/

int main(int argc, char* argv[]) {

	// AUTEURS (à compléter)
	cout << "AUTEURS : Poupa \n" <<endl;

	// TEST longueur (exemple)
	cout << "TEST longueur" << endl;
	liste l = listet(0, NULL);
	cout << "longueur( " << chainel(l) << " ) = " << longueur(l) << endl;
	l = listet(1, (const int[]) {1});
	cout << "longueur( " << chainel(l) << " ) = " << longueur(l) << endl;
	l = listet(3, (const int[]) {1, 2, 3});
	cout << "longueur( " << chainel(l) << " ) = " << longueur(l) << endl;
	l = listet(1, (const int[]) {1}, false, true);
	cout << "longueur( " << chainel(l) << " ) = " << longueur(l) << endl;
	l = listet(3, (const int[]) {1, 2, 3}, false, true);
	cout << "longueur( " << chainel(l) << " ) = " << longueur(l) << endl;

	// TEST occurrences
	cout << endl << "TEST occurences iteratif" << endl;
	liste l2 = listet(0, NULL);
	cout << "occurrences de 3 dans ( " << chainel(l2) << " ) = " << occurrences(l2, 3) << endl;
    l2 = listet(3, (const int[]) {1, 2, 3});
    cout << "occurrences de 3 dans ( " << chainel(l2) << " ) = " << occurrences(l2, 3) << endl;
    l2 = listet(6, (const int[]) {1, 1, 1, 1, 2, 3});
    cout << "occurrences de 1 dans ( " << chainel(l2) << " ) = " << occurrences(l2, 1) << endl;


	// TEST occurrence_rec
	cout << endl << "TEST occurences recursif" << endl;
	liste l3 = listet(0, NULL);
	cout << "occurrences de 3 dans ( " << chainel(l3) << " ) = " << occurrences_rec(l3, 3) << endl;
    l3 = listet(3, (const int[]) {1, 2, 3});
    cout << "occurrences de 3 dans ( " << chainel(l3) << " ) = " << occurrences_rec(l3, 3) << endl;
    l3 = listet(6, (const int[]) {1, 1, 1, 1, 2, 3});
    cout << "occurrences de 1 dans ( " << chainel(l3) << " ) = " << occurrences_rec(l3, 1) << endl;

	// TEST position
	cout << endl << "TEST position" << endl;
	liste l4 = listet(0, NULL);
	cout << "premiere position de 3 dans ( " << chainel(l4) << " ) = " << position(l4, 3) << endl;
    l4 = listet(3, (const int[]) {1, 2, 3});
    cout << "premiere position de 3 dans ( " << chainel(l4) << " ) = " << position(l4, 3) << endl;
    l4 = listet(6, (const int[]) {1, 1, 1, 1, 2, 3});
    cout << "premiere position de 1 dans ( " << chainel(l4) << " ) = " << position(l4, 1) << endl;

	// TEST position_rec
	cout << endl << "TEST position recursif" << endl;
	liste l5 = listet(0, NULL);
	cout << "premiere position de 3 dans ( " << chainel(l5) << " ) = " << position_rec(l5, 3) << endl;
    l5 = listet(3, (const int[]) {1, 2, 3});
    cout << "premiere position de 2 dans ( " << chainel(l5) << " ) = " << position_rec(l5, 2) << endl;
    l5 = listet(6, (const int[]) {1, 1, 1, 1, 2, 3});
    cout << "premiere position de 1 dans ( " << chainel(l5) << " ) = " << position_rec(l5, 1) << endl;
    l5 = listet(6, (const int[]) {1, 1, 1, 1, 2, 3});
    cout << "premiere position de 9 dans ( " << chainel(l5) << " ) = " << position_rec(l5, 9) << endl;

    // TEST estTriee
	cout << endl << "TEST est triee" << endl;
	liste l6 = listet(0, NULL);
	cout << "est triee? ( " << chainel(l6) << " ) = " << estTriee(l6) << endl;
    l6 = listet(3, (const int[]) {1, 2, 3});
    cout << "est triee? ( " << chainel(l6) << " ) = " << estTriee(l6) << endl;
    l6 = listet(1, (const int[]) {1});
    cout << "est triee? ( " << chainel(l6) << " ) = " << estTriee(l6) << endl;
    l6 = listet(6, (const int[]) {1, 1, 1, 1, 2, 3});
    cout << "est triee? ( " << chainel(l6) << " ) = " << estTriee(l6) << endl;
    l6 = listet(3, (const int[]) {3, 2, 1});
    cout << "est triee? ( " << chainel(l6) << " ) = " << estTriee(l6) << endl;

    // TEST estTriee_rec
	cout << endl << "TEST est triee recursif" << endl;
	liste l7 = listet(0, NULL);
	cout << "est triee? ( " << chainel(l7) << " ) = " << estTriee_rec(l7) << endl;
    l7 = listet(3, (const int[]) {1, 2, 3});
    cout << "est triee? ( " << chainel(l7) << " ) = " << estTriee_rec(l7) << endl;
    l7 = listet(2, (const int[]) {1, 2});
    cout << "est triee? ( " << chainel(l7) << " ) = " << estTriee_rec(l7) << endl;
    l7 = listet(1, (const int[]) {1});
    cout << "est triee? ( " << chainel(l7) << " ) = " << estTriee_rec(l7) << endl;
    l7 = listet(6, (const int[]) {1, 1, 1, 1, 2, 3});
    cout << "est triee? ( " << chainel(l7) << " ) = " << estTriee_rec(l7) << endl;
    l7 = listet(3, (const int[]) {3, 2, 1});
    cout << "est triee? ( " << chainel(l7) << " ) = " << estTriee_rec(l7) << endl;

    liste l8 = listet(0, NULL);
    cout << endl << "Chaine " << chainel(l8) << endl;
    inserer(&l8, 1, 3);
    cout << "Appel de inserer(&l8, 1, 3): " << chainel(l8) << endl;
    inserer(&l8, 1, 4);
    cout << "Appel de inserer(&l8, 1, 4): " << chainel(l8) << endl;
    inserer(&l8, 1, 4);
    cout << "Appel de inserer(&l8, 1, 4): " << chainel(l8) << endl;
    inserer(&l8, 2, 8);
    cout << "Appel de inserer(&l8, 2, 8): " << chainel(l8) << endl;
    inserer(&l8, 3, 14);
    cout << "Appel de inserer(&l8, 3, 14): " << chainel(l8) << endl;
    inserer(&l8, 14, 14);
    cout << "Appel de inserer(&l8, 14, 14): " << chainel(l8) << endl;
    supprimer(&l8, 1);
    cout << "Appel de supprimer(&l8, 1): " << chainel(l8) << endl;
    supprimer(&l8, 2);
    cout << "Appel de supprimer(&l8, 2): " << chainel(l8) << endl;

	return 0;
}
