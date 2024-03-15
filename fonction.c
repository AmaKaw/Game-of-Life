#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include "color.h"

extern int couleur;

void import_file()
{
    FILE* myfile = NULL;
    int taille = 0, error = 0, i, j, cara = 0, cpt = 0;
    char *compar[5] = {'.', 't', 'x', 't'};
    myfile = fopen("grid/grille.txt", "r");
    do
    {
        error = 0;
        cpt = 0;
        system("cls");
        padding();
        printf(" DISCLAIMER ");
        padding();
        printf("\n\nLe fichier que vous importez doit etre un fichier .txt et ne contenir que des 0 et des 1.\nLes 0 et 1 doivent former un carre (autant de lignes que de colonnes).");
        printf("\nLe fichier doit s'appeler grille.txt et se trouver dans le fichier [grid].\n\n");
        system("pause");
        //CHECK SI LE FICHIER NE CONTIENT QUE DES 0 OU DES 1
        taille = cptTailleGrille();
        do
        {

            cara = fgetc(myfile);
            if(cara == '\n')
            {
                cpt++;
            }


            if ((cara != '0') && (cara != '1') && (cara != '\n') && (cara != EOF))
            {
                error++;
            }

        }while(cara != EOF);


        if(error != 0)
        {
            //system("cls");
            printf("Le fichier importe ne peut pas etre lu car il ne respecte pas les conditions.\n\n");
            system("pause");
        }
        fclose(myfile);
    }while(error != 0);
}

int cptTailleGrille()
{
    int i, j, cara, cpt = 0;
    FILE* fichier = NULL;
    fichier = fopen("grid/grille.txt", "r");
    if(fichier == NULL)
    {
        system("cls");
        printf("Error when opening the file!");
        exit(0);
    }
    do
    {
        cara = fgetc(fichier);
        if(cara != '\n')
            cpt++;

    }while(cara != '\n');
    return cpt;
}

int recupTailleGrille()
{
    int taille = 0;
    FILE* f = NULL;
    f = fopen("settings/sizegrille.txt", "r");
    if(f == NULL)
    {
        system("cls");
        printf("Erreur lors de l'ouverture de sizegrille.txt\n\n");
        exit(0);
    }
    fscanf(f, "%d", &taille);
    fclose(f);
    return taille;
}

void CreaFichierGrille(int taille)
{
    int i, j, rdm;
    FILE* f2 = NULL;
    f2 = fopen("grid/grille.txt", "w+");
    if(f2 == NULL)
    {
        system("cls");
        printf("Erreur lors de l'ouverture de grille.txt\n\n");
        exit(0);
    }
    srand(time(NULL));
    for(i = 0; i < taille; i++)
    {
        for(j = 0; j < taille; j++)
        {
            rdm = rand()%2;
            fprintf(f2, "%d", rdm);
        }
        fprintf(f2, "\n");
    }
    fclose(f2);
}

Grille * newGrille(int *opt)
{
    int i, j;
    Grille * g = (Grille *)malloc(sizeof(Grille));
    if (g == NULL)
    {
        printf("pas assez de mémoire \n");
        exit(1);
    }
    if(*opt == 1)
    {
        g->taille = recupTailleGrille();
    }
    else if(*opt == 2)
    {
        g->taille = cptTailleGrille();
    }
    g->taille = g->taille+2;
    g->t=(int**)calloc(g->taille,sizeof(int*));
    for(int i=0;i<g->taille;i++)
    {
        *(g->t+i)=(int*)calloc(g->taille,sizeof(int));
        for(j=0;j<g->taille;j++)
        {
            g->t[i][j]=0;
        }
    }
    return g;
}

void save_file(Grille *g)
{
    char *temp[50];
    int compteur, i, j;
    FILE *cpt = NULL;
    FILE *savefile = NULL;
    cpt = fopen("settings/cpt.txt", "r");
    if(cpt == NULL)
    {
        system("cls");
        printf("Erreur lors de l'ouverture de cpt.txt\n\n");
        exit(0);
    }
    fscanf(cpt, "%d", &compteur);
    fclose(cpt);
    sprintf(temp, "Saves/grille%d.txt", compteur);
    savefile = fopen(temp, "w");
    if(savefile == NULL)
    {
        system("cls");
        printf("Erreur lors de l'ouverture de cpt.txt\n\n");
        exit(0);
    }
    for(i = 1; i < g->taille-1; i++)
    {
        for(j = 1; j < g->taille-1; j++)
        {
            fprintf(savefile, "%d", g->t[i][j]);
        }
        fprintf(savefile, "\n", g->t[i][j]);
    }
    compteur++;
    cpt = fopen("settings/cpt.txt", "w");
    if(cpt == NULL)
    {
        system("cls");
        printf("Erreur lors de l'ouverture de cpt.txt\n\n");
        exit(0);
    }
    fprintf(cpt, "%d\n", compteur);
    fclose(cpt);
    fclose(savefile);
}

