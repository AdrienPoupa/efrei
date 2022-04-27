#include <stdio.h>
#include <stdlib.h>

/** Le pas d'incrémentation pour une
    réallocation dynamique d'un tableau
*/
#define INCREMENT 10
#define MAX  1025

typedef struct
{
    int cardinal;
    int taille;
    int * elements;
} Ensemble;

typedef int (*PF_INSERTION) (int ** tab, int * taille_utile, int * taille, int valeur);

/** FONCTIONS SUR LES TABLEAUX */
void AfficheTab(const int * tab, int taille_utile);
void AfficheInvTab(const int * tab, int taille_utile);
int InsertionTrieeTab(int ** tab, int * taille_utile, int * taille, int valeur);
int InsertionTrieeTabDynamique(int ** tab, int * taille_utile, int * taille, int valeur);

/** FONCTIONS SUR LES ENSEMBLES */
void AfficheEnsemble(const Ensemble * ensemble);
void AfficheInvEnsemble(const Ensemble * ensemble);
int CreationEnsemble(Ensemble * ensemble, int taille);
int CreationEnsembleDynamique(Ensemble * ensemble, int taille);
int CreationEnsemble_ChoixInsertion(Ensemble * ensemble, int taille, PF_INSERTION  pf);
void AjoutEnsemble(Ensemble * ensemble, int valeur);
int LitEnsemble(Ensemble *  ensemble, FILE * entree);
void SauveEnsemble(const Ensemble * ensemble, FILE * sortie);

/** FONCTIONS DE TESTS SUR LES TABLEAUX */
void test_InsertionTrieeTab();
void test_InsertionTrieeTabDynamique();
void test_InsertionTrieeTab_ChoixInsertion(PF_INSERTION  pf);


void exo1();
void exo2();
void exo3();
void exo4();
void exo6();

int main()
{
    // exo1();
    // exo2();
    // exo3();
    // exo4();
    exo6();
    return 0;
}

void exo1()
{
    test_InsertionTrieeTab();
    test_InsertionTrieeTabDynamique();

}

void exo2()
{
    Ensemble e = {0, 0, NULL};
    Ensemble * pe = NULL;

    CreationEnsemble(pe, 7);
    AfficheEnsemble(pe);

    CreationEnsemble(&e, 7);
    AfficheEnsemble(&e);
    AfficheInvEnsemble(&e);
    printf("\n");
}

void exo3()
{
    Ensemble e = {0, 0, NULL};
    Ensemble * pe = NULL;

    CreationEnsembleDynamique(pe, 7);
    AfficheEnsemble(pe);

    CreationEnsembleDynamique(&e, 7);
    AfficheEnsemble(&e);
    AfficheInvEnsemble(&e);
    printf("\n");

    int i;
    for (i = 0; i < 50; i++)
    {
        AjoutEnsemble(&e, 5 * i);
    }
    AfficheEnsemble(&e);
}

void exo4()
{
    Ensemble e1 = {0, 0, NULL};
    Ensemble e2 = {0, 0, NULL};
    Ensemble * pe = NULL;

    CreationEnsemble_ChoixInsertion(pe, 7, InsertionTrieeTab);
    AfficheEnsemble(pe);

    CreationEnsemble_ChoixInsertion(pe, 7, InsertionTrieeTabDynamique);
    AfficheEnsemble(pe);

    CreationEnsemble_ChoixInsertion(&e1, 7, InsertionTrieeTab);
    AfficheEnsemble(&e1);

    CreationEnsemble_ChoixInsertion(&e2, 7, InsertionTrieeTabDynamique);
    AfficheEnsemble(&e2);
}

void exo6()
{
    Ensemble e = {0, 0, NULL};

/** OUVERTURE DES FICHIERS */
    FILE * fichEntree,* fichSortie;
    char nomEntree[MAX], nomSortie[MAX];
    int code_erreur;

    printf("Donner le nom du fichier d’entree:");
    scanf("%s", nomEntree);
    printf("Donner le nom du fichier de sortie:");
    scanf("%s", nomSortie);

    fichEntree = fopen(nomEntree,"r");
    if (fichEntree == NULL)
    {
        fprintf(stderr, "ERREUR d’ouverture de %s\n",nomEntree);
        return;
    }

    fichSortie = fopen(nomSortie,"w");
    if (fichSortie == NULL)
    {
        fprintf(stderr, "ERREUR d’ouverture de %s\n",nomSortie);
        fclose(fichEntree);
        return;
    }
    else
    {
        /** LECTURE DE L'ENSEMBLE DANS UN FICHIER */
        code_erreur = LitEnsemble(&e, fichEntree);
        fclose(fichEntree);

        if(code_erreur == 0)
        {
            fprintf(stderr, "Erreur format incorrect dans LitEnsemble\n");
            return;
        }
    }

    CreationEnsemble_ChoixInsertion(&e, 7, InsertionTrieeTabDynamique);
    AfficheEnsemble(&e);

    /** LECTURE DE L'ENSEMBLE DANS UN FICHIER */
    SauveEnsemble(&e, fichSortie);
    fclose(fichSortie);
}



