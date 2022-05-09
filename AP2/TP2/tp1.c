#include <stdio.h>
#include <stdlib.h>

//////////////////////// Les Variables ////////////////////////////////////

typedef enum
{
    BLANC,
    NOIR
} couleur;

typedef enum
{
    PION,
    CAVALIER,
    FOU,
    TOUR,
    ROI,
    DAME
} type_piece;

typedef struct
{
    couleur color;
    type_piece type;
} piece;

typedef piece *echiquier[8][8];

typedef struct
{
    int ligne;
    int colonne;
} position;

typedef struct
{
    position depart;
    position arrivee;
} deplacement;

//////////////////////// Les fonctions ////////////////////////////////////

// Premier version de init:

// void init_jeu(echiquier ech)
// {
//     int i;
//     int j;
//     for (i = 0; i <= 8; i++)
//     {
//         for (j = 0; j <= 8; j++)
//         {
//             ech[i][j] = NULL;
//         }
//     }
// }

// Deuxieme version de init:

void init_jeu(echiquier ech)
{
    int i;
    int j;
    for (i = 0; i <= 8; i++)
    {
        for (j = 0; j <= 8; j++)
        {
            ech[i][j] = NULL;
        }
    }
    piece *tour1_noire = malloc(sizeof(piece));
    tour1_noire->type = TOUR;
    tour1_noire->color = NOIR;
    ech[0][0] = tour1_noire;

    piece *cavalier1_noir = malloc(sizeof(piece));
    cavalier1_noir->type = CAVALIER;
    cavalier1_noir->color = NOIR;
    ech[0][1] = cavalier1_noir;

    piece *fou1_noir = malloc(sizeof(piece));
    fou1_noir->type = FOU;
    fou1_noir->color = NOIR;
    ech[0][2] = fou1_noir;

    piece *dame_noire = malloc(sizeof(piece));
    dame_noire->type = DAME;
    dame_noire->color = NOIR;
    ech[0][3] = dame_noire;

    piece *roi_noir = malloc(sizeof(piece));
    roi_noir->type = ROI;
    roi_noir->color = NOIR;
    ech[0][4] = roi_noir;

    piece *fou2_noir = malloc(sizeof(piece));
    fou2_noir->type = FOU;
    fou2_noir->color = NOIR;
    ech[0][5] = fou2_noir;

    piece *cavalier2_noir = malloc(sizeof(piece));
    cavalier2_noir->type = CAVALIER;
    cavalier2_noir->color = NOIR;
    ech[0][6] = cavalier2_noir;

    piece *tour2_noire = malloc(sizeof(piece));
    tour2_noire->type = TOUR;
    tour2_noire->color = NOIR;
    ech[0][7] = tour2_noire;

    piece *pion1_noir = malloc(sizeof(piece));
    pion1_noir->type = PION;
    pion1_noir->color = NOIR;
    ech[1][0] = pion1_noir;

    piece *pion2_noir = malloc(sizeof(piece));
    pion2_noir->type = PION;
    pion2_noir->color = NOIR;
    ech[1][1] = pion2_noir;

    piece *pion3_noir = malloc(sizeof(piece));
    pion3_noir->type = PION;
    pion3_noir->color = NOIR;
    ech[1][2] = pion3_noir;

    piece *pion4_noir = malloc(sizeof(piece));
    pion4_noir->type = PION;
    pion4_noir->color = NOIR;
    ech[1][3] = pion4_noir;

    piece *pion5_noir = malloc(sizeof(piece));
    pion5_noir->type = PION;
    pion5_noir->color = NOIR;
    ech[1][4] = pion5_noir;

    piece *pion6_noir = malloc(sizeof(piece));
    pion6_noir->type = PION;
    pion6_noir->color = NOIR;
    ech[1][5] = pion6_noir;

    piece *pion7_noir = malloc(sizeof(piece));
    pion7_noir->type = PION;
    pion7_noir->color = NOIR;
    ech[1][6] = pion7_noir;

    piece *pion8_noir = malloc(sizeof(piece));
    pion8_noir->type = PION;
    pion8_noir->color = NOIR;
    ech[1][7] = pion8_noir;

    piece *tour1_blanche = malloc(sizeof(piece));
    tour1_blanche->type = TOUR;
    tour1_blanche->color = BLANC;
    ech[7][0] = tour1_blanche;

    piece *cavalier1_blanc = malloc(sizeof(piece));
    cavalier1_blanc->type = CAVALIER;
    cavalier1_blanc->color = BLANC;
    ech[7][1] = cavalier1_blanc;

    piece *fou1_blanc = malloc(sizeof(piece));
    fou1_blanc->type = FOU;
    fou1_blanc->color = BLANC;
    ech[7][2] = fou1_blanc;

    piece *dame_blanche = malloc(sizeof(piece));
    dame_blanche->type = DAME;
    dame_blanche->color = BLANC;
    ech[7][3] = dame_blanche;

    piece *roi_blanc = malloc(sizeof(piece));
    roi_blanc->type = ROI;
    roi_blanc->color = BLANC;
    ech[7][4] = roi_blanc;

    piece *fou2_blanc = malloc(sizeof(piece));
    fou2_blanc->type = FOU;
    fou2_blanc->color = BLANC;
    ech[7][5] = fou2_blanc;

    piece *cavalier2_blanc = malloc(sizeof(piece));
    cavalier2_blanc->type = CAVALIER;
    cavalier2_blanc->color = BLANC;
    ech[7][6] = cavalier1_blanc;

    piece *tour2_blanche = malloc(sizeof(piece));
    tour2_blanche->type = TOUR;
    tour2_blanche->color = BLANC;
    ech[7][7] = tour2_blanche;

    piece *pion1_blanc = malloc(sizeof(piece));
    pion1_blanc->type = PION;
    pion1_blanc->color = BLANC;
    ech[6][0] = pion1_blanc;

    piece *pion2_blanc = malloc(sizeof(piece));
    pion2_blanc->type = PION;
    pion2_blanc->color = BLANC;
    ech[6][1] = pion2_blanc;

    piece *pion3_blanc = malloc(sizeof(piece));
    pion3_blanc->type = PION;
    pion3_blanc->color = BLANC;
    ech[6][2] = pion3_blanc;

    piece *pion4_blanc = malloc(sizeof(piece));
    pion4_blanc->type = PION;
    pion4_blanc->color = BLANC;
    ech[6][3] = pion4_blanc;

    piece *pion5_blanc = malloc(sizeof(piece));
    pion5_blanc->type = PION;
    pion5_blanc->color = BLANC;
    ech[6][4] = pion5_blanc;

    piece *pion6_blanc = malloc(sizeof(piece));
    pion6_blanc->type = PION;
    pion6_blanc->color = BLANC;
    ech[6][5] = pion6_blanc;

    piece *pion7_blanc = malloc(sizeof(piece));
    pion7_blanc->type = PION;
    pion7_blanc->color = BLANC;
    ech[6][6] = pion7_blanc;

    piece *pion8_blanc = malloc(sizeof(piece));
    pion8_blanc->type = PION;
    pion8_blanc->color = BLANC;
    ech[6][7] = pion8_blanc;
}

