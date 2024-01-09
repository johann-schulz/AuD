#include "datastructure.h"
#include "list.h"
#include "sort.h"
#include "calendar.c"

// Funktion zum Einfügen eines Termins in die doppelt verkettete Liste
void insertInDList(sAppointment *New, int (*cmpfct) (sAppointment *, sAppointment *)) {
    sAppointment *tmp = First;

    if(New){
        if (First == NULL)
            First = Last = New;
        else if (cmpfct(Last, New) >= 0){
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
void removeFromDList(sAppointment *pAppointment, sAppointment **pFirst, sAppointment **pLast) {
    // Implementierung des Entfernens
}