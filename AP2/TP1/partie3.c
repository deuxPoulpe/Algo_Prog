#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *tab;
	int nb_valeurs,i;
	printf("Combien d'entiers souhaitez vous stocker ?\n");
	scanf("%i",&nb_valeurs);
	tab=malloc(nb_valeurs*sizeof(int));
	printf("Saisissez vos %i valeurs.\n",nb_valeurs);
	for(i=0;i<nb_valeurs;i++)
	{
		printf("Valeur %i : ",i+1);
		scanf("%i",&tab[i]);
	}
	printf("votre tableau contient :\n");
	for(i=0;i<nb_valeurs;i++)
	{
		printf("Valeur %i : %i\n",i+1,tab[i]);
	}
	free(tab);
	return 0;
}
