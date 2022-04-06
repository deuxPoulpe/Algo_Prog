#include <stdio.h>
#include <stdlib.h>

int* saisir(int *polynome,int *pdegre)
{
	int i;
	printf("quel est le degre du polynome ?\n");
	scanf("%i",&*pdegre);
	polynome=malloc(*pdegre*sizeof(int));
	printf("Saisissez les coefficients du polynome :\n");
	for(i=0;i<=*pdegre;i++)
	{
		printf("coefficient de degre %i : ",i);
		scanf("%i",&polynome[i]);
	}
	return polynome;
}
void afficher(int *polynome,int degre)
{
	int i;
	printf("\nle polynome est :\t");
	printf("%i",polynome[0]);
	for(i=1;i<=*pdegre;i++)
	{
		printf(" +(%i) x^%i",polynome[i],i);
	}
}
int* difference(int*pol1,int*pol2,int degre)
{
	int*resultat,i;
	resultat=malloc(*pdegre*sizeof(int));
	for(i=0;i<=*pdegre;i++)
	{
	resultat[i]=pol1[i]-pol2[i];
	}
	return resultat;
}
int calcul(int*polynome,int degre,int n)
{
	int i,resultat=0;
	for(i=0;(*pdegre-i)>=0;i++)
	{
		resultat=resultat*n+polynome[*pdegre-i];
	}
	return resultat;
}
int racine(int* polynome, int* pdegre,int n)
{
	if(calcul(polynome,pdegre,n)==0)
	{
		return 1;
	}
	return 0;
}






int main()
{
	int *pol1,*pdegre1,*pol2,*pdegre2,*pol3;
	int degre1,degre2,h=2,d,e;
	pdegre1=&degre1;
	pdegre2=&degre2;
	pol1=saisir(pol1,pdegre1);
	/*pol2=saisir(pol2,pdegre2);
	afficher(pol1,degre1);
	afficher(pol2,degre2);
	pol3=difference(pol1,pol2,degre1);
	afficher(pol3,degre1);
	d=calcul(pol1,degre1,h);
	printf("%i",d);*/
	e=racine(pol1,pdegre1,1);
	printf("%i",e);
	free(pol1);
	/*free(pol2);
	free(pol3);*/
	return 0;
}