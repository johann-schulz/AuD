#include "sort.h"
#include "datastructure.h"

//partition englisch für aufteilen
int partition (sAppointment *pCalendar, int lowerLimit, int upperLimit, int (*compfunction) (sAppointment *, sAppointment *)) {
    sAppointment *comperator = pCalendar + lowerLimit; //comp ist der zu vergleichende grenzwert
    int i = lowerLimit + 1, j = upperLimit;

    while (i <= j) {
        // nachstes Element > *comp von links suchen (im linken Teil)
        while ((i <= j) && (compfunction (pCalendar + i, comperator) <= 0))
            i++;
        while ((j >= i) && (compfunction (pCalendar + j, comperator) >= 0))
            j--;
        if(i < j){
            swapAppointmentPointer(pCalendar + i, pCalendar + j);
            i++;
            j--;
        }
    }
    i--;
    swapAppointmentPointer(comperator, pCalendar + i);

    return i;
}

void Qsort(sAppointment *pCalendar, int lowerLimit, int upperLimit, int (*compFunction) (sAppointment *, sAppointment *)){
    int newComperator; //das neue Grenzwert/vergleichswert nach der partitionierung

    if(lowerLimit >= upperLimit)
        return;
    else{
        newComperator = partition(pCalendar, lowerLimit, upperLimit, compFunction);
        Qsort(pCalendar, lowerLimit            , newComperator - 1, compFunction);
        Qsort(pCalendar, newComperator + 1, upperLimit, compFunction);
    }
}

void quickSort(sAppointment *pCalendar, int count, int (*compFunction) (sAppointment *, sAppointment *)){
    Qsort(pCalendar, 0, count - 1, compFunction );
}


void swapAppointmentPointer(sAppointment *pointer1, sAppointment *pointer2){
    sAppointment temp;
    temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}


// das sind meine CMPFCT(compare function) funktionen


int compareDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2){
    if(pointer1->Date.Year - pointer2->Date.Year != 0)
        return pointer1->Date.Year - pointer2->Date.Year;
    else if(pointer1->Date.Month - pointer2->Date.Month != 0)
        return pointer1->Date.Month - pointer2->Date.Month;
    else if(pointer1->Date.Day - pointer2->Date.Day)
        return pointer1->Date.Day - pointer2->Date.Day;
    else if(pointer1->Time.Hour - pointer2->Time.Hour)
        return pointer1->Time.Hour - pointer2->Time.Hour;
    else if(pointer1->Time.Minute - pointer2->Time.Minute)
        return pointer1->Time.Minute - pointer2->Time.Minute;
    else //if(pointer1->Time.Second - pointer2->Time.Second)
        return pointer1->Time.Second - pointer2->Time.Second;

}
int compareDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2){
    if(pointer2->Date.Year - pointer1->Date.Year != 0)
        return pointer2->Date.Year - pointer1->Date.Year;
    else if(pointer2->Date.Month - pointer1->Date.Month != 0)
        return pointer2->Date.Month - pointer1->Date.Month;
    else if(pointer2->Date.Day - pointer1->Date.Day)
        return pointer2->Date.Day - pointer1->Date.Day;
    else if(pointer2->Time.Hour - pointer1->Time.Hour)
        return pointer2->Time.Hour - pointer1->Time.Hour;
    else if(pointer2->Time.Minute - pointer1->Time.Minute)
        return pointer2->Time.Minute - pointer1->Time.Minute;
    else //if(pointer2->Time.Second - pointer1->Time.Second)
        return pointer2->Time.Second - pointer1->Time.Second;
}




// string comp liefert 0 wenn beide gleich, ist 1. größer bekomme ich positve ist 1. kleiner als 2. beomme ich negative zahl
// D

// Datum/Uhrzeit                    (nach datum, wenn datum gleich nach Uhrzeit)
// Dauer/Datum/Uhrzeit              (nach Dauer, wenn gleiche nach Datum, wenn gleiches nach Uhrzeit) (nach dauer und sonst 1. aufrufen)
// Bezeichnung / Datum / Uhrzeit                                                                      (nach bezeichnung und sonst 1. aufrufen)
// Ort / Datum / Uhrzeit                                                                              (nach Ort und sonst 1. aufrufen)

// irgendwie noch maxtime hinzufügen