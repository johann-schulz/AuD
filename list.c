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
