#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{

    piece p1;
    echiquier e1;
    deplacement d1;

    return 0;
}
