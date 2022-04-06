#include <stdio.h>
void min_maj(char *pc)
{
	if(*pc>='a' && *pc<='z')
		*pc=*pc+'A'-'a';
	else if (*pc>='A' && *pc<='Z')
		*pc = *pc+'a'-'A';
		printf("adresse : %p valeur : %c\n" ,pc,*pc);
	
}
int main()
{
	char c,*pc;
	pc=&c;
	printf("Saisissez un caractere.\n");
	c=getchar();
	min_maj(pc);
	printf("adresse : %p valeur : %c\n" ,pc,*pc);
	printf("Le nouveau caractere est : %c.\n",*pc);
	return 0;
}