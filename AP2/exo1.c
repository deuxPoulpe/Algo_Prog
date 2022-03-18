#include <stdio.h>

int main()
{

    int x;
    int *gigapointeur;

    gigapointeur = &x;

    printf("Entrer un entier:\n");
    scanf("%i", &x);
    printf("la variable x :\n%i", *gigapointeur);
    printf("\nl'addresse de x :\n%p", gigapointeur);

    return 0;
}