// Fonction affichage de la grille:

void affichage_jeu(echiquier ech)
{
    int i;
    int j;
    printf("\n");
    for (i = 0; i < 8; i++)
    {
        printf("%i      |", 8 - i);
        for (j = 0; j < 8; j++)
        {
            if (ech[i][j] == NULL)
            {
                printf("      |");
            }
            else if (ech[i][j]->color == NOIR)
            {
                if (ech[i][j]->type == ROI)
                {
                    printf(" R(n) |");
                }
                else if (ech[i][j]->type == DAME)
                {
                    printf(" D(n) |");
                }
                else if (ech[i][j]->type == FOU)
                {
                    printf(" F(n) |");
                }
                else if (ech[i][j]->type == CAVALIER)
                {
                    printf(" C(n) |");
                }
                else if (ech[i][j]->type == TOUR)
                {
                    printf(" T(n) |");
                }
                else
                {
                    printf(" P(n) |");
                }
            }
            else
            {
                if (ech[i][j]->type == ROI)
                {
                    printf(" R(b) |");
                }
                else if (ech[i][j]->type == DAME)
                {
                    printf(" D(b) |");
                }
                else if (ech[i][j]->type == FOU)
                {
                    printf(" F(b) |");
                }
                else if (ech[i][j]->type == CAVALIER)
                {
                    printf(" C(b) |");
                }
                else if (ech[i][j]->type == TOUR)
                {
                    printf(" T(b) |");
                }
                else
                {
                    printf(" P(b) |");
                }
            }
        }
        printf("\n       ---------------------------------------------------------\n");
    }
    printf("           A      B      C      D      E      F      G      H\n\n");
}

// Fonction de déplacement :

deplacement saisie_deplacement(echiquier ech, couleur clr)
{
    position pos1, pos2;
    char col1, col2;
    piece *p;
    deplacement dep;
    printf("Entrer la position (ligne et colonne) de la piece : ");
    scanf("%i %c", &pos1.ligne, &col1);
    pos1.ligne = 8 - pos1.ligne;

    pos1.colonne = col1 - 'A';

    p = ech[pos1.ligne][pos1.colonne];
    if (p != NULL && p->color == clr)
    {
        printf("Entrer la position d'arrivee : ");
        scanf("%i %c", &pos2.ligne, &col2);
        if (pos2.ligne > 0 && pos2.ligne < 9 && col2 >= 'A' && col2 <= 'H')
        {
            pos2.ligne = 8 - pos2.ligne;
            pos2.colonne = col2 - 'A';
            dep.depart = pos1;
            dep.arrivee = pos2;
            // Simple affichage pour voir si ca fonctionne
            // printf("%i %i", pos1.colonne, pos1.ligne);
            // printf("%i %i", pos2.colonne, pos2.ligne);
            return dep;
        }
        else
        {
            printf("La piece sort de l'echiquier");
        }
    }
    else if (p == NULL)
    {
        printf("La piece n'existe");
    }
    else
    {
        printf("La piece est de mauvaise couleur");
    }
    return dep;
}

void deplacer_piece(echiquier ech, deplacement dep)
{

    if (ech[dep.arrivee.ligne][dep.arrivee.colonne] != NULL)
    {
        free(ech[dep.arrivee.ligne][dep.arrivee.colonne]);
    }
    ech[dep.arrivee.ligne][dep.arrivee.colonne] = ech[dep.depart.ligne][dep.depart.colonne];
    ech[dep.depart.ligne][dep.depart.colonne] = NULL;
}

int main(void)
{

    echiquier ech;
    couleur clr;
    deplacement dep;
    init_jeu(ech);
    affichage_jeu(ech);
    printf("Choisissez une couleur (0 = blanc et 1 = noir) : ");
    scanf("%i", &clr);
    dep = saisie_deplacement(ech, clr);
    deplacer_piece(ech, dep);
    printf("\n");
    affichage_jeu(ech);

    return 0;
}
