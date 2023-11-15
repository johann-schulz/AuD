#ifndef datetime_h
#define datetime_h
    #include "datastructure.h"

    /***************************************************************************
    *  isLeapYear
    *  Ueberprueft ob das uebergebene Jahr ein Schaltjahr ist
    *  Parameter: - int pYear: die Jahreszahl
    *  Ergebnis : - 1 wenn pYear ein Schaltjahr ist, sonst 0
    ***************************************************************************/
    int isLeapYear(int);

    /***************************************************************************
    *  isDateValid
    *  Ueberprueft, ob das eingegebene Datum valide ist
    *  Parameter: - sDate* das Datum
    *  Ergebnis : - 1 wenn gueltig, sonst 0
    ***************************************************************************/
    int isDateValid(sDate*);

    /***************************************************************************
    *  getDateFromString
    *  liest vom Benutzer eingegebenen String ein und mach den Datentyp sDate draus
    *  Parameter: - char[]: input, sDate* pointer auf das noch leere Datum
    *  Ergebnis : - 1 wenn Datum gueltig, sonst 0
    ***************************************************************************/
    int getDateFromString(char[], sDate*);

    /***************************************************************************
    *  getTimeFromString
    *  liest vom Benutzer eingegebenen String ein und mach den Datentyp sTime draus
    *  Parameter: - char[]: input, sTime* pointer auf die noch leere Zeit
    ***************************************************************************/
    void getTimeFromString(char[], sTime*);

    /***************************************************************************
    *  Name: getDate
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis :
    ***************************************************************************/
    void getDate(char *, sDate *);

    /***************************************************************************
    *  Name: getTime
    *  Beschreibung:
    *  Parameter:
    *  Ergebnis :
    ***************************************************************************/

    void getTime(char *, sTime **);

    void printDate(sDate);

    void printTime(sTime);

    void printAppointment(sAppointment*);

    char* dayOfWeekToString(eDayOfTheWeek);

    int isSameDate(sDate, sDate);

#endif /* datetime_h */
