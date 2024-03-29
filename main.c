#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "calendar.h"
#include "menu.h"
#include "database.h"

extern sAppointment *First, *Last;

void inputDate();
void endProgramm();

int main()
{
    First = NULL;
    Last = NULL;
    char menuTitle[] = "Terminverwaltung V 0.2";
    char *menuItems[] = {"Neuen Termin anlegen", "Termin bearbeiten", "Termin loeschen", "Termin suchen", "Termine auflisten", "Programm beenden",};
    countAppointments=0;
    for(int i = 0; i<countAppointments; i++){
        //Calendar[i].Duration = malloc(sizeof(sTime));
    }

    loadCalendar();

    while("Für Fortnite"){
        switch (getMenu(menuTitle, menuItems, 6)){
            case 1: createAppointment(); break;
            case 2: editAppointment(); break;
            case 3: deleteAppointment(); break;
            case 4: searchAppointment(); break;
            case 5: listCalendar(); break;
            case 6: endProgramm();
        }
    }
}

/********************************************************************
 * Funktion endProgramm
 * Includes everything necessary to exit the calendar safely:
 *      - asks if changes should be safed, safes them if yes
 *      - cleans buffer for calendar content
 *      - informs the user about whats going on
 * Paramater: keine
 * Funktionsergebnis: nichts
 *******************************************************************/
void endProgramm(){
    if (askYesOrNo("Sollen die Aenderungen am Kalender gespeichert werden? [j/n]"))
        saveCalendar();
    printf("Beende...\n");
    freeCalendar();
    printf("Fertig!\n");
    exit(0);
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