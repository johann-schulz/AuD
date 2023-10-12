#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

void clearBuffer(void){
    char dummy;

    do{
        scanf("%c", &dummy);
    } while(dummy != '\n');
}

void waitForEnter(void){

}

void clearScreen(void){
    system("cls");
    // system("clear");
}

int askYesOrNo(char *Question){
    char answer;

    do{
        printf("%s", Question);
        scanf("%c", &answer);
        if (answer == '\n') continue;
        clearBuffer();
    } while((answer != 'j') && (answer != 'J') && (answer != 'n') && (answer != 'N'));

    if((answer == 'j')||(answer == 'J')){
        clearScreen();
        return 1;
    }
    else {
        return 0;
    }
}
