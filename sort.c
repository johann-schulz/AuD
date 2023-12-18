#include "sort.h"
#include "datastructure.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

//partition englisch für aufteilen
int partition (sAppointment *pCalendar, int lowerLimit, int upperLimit,  char *sortField, char *Sortdirection) {
//    printf("partitionFKT\n");
//    printf("\nArray elements: ");
//    for (int i = 0; i < countAppointments; i++) {
//        printf("%d ", pCalendar[i].Date.Year);
//    }
//    waitForEnter();

    sAppointment *comparator = pCalendar + lowerLimit; //comp ist der zu vergleichende grenzwert
    int i = lowerLimit + 1, j = upperLimit;
    char *sortField2 = malloc(12);
    char *sortField3 = malloc(12);
    if (sortField2 == NULL || sortField3 == NULL ) {
        fprintf(stderr, "Memory allocation failed.\n");
        //add Exit with an error code
    }


    while (i <= j) {
        // nachstes Element > *comp von links suchen (im linken Teil)

        printf("SortField: %s\n", sortField);

        int compareValueI = cmpfct(pCalendar + i, comparator, sortField, Sortdirection);
        printf("compValue: %d\n",compareValueI);
        while ((i <= j) && (compareValueI <= 0)) {
            if (compareValueI == 0) {
//                printf("if i++ zweig rein\n");
//                waitForEnter();
                if (strcmp(sortField, "yearsssssss") == 0){
//                    printf("yearsssssss\n");
//                    waitForEnter();
                    strncpy(sortField2, "monthssssss",12);
                    cmpfct(pCalendar + i, comparator, sortField2, Sortdirection);
                } else if (strcmp(sortField2, "monthssssss") == 0) {
                    strncpy(sortField3, "dayssssssss", 12);
                    cmpfct(pCalendar + i, comparator, sortField3, Sortdirection);
                } else if (strcmp(sortField, "hoursssssss") == 0){
                    strncpy(sortField2, "minutesssss",12);
                    cmpfct(pCalendar + i, comparator, sortField2, Sortdirection);
                } else if (strcmp(sortField2, "minutesssss") == 0) {
                    strncpy(sortField3, "secondsssss", 12);
                    cmpfct(pCalendar + i, comparator, sortField3, Sortdirection);
                }
            }
            i++;
//            printf("i++ zweig raus\n");
//            waitForEnter();
        }

        int compareValueJ = cmpfct(pCalendar + j, comparator, sortField, Sortdirection);
        printf("compValue: %d\n",compareValueJ);
        while ((j >= i) && (compareValueJ >= 0)){
            if (compareValueJ == 0) {
                if (strcmp(sortField, "yearsssssss") == 0){
                    strncpy(sortField2, "monthssssss",12);
                    cmpfct(pCalendar + i, comparator, sortField2, Sortdirection);
                    printf("comp mit sF2 %s\n",sortField2);
                    waitForEnter();
                } else if (strcmp(sortField2, "monthssssss") == 0) {
                    strncpy(sortField3, "dayssssssss", 12);
                    cmpfct(pCalendar + i, comparator, sortField3, Sortdirection);
                    printf("comp mit sF3 %s\n",sortField3);
                    waitForEnter();
                } else if (strcmp(sortField, "hoursssssss") == 0){
                    strncpy(sortField2, "minutesssss",12);
                    cmpfct(pCalendar + i, comparator, sortField2, Sortdirection);
                } else if (strcmp(sortField2, "minutesssss") == 0) {
                    strncpy(sortField3, "secondsssss", 12);
                    cmpfct(pCalendar + i, comparator, sortField3, Sortdirection);
                }
            }
            j--;
//            printf("j-- zweig raus\n");
//            waitForEnter();
        }
        if(i < j){
            swapAppointmentPointer(pCalendar + i, pCalendar + j);
            i++;
            j--;
//            printf("\nif bedninugnf!!}\n");
        }
//        printf("\nlaufvariablen: i:%d j:%d\n",i,j);
//        printf("gbhdwadguaiwodhuwiaoldhuiwaohduiaowhduiawhdiuohawudiwhidohiuadhiowhduiwd\n");
//        waitForEnter();
    }

    i--;
    swapAppointmentPointer(comparator, pCalendar + i);

    return i; //position des grenzwertes
}

void Qsort(sAppointment *pCalendar, int lowerLimit, int upperLimit, char *sortField, char *direction){
//    printf("QsortFKT\n");
    int newComperator; //der neue Grenzwert/vergleichswert nach der partitionierung

    if(lowerLimit >= upperLimit) //abbruchbedingnung der rekursion
        return;
    else{
        newComperator = partition(pCalendar, lowerLimit, upperLimit, sortField, direction);
        Qsort(pCalendar, lowerLimit            , newComperator - 1, sortField, direction); //oberer index lauf
        Qsort(pCalendar, newComperator + 1, upperLimit, sortField, direction); //unterer index lauf
    }
}

void appointmentQuickSort(sAppointment *pCalendar, int count, char *sortField, char *direction){
//    printf("appointmentQUicksortFKT\n");
    Qsort(pCalendar, 0, count - 1, sortField, direction);
}


void swapAppointmentPointer(sAppointment *pointer1, sAppointment *pointer2){
    sAppointment temp;
    temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}


// das sind meine CMPFCT(compare function) funktionen
int DateCompareFunction(sAppointment *pointer1, sAppointment *pointer2, char *sortField, char *Sortdirection){
    int result;

//    muss geaendert werden, da decreasing nicht funktioniert
//    printf("%s", Sortdirection);
    if((strcmp(Sortdirection,"decreasing")) == 0) {
//        printf("tausche");
        swapAppointmentPointer(pointer1, pointer2);
    }

    if(!strcmp(sortField, "yearsssssss"))
        result = pointer1->Date.Year - pointer2->Date.Year;
    else if(!strcmp(sortField, "monthssssss"))
        result = pointer1->Date.Month - pointer2->Date.Month;
    else if(!strcmp(sortField, "dayssssssss"))
        result = pointer1->Date.Day - pointer2->Date.Day;
    else if(!strcmp(sortField, "hoursssssss"))
        result = pointer1->Time.Hour - pointer2->Time.Hour;
    else if(!strcmp(sortField, "minutesssss"))
        result = pointer1->Time.Minute - pointer2->Time.Minute;
    else if(!strcmp(sortField, "secondsssss"))
        result = pointer1->Time.Second - pointer2->Time.Second;
    else
        result=1337;

//    printf("%d(p1) - %d(p2) = %d(erg)\n",pointer1->Date.Year,pointer2->Date.Year,result);
    return result;
}






// string comp liefert 0 wenn beide gleich, ist 1. größer bekomme ich positve ist 1. kleiner als 2. beomme ich negative zahl
// D

// Datum/Uhrzeit                    (nach datum, wenn datum gleich nach Uhrzeit)
// Dauer/Datum/Uhrzeit              (nach Dauer, wenn gleiche nach Datum, wenn gleiches nach Uhrzeit) (nach dauer und sonst 1. aufrufen)
// Bezeichnung / Datum / Uhrzeit                                                                      (nach bezeichnung und sonst 1. aufrufen)
// Ort / Datum / Uhrzeit                                                                              (nach Ort und sonst 1. aufrufen)

// irgendwie noch maxtime hinzufügen