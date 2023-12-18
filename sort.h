//
// Created by Timsken on 16/12/2023.
//

#ifndef SORT_H
#define SORT_H
#include "datastructure.h"

int partition(sAppointment *pCalendar, int lowerLimit, int upperLimit, int (*compfunction) (sAppointment *, sAppointment *));

void Qsort(sAppointment *pCalendar, int lowerLimit, int upperLimit, int (*compFunction) (sAppointment *, sAppointment *));

void quickSort(sAppointment *pCalendar, int count, int (*compFunction) (sAppointment *, sAppointment *));

void swapAppointmentPointer(sAppointment *pointer1, sAppointment *pointer2);

int compareDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2);

int compareDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2);

#endif //AUD_SORT_H