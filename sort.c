#include "sort.h"

//partition englisch für aufteilen
int Partition (int *array, int lowerLimit, int upperLimit, int (*compfunction) (int *, int *)) {
    int *comperator = array + lowerLimit; //comp ist der zu vergleichende grenzwert
    int i = lowerLimit + 1, j = upperLimit;

    while (i <= j) {
        // nachstes Element > *comp von links suchen (im linken Teil)
        while ((i <= j) && (compfunction (array + i, comperator) <= 0))
            i++;
        while ((j >= i) && (compfunction (array + j, comperator) >= 0))
            j--;
        if(i < j){
            SwapIntPointer(array + i, array + j);
            i++;
            j--;
        }
    }
    i--;
    SwapIntPointer(comperator, array + i);

    return i;
}

void Qsort(int *array, int lowerLimit, int upperLimit, int (*compfunction) (int *, int *)){
    int newComperator; //das neue Grenzwert/vergleichswert nach der partitionierung

    if(lowerLimit >= upperLimit)
        return;
    else{
        newComperator = Partition(array, lowerLimit, upperLimit, compfunction);
        Qsort(array, lowerLimit            , newComperator - 1, compfunction);
        Qsort(array, newComperator + 1, upperLimit, compfunction);
    }
}

void IntQuickSort(int *array, int count, int (*compfunction) (int *, int *)){
    Qsort(array, 0, count - 1, compfunction );
}


void SwapIntPointer(int *pointer1, int *pointer2){
    int temp;
    temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}


// das sind meine CMPFCT(compare function) funktionen
int IncreasingDirection(int *pointer1, int *pointer2){
    return *pointer1 - *pointer2;
}

int DecreasingDirection(int *pointer1, int *pointer2){
    return *pointer2 - *pointer1;
}




// string comp liefert 0 wenn beide gleich, ist 1. größer bekomme ich positve ist 1. kleiner als 2. beomme ich negative zahl
// D

// Datum/Uhrzeit                    (nach datum, wenn datum gleich nach Uhrzeit)
// Dauer/Datum/Uhrzeit              (nach Dauer, wenn gleiche nach Datum, wenn gleiches nach Uhrzeit) (nach dauer und sonst 1. aufrufen)
// Bezeichnung / Datum / Uhrzeit                                                                      (nach bezeichnung und sonst 1. aufrufen)
// Ort / Datum / Uhrzeit                                                                              (nach Ort und sonst 1. aufrufen)

// irgendwie noch maxtime hinzufügen