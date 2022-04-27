#include <iostream>
#define TAILLE_MAXIMALE1 5
#define TAILLE_MAXIMALE2 7

using namespace std;

int main()
{
    long tab1[TAILLE_MAXIMALE1];
    long tab2[TAILLE_MAXIMALE2];
    long tab3[TAILLE_MAXIMALE1 + TAILLE_MAXIMALE2];
    long tailleUtile1 = 0;
    long tailleUtile2 = 0;
    long tailleUtile3 = 0;
    long * ptr1 = NULL, * ptr2 = NULL, * ptr3 = NULL;

    cout << "Saisie des " << TAILLE_MAXIMALE1 << " valeurs du premier tableau par ordre croissant : " << endl;
    for (ptr1 = tab1; ptr1 < tab1 + TAILLE_MAXIMALE1; ptr1++)
    {
        cout << "entier : ";
        cin >> *ptr1;
        tailleUtile1++;
    }

    cout << "Saisie des " << TAILLE_MAXIMALE2 << " valeurs  du second tableau par ordre croissant : " << endl;
    for (ptr2 = tab2; ptr2 < tab2 + TAILLE_MAXIMALE1; ptr2++)
    {
        cout << "entier : ";
        cin >> *ptr2;
        tailleUtile2++;
    }

    cout << "Tableau1 : ";
    for (ptr1 = tab1; ptr1 < tab1 + tailleUtile1; ptr1++)
        cout << *ptr1 << ' ';
    cout << endl;

    cout << "Tableau2 : ";
    for (ptr2 = tab2; ptr2 < tab2 + tailleUtile2; ptr2++)
        cout << *ptr2 << ' ';
    cout << endl;

    ptr1 = tab1;
    ptr2 = tab2;
    ptr3 = tab3;
    // tant qu'il y a des éléments dans les 2 tableaux
    while ((ptr1 < tab1 + tailleUtile1) && (ptr2 < tab2 + tailleUtile2))
    {
        if (*ptr1 <= *ptr2)
        {
            *ptr3 = *ptr1;
            ptr1++;
            ptr3++;
        }
        else // *ptr1 > *ptr2
        {
            *ptr3 = *ptr2;
            ptr2++;
            ptr3++;
        }
        tailleUtile3++;
    }
    // tant qu'il y a encore des éléments dans le premier tableau
    while (ptr1 < tab1 + tailleUtile1)
    {
        *ptr3 = *ptr1;
        ptr1++;
        ptr3++;
        tailleUtile3++;
    }
    // tant qu'il y a encore des éléments dans le second tableau
    while (ptr2 < tab2 + tailleUtile2)
    {
        *ptr3 = *ptr2;
        ptr2++;
        ptr3++;
        tailleUtile3++;
    }

    cout << "Tableau3 : " << endl;

    for (ptr3 = tab3; ptr3 < tab3 + tailleUtile3; ptr3++)
        cout << *ptr3 << ' ';
    cout << endl;
    return 0;
}
