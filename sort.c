#include "sort.h"

//partition englisch für aufteilen
int partition (int *Array, int lowerLimit, int upperLimit, int (*cmpfct) (int *, int *)) {
    int *limit = Array + lowerLimit; //limit ist der zu vergleichende grenzwert
    int i = lowerLimit + 1, j = upperLimit;

    while (i <= j) {
        // nachstes Element > *comp von links suchen (im linken Teil)
        while ((i <= j) && (cmpfct (Array + i, Limit) <= 0))
            i++;
        while ((j >= i) && (cmpfct (Array + j, Limit) >= 0))
            j--;
        if(i < j){
            swapIntPointer(Array + i, Array + j);
            i++;
            j--;
        }
    }
    i--;
    swapIntPointer(limit, Array + i);

    return i;
}

void qsort(int *Array, int lowerLimit, int upperLimit, int (*cmpfct) (int *, int *)){
    int newLimit; //dsa neue limit nach der partitionierung

    if(lowerLimit >= upperLimit)
        return;
    else{
        newLimit = partition(Array, lowerLimit, upperLimit, cmpfct);
        qsort(Array, lowerLimit            , newLimit - 1, cmpfct);
        qsort(Array, newLimit + 1, upperLimit, cmpfct);
    }
}

void IntQuickSort(int *array, int count, int (*cmpfct) (int *, int *)){
    qsort(Array, 0, count - 1, cmpfct )
}


void swapIntPointer(int *pointer1, int *pointer2){
    int temp;
    temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}

int IncreasingDirection(int *pointer1, int *pointer2){
    return *pointer1 - *pointer2;
}

int DecreasingDirection(int *pointer1, int *pointer2){
    return *pointer2 - *pointer1;
}

