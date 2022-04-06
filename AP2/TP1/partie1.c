#include <stdio.h>
int main()
{
	int x1,x2,x3,i;
	int *px1,*px2,*px3;
	px1=&x1;
	px2=&x2;
	px3=&x3;
	for(i==0;i<=2;i++)
	{
		printf("Donnez 3 valeurs entieres\n");
		scanf("%i %i %i",&x1,&x2,&x3);
		printf("x1 : %p | %i\nx2 : %p | %i\nx3 : %p | %i\n",px1,*px1,px2,*px2,px3,*px3);
	}
	return 0;
 }