/*********** FONCTIONS DE TESTS SUR LES TABLEAUX ******************/
void test_InsertionTrieeTab()
{
    int i;
    /** tableau déjà trié */
    /* int tab[8] = {11, 106, 1312, 1555, 1600, 2011}; */
    int * tab = (int *) malloc(8 * sizeof(int));
    if (tab == NULL)
        return;

    tab[0] = 11;
    tab[1] = 106;
    tab[2] = 1312;
    tab[3] = 1555;
    tab[4] = 1600;
    int taille = 8;
    AfficheTab(tab, taille);

    /** on ne garde que les 3 premiers éléments du tableau */
    int taille_utile = 3;

    AfficheTab(tab, taille_utile);

    /** tests des doublons */
    for (i = 0; i < 4; i++)
    {
        InsertionTrieeTab(&tab, &taille_utile, &taille, 2014);
    }
    AfficheTab(tab, taille_utile);

    /** encore des insertions */
    for (i = 0; i < 2; i++)
    {
        InsertionTrieeTab(&tab, &taille_utile, &taille, i + 100);
    }
    AfficheTab(tab, taille_utile);

    InsertionTrieeTab(&tab, &taille_utile, &taille, 2014);
    AfficheTab(tab, taille_utile);
    InsertionTrieeTab(&tab, &taille_utile, &taille, 15);
    AfficheTab(tab, taille_utile);
    InsertionTrieeTab(&tab, &taille_utile, &taille, 666);
    AfficheTab(tab, taille_utile);
    /** ne fait rien : tableau déjà plein */
    InsertionTrieeTab(&tab, &taille_utile, &taille, 99);
    AfficheTab(tab, taille_utile);
    AfficheInvTab(tab, taille_utile);
    printf("\n");
}

void test_InsertionTrieeTabDynamique()
{
    int i;
    /** tableau déjà trié */
    int * tab = NULL;
    int taille = 8;
    tab = (int *) malloc(taille * sizeof(int));
    if (tab == NULL)
        return;

    tab[0] = 11;
    tab[1] = 106;
    tab[2] = 1312;
    tab[3] = 1555;
    tab[4] = 1600;
    AfficheTab(tab, taille);

    /** on ne garde que les 3 premiers éléments du tableau */
    int taille_utile = 3;

    AfficheTab(tab, taille_utile);

    /** tests des doublons */
    for (i = 0; i < 4; i++)
    {
        InsertionTrieeTabDynamique(&tab, &taille_utile, &taille, 2014);
    }
    AfficheTab(tab, taille_utile);

    /** encore des insertions */
    for (i = 0; i < 2; i++)
    {
        InsertionTrieeTabDynamique(&tab, &taille_utile, &taille, i + 100);
    }
    AfficheTab(tab, taille_utile);

    InsertionTrieeTabDynamique(&tab, &taille_utile, &taille, 2014);
    AfficheTab(tab, taille_utile);
    InsertionTrieeTabDynamique(&tab, &taille_utile, &taille, 15);
    AfficheTab(tab, taille_utile);
    InsertionTrieeTabDynamique(&tab, &taille_utile, &taille, 666);
    AfficheTab(tab, taille_utile);

    if (taille_utile == taille)
    {
        printf("tableau plein ==> réallocation dynamique %d \n", taille);
    }
    /** encore des insertions */
    for (i = 0; i < 38; i++)
    {
        InsertionTrieeTabDynamique(&tab, &taille_utile, &taille, i + 200);
    }

    printf("taille_utile = %d \t taille = %d\n", taille_utile, taille);
    InsertionTrieeTabDynamique(&tab, &taille_utile, &taille, 99);
    InsertionTrieeTabDynamique(&tab, &taille_utile, &taille, 2020);
    InsertionTrieeTabDynamique(&tab, &taille_utile, &taille, 1000000);
    printf("taille_utile = %d \t taille = %d\n", taille_utile, taille);
    AfficheTab(tab, taille_utile);

    AfficheInvTab(tab, taille_utile);
    printf("\n");
    free(tab);
}
/********************************************************************/


