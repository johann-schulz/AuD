#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "calendar.h"
#include "tools.h"
#include "datetime.h"


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

    printf("Erfassung eines neuen Termins\n");
    printLine('=', 30);
    printf("\n");

    sAppointment *appointment = &Calendar[countAppointments];
    getDate("Datum          : \n", &appointment->Date);
    do{
        getTime("Uhrzeit        : \n", &tempTime);
        if (tempTime == NULL){
            printf("Eine Uhrzeit muss eingegeben werden!\n");
        }
    } while(tempTime == NULL);
    getTime("Dauer          : \n", &tempDuration);
    getText("Beschreibung   : \n", 100, &tempDescription, 0);
    getText("Ort            : \n", 15, &tempLocation, 1);

    appointment->Time = *tempTime;
    appointment->Duration = tempDuration;
    appointment->Description = tempDescription;
    appointment->Location = tempLocation;

    free(tempTime);

    printf("Termin wurde erfolgreich gespeichert!\n");
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

void sortCalendar() {
    printf("Sort Calendar\n");
    waitForEnter();
}

void listCalendar(sAppointment calendar[]) {
    sDate currentDate = {0, 0, 0};
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

