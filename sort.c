#include "sort.h"
#include "datastructure.h"

//partition englisch für aufteilen
int partition (sAppointment *array, int lowerLimit, int upperLimit, int (*compfunction) (sAppointment *, sAppointment *)) {
    sAppointment *comperator = array + lowerLimit; //comp ist der zu vergleichende grenzwert
    int i = lowerLimit + 1, j = upperLimit;

    while (i <= j) {
        // nachstes Element > *comp von links suchen (im linken Teil)
        while ((i <= j) && (compfunction (array + i, comperator) <= 0))
            i++;
        while ((j >= i) && (compfunction (array + j, comperator) >= 0))
            j--;
        if(i < j){
            swapAppointmentPointer(array + i, array + j);
            i++;
            j--;
        }
    }
    i--;
    swapAppointmentPointer(comperator, array + i);

    return i;
}

void Qsort(sAppointment *array, int lowerLimit, int upperLimit, int (*compFunction) (sAppointment *, sAppointment *)){
    int newComperator; //das neue Grenzwert/vergleichswert nach der partitionierung

    if(lowerLimit >= upperLimit)
        return;
    else{
        newComperator = partition(array, lowerLimit, upperLimit, compFunction);
        Qsort(array, lowerLimit            , newComperator - 1, compFunction);
        Qsort(array, newComperator + 1, upperLimit, compFunction);
    }
}

void quickSort(sAppointment *array, int count, int (*compFunction) (sAppointment *, sAppointment *)){
    Qsort(array, 0, count - 1, compFunction );
}


void swapAppointmentPointer(sAppointment *pointer1, sAppointment *pointer2){
    sAppointment temp;
    temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}


// das sind meine CMPFCT(compare function) funktionen
int compareYears(sAppointment *pointer1, sAppointment *pointer2){
    return pointer1->Date.Year - pointer2->Date.Year;
}

int compareMonths(sAppointment *pointer1, sAppointment *pointer2){
    return pointer1->Date.Month - pointer2->Date.Month;
}

int compareDays(sAppointment *pointer1, sAppointment *pointer2){
    return pointer1->Date.Day - pointer2->Date.Day;
}




// string comp liefert 0 wenn beide gleich, ist 1. größer bekomme ich positve ist 1. kleiner als 2. beomme ich negative zahl
// D

// Datum/Uhrzeit                    (nach datum, wenn datum gleich nach Uhrzeit)
// Dauer/Datum/Uhrzeit              (nach Dauer, wenn gleiche nach Datum, wenn gleiches nach Uhrzeit) (nach dauer und sonst 1. aufrufen)
// Bezeichnung / Datum / Uhrzeit                                                                      (nach bezeichnung und sonst 1. aufrufen)
// Ort / Datum / Uhrzeit                                                                              (nach Ort und sonst 1. aufrufen)

// irgendwie noch maxtime hinzufügen