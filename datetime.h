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

#endif /* datetime_h */
