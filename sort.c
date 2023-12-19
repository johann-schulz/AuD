#include "sort.h"
#include "datastructure.h"
#include "tools.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    dummyWaitingFunction();
    return;
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

int compareDurationAndDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2){
    if(pointer1->Duration->Hour - pointer2->Duration->Hour != 0)
        return pointer1->Date.Year - pointer2->Duration->Hour;
    else if(pointer1->Duration->Minute - pointer2->Duration->Minute != 0)
        return pointer1->Duration->Minute - pointer2->Duration->Minute;
    else if(pointer1->Duration->Second - pointer2->Duration->Second != 0)
        return pointer1->Duration->Second - pointer2->Duration->Second;
    else
        return compareDateAndTimeIncreasing(pointer1,pointer2);
}

int compareDurationAndDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2) {
    if (pointer2->Duration->Hour - pointer1->Duration->Hour != 0)
        return pointer2->Date.Year - pointer1->Duration->Hour;
    else if (pointer2->Duration->Minute - pointer1->Duration->Minute != 0)
        return pointer2->Duration->Minute - pointer1->Duration->Minute;
    else if (pointer2->Duration->Second - pointer1->Duration->Second != 0)
        return pointer2->Duration->Second - pointer1->Duration->Second;
    else
        return compareDateAndTimeDecreasing(pointer1, pointer2);
}

int compareDescriptionAndDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2){
    if (strcmp(pointer1->Description, pointer2->Description) != 0){
        return strcmp(pointer1->Description,pointer2->Description);
    }else
        return compareDateAndTimeIncreasing(pointer1,pointer2);
}

int compareDescriptionAndDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2){
    if (strcmp(pointer1->Description, pointer2->Description) != 0){
        return strcmp(pointer1->Description,pointer2->Description);
    }else
        return compareDateAndTimeDecreasing(pointer1,pointer2);
}

int compareLocationAndDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2){
    printf("rein in cmpfct:     ");
    printf("Locaiton1: %s       ",pointer1->Location);
    printf("Locaiton2: %s\n",pointer2->Location);
    waitForEnter();
    if (pointer1->Location && pointer2->Location && strcmp(pointer1->Location, pointer2->Location) != 0 ){
        printf("nichts ist (null)");
        return strcmp(pointer1->Location,pointer2->Location);
    }else
        return compareDateAndTimeIncreasing(pointer1,pointer2);
}

int compareLocationAndDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2){
    if (strcmp(pointer1->Location, pointer2->Location) != 0){
        return strcmp(pointer1->Location,pointer2->Location);
    }else
        return compareDateAndTimeDecreasing(pointer1,pointer2);
}



// string comp liefert 0 wenn beide gleich, ist 1. größer bekomme ich positve ist 1. kleiner als 2. beomme ich negative zahl
// D

// Datum/Uhrzeit                    (nach datum, wenn datum gleich nach Uhrzeit)
// Dauer/Datum/Uhrzeit              (nach Dauer, wenn gleiche nach Datum, wenn gleiches nach Uhrzeit) (nach dauer und sonst 1. aufrufen)
// Bezeichnung / Datum / Uhrzeit                                                                      (nach bezeichnung und sonst 1. aufrufen)
// Ort / Datum / Uhrzeit                                                                              (nach Ort und sonst 1. aufrufen)

// irgendwie noch maxtime hinzufügen

void dummyWaitingFunction() {
    const int totalProgress = 10;  // Total number of steps in the progress bar
    const char progressBarChar = '#';

    printf("Kalender sortieren: [");

    for (int i = 0; i < totalProgress; ++i) {
        // Simulate a random time interval between 1 and 5 seconds
        struct timespec interval;
        interval.tv_sec = 0;
        interval.tv_nsec = 1000000000 * (3 + rand() % 10);  // nanosleep takes nanoseconds

        nanosleep(&interval, NULL);

        // Update the progress bar
        printf("%c", progressBarChar);
        fflush(stdout);  // Flush the output to ensure immediate display

        // Simulate a longer pause after the progress bar is complete
        if (i == totalProgress - 1) {
            interval.tv_nsec = 2000000000;  // 2 seconds
            nanosleep(&interval, NULL);
        }
    }
    printf("] Fertig!\n");
}