/*************** FONCTIONS SUR LES TABLEAUX *****************************/
int InsertionTrieeTab(int ** tab, int * taille_utile, int * taille, int valeur)
{
    int i = 0;
    /** position de l'insertion triée */
    int position = -1;

    if (*taille_utile == *taille)
        return 0;

    for (i = 0; i < *taille_utile; i++)
    {
        if ((*tab)[i] >= valeur)
            break;
    }

    /** pas de doublons */
    if ((*tab)[i] == valeur)
        return 0;

    position = i;
    for(i = *taille_utile; i > position; i--)
        (*tab)[i] = (*tab)[i-1];
    (*tab)[position] = valeur;

    *taille_utile += 1;

    return 1;
}

int InsertionTrieeTabDynamique(int ** tab, int * taille_utile, int * taille, int valeur)
{
    int i = 0;
    /** position de l'insertion triée */
    int position = -1;
    /** le nouveau tableau pour la réallocation dynamique */
    int * newElements = NULL;

    /** test de débordement
        RECOURS A L'ALLOCATION DYNAMIQUE : fonction realloc
        Si le tableau est trop petit, on l'aggrandit de 10 éléments
        Les valeurs du tableau sont automatiquement recopiées dans le nouveau
        et l'ancien tableau est libéré.
    */
    if (*taille_utile == *taille)
    {
        newElements = (int *) realloc(*tab, (*taille + INCREMENT) * sizeof(int));
        if (newElements == NULL)
            return 0;
        printf("REALLOC OK\n");
        *tab = newElements;
        *taille += INCREMENT;
    }

    for (i = 0; i < *taille_utile; i++)
    {
        if ((*tab)[i] >= valeur)
            break;
    }

    /** pas de doublons */
    if ((*tab)[i] == valeur)
        return 0;

    position = i;
    for(i = *taille_utile; i > position; i--)
        (*tab)[i] = (*tab)[i-1];
    (*tab)[position] = valeur;

    *taille_utile += 1;

    return 1;
}

void AfficheTab(const int * tab, int taille_utile)
{
    int i;
    for (i = 0; i < taille_utile; i++)
        printf("%d\t", tab[i]);
    printf("\n");
}

/** ATTENTION AU TEST D'ARRET
    Ne pas utiliser tab == NULL
    car le pointeur avance dans le tableau,
    puis déborde du tableau, sans pour autant avoir la valeur NULL
    Ne pas confondre avec les listes chaînées
*/
void AfficheInvTab(const int * tab, int taille_utile)
{
    if (taille_utile == 0)
        return;
    AfficheInvTab(tab + 1, taille_utile -1);
    printf("%d\t", tab[0]);
}
/************************************************************/


/*********** FONCTIONS SUR LES ENSEMBLES **********************************************************/
int CreationEnsemble(Ensemble * ensemble, int taille)
{
    int i;
    int valeur;

    /** ENSEMBLE INEXISTANT */
    if (ensemble == NULL)
        return 0;

    /** ENSEMBLE DEJA CREE */
    if ((ensemble->cardinal != 0) && (ensemble->taille != 0) && (ensemble->elements != NULL))
        return 0;

    ensemble->elements = (int *) malloc(taille * sizeof(int));
    if (ensemble->elements == NULL)
    {
        printf("PLUS DE PLACE MEMOIRE POUR L'ALLOCATION DYNAMIQUE!\n");
        return 0;
    }

    ensemble->taille = taille;
    printf("\n Saisissez les %d valeurs: \n", taille);
    for (i = 0; i < taille; i++)
    {
        printf("valeur : ");
        scanf(" %d", &valeur);

        if (InsertionTrieeTab(&ensemble->elements, &ensemble->cardinal, &ensemble->taille, valeur) == 0)
        {
            printf("SVP pas de doublon dans un ensemble! \n");
            i--;
        }
    }
    return 1;
}

