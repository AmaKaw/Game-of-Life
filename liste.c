#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Liste *init_liste(Grille *g)
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->grille = LireFichier(g);
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, Grille *g)
{
    int i, j;
    char *temp[g->taille][g->taille];
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < g->taille; i++)
    {
        for(j = 0; j < g->taille; j++)
        {
            temp[i][j] = g->t[i][j];
            printf("%c = %c",g->t[i][j], temp[i][j]);
        }
    }

    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}
