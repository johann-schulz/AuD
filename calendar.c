#include <stdio.h>
#include "datastructure.h"
#include "calendar.h"
#include "tools.h"

int countAppointments = 0;
sAppointment Calendar[MAXAPPOINTMENTS];

void createAppointment() {
    printf("Create Appointment\n");
    waitForEnter();
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

void listCalendar() {
    printf("List Calendar\n");
    waitForEnter();
}
