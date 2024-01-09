#ifndef LIST_H
#define LIST_H

#include "datastructure.h"

void insertInDList(sAppointment *pAppointment, int (*cmpfct) (sAppointment *, sAppointment *));
void removeFromDList(sAppointment *pAppointment, sAppointment **pFirst, sAppointment **pLast);

#endif
