#include <stdio.h>

/**
    On fait pointer *p au même endroit que x
    au passage de paramètres, x est une copie du second argument (ici &b)

    on ne peut pas définir f ainsi, car p pointerait sur une variable locale, le paramètre x
        int f(int ** p, int x)
        {
            *p = &x;
        }
*/
void f(int ** p, int  * x)
{
    *p = x;
}


/**
    définition d'une fonction d'échange de 2 pointeurs : échange de valeurs qui sont des adresses
*/
void echangePtr(int ** p1, int ** p2)
{
    int * tmp = NULL;

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main()
{
    int a = 8;
    int b = 3;

    int * p = NULL;
    p = &a;

    printf("*p vaut %d \n", *p);
    /**
        on veut faire pointer p sur b : il faut modifier p
        on passe en paramètre &p pour modifier p
        le second paramètre est l'adresse de la variable sur la laquelle p doit pointer
    */
    f(&p, &b);
    printf("*p vaut %d \n", *p);

    int * p1 = NULL;
    int * p2 = NULL;
    p1 = &a;
    p2 = &b;

    printf("p1 vaut %x \n", p1);
    printf("p2 vaut %x \n", p2);
    printf("*p1 vaut %d \n", *p1);
    printf("*p2 vaut %d \n", *p2);

    echangePtr(&p1, &p2);

    printf("p1 vaut %x \n", p1);
    printf("p2 vaut %x \n", p2);
    printf("*p1 vaut %d \n", *p1);
    printf("*p2 vaut %d \n", *p2);

    return 0;
}
