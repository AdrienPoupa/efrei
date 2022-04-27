/*************************************************************/
/***  L'3 - SDD - TP3  Arbres binaires - tp3.cpp           ***/
/*************************************************************/

#include <iostream>
#include <sstream>
#include <string>

#include <stdio.h>
#include <string.h>

#include "tp3util.h"

using namespace std;

/*****************************************************************************
 1- ARBRES BINAIRES
 *****************************************************************************/

/**
 * Détermine la nombre de noeuds d'un arbre binaire.
 *
 * Paramètre a : arbre à examiner.
 *
 * Retourne : le nombre de noeuds de a.
 *
 */
int nbNoeuds(arbre a) {
	if(a == NULL)
		return 0;
	else
		return 1 + nbNoeuds(a->sag) + nbNoeuds(a->sad);
}

/**
 * Détermine la hauteur d'un arbre binaire.
 *
 * Paramètre a : arbre à examiner.
 *
 * Retourne : -1 si a est vide et sa hauteur sinon.
 *
 */
int hauteur(arbre a) {
	if (a == NULL)
		return 0;
	else
		return 1 + max( hauteur(a->sag) , hauteur(a->sad) );
}

/**
 * Détermine la plus petite des valeurs d'un arbre non vide.
 *
 * Paramètre a : arbre non vide à examiner
 *
 * Retourne : la plus petite des valeurs de l'arbre non vide a.
 *
 */
int minimum(arbre a) {
    int min = a->info;

    if(a->sag != NULL) {
        int leftMin = minimum(a->sag);
        if(min > leftMin)
            min = leftMin;
    }

    if(a->sad != NULL) {
        int rightMin = minimum(a->sad);
        if(min > rightMin)
            min = rightMin;
    }

    return min;
}

/**
 * Crée une copie d'un arbre. L'arbre d'origine n'est pas modifié : les noeuds
 * de l'arbre créé sont des copies des noeuds d'origine.
 *
 * Paramètre a : arbre à copier.
 *
 * Retourne : la copie de a.
 *
 */
arbre copie(arbre a) {
	noeud* c = NULL;

	if (a != NULL) {
        c = new noeud;

        c->info = a->info;
        c->sad = copie(a->sad);
        c->sag = copie(a->sag);
	}
	else {
        return NULL;
	}

	return c;
}

/**
 * Transforme un arbre en son arbre miroir, càd en son symétrique par rapport
 * à l'axe vertical (pour chaque niveau de profondeur, l'ordre est inversé
 * entre la droite et la gauche).
 * L'arbre est modifié en place.
 *
 * Exemple :    9          deviendra         9
 *            /   \                        /   \
 *           5     4                      4     5
 *          / \     \                    /     / \
 *         2   6     8                  8     6   2
 *            /                                \
 *           10                                10
 *
 * Paramètre a : arbre à transformer.
 *
 */
void miroir(arbre a) {
    if(a != NULL) {
        noeud *tmp = a->sag;
        a->sag = a->sad;
        a->sad = tmp;

        miroir(a->sag);
        miroir(a->sad);
    }
}

/**
 * Détermine si un arbre est parfait au sens de la définition suivante:
 * un arbre est parfait ssi il est complet (càd tous ses noeuds internes
 * sont de degré deux) et toutes ses feuilles sont à la même profondeur.
 *
 * Paramètre a : arbre à tester.
 *
 * Retourne : 1 si a est parfait et 0 sinon.
 *
 */
int estParfait(arbre a) {
	if (a == NULL)
        return 1;

   int gauche = hauteur(a->sag);
   int droit = hauteur(a->sad);

   return (gauche == droit && estParfait(a->sag) && estParfait(a->sad));
}

