#ifndef _FONCTION_H_
#define _FONCTION_H_

typedef struct {
    int ** t;
    int taille;
}Grille;

int recupTailleGrille();
void CreaFichierGrille(int taille);
Grille * newGrille ();
Grille * LireFichier(Grille *g);
void DetectionVoisins(Grille * g);
void afficherGrille(Grille * g);
int cptTailleGrille();
void save_file(Grille *g);
void import_file();

#endif // _FONCTION_H_
