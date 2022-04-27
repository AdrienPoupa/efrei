#include <iostream>

using namespace std;

int main()
{
    long ** matrice2D;
    long n = 5; // nombre de lignes
    long p = 6;// nombre de colonnes

    // allocation du tableau 1D de lignes, chaque ligne contient un pointeur de type long * vers un tableau 1D d'entiers
    matrice2D = new long * [n];

    // allocations des n tableaux 1D de p entiers
    for (int i = 0; i < n; i++)
    {
        matrice2D[i] = new long [p];
    }

    // remplissage de la matrice alternativement avec des 0 et des 1
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            matrice2D[i][j] = j%2;
        }
    }

    // affichage de la matrice
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            cout << *( (*(matrice2D + i)) + j) << ' '; // <==>  matrice2D[i][j]
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