Grille * LireFichier(Grille *g)
{
//INITIALISATION DE LA GRILLE DYNAMIQUE A PARTIR D'UN FICHIER
    FILE* fichier = NULL;
    int caractereActuel = 0, i, j;
    fichier = fopen("grid/grille.txt", "r");
    if (fichier != NULL)
    {
        //BOUCLE DE LECTURE DES CARACTERES UN A UN
        //printf("fichier ouvert \n\n");
        for(i = 1; i < g->taille-1; i++)
        {
            for(j = 1; j < g->taille-1; j++)
            {
                caractereActuel = fgetc(fichier);
                //printf("%c", caractereActuel);

                if (caractereActuel == '1')
                {
                    g->t[i][j] = 1;
                }
                if (caractereActuel == '0')
                {
                    g->t[i][j] = 0;
                }
                if (caractereActuel == '\n')
                {
                    j--;
                }
            }
        }
        fclose(fichier);
    }
    return g;
}

void afficherGrille(Grille *g)
{
    //printf("\n");
    int j, n = g->taille, i;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(*(*(g->t+i)+j) == 0)
                Color(BLACK, BLACK);
            else
                Color(couleur, couleur);

            if(j == (n-1))
                printf(" %d \n", g->t[i][j]);
            else
                printf(" %d ", g->t[i][j]);
        }
    }
}


void DetectionVoisins(Grille * g)
{
    int NbCellViv = 0, NumSimu=0;
    int compteur = 1;
    //char filename[255];
    //FILE* f;
    long touche = 0;

    //GRILLE TAMPON
    Grille * tampon = (Grille *)malloc(sizeof(Grille));

    if (tampon == NULL)
        {
            printf("pas assez de mémoire \n");
            exit(1);
        }
    tampon->taille = g->taille; //TAILLE GRILLE
    tampon->t=(int**)calloc(tampon->taille,sizeof(int*));
        for(int i=0;i<tampon->taille;i++)
            {
                *(tampon->t+i)=(int*)calloc(tampon->taille,sizeof(int));
                for(int j=0;j<tampon->taille;j++)
                    {
                        tampon->t[i][j]=0;
                    }
            }

          for(int C=1;C<g->taille-1;C++)
            {
                for(int L=1;L<g->taille-1;L++)
                    {

                        //RECHERCHE DES CELLULES VIVANTES

                        if ((*(*(g->t+(C-1))+(L-1)))== 1)
                            NbCellViv = NbCellViv+1;

                        if ((*(*(g->t+(C))+(L-1)))== 1)
                            NbCellViv = NbCellViv+1;

                        if ((*(*(g->t+(C+1))+(L-1)))== 1)
                            NbCellViv = NbCellViv+1;

                        if ((*(*(g->t+(C-1))+(L)))== 1)
                            NbCellViv = NbCellViv+1;

                        if ((*(*(g->t+(C+1))+(L)))== 1)
                            NbCellViv = NbCellViv+1;

                        if ((*(*(g->t+(C-1))+(L+1)))== 1)
                            NbCellViv = NbCellViv+1;

                        if ((*(*(g->t+(C))+(L+1)))== 1)
                            NbCellViv = NbCellViv+1;

                        if ((*(*(g->t+(C+1))+(L+1)))== 1)
                            NbCellViv = NbCellViv+1;

                        //APPLICATION DES REGLES DE VIE OU DE MORT&

                        if ((*(*(g->t+(C))+(L))) == 0 )
                            {
                                if (NbCellViv == 3)
                                {
                                    *(*(tampon->t+(C))+(L)) = 1;
                                }
                                else
                                {
                                    *(*(tampon->t+(C))+(L)) = 0;
                                }

                            }

                        if ((*(*(g->t+(C))+(L))) == 1 )
                        {
                                if (NbCellViv >= 2 && NbCellViv <= 3)
                                {
                                    *(*(tampon->t+(C))+(L)) = 1;
                                }
                                else
                                {
                                    *(*(tampon->t+(C))+(L)) = 0;
                                }

                            }

                        NbCellViv = 0;

                    }

            }
            //CHANGEMENT DE GRILLE

            for(int i=0;i<g->taille;i++)
            {

                for(int j=0;j<g->taille;j++)
                    {
                        *(*(g->t+i)+j) = *(*(tampon->t+i)+j);
                    }
            }
}
