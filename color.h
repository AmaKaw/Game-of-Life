#ifndef _COLOR_H_
#define _COLOR_H_
#include <windows.h>
#include <conio.h>
#include <time.h>

enum couleur {BLACK, DARK_BLUE, GREEN, CYAN, MAROON, PURPLE, KHAKI, LIGHT_GREY, DARK_GREY, BLUE, LIME, TURQUOISE, RED, MAUVE, YELLOW, WHITE};

void Color(int couleurDuTexte,int couleurDeFond);
void chgmt_color(int max, int pos, int val);
void color_settings();
void display_color_settings(int *ptr, int *val);

#endif // _COLOR_H_
