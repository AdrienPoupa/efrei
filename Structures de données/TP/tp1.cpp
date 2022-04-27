/*************************************************************/
/***  L'3 - SDD - TP 1 - Listes cha�n�es                   ***/
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
 * cha�n�e, lin�aire ou circulaire.
 *
 * Param�tre n : le nombre d'�l�ments de t.
 * Param�tre t : tableau d'entiers � convertir.
 * Param�tre d : vrai si la liste doit �tre doublement cha�n�e; d�faut : faux.
 * Param�tre c : vrai si la liste doit �tre circulaire; d�faut : faux.
 *
 * Retourne : la liste �quivalente � t.
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
 * Repr�sente une liste sous forme d'une cha�ne de caract�res. La liste peut
 * �tre simplement ou doublement cha�n�e, lin�aire ou circulaire.
 *
 * Param�tre l : liste � repr�senter.
 *
 * Retourne : la cha�ne repr�sentant l.
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
 * D�termine la longueur d'une liste lin�aire ou circulaire.
 *
 * Param�tre l : liste � examiner.
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
 * D�termine le nombre d'occurrences d'un �l�ment dans une liste lin�aire.
 *
 * La fonction doit �tre impl�ment�e en it�ratif et en r�cursif.
 *
 * Param�tre l : liste � examiner.
 * Param�tre e : �l�ment � compter.
 *
 * Retourne : le nombre d'occurrences de e dans l.
 */
int occurrences(liste l, int e) {
    // Liste nulle = pas d'occurrences
	if (l == NULL) {
		return 0;
	}

	// Compteur initialis�
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
    // Condition d'arr�t de la fonction
	if (l == NULL) {
		return 0;
	}

    // Cr�ation du premier maillon
	maillon* m = l;

    // Suivant si on a une occurrence ou pas, on retourne la fonctionne elle-m�me
    // ou la fonction +1
    if (m->info == e) {
        return 1 + occurrences_rec(m->succ, e);
    }
    else {
        return occurrences_rec(m->succ, e);
    }
}

/**
 * D�termine la position de la premi�re occurrence d'un �l�ment dans une liste
 * lin�aire. La position du maillon de t�te est 1.
 *
 * La fonction doit �tre impl�ment�e en it�ratif et en r�cursif.
 *
 * Param�tre l : liste � examiner.
 * Param�tre e : �l�ment � trouver.
 *
 * Retourne : la position de la premi�re occurrence de e dans l ou 0 si e n'est
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

// Version avec param�tre suppl�mentaire
/*int position_rec(liste l, int e, int compteur = 0) {
    // Liste nulle = fin de la liste
    // Condition d'arr�t de la fonction
	if (l == NULL) {
		return 0;
	}

    // Suivant si on a une occurrence ou pas, on retourne la fonctionne elle-m�me
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
    // Condition d'arr�t de la fonction
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
 * D�termine si une liste simplement cha�n�e lin�aire est tri�e par ordre
 * croissant de ses �l�ments.
 *
 * La fonction doit �tre impl�ment�e en it�ratif et en r�cursif.
 *
 * Param�tre l : liste � examiner.
 *
 * Retourne : 1 si la liste est tri�e par ordre croissant de ses �l�ments et
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
 * Ins�re un �l�ment dans une liste doublement cha�n�e lin�aire apr�s une
 * position donn�e. Si la position sp�cifi�e est 0, l'insertion se fait en
 * t�te de liste.
 *
 * Param�tre l : liste � modifier.
 * Param�tre p : position apr�s laquelle Ins�rer.
 * Param�tre e : �l�ment � Ins�rer.
 *
 * Retourne : 1 si succ�s ou 0 sinon (un param�tre est incorrect).
 */
int inserer(liste* l, int p, int e) {

    maillon *pnv = new maillon;
    pnv->succ = NULL;
    pnv->pred = NULL;
    pnv->info = e;

    // Insertion en t�te de liste
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
 * Supprime d'une liste doublement cha�n�e lin�aire l'�l�ment situ� � une
 * position donn�e. Si la position est sup�rieure � la longueur de la liste,
 * le dernier maillon est supprim�.
 *
 * Param�tre l : liste � modifier.
 * Param�tre p : position de l'�l�ment � supprimer.
 *
 * Retourne : 1 si succ�s ou 0 sinon (un param�tre est incorrect).
 */
int supprimer(liste* l, int p) {
    // On veut supprimer 1 �l�ment et la liste n'a qu'un �l�ment: on renvoie la liste nulle
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
 * Supprime toutes les occurrences d'un �l�ment dans une liste simplement
 * cha�n�e lin�aire.
 *
 * La fonction doit �tre impl�ment�e en it�ratif et en r�cursif.
 *
 * Param�tre l : liste dans laquelle supprimer e.
 * Param�tre e : �l�ment � supprimer dans l.
 *
 * Retourne : 1 si succ�s ou 0 sinon (un param�tre est incorrect).
 */
int supprimero(liste* l, int e) {
	throw "non traite";
}

int supprimero_rec(liste* l, int e) {
	throw "non traite";
}

/**
 * Inverse l'ordre des �l�ments d'une liste simplement cha�n�e lin�aire.
 * L'inversion se fait en place, sans recopie des maillons de la liste.
 *
 * La fonction doit �tre impl�ment�e en it�ratif et en r�cursif.
 *
 * Param�tre l : liste � inverser.
 *
 * Retourne : 1 si succ�s ou 0 sinon (un param�tre est incorrect).
 */
int inverser(liste* l) {
	throw "non traite";
}

int inverser_rec(liste* l) {
	throw "non traite";
}

/**
 * Cr�e une liste doublement cha�n�e lin�aire, copie invers�e d'une liste
 * simplement cha�n�e lin�aire. La liste initiale n'est pas modifi�e.
 *
 * Param�tre l : liste � inverser.
 *
 * Retourne : la liste doublement cha�n�e lin�aire copie invers�e de l.
 */
liste copierInverser(liste l) {
	throw "non traite";
}

/**
 * Concat�ne deux listes simplement cha�n�es lin�aires entre elles.
 *
 * Param�tre l1 : liste � laquelle concatener l2.
 * Param�tre l2 : liste � concatener � l1.
 *
 * Retourne : 1 si succ�s ou 0 sinon (un param�tre est incorrect).
 */
int concatener(liste* l1, liste l2) {
	throw "non traite";
}

/**
 * D�truit une liste cha�n�e lin�aire. L'ensemble de ses maillons est lib�r�.
 *
 * La fonction doit �tre impl�ment�e en it�ratif et en r�cursif.
 *
 * Param�tre l : liste � d�truire.
 *
 * Retourne : 1 si succ�s ou 0 sinon (un param�tre est incorrect).
 */
int detruire(liste* l) {
	throw "non traite";
}

int detruire_rec(liste* l) {
	throw "non traite";
}


/******************************************************************************
 PROGRAMME DE TEST - Tester ici chaque fonction developp�e
 ******************************************************************************/

int main(int argc, char* argv[]) {

	// AUTEURS (� compl�ter)
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
