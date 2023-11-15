#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "calendar.h"
#include "menu.h"

void inputDate();

int main()
{
    char menuTitle[] = "Terminverwaltung V 0.2";
    char *menuItems[] = {"Neuen Termin anlegen", "Termin bearbeiten", "Termin loeschen", "Termin suchen", "Termine sortieren", "Termine auflisten", "Programm beenden"};

    while (1){

        switch (getMenu(menuTitle, menuItems, 7)){
            case 1: createAppointment(); break;
            case 2: editAppointment(); break;
            case 3: deleteAppointment(); break;
            case 4: searchAppointment(); break;
            case 5: sortCalendar(); break;
            case 6: listCalendar(Calendar); break;
            case 7: freeCalendar(Calendar); exit(0);
        }
    }

    // Code from ueb_1 which is at least now not required if i understood everything right
//    do
//    {
//        clearScreen();
//        inputDate();
//    } while (askYesOrNo("Moechten Sie noch einmal (j/n) ? "));
//
//    return 0;
}

/********************************************************************
 * Funktion void inputDate(void)
 *   - Benutzer soll ein Datum eingeben.
 *   - Eingabe wird mit Hilfe der Funktion getDateFromString geparst
 *     und geprueft. Bei gueltigem Datum steht dieses in der Datums-
 *     variable Date.
 *   - Ergebnis der Eingabe wird entsprechend angezeigt.
 * Paramater: keine
 * Funktionsergebnis: nichts
 *******************************************************************/
void inputDate()
{
    sDate Date;
    char Input[20];

    printf("Geben Sie bitte ein gueltiges Datum ein: ");
    *Input = '\0';
    scanf("%19[^\n]", Input);
    clearBuffer();
    if (getDateFromString(Input, &Date))
        printf("Das Datum %02i.%02i.%04i ist gueltig!\n", Date.Day, Date.Month, Date.Year);
    else
        printf("Das eingegebene Datum '%s' ist ungueltig!\n", Input);

    printf("\n");
}