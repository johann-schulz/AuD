#ifndef calendar_h
#define calendar_h
    #include "datastructure.h"

    /***************************************************************************
    *  Name: createAppointment
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis :
    ***************************************************************************/
    sAppointment* createAppointment();

    /***************************************************************************
    *  Name: editAppointment
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis :
    ***************************************************************************/
    void editAppointment();

    /***************************************************************************
    *  Name: deleteAppointment
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis :
    ***************************************************************************/
    void deleteAppointment();

    /***************************************************************************
    *  Name: searchAppointment
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis :
    ***************************************************************************/
    void searchAppointment();

    /***************************************************************************
    *  Name: sortCalendar
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis :
    ***************************************************************************/
    void sortCalendar();

    /***************************************************************************
    *  Name: listCalendar
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis :
    ***************************************************************************/
    void listCalendar(sAppointment *);

    void freeAppointment(sAppointment*);

    void freeCalendar(sAppointment*);

#endif /* calendar_h */
