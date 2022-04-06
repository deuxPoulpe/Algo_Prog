#include <stdio.h>
#include <stdlib.h>

int* saisir(int *polynome,int *pdegre)
{
	int i;
	printf("quel est le degre du polynome ?\n");
	scanf("%i",&*pdegre);
	polynome=malloc((*pdegre+1)*sizeof(int));
	polynome[0]=*pdegre;
	printf("Saisissez les coefficients du polynome :\n");
	for(i=0;*pdegre-i>=0;i++)
	{
		printf("coefficient de degre %i : ",i);
		scanf("%i",&polynome[i+1]);
	}
	return polynome;
}
void afficher(int *polynome)
{
	int i;
	printf("\nle polynome de degre %i est :\t",polynome[0]);
	printf("%i",polynome[1]);
	for(i=1;polynome[0]-i>=0;i++)
	{
		printf(" +(%i) x^%i",polynome[i+1],i);
	}
}
int* difference(int*pol1,int*pol2)
{
	int*resultat;
	int i;
	resultat[0]=pol1[0];
	if (pol1[0]<=pol2[0])
	{
		resultat[0]=pol2[0];	
	}
	resultat=malloc(resultat[0]*sizeof(int));
	for(i=1;resultat[0]-i>=0;i++)
	{
	resultat[i]=pol1[i]-pol2[i];
	}
	return resultat;
}
int calcul(int*polynome,int n)
{
	int i,resultat=0;
	for(i=0;(polynome[0]-i)>=0;i++)
	{
		resultat=resultat*n+polynome[polynome[0]-i];
	}
	return resultat;
}
int racine(int* polynome,int n)
{
	if(calcul(polynome,n)==0)
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
	pol2=saisir(pol1,pdegre2);
	afficher(pol1);
	afficher(pol2);
	pol3=difference(pol1,pol2);
	afficher(pol3);/*
	d=calcul(pol1,h);
	printf("%i",d);
	e=racine(pol1,1);
	printf("%i",e);*/
	free(pol1);
	free(pol2);/*
	free(pol3);*/
	return 0;
}