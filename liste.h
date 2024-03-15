#ifndef _LISTE_H_
#define _LISTE_H_
#include "fonction.h"

typedef struct Element Element;
struct Element
{
    Grille *grille;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};


Liste *init_liste(Grille *g);
void insertion(Liste *liste, Grille *g);
void afficherListe(Liste *liste);

#endif // _LISTE_H_
