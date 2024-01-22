#ifndef DATABASE_H
#define DATABASE_H
#include "datastructure.h"

    /***************************************************************************
    *  Name: loadCalendar
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis : -
    ***************************************************************************/
    int loadCalendar();

    /***************************************************************************
    *  Name: saveCalendar
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis : -
    ***************************************************************************/
    int saveCalendar();

    /***************************************************************************
    *  Name: saveAppointment
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis : -
    ***************************************************************************/
    int saveAppointment(sAppointment *, FILE*);

#endif //DATABASE_H
