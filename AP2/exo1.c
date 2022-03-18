#include <stdio.h>

int main()
{

    int x;
    printf("Entrer un entier:\n");
    scanf("%i", &x);
    printf("la variable x :\n%i", x);
    printf("\nl'addresse de x :\n%d", &x);

    return 0;
}