#include <stdio.h>

int main()
{

    // int x;
    // int *gigapointeur;

    // gigapointeur = &x;

    // printf("Entrer un entier:\n");
    // scanf("%i", &x);
    // printf("la variable x :\n%i", *gigapointeur);
    // printf("\nl'addresse de x :\n%p", gigapointeur);

    int tab[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("Entrer l'entier d'indice %i : ", i);
        scanf("%i", &tab[i]);
    }

    for (i = 0; i < 3; i++)
    {
        printf("L'entier d'indice %i est %i : son addresse est %p \n", i, tab[i], &tab[i]);
    }

    return 0;
}