int CreationEnsembleDynamique(Ensemble * ensemble, int taille)
{
    int i;
    int valeur;

    /** ENSEMBLE INEXISTANT */
    if (ensemble == NULL)
        return 0;

    /** ENSEMBLE DEJA CREE */
    if ((ensemble->cardinal != 0) && (ensemble->taille != 0) && (ensemble->elements != NULL))
        return 0;

    ensemble->elements = (int *) malloc(taille * sizeof(int));
    if (ensemble->elements == NULL)
    {
        printf("PLUS DE PLACE MEMOIRE POUR L'ALLOCATION DYNAMIQUE!\n");
        return 0;
    }

    ensemble->taille = taille;
    printf("\n Saisissez les %d valeurs: \n", taille);
    for (i = 0; i < taille; i++)
    {
        printf("valeur : ");
        scanf(" %d", &valeur);
        if (InsertionTrieeTabDynamique(&ensemble->elements, &ensemble->cardinal, &ensemble->taille, valeur) == 0)
        {
            printf("SVP pas de doublon dans un ensemble! \n");
            i--;
        }
    }
    return 1;
}

int CreationEnsemble_ChoixInsertion(Ensemble * ensemble, int taille, PF_INSERTION  pf)
{
    int i;
    int valeur;

    /** ENSEMBLE INEXISTANT */
    if (ensemble == NULL)
        return 0;

    /** ENSEMBLE DEJA CREE */
    if ((ensemble->cardinal != 0) && (ensemble->taille != 0) && (ensemble->elements != NULL))
        return 0;

    ensemble->elements = (int *) malloc(taille * sizeof(int));
    if (ensemble->elements == NULL)
    {
        printf("PLUS DE PLACE MEMOIRE POUR L'ALLOCATION DYNAMIQUE!\n");
        return 0;
    }

    ensemble->taille = taille;
    printf("\n Saisissez les %d valeurs: \n", taille);

    for (i = 0; i < taille; i++)
    {
        printf("valeur : ");
        scanf("%d", &valeur);
        if ((*pf)(&ensemble->elements, &ensemble->cardinal,  &ensemble->taille, valeur) == 0)
        {
            printf("SVP pas de doublon dans un ensemble! \n");
            i--;
        }
    }
    return 1;
}

void AfficheEnsemble(const Ensemble * ensemble)
{
    if(ensemble == NULL)
    {
        printf("ENSEMBLE INEXISTANT!\n");
        return;
    }

    if ((ensemble->cardinal == 0) && (ensemble->taille == 0) && (ensemble->elements == NULL))
    {
        printf("ENSEMBLE VIDE!\n");
        return;
    }

    /** DUPLICATION DE CODE :
        SI L'ON NE PENSE A UTILISER LA FONCTION D'AFFICHAGE D'UN TABLEAU
        ALORS ON ECRIT UN CODE EQUIVALENT A CELUI DEJA ECRIT DANS LA
        FONCTION EXISTANTE!
    int i;
    for (i = 0; i < ensemble->cardinal; i++)
        printf("%d\t", ensemble->elements[i]);
    printf("\n");
    */
    AfficheTab(ensemble->elements,ensemble->cardinal);
}

void AfficheInvEnsemble(const Ensemble * ensemble)
{
    if (ensemble->elements == NULL)
        return;

    AfficheInvTab(ensemble->elements, ensemble->cardinal);
}

void AjoutEnsemble(Ensemble * ensemble, int valeur)
{
    if (InsertionTrieeTabDynamique(&ensemble->elements, &ensemble->cardinal, &ensemble->taille, valeur) == 0)
    {
        printf("SVP pas de doublon dans un ensemble! \n");
    }
}
/*******************************************************************************************/

void SauveEnsemble(const Ensemble * ensemble, FILE * sortie)
{
    int n;
    fprintf(sortie,"%d\n", ensemble->cardinal);
    fprintf(sortie,"%d\n", ensemble->taille);
    for(n = 0; n <  ensemble->cardinal; n++)
        fprintf(sortie,"%d\t", ensemble->elements[n]);
    fprintf(sortie, "\n");
}

int LitEnsemble(Ensemble *  ensemble, FILE * entree)
{
    int i = 0;

    /** erreur de lecture */
    if (fscanf(entree,"%d",&(ensemble->cardinal)) != 1)
        return 0;
    if (fscanf(entree,"%d",&(ensemble->taille)) != 1)
        return 0;

    ensemble->elements = (int * )malloc(ensemble->taille * sizeof(int));
    if(ensemble->elements == NULL)
    {
        fprintf(stderr,"erreur allocation\n");
        return 0;
    }

    while (i < ensemble->cardinal && fscanf(entree,"%d",&(ensemble->elements[i])) == 1)
        i += 1;
    if (i == ensemble->cardinal)
        return 1;
    else
        /** une erreur de lecture s’est produite */
        return 0;
}
