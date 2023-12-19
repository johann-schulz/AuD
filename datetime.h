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
    int getTimeFromString(char[], sTime*);

    /***************************************************************************
    *  Name: getDate
    *  Beschreibung: asks message and expects properly formatted and valid date
    *  Parameter: char * message, sDate to write into
    *  Ergebnis : -
    ***************************************************************************/
    void getDate(char *, sDate *);

    /***************************************************************************
    *  Name: getTime
    *  Beschreibung: asks message and expects properly formatted and valid time
    *  Parameter: char * message, sDate to write into
    *  Ergebnis : -
    ***************************************************************************/
    void getTime(char *, sTime **);

    /***************************************************************************
    *  Name: printDate
    *  Beschreibung:used as a workaround to using a lot of format flags when printing a date
    *  Parameter: the Date to be displayed
    *  Ergebnis : -
    ***************************************************************************/
    void printDate(sDate);

    /***************************************************************************
    *  Name: printTime
    *  Beschreibung: used as a workaround to using a lot of format flags when printing a time
    *  Parameter: the Time to be displayed
    *  Ergebnis : -
    ***************************************************************************/
    void printTime(sTime);

    /***************************************************************************
    *  Name: printAppointment
    *  Beschreibung: prints Time, Location if it exists and Description cut after 44 characters
    *  if string is longer than 48 chars
    *  Parameter: sAppointment containing data to be displayed
    *  Ergebnis : -
    ***************************************************************************/
    void printAppointment(sAppointment*);

    /***************************************************************************
    *  Name: dayOfWeekToString
    *  Beschreibung: returns string with short form for Day of the week depending on the enums value.
    *  Purpose is to convert english code to german expression.
    *  Parameter: enum with value
    *  Ergebnis : char* with Mo/ Di/ Mi etc.
    ***************************************************************************/
    char* dayOfWeekToString(eDayOfTheWeek);

    /***************************************************************************
    *  Name: isSameDate
    *  Beschreibung: Checks if Day, Month and Year of two sDate are the same, returns 1 if yes
    *  Parameter: two sDate to be compared
    *  Ergebnis : false or true
    ***************************************************************************/
    int isSameDate(sDate, sDate);

    sTime calculateEndTime(sAppointment *);
#endif /* datetime_h */
