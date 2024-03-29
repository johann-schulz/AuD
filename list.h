#ifndef LIST_H
#define LIST_H

#include "datastructure.h"

void insertInDList(sAppointment *New, int (*cmpfct) (sAppointment *, sAppointment *));
sAppointment *removeListElement(sAppointment *Remove, int (*cmpfct)(sAppointment *, sAppointment *));
int AppendInSList(sHashEntry * hashEntry, sAppointment * app);
sListEntry * RemoveFromSList(sHashEntry * hashEntry, sAppointment * app);


#endif
