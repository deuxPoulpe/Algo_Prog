#include "data.h"
#include "interface.h"
#include "jeu.h"

int main()
{
  echiquier ech;
  init_dessins_pieces();

  printf("\n\n\n\n\n\n \t\tMETTRE EN PLEIN ECRAN PUIS APPUYER SUR UNE TOUCHE\n");
  getchar();

  init_jeu(ech);
  afficher_grille(ech);

  deplacement deplacement_joueur;
  couleur couleur_joueur = BLANC;

  int sortie = 1;
  int cl_n = 1;

  while (sortie == 1)
  {
    if (cl_n == 1)
    {
      couleur_joueur = BLANC;
      printf("Le joueur des blancs c'est a vous (Exemple : A puis 1)\n");

      cl_n = 0;
    }
    else
    {
      couleur_joueur = NOIR;
      printf("Le joueur des noirs c'est a vous (Exemple : A puis 1)\n");

      cl_n = 1;
    }

    deplacement_joueur = saisie_deplacement(ech, couleur_joueur);

    deplacer_piece(ech, deplacement_joueur);
    afficher_grille(ech);
  }

  return 0;
}
