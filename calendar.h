#ifndef calendar_h
#define calendar_h
    #include "datastructure.h"

    /***************************************************************************
    *  Name: createAppointment
    *  Beschreibung: Frame for creating a new Appointment
    *  Parameter: -
    *  Ergebnis : the created appointment
    ***************************************************************************/
    sAppointment* createAppointment();

    /***************************************************************************
    *  Name: editAppointment
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis : -
    ***************************************************************************/
    void editAppointment();

    /***************************************************************************
    *  Name: deleteAppointment
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis : -
    ***************************************************************************/
    void deleteAppointment();

    /***************************************************************************
    *  Name: searchAppointment
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis : -
    ***************************************************************************/
    void searchAppointment();

    /***************************************************************************
    *  Name: sortCalendar
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis : -
    ***************************************************************************/
    void sortCalendar();

    /***************************************************************************
    *  Name: listCalendar
    *  Beschreibung: lists all Appointments in calendar
    *  Parameter: the calendar
    *  Ergebnis : -
    ***************************************************************************/
    void listCalendar(sAppointment*);

    /***************************************************************************
    *  Name: freeAppointment
    *  Beschreibung: deletes all values form provided appointment
    *  Parameter: sAppointment to be cleared
    *  Ergebnis : -
    ***************************************************************************/
    void freeAppointment(sAppointment*);

    /***************************************************************************
    *  Name: freeCalendar
    *  Beschreibung: deletes all appointments from calendar
    *  Parameter: calendar to be cleared out
    *  Ergebnis : -
    ***************************************************************************/
    void freeCalendar(sAppointment*);

#endif /* calendar_h */
