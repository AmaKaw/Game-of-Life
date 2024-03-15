#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "settings.h"
#pragma once

extern int couleur;

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void color_settings()
{
    char ch;
    int pos = 1, min = 1, max = 15, val = 0;

    while(((int)ch != 13)&&((int)ch != 27)) //Tant qu'on appuie pas sur ENTER ou ECHAP
    {
        display_color_settings(&pos, &val);
        pos = dplcmt(pos, min, max, &ch);
    }
    if((int)ch == 27)
        settings_menu();
    else
    {
        chgmt_color(max, pos, val);
        settings_menu();
    }
}

void chgmt_color(int max, int pos, int val)
{
    int i;
    char tab[3];
    FILE* f = NULL;
    f = fopen("colorsetting.txt", "w+");
    if(f == NULL)
    {
        system("cls");
        printf("Error when opening the file: colorsetting.txt\n\n");
        exit(0);
    }
    for(i = 1; i < max; i++)
    {
        if(i == pos)
            fprintf(f, "%d", val);
    }

    //couleur = fgets(tab, 3, f);
    couleur = val;
}

void display_color_settings(int *ptr, int *val)
{
    int stock;
    stock = *ptr;

    switch(stock)
    {
        case 1: //Gris foncé
            *val = DARK_GREY;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            Color(DARK_GREY, BLACK);
            printf("\n\n[");
            Color(DARK_GREY, DARK_GREY);
            printf("X");
            Color(DARK_GREY, BLACK);
            printf("].........................................DARK GREY");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 2: //Gris clair
            *val = LIGHT_GREY;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            Color(LIGHT_GREY, BLACK);
            printf("\n[");
            Color(LIGHT_GREY, LIGHT_GREY);
            printf("X");
            Color(LIGHT_GREY, BLACK);
            printf("].........................................LIGHT GREY");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 3: //Blanc
            *val = WHITE;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            Color(WHITE, BLACK);
            printf("\n[");
            Color(WHITE, WHITE);
            printf("X");
            Color(WHITE, BLACK);
            printf("].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 4: //Jaune
            *val = YELLOW;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            Color(YELLOW, BLACK);
            printf("\n[");
            Color(YELLOW, YELLOW);
            printf("X");
            Color(YELLOW, BLACK);
            printf("].........................................YELLOW");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 5: //Kaki
            *val = KHAKI;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            Color(KHAKI, BLACK);
            printf("\n[");
            Color(KHAKI, KHAKI);
            printf("X");
            Color(KHAKI, BLACK);
            printf("].........................................KHAKI");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 6: //Lime
            *val = LIME;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            Color(LIME, BLACK);
            printf("\n[");
            Color(LIME, LIME);
            printf("X");
            Color(LIME, BLACK);
            printf("].........................................LIME");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 7: //Vert
            *val = GREEN;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            Color(GREEN, BLACK);
            printf("\n[");
            Color(GREEN, GREEN);
            printf("X");
            Color(GREEN, BLACK);
            printf("].........................................GREEN");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 8: //Bleu foncé
            *val = DARK_BLUE;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            Color(DARK_BLUE, BLACK);
            printf("\n[");
            Color(DARK_BLUE, DARK_BLUE);
            printf("X");
            Color(DARK_BLUE, BLACK);
            printf("].........................................DARK BLUE");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 9: //Cyan
            *val = CYAN;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            Color(CYAN, BLACK);
            printf("\n[");
            Color(CYAN, CYAN);
            printf("X");
            Color(CYAN, BLACK);
            printf("].........................................CYAN");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 10: //Bleu
            *val = BLUE;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            Color(BLUE, BLACK);
            printf("\n[");
            Color(BLUE, BLUE);
            printf("X");
            Color(BLUE, BLACK);
            printf("].........................................BLUE");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 11: //Turquoise
            *val = TURQUOISE;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            Color(TURQUOISE, BLACK);
            printf("\n[");
            Color(TURQUOISE, TURQUOISE);
            printf("X");
            Color(TURQUOISE, BLACK);
            printf("].........................................TURQUOISE");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 12: //Mauve
            *val = MAUVE;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            Color(MAUVE, BLACK);
            printf("\n[");
            Color(MAUVE, MAUVE);
            printf("X");
            Color(MAUVE, BLACK);
            printf("].........................................MAUVE");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 13: //Violet
            *val = PURPLE;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            Color(PURPLE, BLACK);
            printf("\n[");
            Color(PURPLE, PURPLE);
            printf("X");
            Color(PURPLE, BLACK);
            printf("].........................................PURPLE");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................MAROON");
            printf("\n[ ].........................................RED");
            break;

        case 14: //Marron
            *val = MAROON;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            Color(MAROON, BLACK);
            printf("\n[");
            Color(MAROON, MAROON);
            printf("X");
            Color(MAROON, BLACK);
            printf("].........................................MAROON");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................RED");
            break;

        case 15: //Rouge
            *val = RED;
            system("cls");
            padding();
            printf(" CHOSE YOUR FAVORITE ");
            Color(RED, BLACK);
            printf("C");
            Color(DARK_BLUE, BLACK);
            printf("O");
            Color(GREEN, BLACK);
            printf("L");
            Color(YELLOW, BLACK);
            printf("O");
            Color(CYAN, BLACK);
            printf("R ");
            Color(WHITE, BLACK);
            padding();
            printf("\n\nUtilisez les touches Z ou S pour naviguer dans le menu. Appuyez sur la touche ENTER\npour selectionner votre choix.");
            printf("\n\n[ ].........................................DARK GREY");
            printf("\n[ ].........................................LIGHT GREY");
            printf("\n[ ].........................................WHITE");
            printf("\n[ ].........................................YELLOW");
            printf("\n[ ].........................................KHAKI");
            printf("\n[ ].........................................LIME");
            printf("\n[ ].........................................GREEN");
            printf("\n[ ].........................................DARK BLUE");
            printf("\n[ ].........................................CYAN");
            printf("\n[ ].........................................BLUE");
            printf("\n[ ].........................................TURQUOISE");
            printf("\n[ ].........................................MAUVE");
            printf("\n[ ].........................................PURPLE");
            printf("\n[ ].........................................MAROON");
            Color(RED, BLACK);
            printf("\n[");
            Color(RED, RED);
            printf("X");
            Color(RED, BLACK);
            printf("].........................................RED");
            Color(WHITE, BLACK);
            break;
    }
}

void select_color_settings()
{
    return 0;
}
