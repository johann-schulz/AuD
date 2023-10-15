#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "tools.h"

int getMenu(char *menuTitle, char *menuItems[], int itemCount){
    while (1){
        int choice = 0;
        clearScreen();

        // Ausgabe des Titels
        printf("%s\n", menuTitle);
        printLine('=', 22);
        printf("\n");

        // Ausgabe der Menuepunkte
        for (int i = 0; i < itemCount; i++) {
            printf("%d. %s\n", i + 1, menuItems[i]);
        }

        // Fragt Benutzerauswahl ab mit dem bekannten Problem bei einem %d, dass ein reines \n nicht erkannt werden kann
        printf("\nGib deine Auswahl ein: ");
        int validInput = scanf("%d", &choice);
        clearBuffer();
        if (choice == '\n') continue;

        // Validierung der Eingabe Durchführen einer Aktion je nach Eingabe
        if (validInput != 1 || choice < 1 || choice > itemCount){
            continue;
        } else{
            return choice;
        }
    }
}

