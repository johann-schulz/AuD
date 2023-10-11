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
    system("clear");
}

int askYesOrNo(char *Question){
    int ans = 0;
    char answer;

    printf("%s", Question);

    do{
        scanf("%c", &answer);
        clearBuffer();
    } while((answer != 'j') && (answer != 'J') && (answer != 'n') && (answer != 'N'));

    if((answer == 'j')||(answer == 'J')){
        ans = 1;
    }
    else if((answer == 'n') || (answer == 'N')){
        ans = 0;
    }
    return ans;
}