/**
 * Calcule la profondeur d'un arbre pour laquelle la somme des valeurs des
 * noeuds est la plus grande.
 *
 * Paramètre a : arbre à examiner.
 *
 * Retourne : la profondeur cherchée ou -1 si l'arbre est vide.
 *

int profondeurSommeMax(arbre a) {
	if (a == NULL)
        return -1;

    file *f = new file;
	f->debut = NULL;
	f->taille = 0;

    enfiler(f, a);

    T* e = new T;

    while (estFileVide(*f) == 0) {
        defiler(f, e);
        if (a->sad != NULL) {
            enfiler(f, a->sad);
        }

        if (a->sag != NULL) {
            enfiler(f, a->sag);
        }
    }

    return 1;
}
*/

void setHorizontalSum(arbre a,int level,int **sums)
{
    if(a == NULL)
        return;

    int *arr = *sums;
    arr[level] += a->info;
    setHorizontalSum(a->sag,level+1,sums);
    setHorizontalSum(a->sad,level+1,sums);
}

int profondeurSommeMax(arbre a)
{
    int *arr = new int[50];
    memset(arr,0,23*sizeof(int));

    setHorizontalSum(a, 0, &arr);

    int i = 0;
    int profMinimum = -1;
    int minimum = -1;
    while(arr[i] != 0) {
        if (arr[i] > minimum) {
            profMinimum = i;
        }

        //cout<<" Somme des elements du niveau " << i << " = " << arr[i] << endl;

        i = i+1;
    }

    return profMinimum;
}

/**
 * Etablit la liste des feuilles d'un arbre triée de droite à gauche.
 *
 * Paramètre a : arbre à examiner.
 *
 * Retourne : la liste cherchée.
 *
 */
liste listeFeuilles(arbre a) {

	if (a == NULL) {
        liste l;
        return l;
	}
	if (a->sad != NULL && a->sad != NULL) {
        liste l =singleton(a);
        return l;
	}
	else {
        liste lg = listeFeuilles(a->sag);
        liste ld = listeFeuilles(a->sad);
        //return concatener(&lg, ld);
	}
}

/**
 * Détruit un arbre. Chacun de ses noeuds est libéré.
 *
 * Paramètre a : arbre à détruire.
 *
 * Retourne : 1 si succès et 0 sinon.
 *
 */
int detruire(arbre* a) {
	throw "non traité";
}

/*****************************************************************************
 2- ARBRES BINAIRES DE RECHERCHE (ABR : G <= R < D)
 *****************************************************************************/

/**
 * Détermine si un arbre est un ABR G <= R < D.
 * Appel initial : estABR(a)
 *
 * Paramètre a : arbre à tester.
 *
 * Retourne : 1 si a est un ABR G <= R < D et 0 sinon.
 *
 */
int estABR(arbre a, arbre inf = NULL, arbre sup = NULL) {
	throw "non traité";
}

/**
 * Recherche une valeur dans un ABR. La fonction s'arrête à la première
 * occurrence trouvée.
 *
 * Solution itérative.
 *
 * Paramètre a : arbre à examiner.
 * Paramètre v : valeur à chercher.
 *
 * Retourne : le pointeur vers un noeud portant la valeur v, ou NULL si aucun
 * noeud ne porte la valeur v.
 *
 */
noeud* chercher(arbre a, int v) {
	throw "non traité";
}

/**
 * Insère une valeur dans un ABR. L'ordre de l'arbre est G <= R < D. Il peut
 * contenir plusieurs fois la même valeur.
 *
 * Solution itérative.
 *
 * Paramètre a : arbre dans lequel insérer.
 * Paramètre v : valeur à insérer.
 *
 * Retourne : 0 si la valeur v existait déjà, 1 si elle est insérée pour la
 * première fois, ou -1 si un des paramètres est incorrect.
 *
 */
int inserer(arbre* a, int v) {
	throw "non traité";
}

/**
 * Supprime une valeur d'un ABR. La fonction ne supprime qu'une occurrence de la
 * valeur spécifiée.
 *
 * Paramètre a : arbre dans lequel supprimer.
 * Paramètre v : valeur à supprimer.
 *
 * Retourne : 0 si la valeur v n'est pas trouvée, 1 si la valeur v est trouvée,
 * ou -1 si un des paramètres est incorrect.
 *
 */
