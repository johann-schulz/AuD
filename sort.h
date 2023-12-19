//
// Created by Timsken on 16/12/2023.
//

#ifndef SORT_H
#define SORT_H
#include "datastructure.h"

/***************************************************************************
*  Name: partition
*  Beschreibung:
*  Parameter: pointer to Calendar, lowerLimit of Array, upperLimit of Array, Pointer to compare function
*  Ergebnis : -
***************************************************************************/
int partition(sAppointment *pCalendar, int lowerLimit, int upperLimit, int (*compfunction) (sAppointment *, sAppointment *));

/***************************************************************************
*  Name: Qsort
*  Beschreibung:
*  Parameter: pointer to Calendar, ID for Type of sorting
*  Ergebnis : -
***************************************************************************/
void Qsort(sAppointment *pCalendar, int lowerLimit, int upperLimit, int (*compFunction) (sAppointment *, sAppointment *));

/***************************************************************************
*  Name: quickSort
*  Beschreibung:
*  Parameter: pointer to Calendar, ID for Type of sorting
*  Ergebnis : -
***************************************************************************/
void quickSort(sAppointment *pCalendar, int count, int (*compFunction) (sAppointment *, sAppointment *));

/***************************************************************************
*  Name: swapAppointmentPointer
*  Beschreibung: lets the user decide if the calendar should be sorted increasing or decreasing
*  Parameter:
*  Ergebnis : -
***************************************************************************/
void swapAppointmentPointer(sAppointment *pointer1, sAppointment *pointer2);

/***************************************************************************
*  Name: compareDateAndTimeIncreasing
*  Beschreibung: lets the user decide if the calendar should be sorted increasing or decreasing
*  Parameter:
*  Ergebnis : -
***************************************************************************/
int compareDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2);

int compareDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2);

int compareDurationAndDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2);

int compareDurationAndDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2);

int compareDescriptionAndDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2);

int compareDescriptionAndDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2);

int compareLocationAndDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2);

int compareLocationAndDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2);



#endif //AUD_SORT_H