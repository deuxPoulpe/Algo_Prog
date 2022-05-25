#include "jeu.h"

void init_jeu(echiquier grid)
{
    int i, j;
    piece *blancs[2 * _SIZE];
    piece *noirs[2 * _SIZE];

    for (i = 0; i < _SIZE; i++)
        for (j = 0; j < _SIZE; j++)
            grid[i][j] = NULL;

    /** Allocation des blancs **/
    for (i = 0; i < 2 * _SIZE; i++)
    {
        blancs[i] = malloc(sizeof(piece));
        blancs[i]->color = BLANC;
    }
    for (i = 0; i < 2 * _SIZE; i++)
    {
        noirs[i] = malloc(sizeof(piece));
        noirs[i]->color = NOIR;
    }

    blancs[0]->type = TOUR;
    blancs[1]->type = CAVALIER;
    blancs[2]->type = FOU;
    blancs[3]->type = DAME;
    blancs[4]->type = ROI;
    blancs[5]->type = FOU;
    blancs[6]->type = CAVALIER;
    blancs[7]->type = TOUR;
    for (i = _SIZE; i < 2 * _SIZE; i++)
        blancs[i]->type = PION;
    for (j = 0; j < _SIZE; j++)
    {
        grid[_SIZE - 1][j] = blancs[j];
        grid[_SIZE - 2][j] = blancs[j + _SIZE];
    }
    noirs[0]->type = TOUR;
    noirs[1]->type = CAVALIER;
    noirs[2]->type = FOU;
    noirs[3]->type = DAME;
    noirs[4]->type = ROI;
    noirs[5]->type = FOU;
    noirs[6]->type = CAVALIER;
    noirs[7]->type = TOUR;
    for (i = _SIZE; i < 2 * _SIZE; i++)
        noirs[i]->type = PION;
    for (i = 0; i < 2; i++)
        for (j = 0; j < _SIZE; j++)
            grid[i][j] = noirs[j + _SIZE * i];
}

void deplacer_piece(echiquier grid, deplacement d)
{
    if (grid[d.arrivee.ligne][d.arrivee.colonne] != NULL)
        free(grid[d.arrivee.ligne][d.arrivee.colonne]);
    grid[d.arrivee.ligne][d.arrivee.colonne] = grid[d.depart.ligne][d.depart.colonne];
    grid[d.depart.ligne][d.depart.colonne] = NULL;
}

void deplacements_possibles(echiquier grid, position pos, int test_grid[8][8])
{
    int i;
    int j;

    for (i = 0; i < 8; i++)
    {

        for (j = 0; j < 8; j++)
        {
            test_grid[i][j] = 0;
        }
    }

    piece ptm;
    ptm.color = grid[pos.ligne][pos.colonne]->color;
    ptm.type = grid[pos.ligne][pos.colonne]->type;
    printf("%i  et %i\n", pos.ligne - 1, pos.colonne - 2);
    if (ptm.color == 0)
    {
        if (ptm.type == 0)
        {
            if (pos.ligne == 6)
            {
                if ((grid[pos.ligne - 1][pos.colonne] == NULL) && (0 < pos.ligne - 1) && (7 > pos.ligne - 1) && (0 < pos.colonne) && (7 > pos.colonne))
                {
                    test_grid[pos.ligne - 1][pos.colonne] = 1;

                    if ((grid[pos.ligne - 2][pos.colonne] == NULL) && (0 < pos.ligne - 2) && (7 > pos.ligne - 2) && (0 < pos.colonne) && (7 > pos.colonne))
                    {
                        test_grid[pos.ligne - 2][pos.colonne] = 1;
                    }
                }
            }
            else if ((grid[pos.ligne - 1][pos.colonne] == NULL) && (0 < pos.ligne - 1) && (7 > pos.ligne - 1) && (0 < pos.colonne) && (7 > pos.colonne))
            {
                test_grid[pos.ligne - 1][pos.colonne] = 1;
            }
        }
        else if (ptm.type == 1)
        {
            if ((grid[pos.ligne - 2][pos.colonne - 1] == NULL) && (0 < pos.ligne - 2) && (7 > pos.ligne - 2) && (0 < pos.colonne - 1) && (7 > pos.colonne - 1))
            {
                test_grid[pos.ligne - 2][pos.colonne - 1] = 2;
            }
            if ((grid[pos.ligne - 1][pos.colonne - 2] == NULL) && (0 < pos.ligne - 1) && (7 > pos.ligne - 1) && (0 < pos.colonne - 2) && (7 > pos.colonne - 2))
            {
                test_grid[pos.ligne - 1][pos.colonne - 2] = 3;
            }
            if ((grid[pos.ligne - 2][pos.colonne + 1] == NULL) && (0 < pos.ligne - 2) && (7 > pos.ligne - 2) && (0 < pos.colonne + 1) && (7 > pos.colonne + 1))
            {
                test_grid[pos.ligne - 2][pos.colonne + 1] = 4;
            }
            if ((grid[pos.ligne - 1][pos.colonne + 2] == NULL) && (0 < pos.ligne - 1) && (7 > pos.ligne - 1) && (0 < pos.colonne + 2) && (7 > pos.colonne + 2))
            {
                test_grid[pos.ligne - 1][pos.colonne + 2] = 5;
            }
        }
    }

    printf("\n");
    for (i = 0; i < 8; i++)
    {

        for (j = 0; j < 8; j++)
        {
            if (test_grid[i][j] == 0)
            {
                printf("0   ");
            }
            else
            {
                printf("%i   ", test_grid[i][j]);
            }
        }
        printf("\n");
    }
}
