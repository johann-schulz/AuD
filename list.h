#ifndef LIST_H
#define LIST_H

#include "datastructure.h"

void insertInDList(sAppointment *pAppointment, int (*cmpfct) (sAppointment *, sAppointment *));
sAppointment *removeListElement(sAppointment *Remove, int (*cmpfct)(sAppointment *, sAppointment *));

#endif