#include <stdio.h>
#include <stdlib.h>

typedef char Texte[101];
typedef struct
{
    int num;
    Texte nom_de_rue;
    int postal;
    Texte localite;
} Adresse;

typedef enum
{
    MASCULIN,
    FEMININ
} Sexe;

typedef struct
{
    Texte nom;
    Texte prenom;
    Adresse adresse;
    Sexe sexe;
} Employe;

typedef struct
{
    Employe liste_employes[100];
    int nb_employes;
} Societe;

Employe saisir_employer()
{
    Employe employe;
    printf("Saisir l'employé:\n");
    printf("Nom : ");
    scanf("%[^\n]100s", employe.nom);
    printf("\tPrénom : ");
    scanf("%s", employe.prenom);
    printf("Adresse : \n");
    printf("\tNuméro : ");
    scanf("%i", &employe.adresse.num);
    printf("\t Nom de la rue : ");
    scanf("%s", employe.adresse.nom_de_rue);
    printf("\tCode postal : ");
    scanf("%i", &employe.adresse.postal);
    printf("\tLocalité : ");
    scanf("%s", employe.adresse.localite);
    printf("\nSexe (H/F): ");
    char s;
    scanf("%c", &s);
    if (s == 'H')
    {
        employe.sexe = "MASCULIN";
    }
    else if (s == 'F')
    {
        employe.sexe = "FEMININ";
    }

    return employe;
}

int main()
{

    return 0;
}