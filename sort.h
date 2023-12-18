//
// Created by Timsken on 16/12/2023.
//

#ifndef SORT_H
#define SORT_H
#include "datastructure.h"

int partition(sAppointment *array, int lowerLimit, int upperLimit, int (*compfunction) (sAppointment *, sAppointment *));

void Qsort(sAppointment *array, int lowerLimit, int upperLimit, int (*compFunction) (sAppointment *, sAppointment *));

void quickSort(sAppointment *array, int count, int (*compFunction) (sAppointment *, sAppointment *));

void swapAppointmentPointer(sAppointment *pointer1, sAppointment *pointer2);

int compareYears(sAppointment *pointer1, sAppointment *pointer2);

int compareMonths(sAppointment *pointer1, sAppointment *pointer2);

int compareDays(sAppointment *pointer1, sAppointment *pointer2);

#endif //AUD_SORT_H