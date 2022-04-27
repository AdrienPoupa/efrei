/**
*   On veut calculer P(x), où x est un réel (long double )
*   et P est un polynôme de degré n, représenté par un
*   tableau :
*   si P(X) = a0 + a1X + . . . + anXn,
*   alors pour tout i dans [0, n] on a P[i] = ai.
*
    long double Horner(long double  P[], long n, long double x)
    {
        long i;
        long double r = P[n];
        for(i = n-1; i >= 0; i--)
            r = (r*x) + P[i];
        return r;
    }
*
*   La complexité de l’algorithme de Horner est en O(n).
*/

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

typedef struct polynome
{
    long double * a; // tableau des coefficients
    long n; // degre
} Polynome;

void saisirPolynome(Polynome * P);
void afficherPolynome(Polynome P);
long double Horner(Polynome P, long double x);
void sommePolynome(Polynome P, Polynome Q, Polynome * S);
void derivePolynome(Polynome P, Polynome * Pprim);
void integralPolynome(Polynome P, Polynome * Pintegral);

int main()
{
    cout << "SAISIE DU POLYNOME P" << endl;
    Polynome P;
    saisirPolynome(&P);

    cout << "POLYNOME P DE DEGRE " << P.n << " : ";
    afficherPolynome(P);
    cout << endl;

    /** #######################################################################*/
    long double x;
    cout << "Methode de Horner : calcul de P(X) pour X : ";
    cin >> x;
    cout << "P(" << x << ") = " << Horner(P, x) << endl;
    cout << endl;

    /** #######################################################################*/
    cout << "SAISIE DU POLYNOME Q" << endl;
    Polynome Q;
    saisirPolynome(&Q);

    cout << "POLYNOME Q DE DEGRE " << Q.n << " : ";
    afficherPolynome(Q);
    cout << endl;

    /** #######################################################################*/
    cout << "CALCUL DU POLYNOME S = P+Q " << endl;
    Polynome S;
    sommePolynome(P, Q, &S);
    cout << "POLYNOME P DE DEGRE " << P.n << " : ";
    afficherPolynome(P);
    cout << "POLYNOME Q DE DEGRE " << Q.n << " : ";
    afficherPolynome(Q);
    cout << "POLYNOME S = P+Q DE DEGRE " << S.n << " : ";;
    afficherPolynome(S);
     cout << endl;

    /** #######################################################################*/
    cout << "CALCUL DU POLYNOME DERIVE P' DU POLYNOME P " << endl;
    Polynome Pprim;
    derivePolynome(P, &Pprim);
    cout << "POLYNOME P DE DEGRE " << P.n << " : ";;
    afficherPolynome(P);
    cout << "POLYNOME P' DE DEGRE " << P.n- 1 << " : ";;
    afficherPolynome(Pprim);
    cout << endl;

    /** #######################################################################*/
    cout << "CALCUL DU POLYNOME INTEGRAL DU POLYNOME P " << endl;
    Polynome Pintegral;
    integralPolynome(P, &Pintegral);
    cout << "POLYNOME P DE DEGRE " << P.n << " : ";
    afficherPolynome(P);
    cout << "POLYNOME INTEGRAL DE DEGRE " << P.n+ 1 << " : ";
    afficherPolynome(Pintegral);

    return 0;
}

long double Horner(Polynome P, long double x)
{
    long i;
    long double r = P.a[P.n];

    for(i = P.n- 1; i >= 0; i--)
        r = (r*x) + P.a[i];

    return r;
}

void saisirPolynome(Polynome * P)
{
    long n;
    cout << "degre : ";
    cin >> n;
    P->a = new long double [n + 1] ; // degré p donc p + 1 coefficients
    P->n = n;

    for(long i = 0; i < P->n + 1; i++)
    {
        cout << "coefficient a" << i  << " : ";
        cin >> P->a[i];
    }
}

void afficherPolynome(Polynome P)
{
    cout << fixed << setprecision(2);

    cout << '(';
    for(long i = 0; i < P.n; i++)
    {
        cout << P.a[i] << ", ";
    }
    cout << P.a[P.n] << ')' << endl;
}


void sommePolynome(Polynome P, Polynome Q, Polynome * S)
{
    long max = (P.n > Q.n) ? P.n : Q.n;
    long min = (P.n> Q.n) ? Q.n : P.n;
    long drapeau = (P.n> Q.n) ? 1 : 0;

    S->a = new long double [max + 1];
    S->n = max; // degré du polynôme somme

    long i;
    for (i = 0; i < min + 1; i++)
        S->a[i] = P.a[i] + Q.a[i];

    if (drapeau == 1)
    {
        for (i = min + 1; i < S->n + 1; i++)
            S->a[i] = P.a[i];
    }
    else
    {
        for (i = min + 1; i < S->n + 1; i++)
            S->a[i] = Q.a[i];
    }
}

void derivePolynome(Polynome P, Polynome * Pprim)
{
    Pprim->a = new long double [P.n]; // degré p-1 donc p coefficients
    Pprim->n = P.n- 1;

    for (long i = 1; i < P.n + 1; i++)
        Pprim->a[i-1] = P.a[i] * i;
}

void integralPolynome(Polynome P, Polynome * Pintegral)
{
    Pintegral->a = new long double [P.n + 2]; // degré p+1 donc p+2 coefficients
    Pintegral->n = P.n + 1;

    Pintegral->a[0] = 0;
    for (long i = 0; i < P.n + 1; i++)
        Pintegral->a[i+1] = P.a[i] / (i + 1);
}
