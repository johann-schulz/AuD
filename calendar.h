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
    *  Beschreibung: lets the user decide between 4 options to sort the calendar
    *  Parameter: pointer on Calendar
    *  Ergebnis : -
    ***************************************************************************/
    void sortCalendar(sAppointment *calendar);

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

    /***************************************************************************
    *  Name: chooseSortingDirection
    *  Beschreibung: lets the user decide if the calendar should be sorted increasing or decreasing
    *  Parameter: pointer to Calendar, ID for Type of sorting
    *  Ergebnis : -
    ***************************************************************************/
    void chooseSortingDirection(sAppointment *calendar, int sortingTypeID);

#endif /* calendar_h */
