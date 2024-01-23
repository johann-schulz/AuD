#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "escapesequenzen.h"

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

    //system("cls"); // windows
    system("clear"); // unix
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

int newGetText(char* prompt, int maxLen, char** text, int isEmptyInputAllowed)
{
    int isInputValid = 0, len;
    char format[15];
    if (maxLen <= 0 || !text) return 0;

    char* input = calloc(maxLen + 1, sizeof(char));
    if (!input) return printf("malloc fehler");

    sprintf(format, "%%%i[^\n]", maxLen);

    if (prompt) printf("  %-12s: ", prompt);

    STORE_POS;

    do
    {
        RESTORE_POS;
        FORECOLOR_YELLOW;
        printf("Enter text here. (max. %i characters; Empty %s allowed)%-*s", maxLen, isEmptyInputAllowed ? "is" : "is not", 36, "");
        RESTORE_POS;
        FORECOLOR_WHITE;

        isInputValid = scanf(format, input);
        clearBuffer();

        RESTORE_POS;
        if (isInputValid)
        {
            len = strlen(input);
            if (len > 0)
            {
                *text = malloc(len + 1);
                if (*text)
                {
                    strcpy(*text, input);
                    printf("%-*s\n", 100, input);
                }
                else return printf("malloc fehler");
            }
            else
            {
                if (!isEmptyInputAllowed)
                {
                    printf("Invalid input! Empty input is not allowed. ");
                    waitForEnter();
                    isInputValid = 0;
                }
                else isInputValid = 1;
            }
        }
        else
        {
            if (isEmptyInputAllowed)
            {
                printf("No %s set ...%*s\n", prompt, 60, "");
                isInputValid = 1;
            }
            else
            {
                printf("Invalid input! Empty input is not allowed. ");
                waitForEnter();
                isInputValid = 0;
            }
        }
    } while (!isInputValid);
    free(input);
    input = NULL;

    return isInputValid;
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

char ToUpper(char c)
{
    if (c < 97 || c > 122) return c;
    return c - 32; // ascii offset from lower to upper character (e.g. a=97, A=65)
}

void PrintNewLine(unsigned short count)
{
    while(count)
    {
        printf("\n");
        count--;
    }
}
