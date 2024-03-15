#include <stdio.h>
#include <stdlib.h>
#include "settings.h"
#include "color.h"
#include "menu.h"
#pragma once

extern int couleur;

int getSizeTab()
{
    int taille;
    do
    {
        system("cls");
        padding();
        printf(" SETTINGS ");
        padding();
        printf("\n\nSelectionnez la taille du plateau (min: 10 | max: 40): ");
        scanf("%d", &taille);
        if(taille < 10)
        {
            printf("\nLa valeur saisie est trop petite. Le plateau doit faire 10 unites par 10 unites au minimum.\n");
            system("pause");
        }
        else if(taille > 40)
        {
            printf("\nLa valeur saisie est trop grande. Le plateau peut faire 40 unites par 40 unites au maximum.\n");
            system("pause");
        }


    }while(taille < 10 || taille > 40);

    return taille;
}

void defineSizeTab(int taille)
{
    int i, j, rdm;
    FILE* fichier = NULL;
    fichier = fopen("settings/sizegrille.txt", "w+");
    if(fichier == NULL)
    {
        system("cls");
        printf("Erreur lors de l'ouverture du fichier grille_modified.txt\n\n");
        exit(0);
    }
    //taille = getSizeTab();
    fprintf(fichier, "%d\n", taille);
    fclose(fichier);
    settings_menu();
}

//AFFICHAGE GRAPHIQUE SETTINGS MENU

void settings_menu()
{
    char ch;
    int pos = 1, min = 1, max = 4;
    while(((int)ch != 13)&&((int)ch != 27)) //Tant qu'on appuie pas sur ENTER ou ECHAP
    {
        display_settings_menu(&pos);
        pos = dplcmt(pos, min, max, &ch);
    }
    if((int)ch == 27) //Si on appuie sur ECHAP
        menu();       //Retour à la page précédente
    else
        select_settings_menu(pos);
}

void display_settings_menu(int *ptr)
{
    int stock;
    stock = *ptr;

    switch(stock)
    {
        case 1: //DEFINIR
            system("cls");
            padding();
            printf(" SETTINGS OF THE GAME ");
            padding();
            printf("\n\nUse ARROWS (UP/DOWN) to move up or down in the menu. Press ENTER to select your choice.\nPress ESC to go back.");
            Color(couleur, BLACK);
            printf("\n\n[");
            Color(couleur, couleur);
            printf("X");
            Color(couleur, BLACK);
            printf("].........................DEFINE SIZE OF TABLE");
            Color(WHITE, BLACK);
            printf("\n[ ].....................RESET SIZE OF TABLE (10)");
            printf("\n[ ].................................CHANGE COLOR");
            printf("\n[ ].........................................BACK");
            break;

        case 2: //REINITIALISER
            system("cls");
            padding();
            printf(" SETTINGS OF THE GAME ");
            padding();
            printf("\n\nUse ARROWS (UP/DOWN) to move up or down in the menu. Press ENTER to select your choice.\nPress ESC to go back.");
            printf("\n\n[ ].........................DEFINE SIZE OF TABLE");
            Color(couleur, BLACK);
            printf("\n[");
            Color(couleur, couleur);
            printf("X");
            Color(couleur, BLACK);
            printf("].....................RESET SIZE OF TABLE (10)");
            Color(WHITE, BLACK);
            printf("\n[ ].................................CHANGE COLOR");
            printf("\n[ ].........................................BACK");
            break;

        case 3: //COULEUR
            system("cls");
            padding();
            printf(" SETTINGS OF THE GAME ");
            padding();
            printf("\n\nUse ARROWS (UP/DOWN) to move up or down in the menu. Press ENTER to select your choice.\nPress ESC to go back.");
            printf("\n\n[ ].........................DEFINE SIZE OF TABLE");
            printf("\n[ ].....................RESET SIZE OF TABLE (10)");
            Color(couleur, BLACK);
            printf("\n[");
            Color(couleur, couleur);
            printf("X");
            Color(couleur, BLACK);
            printf("].................................CHANGE COLOR");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................BACK");
            break;

        case 4: //RETOUR
            system("cls");
            padding();
            printf(" SETTINGS OF THE GAME ");
            padding();
            printf("\n\nUse ARROWS (UP/DOWN) to move up or down in the menu. Press ENTER to select your choice.\nPress ESC to go back.");
            printf("\n\n[ ].........................DEFINE SIZE OF TABLE");
            printf("\n[ ].....................RESET SIZE OF TABLE (10)");
            printf("\n[ ].................................CHANGE COLOR");
            Color(couleur, BLACK);
            printf("\n[");
            Color(couleur, couleur);
            printf("X");
            Color(couleur, BLACK);
            printf("].........................................BACK");
            Color(WHITE, BLACK);
            break;
    }
}

void select_settings_menu(int mode)
{
    switch(mode)
    {
        case 1: set1(); //DEFINIR
            break;

        case 2: set2(); //REINITIALISER
            break;

        case 3: set3(); //COULEUR
            break;

        case 4: back(); //RETOUR
            break;
    }
}

void set1() //DEFINIR
{
    system("cls");
    defineSizeTab(getSizeTab());
}

void set2() //REINITIALISER
{
    defineSizeTab(10);
}

void set3() // COULEUR
{
    color_settings();
}

void back() //RETOUR
{
    menu();
}

