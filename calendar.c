#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "calendar.h"
#include "tools.h"
#include "datetime.h"
#include "menu.h"
#include "sort.h"


int countAppointments = 0;
sAppointment Calendar[MAXAPPOINTMENTS];

sAppointment* createAppointment() {
    // Temporäre Zeiger
    char *tempDescription;
    char *tempLocation;
    sTime *tempTime;
    sTime *tempDuration;

    if(countAppointments >= MAXAPPOINTMENTS){
        printf("Der Speicher ist voll. Sie können keine weiteren Termine machen\n");
        return NULL;
    }

    clearScreen();
    printf("Erfassung eines neuen Termins\n");
    printLine('=', 30);
    printf("\n");

    sAppointment *appointment = &Calendar[countAppointments];
    getDate("Datum          : ", &appointment->Date);
    getTime("Uhrzeit        : ", &tempTime);
    getTime("Dauer          : ", &tempDuration);
    getText("Beschreibung   : ", 100, &tempDescription, 0);
    getText("Ort            : ", 15, &tempLocation, 1);

    appointment->Time = *tempTime;
    appointment->Duration = tempDuration;
    appointment->Description = tempDescription;
    appointment->Location = tempLocation;

    free(tempTime);

    printf("\nTermin wurde erfolgreich gespeichert!\n");
    waitForEnter();

    countAppointments++;
    return appointment;
}

void editAppointment() {
    printf("Edit Appointment\n");
    waitForEnter();
}

void deleteAppointment() {
    printf("Delete Appointment\n");
    waitForEnter();
}

void searchAppointment() {
    printf("Search Appointment\n");
    waitForEnter();
}

void sortCalendar(sAppointment *calendar) {
    char menuTitle[] = "Termine sortieren nach:";
    char *menuItems[] = {"Datum / Uhrzeit",
                         "Dauer / Datum / Uhrzeit",
                         "Bezeichnung / Datum / Uhrzeit",
                         "Ort / Datum / Uhrzeit",
                         "zurueck zum Hauptmenue"};

    while("Für Fortnite"){
        switch (getMenu(menuTitle, menuItems, 5)){
            case 1: chooseSortingDirection(calendar,1); break;
            case 2: chooseSortingDirection(calendar,2); break;
            case 3: chooseSortingDirection(calendar,3); break;
            case 4: chooseSortingDirection(calendar,4); break;
            case 5: return;
        }
    }
}

void listCalendar(sAppointment *calendar) {
    sDate currentDate = {0, 0, 0};

    clearScreen();
    printf("Liste der Termine\n");
    printLine('=', 17);


    for(int i = 0; i < countAppointments; i++){
        if(!isSameDate(currentDate, calendar[i].Date)){
            currentDate = calendar[i].Date;
            printLine('=', 78);
            printf("%s, ", dayOfWeekToString(currentDate.DayOfWeek));
            printDate(currentDate);
            printLine('-', 15);
        }
        printAppointment(&calendar[i]);

        if(((i+1) % 15) == 0){
            waitForEnter();
        }
    }

    waitForEnter();
}

void freeAppointment(sAppointment *appointment) {
    if (appointment == NULL) {
        return;
    }

    if (appointment->Description != NULL) {
        free(appointment->Description);
        appointment->Description = NULL;
    }

    if (appointment->Location != NULL) {
        free(appointment->Location);
        appointment->Location = NULL;
    }

    if (appointment->Duration != NULL) {
        free(appointment->Duration);
        appointment->Duration = NULL;
    }
}

void freeCalendar(sAppointment *calendar){
    for(int i = 0; i < countAppointments; i++){
        freeAppointment(&calendar[i]);
    }
}

void chooseSortingDirection(sAppointment *pCalendar, short sortingTypeID) {
    signed int directionModifier = 0;

    char *menuItems[] = {"Aufsteigend sortieren",
                         "Absteigend sortieren",
                         "zurueck zum Hauptmenue"};

    int (*compareFunction)(sAppointment *, sAppointment *);
    char *sortAfter[] = { "Hallo, hoffe du hast nen shcönen Tag :)",
                         "Sortieren nach Datum / Uhrzeit",
                         "Sortieren nach Dauer / Datum / Uhrzeit",
                         "Sortieren nach Bezeichnung / Datum / Uhrzeit",
                         "Sortieren nach Ort / Datum / Uhrzeit"};

    while ("Für Fortnite") {
        switch (getMenu(sortAfter[sortingTypeID], menuItems, 3)) {
            case 1:
                directionModifier = 1;
                break;
            case 2:
                directionModifier = -1;
                break;
            case 3:
                return;
        }
        break;
    }

    directionModifier = directionModifier * sortingTypeID;
    switch (directionModifier){
        case  0: return;
        case  1: compareFunction = compareDateAndTimeIncreasing; break;
        case -1: compareFunction = compareDateAndTimeDecreasing; break;
        case  2: compareFunction = compareDurationAndDateAndTimeIncreasing; break;
        case -2: compareFunction = compareDurationAndDateAndTimeDecreasing; break;
        case  3: compareFunction = compareDescriptionAndDateAndTimeIncreasing; break;
        case -3: compareFunction = compareDescriptionAndDateAndTimeDecreasing; break;
        case  4: compareFunction = compareLocationAndDateAndTimeIncreasing; break;
        case -4: compareFunction = compareLocationAndDateAndTimeDecreasing; break;
    }

    quickSort(pCalendar, countAppointments, compareFunction);

    return;
}