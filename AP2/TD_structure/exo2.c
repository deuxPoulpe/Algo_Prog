#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    APPLE,
    PC,
    STATION
} Type_pc;

typedef char Nom_salle[3];

typedef struct
{
    char num_inv[15];
    Type_pc type;
    char nom_cpu[21];
    int freq;
    int ram;
    int mem;
    Nom_salle nom_salle[3];
} Ordinateur;

typedef struct
{
    int nb_pc;
    Nom_salle nom;
    int etage;
    // Ordinateur *liste_ordinateurs; //version statique
    Ordinateur liste_ordinateurs[100]; // version dynamique
} Salle;

int main()
{
    Salle liste_salle[100];

    return 0;
}