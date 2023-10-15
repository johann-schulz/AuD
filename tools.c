#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

void clearBuffer(){
    char dummy;
    do{
        scanf("%c", &dummy);
    } while(dummy != '\n');
}

void waitForEnter(){
    printf("Bitte Eingabetaste druecken ...");
    char c;
    do{
        scanf("%c", &c);
    } while (c != '\n');
}

void clearScreen(){
    // je nach nutzer einfach das andere auskommentieren

    system("cls"); // windows
    // system("clear"); // osx
}

int askYesOrNo(char *Question){
    char answer;

    // Benutzerabfrage, die Schleife wird nur bei gültiger Eingabe verlassen
    do{
        printf("%s", Question);
        scanf("%c", &answer);
        if (answer == '\n') continue; // für den Fall dass input nur \n ist
        clearBuffer();
    } while((answer != 'j') && (answer != 'J') && (answer != 'n') && (answer != 'N'));

    // Durchführen der Aktion je nach Ergebnis
    if((answer == 'j')||(answer == 'J')){
        clearScreen();
        return 1;
    }
    return 0;
}

void printLine(char c, int count){
    for (int i = 0; i < count; i++)
        printf("%c", c);
    printf("\n");
}

