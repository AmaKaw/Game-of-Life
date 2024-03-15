#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "color.h"

int main()
{
    SetConsoleTitleA("THE GAME OF THE LIFE");
    Color(WHITE, BLACK);
    menu();
    return 0;
}
