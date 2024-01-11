#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "calendar.h"
#include "tools.h"
#include "datetime.h"
#include "menu.h"
#include "sort.h"
#include "string.h"
#include "list.h"


int countAppointments = 0;
extern sAppointment *First = NULL, *Last = NULL;

sAppointment* createAppointment() {
    // Temporäre Zeiger
    char *tempDescription;
    char *tempLocation;
    sTime *tempTime;
    sTime *tempDuration;

//    if(countAppointments >= MAXAPPOINTMENTS){
//        printf("Der Speicher ist voll. Sie können keine weiteren Termine machen\n");
//        return NULL;
//    }

    clearScreen();
    printf("Erfassung eines neuen Termins\n");
    printLine('=', 30);
    printf("\n");

    sAppointment *appointment = NULL;
    getDate("Datum          : ", &appointment->Date);
    getTime("Uhrzeit        : ", &tempTime);
    getTime("Dauer          : ", &tempDuration);
    getText("Beschreibung   : ", 100, &tempDescription, 0);
    getText("Ort            : ", 15, &tempLocation, 1);

    appointment->Time = *tempTime;
    appointment->Duration = tempDuration;
    appointment->Description = tempDescription;
    appointment->Location = tempLocation;
    appointment->id = countAppointments;

    insertInDList(appointment, compareDateAndTimeIncreasing);

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
    sAppointment *tmp = NULL;
    int choice;
    int localcount = listCalendar();
    while("für Fortnite") {
        printf("\nGib deine Auswahl ein (für Abbruch gib 0 ein): ");
        int validInput = scanf("%d", &choice);
        clearBuffer();
        if (choice == '\n') continue;

        // Validierung der Eingabe Durchführen einer Aktion je nach Eingabe
        if (validInput != 1 || choice < 1 || choice > localcount) {
            continue;
        }
        break;
    }
    for (int j = 1; j < choice; j++){
        tmp = tmp->Next;
    }
    removeListElement(tmp, compareDateAndTimeIncreasing);
    freeAppointment(tmp);
    free(tmp);
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

int listCalendar() {
    sDate currentDate = {0, 0, 0};

    sAppointment *tmp = NULL;

    clearScreen();
    printf("Liste der Termine\n");
    printLine('=', 17);

    int i = 0;
    int j = 1;
    int k = 10;
    while (tmp = First){
        if(!isSameDate(currentDate, tmp->Date)){
            currentDate = tmp->Date;
            printLine('=', 80 + j);
            printf("%s, ", dayOfWeekToString(currentDate.DayOfWeek));
            printDate(currentDate);
            printLine('-', 15);
        }
        printf("#%d ", i+1);
        printAppointment(tmp);

        if(((i+1) % 15) == 0){
            waitForEnter();
        }
        if (((i+1)%k) == 0){
            j++;
            k = k*10;
        }
        i++;
        tmp = tmp->Next;
    }
    waitForEnter();
    return i+1;
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

void freeCalendar(){
    sAppointment *tmp = NULL;
    while(tmp = First){
        freeAppointment(tmp);
        tmp = tmp->Next;
    }
}

void chooseSortingDirection(sAppointment *calendar, int sortingTypeID){
    signed int directionModifier = 0;
    int (*compareFunction)(sAppointment *, sAppointment *);
    char *menuItems[] = {"Aufsteigend sortieren",
                         "Absteigend sortieren",
                         "Doch lieber anders Sortieren"};
    char *sortAfter[] = { "Hallo, hoffe du hast nen schoenen Tag :)",
                         " Datum / Uhrzeit",
                         " Dauer / Datum / Uhrzeit",
                         " Bezeichnung / Datum / Uhrzeit",
                         " Ort / Datum / Uhrzeit"};

    char *title = malloc(50);
    if (title == NULL) {
        fprintf(stderr, "Memory allocation error in Title\n");
        exit(EXIT_FAILURE);
    }
    sprintf(title, "Sortieren nach %s", sortAfter[sortingTypeID]);
    while ("Für Fortnite") {
        switch (getMenu(title, menuItems, 3)) {
            case 1: directionModifier = 1; break;
            case 2: directionModifier = -1; break;
            case 3: sortCalendar(calendar);break;
        }
        break;
    }

    directionModifier = directionModifier * sortingTypeID;
    switch (directionModifier){
        case  1: compareFunction = compareDateAndTimeIncreasing; break;
        case -1: compareFunction = compareDateAndTimeDecreasing; break;
        case  2: compareFunction = compareDurationAndDateAndTimeIncreasing; break;
        case -2: compareFunction = compareDurationAndDateAndTimeDecreasing; break;
        case  3: compareFunction = compareDescriptionAndDateAndTimeIncreasing; break;
        case -3: compareFunction = compareDescriptionAndDateAndTimeDecreasing; break;
        case  4: compareFunction = compareLocationAndDateAndTimeIncreasing; break;
        case -4: compareFunction = compareLocationAndDateAndTimeDecreasing; break;
        default: printf("Error, please try again!");return;
    }

    quickSort(calendar, countAppointments, compareFunction);
    char *successMsg = malloc(100);  // Adjust the size as needed
    if (successMsg == NULL) {
        fprintf(stderr, "Memory allocation error for successMsg\n");
        exit(EXIT_FAILURE);
    }
    sprintf(successMsg, "Der Kalender wurde erfolgreich nach %s Verglichen.", sortAfter[sortingTypeID]);
    printLine('=', strlen(successMsg));
    puts(successMsg);
    printLine('=', strlen(successMsg));
    waitForEnter();
    free(successMsg);
    free(title);
}