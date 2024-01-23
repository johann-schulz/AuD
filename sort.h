//
// Created by Timsken on 16/12/2023.
//

#ifndef SORT_H
#define SORT_H
#include "datastructure.h"

/***************************************************************************
*  Name: partition
*  Beschreibung: Divides the Array in two Smaller ones
*  Parameter: pointer to Calendar, lowerLimit of Array, upperLimit of Array, Pointer to the compare function
*  Ergebnis : new Value to be compared with "Grenzwert"
***************************************************************************/
int partition(sAppointment *pCalendar, int lowerLimit, int upperLimit, int (*compfunction) (sAppointment *, sAppointment *));

/***************************************************************************
*  Name: Qsort
*  Beschreibung:
*  Parameter: Part of Quicksort algorithm
*  Ergebnis : -
***************************************************************************/
void Qsort(sAppointment *pCalendar, int lowerLimit, int upperLimit, int (*compFunction) (sAppointment *, sAppointment *));

/***************************************************************************
*  Name: quickSort
*  Beschreibung:
*  Parameter: Part of Quicksort algorithm
*  Ergebnis : -
***************************************************************************/
void quickSort(sAppointment *pCalendar, int count, int (*compFunction) (sAppointment *, sAppointment *));

/***************************************************************************
*  Name: swapAppointmentPointer
*  Beschreibung: swaps the L-value of two pointers on sAppointment
*  Parameter: 2 pointer on sAppointment
*  Ergebnis : -
***************************************************************************/
void swapAppointmentPointer(sAppointment *pointer1, sAppointment *pointer2);

/***************************************************************************
*  Name: compareDateAndTimeIncreasing
*  Beschreibung: takes two pointer on sAppointment and subtracts the int value(from corresponding Sort type) of the first from the second
*  Parameter: 2 pointer on sAppointment (Appointments to compare)
*  Ergebnis : -
***************************************************************************/
int compareDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2);

/***************************************************************************
*  Name: compareDateAndTimeDecreasing
*  Beschreibung: takes two pointer on sAppointment and subtracts the int value(from corresponding Sort type) of the first from the second
*  Parameter: 2 pointer on sAppointment (Appointments to compare)
*  Ergebnis : -
***************************************************************************/
int compareDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2);

//Duration
/***************************************************************************
*  Name: compareDurationAndDateAndTimeIncreasing
*  Beschreibung: takes two pointer on sAppointment and subtracts the int value(from corresponding Sort type) of the first from the second
*  Parameter: 2 pointer on sAppointment (Appointments to compare)
*  Ergebnis : -
***************************************************************************/
int compareDurationAndDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2);

/***************************************************************************
*  Name: compareDurationAndDateAndTimeDecreasing
*  Beschreibung: takes two pointer on sAppointment and subtracts the int value(from corresponding Sort type) of the first from the second
*  Parameter: 2 pointer on sAppointment (Appointments to compare)
*  Ergebnis : -
***************************************************************************/
int compareDurationAndDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2);
//Description

/***************************************************************************
*  Name: compareDurationAndDateAndTimeDecreasing
*  Beschreibung: takes two pointer on sAppointment and compares the specific Strings(from corresponding Sort type) with strcmp
*  Parameter: 2 pointer on sAppointment
*  Ergebnis : -
***************************************************************************/
int compareDescriptionAndDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2);

/***************************************************************************
*  Name: compareDurationAndDateAndTimeDecreasing
*  Beschreibung: takes two pointer on sAppointment and compares the specific Strings(from corresponding Sort type) with strcmp
*  Parameter: 2 pointer on sAppointment
*  Ergebnis : -
***************************************************************************/
int compareDescriptionAndDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2);

//location
/***************************************************************************
*  Name: compareDurationAndDateAndTimeDecreasing
*  Beschreibung: takes two pointer on sAppointment and compares the specific Strings(from corresponding Sort type) with strcmp
*  Parameter: 2 pointer on sAppointment
*  Ergebnis : -
***************************************************************************/
int compareLocationAndDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2);

/***************************************************************************
*  Name: compareDurationAndDateAndTimeDecreasing
*  Beschreibung: takes two pointer on sAppointment and compares the specific Strings(from corresponding Sort type) with strcmp
*  Parameter: 2 pointer on sAppointment
*  Ergebnis : -
***************************************************************************/
int compareLocationAndDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2);
int int_cmp(int a, int b);
int time_cmp(sTime t1, sTime t2);
int date_cmp(sDate d1, sDate d2);
int text_cmp(char * s1, char * s2);
int Sort_description(sAppointment * app1, sAppointment * app2);



#endif //AUD_SORT_H