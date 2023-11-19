#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


int getText(char*promptMessage, unsigned max, char **Pointer, int AllowEmpty){
    char*Input;
    char Format[20];
    unsigned Len=0;
    int ok = 0;

    if ((Pointer==NULL) || (max == 0))
        return 0;
    *Pointer=NULL;

    Input=malloc(max + 1);
    if (Input){
        sprintf(Format, "%%%i[^\n]", max);
        do {
            printf("%s", promptMessage);
            *Input='\0';
            scanf(Format, Input);
            clearBuffer();
            Len= strlen(Input);
            if(Len>0){
                *Pointer= malloc(Len+1);
                if(*Pointer){
                    strncpy(*Pointer, Input, Len+1);
                    ok=1;
                }
            }else if(AllowEmpty){
                ok=1;
            }else{
                printf("Eingabe darf nicht leer sein!");
            }
        }while(ok!=1);
        free(Input);
        return 1;
    } else
        return 0;
}





