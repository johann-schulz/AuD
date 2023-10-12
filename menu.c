#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "tools.h"

int getMenu(char *menuTitle, char *menuItems[], int itemCount){
    while (1){
        int choice = 0;
        clearScreen();
        printf("%s\n", menuTitle);

        for (int i = 0; i < itemCount; i++) {
            printf("%d. %s\n", i + 1, menuItems[i]);
        }

        printf("\nGib deine Auswahl ein: ");
        int validInput = scanf("%d", &choice);
        clearBuffer();
        if (validInput != 1 || choice < 1 || choice > itemCount){
            continue;
        } else{
            return choice;
        }
    }
}