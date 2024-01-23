#include "datastructure.h"
#include <stdio.h>
#include <stdlib.h>
#include "datetime.h"

extern sAppointment *First, *Last;

// Funktion zum Einfügen eines Termins in die doppelt verkettete Liste
void insertInDList(sAppointment *New, int (*cmpfct) (sAppointment *, sAppointment *)) {
    sAppointment *tmp = First;

    if(New){
        if (First == NULL)
            First = Last = New;
        else if (cmpfct(First, New) >= 0){
            First->Prev = New;
            New->Next = First;
            First = New;
        }
        else if (cmpfct(Last, New) <= 0){
            New->Prev = Last;
            Last = Last->Next = New;
        }
        else{
            while (tmp->Next){
                if (cmpfct(tmp->Next, New) > 0){
                    New->Prev = tmp;
                    New->Next = tmp->Next;
                    tmp->Next->Prev = New;
                    tmp->Next = New;
                    break;
                }
                tmp = tmp->Next;
            }
        }
    }
}

// Funktion zum Entfernen eines Termins aus der doppelt verketteten Liste
sAppointment *removeListElement(sAppointment *Remove, int (*cmpfct)(sAppointment *, sAppointment *)) {
    sAppointment *tmp = First, *rmv = NULL;

    if (Remove) {
        if (First == NULL) {
            ; // Fall 1: Liste ist leer
        } else if ((*cmpfct)(First, Remove) == 0) { // Fall 2: erstes Element entfernen
            rmv = First;
            First = First->Next;
            if (First == NULL) {
                Last = NULL; // Fall 2: Sonderfall erstes Element == letztes Element
            } else {
                First->Prev = NULL;
            }
        } else if (cmpfct(Last, Remove) == 0) { // Fall 3: letztes Element entfernen
            rmv = Last;
            Last = Last->Prev;
            Last->Next = NULL;
        } else {
            while (tmp->Next) { // Fall 4: sonstiges Element entfernen
                if (cmpfct(tmp->Next, Remove) == 0) {
                    rmv = tmp->Next;
                    tmp->Next = rmv->Next;
                    tmp->Next->Prev = tmp;
                    break;
                }
                tmp = tmp->Next;
            }
        }
    }
    return rmv;
}

int AppendInSList(sHashEntry * hashEntry, sAppointment * app)
{
    if (!hashEntry || !app) return (EXIT_FAILURE);

    sListEntry * listEntry = malloc(sizeof(sListEntry));
    if (!listEntry) return printf("listEntry malloc error");
    listEntry->Appointment = app;
    listEntry->Next = NULL;

    if (!hashEntry->First)
    {
        hashEntry->First = hashEntry->Last = listEntry;
        return EXIT_SUCCESS;
    }
    else
    {
        hashEntry->Last = hashEntry->Last->Next = listEntry;
        return EXIT_SUCCESS;
    }
}

sListEntry * RemoveFromSList(sHashEntry * hashEntry, sAppointment * app)
{
    sListEntry * tmp = hashEntry->First;

    if (hashEntry->First->Appointment == app)
    {
        hashEntry->First = hashEntry->Last = NULL;
        return tmp;
    }
    else
    {
        sListEntry * previousListEntry = NULL;
        while (tmp)
        {
            /* tmp is initialized with first and that is already checked for. So in the first iteration the if condition will ALWAYS be false
             * and previousListEntry will be set to tmp, so the warnings in the if condition that tmp2 may be NULL is false */
            if (tmp->Appointment == app)
            {
                sListEntry * tmp2 = previousListEntry;
                if (tmp->Next) tmp2->Next = tmp->Next; // element is in the middle so previous one is connected with next one
                else tmp2->Next = NULL; // element is at the end so previous one is now last
                return tmp;
            }
            previousListEntry = tmp;
            tmp = tmp->Next;
        }
    }
    return NULL;
}