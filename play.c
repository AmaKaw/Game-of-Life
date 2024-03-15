#include <stdio.h>
#include <stdlib.h>
#include "play.h"
#include "color.h"
#include "menu.h"
#include "fonction.h"
#include "liste.h"
#pragma once

extern int couleur;

void play_menu()
{
    char ch;
    int pos = 1, min = 1, max = 2;
    while(((int)ch != 13)&&((int)ch != 27)) //Tant qu'on appuie pas sur ENTER ou ECHAP
    {
        display_play_menu(&pos);
        pos = dplcmt(pos, min, max, &ch);
    }
    if((int)ch == 27) //Si on appuie sur ECHAP
        menu();       //Retour à la page précédente
    else
        select_play_menu(pos);
}

void display_play_menu(int *ptr)
{
    int stock;
    stock = *ptr;

    switch(stock)
    {
        case 1:
            system("cls");
            padding();
            printf(" GAME MODE ");
            padding();
            printf("\n\nUse ARROWS (UP/DOWN) to move up or down in the menu. Press ENTER to select your choice.\nPress ESC to go back.");
            Color(couleur, BLACK);
            printf("\n\n[");
            Color(couleur, couleur);
            printf("X");
            Color(couleur, BLACK);
            printf("].................................INFINITY MODE");
            Color(WHITE, BLACK);
            printf("\n[ ]............................STEP-FOR-STEP MODE");
            break;

        case 2:
            system("cls");
            padding();
            printf(" GAME MODE ");
            padding();
            printf("\n\nUse ARROWS (UP/DOWN) to move up or down in the menu. Press ENTER to select your choice.\nPress ESC to go back.");
            printf("\n\n[ ].................................INFINITY MODE");
            Color(couleur, BLACK);
            printf("\n[");
            Color(couleur, couleur);
            printf("X");
            Color(couleur, BLACK);
            printf("]............................STEP-FOR-STEP MODE");
            Color(WHITE, BLACK);
            break;
    }
}

void select_play_menu(int mode)
{
    switch(mode)
    {
        case 1: play_inf();
            break;

        case 2: play_step();
            break;
    }
}

void play_inf()
{

    int *opt;
    Grille *g;
    select_grid(&opt);
    g = newGrille(&opt);
    g = LireFichier(g);
    while(1)
    {
        system("cls");
        DetectionVoisins(g);
        afficherGrille(g);
        if(g->taille > 26)
            Sleep(500);
    }
    menu();
}

void play_step()
{
    int *opt;
    char ch;
    Grille *g;
    select_grid(&opt);
    g = newGrille(&opt);
    g = LireFichier(g);
    while((int)ch != 27)
    {
        system("cls");
        Color(WHITE, BLACK);
        printf("Press a key to continue. Press S to save the grid. Press ESC to leave the game.\n\n");
        DetectionVoisins(g);
        afficherGrille(g);
        if(kbhit)
        {
            ch = getch();
            if((int)ch == 115)
                save_file(g);
        }
    }
    menu();
}

void select_grid(int *opt)
{
    char ch;
    int taille = 0;
    system("cls");
    padding();
    printf(" GRID MODE ");
    padding();
    printf("\n\n Press R to get a randomize grid.\n Press I to import a grid.\n Press ESC to go back.");
    while(((int)ch != 27) && ((int)ch != 114) && ((int)ch != 105))
    {
        if(kbhit)
        {
            ch = getch();
            if((int)ch == 114)
            {
                *opt = 1;
                taille = recupTailleGrille();
                CreaFichierGrille(taille);
            }
            else if((int)ch == 105)
            {
                *opt = 2;
                import_file();
            }
            else if((int)ch == 27)
            {
                play_menu();
            }
        }
    }
}
