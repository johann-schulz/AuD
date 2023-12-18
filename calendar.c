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
            case 1: sortDateTime(calendar); break;
            case 2: editAppointment(); break;
            case 3: deleteAppointment(); break;
            case 4: searchAppointment(); break;
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

void sortDateTime(sAppointment *pCalendar){
    int true=1;
    char *sortField = malloc(12);
    char *sortDirection = malloc(11);
    if (sortDirection == NULL || sortField == NULL ) {
        fprintf(stderr, "Memory allocation failed.\n");
        //add Exit with an error code
    }
    char *menuItems[] = {"aufsteigend sortieren", "absteigend sortieren", "Doch nichts sortieren"};
    while(true){
        switch (getMenu("Sort after Date / Time" , menuItems, 3)){
            case 1: strcpy(sortDirection, "increasing");true=0; break;
            case 2: strcpy(sortDirection, "decreasing");true=0; break;
            case 3: return;
        }
    }

    strncpy(sortField, "yearsssssss",12);// umaendern, wenn year nicht ausreicht
    appointmentQuickSort(pCalendar, countAppointments, sortField, sortDirection);
    printf("\nArray elements: ");
    for (int i = 0; i < countAppointments; i++) {
        printf("%d ", pCalendar[i].Date.Year);
    }



    //waitForEnter();
    free(sortDirection);
    free(sortField);

}