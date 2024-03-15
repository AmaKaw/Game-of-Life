#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "color.h"
#include "settings.h"
#include "play.h"
#pragma once

int couleur = WHITE; //Variable globale

int dplcmt(int pos, int min, int max, char *ch)
{
    if(kbhit)
    {
        *ch = getch();
        switch((int)*ch)
        {
            case 72: // ↑ = Monter
                if((pos > min)&&(pos <= max))
                    pos--;
                break;

            case 80: // ↓ = Descendre
                if((pos >= min)&&(pos < max))
                    pos++;
                break;
        }
    }
    return pos;
}

void menu()
{
    char ch;
    int pos = 1, min = 1, max = 4;

    while(((int)ch != 13)&&((int)ch != 27)) //Tant qu'on appuie pas sur ENTER ou ECHAP
    {
        display_menu(&pos);
        pos = dplcmt(pos, min, max, &ch);
    }
    if((int)ch == 27) //Si on appuie sur ECHAP
    {
        choix4();
    }
    select_menu(pos);
}

void display_menu(int *ptr)
{
    int stock;
    stock = *ptr;

    switch(stock)
    {
        case 1: //PLAY
            Color(WHITE, BLACK);
            system("cls");
            padding();
            printf(" THE GAME OF THE LIFE ");
            padding();
            printf("\n\nUse ARROWS (UP/DOWN) to move up or down in the menu. Press ENTER to select your choice.\nPress ESC to quit.");
            Color(couleur, BLACK);
            printf("\n\n[");
            Color(couleur, couleur);
            printf("X");
            Color(couleur, BLACK);
            printf("].........................................PLAY");
            Color(WHITE, BLACK);
            printf("\n[ ].....................................SETTINGS");
            printf("\n[ ]......................................CREDITS");
            printf("\n[ ].........................................QUIT");
            break;

        case 2: //SETTINGS
            system("cls");
            padding();
            printf(" THE GAME OF THE LIFE ");
            padding();
            printf("\n\nUse ARROWS (UP/DOWN) to move up or down in the menu. Press ENTER to select your choice.\nPress ESC to quit.");
            printf("\n\n[ ].........................................PLAY");
            Color(couleur, BLACK);
            printf("\n[");
            Color(couleur, couleur);
            printf("X");
            Color(couleur, BLACK);
            printf("].....................................SETTINGS");
            Color(WHITE, BLACK);
            printf("\n[ ]......................................CREDITS");
            printf("\n[ ].........................................QUIT");
            break;

        case 3: //CREDIT
            system("cls");
            padding();
            printf(" THE GAME OF THE LIFE ");
            padding();
            printf("\n\nUse ARROWS (UP/DOWN) to move up or down in the menu. Press ENTER to select your choice.\nPress ESC to quit.");
            printf("\n\n[ ].........................................PLAY");
            printf("\n[ ].....................................SETTINGS");
            Color(couleur, BLACK);
            printf("\n[");
            Color(couleur, couleur);
            printf("X");
            Color(couleur, BLACK);
            printf("]......................................CREDITS");
            Color(WHITE, BLACK);
            printf("\n[ ].........................................QUIT");
            break;

        case 4: //QUIT
            system("cls");
            padding();
            printf(" THE GAME OF THE LIFE ");
            padding();
            printf("\n\nUse ARROWS (UP/DOWN) to move up or down in the menu. Press ENTER to select your choice.\nPress ESC to quit.");
            printf("\n\n[ ].........................................PLAY");
            printf("\n[ ].....................................SETTINGS");
            printf("\n[ ]......................................CREDITS");
            Color(couleur, BLACK);
            printf("\n[");
            Color(couleur, couleur);
            printf("X");
            Color(couleur, BLACK);
            printf("].........................................QUIT");
            Color(WHITE, BLACK);
            break;
    }
}

void padding()
{
    int i;
    for(i = 0; i < 35; i++)
    {
        printf("-");
    }
}

void select_menu(int mode)
{
    switch(mode)
    {
        case 1: choix1(); //PLAY
            break;

        case 2: choix2(); //SETTINGS
            break;

        case 3: choix3(); //CREDITS
            break;

        case 4: choix4(); //QUIT
            break;
    }
}

void choix1() //PLAY
{
    play_menu();
}

void choix2() //SETTINGS
{
    settings_menu();
}

void choix3() //CREDITS
{
    system("cls");
    FILE *f;
    char c;
    f=fopen("settings/troll.txt","rt");
    while((c=fgetc(f))!=EOF){
        Color(couleur, BLACK);
        printf("%c",c);
    }
    fclose(f);
    system("pause");
    menu();
}

void choix4() //QUIT
{
    system("cls");
    printf("See you soon!\n\n");
    exit(0);
}
