#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Employe saisir_employer_valeur()
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
        employe.sexe = MASCULIN;
    }
    else if (s == 'F')
    {
        employe.sexe = FEMININ;
    }

    return employe;
}

void saisir_employer_adresse(Employe *employe)
{

    printf("Saisir l'employé:\n");
    printf("Nom : ");
    scanf("%[^\n]100s", employe->nom);
    printf("\tPrénom : ");
    scanf("%s", employe->prenom);
    printf("Adresse : \n");
    printf("\tNuméro : ");
    scanf("%i", &employe->adresse.num);
    printf("\t Nom de la rue : ");
    scanf("%s", employe->adresse.nom_de_rue);
    printf("\tCode postal : ");
    scanf("%i", &employe->adresse.postal);
    printf("\tLocalité : ");
    scanf("%s", employe->adresse.localite);
    printf("\nSexe (H/F): ");
    char s;
    scanf(" %c", &s);
    if (s == 'H')
    {
        employe->sexe = MASCULIN;
    }
    else if (s == 'F')
    {
        employe->sexe = FEMININ;
    }
}

void affiche_employe(Employe employe)
{

    printf("%s %s, %i %s, %i %s, ", employe.nom, employe.prenom, employe.adresse.num, employe.adresse.nom_de_rue, employe.adresse.postal, employe.adresse.localite);
}

void ini_societe(Societe *societe)
{
    societe->nb_employes = 0;
}

int add_emp_to_societe(Societe *societe, Employe employe)
{
    if (societe->nb_employes >= 100)
    {
        return -1;
    }

    societe->liste_employes[societe->nb_employes] = employe;
    societe->nb_employes++;
    return 0;
}

void affiche_societe(Societe societe)
{
    int i;
    printf("liste des employés de la société:\n");
    for (i = 0; i < societe.nb_employes; i++)
    {
        printf("\tEmployé numéro %i : ", i + 1);
        affiche_employe(societe.liste_employes[i]);
        printf("\n");
    }
}

int recherche_employe(Societe societe, Texte prenom, Texte nom)
{
    int i;
    for (i = 0; i < societe.nb_employes; i++)
    {
        if ((srtcmp(societe.liste_employes[i].nom, nom) == 0) && (srtcmp(societe.liste_employes[i].prenom, prenom) == 0))
            return i;
    }
    return -1;
}

void affiche_recherche_employe(Societe societe, Texte nom, Texte prenom)

{
    int i = recherche_employe(societe, nom, prenom);

    if (i == -1)
    {
        printf("cette employé n'existe pas:");
    }
    printf("l'employé est le %ieme de la societé : ", i);
    affiche_employe(societe.liste_employes[i]);
    printf("\n");
}

int supp_empleye_to_societe(Societe *societe, Texte nom, Texte prenom)
{
    int i = recherche_employe(*societe, nom, prenom);

    if (i == -1)
    {
        return -1;
    }
    societe->liste_employes[i] = societe->liste_employes[societe->nb_employes - 1];
    societe->nb_employes--;
    return 0;
}

int main()
{
    Employe employe1, employe2;
    saisir_employer_adresse(&employe1);
    saisir_employer_adresse(&employe1);
    affiche_employe(employe1);
    printf("\n");
    affiche_employe(employe2);

    // employe1 = saisir_employer_valeur;
    // employe2 = saisir_employer_valeur;

    // affiche_employe(employe1);
    // printf("\n");
    // affiche_employe(employe2);

    return 0;
}