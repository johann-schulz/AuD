//
// Created by Timsken on 16/12/2023.
//

#ifndef SORT_H
#define SORT_H
#include "datastructure.h"
#include "string.h"

int partition(sAppointment *pCalendar, int lowerLimit, int upperLimit, char *, char *);

void Qsort(sAppointment *pCalendar, int lowerLimit, int upperLimit, char *, char *);

void appointmentQuickSort(sAppointment *pCalendar, int count, char *, char *);

void swapAppointmentPointer(sAppointment *pointer1, sAppointment *pointer2);

int cmpfct(sAppointment *pointer1, sAppointment *pointer2, char *sortField, char *Sortdirection);


#endif //AUD_SORT_H