int supprimer(arbre* a, int v) {
	throw "non traité";
}

/*****************************************************************************
 3- PROGRAMME DE TEST - Tester ici chaque fonction développée
 *****************************************************************************/

int main(int argc, char* argv[]) {

    // AUTEURS (à compléter)
    cout << "AUTEUR : Poupa \n" << endl;

	// AFFICHAGE D'ARBRES BINAIRES
	cout << "\nAFFICHAGE d'arbres binaires\n";
	// arbre vide :
	arbre a = arbret(0, NULL);
	cout << "\narbre a : " << endl << chainea(a) << endl;
	// arbre parfait :
	arbre b = arbret(7, (const int[]) {1, 2, 3, 4, 5, 6, 7});
	cout << "\narbre b : " << endl << chainea(b) << endl;
	// les valeurs négatives dans le tableau dénotent des noeuds absents :
	arbre c = arbret(7, (const int[]) {1, 2, -3, 4, -5, 6, 7});
	cout << "\narbre c : " << endl << chainea(c) << endl;

    //========================================================================
	// ARBRES BINAIRES
	//========================================================================

	cout << "\n\n*** ARBRES BINAIRES ***\n";

	// TEST nbNoeuds()
	cout << "test nbNoeuds arbre a: " << nbNoeuds(a) << endl;
	cout << "test nbNoeuds arbre b: " << nbNoeuds(b) << endl;
	cout << "test nbNoeuds arbre c: " << nbNoeuds(c) << endl;

	// TEST hauteur()
	cout << "test hauteur arbre a: " << hauteur(a) << endl;
	cout << "test hauteur arbre b: " << hauteur(b) << endl;
	cout << "test hauteur arbre c: " << hauteur(c) << endl;

	// TEST minimum()
	cout << "test minimum arbre b: " << minimum(b) << endl;
	cout << "test minimum arbre c: " << minimum(c) << endl;

	// TEST copie()
	arbre copieA = copie(a);
	arbre copieB = copie(b);
	arbre copieC = copie(c);
	cout << "copie de A:" << endl << chainea(copieA) << endl;
	cout << "copie de B:" << endl << chainea(copieB) << endl;
	cout << "copie de C:" << endl << chainea(copieC) << endl;

    // TEST miroir()
    miroir(copieA);
    miroir(copieB);
    miroir(copieC);
    cout << "miroir de A" << endl << chainea(copieA) << endl;
    cout << "miroir de B" << endl << chainea(copieB) << endl;
    cout << "miroir de C" << endl << chainea(copieC) << endl;

	// TEST estParfait()
	cout << "test estParfait(a) = " << estParfait(a) << endl;
	cout << "test estParfait(b) = " << estParfait(b) << endl;
	cout << "test estParfait(c) = " << estParfait(c) << endl;

	// TEST profondeurSommeMax()
	cout << "test profondeurSommeMax(a) = " << profondeurSommeMax(a) << endl;
	cout << "test profondeurSommeMax(b) = " << profondeurSommeMax(b) << endl;
	cout << "test profondeurSommeMax(c) = " << profondeurSommeMax(c) << endl;

	// TEST listeFeuilles()
	/*cout << "test listeFeuilles(a) = " << chainel(listeFeuilles(a)) << endl;
	cout << "test listeFeuilles(b) = " << chainel(listeFeuilles(b)) << endl;
	cout << "test listeFeuilles(c) = " << chainel(listeFeuilles(c)) << endl;*/

	// TEST detruire()


    //========================================================================
	// ARBRES BINAIRES DE RECHERCHE (ABR)
	//========================================================================
	cout << "\n\n*** ARBRES BINAIRES DE RECHERCHE ***\n";

	// TEST estABR()

	// TEST inserer()

	// TEST chercher()

	// TEST supprimer()

	return 0;
}
