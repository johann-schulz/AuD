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
#include "search.h"

sHashEntry HashTable[MAXINDEX];
int countAppointments = 0;
sAppointment *First = NULL, *Last = NULL;

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

    sAppointment *appointment = malloc(sizeof(sAppointment));
    if (appointment != NULL) {
        getDate("Datum          : ", &appointment->Date);
        getTime("Uhrzeit        : ", &tempTime);
        getTime("Dauer          : ", &tempDuration);
        getText("Beschreibung   : ", 100, &tempDescription, 0);
        getText("Ort            : ", 15, &tempLocation, 1);

        appointment->Time = *tempTime;
        appointment->Duration = tempDuration;
        appointment->Description = tempDescription;
        appointment->Location = tempLocation;

        insertInDList(appointment, compareDateAndTimeIncreasing);
        if (appointment->Description) if(AppendInSList((HashTable + DivRest(appointment->Description)), appointment)) exit(EXIT_FAILURE);
        free(tempTime);

        printf("\nTermin wurde erfolgreich gespeichert!\n");
        waitForEnter();

        countAppointments++;
        return appointment;
    }
    return NULL;
}

void editAppointment() {
    printf("Edit Appointment\n");
    waitForEnter();
}

void deleteAppointment() {
    sAppointment *tmp = malloc(sizeof(sAppointment));
    if (tmp == NULL) {
        // Fehlerbehandlung: Speicherreservierung fehlgeschlagen
        return;
    }

    int choice;
    int localcount = listCalendar();
    while("für Fortnite") {
        printf("\nGib deine Auswahl ein (für Abbruch gib 0 ein): ");
        int validInput = scanf("%d", &choice);
        clearBuffer();
        if (choice == '\n') continue;

        // Validierung der Eingabe Durchführen einer Aktion je nach Eingabe
        if (validInput != 1 || choice < 0 || choice > localcount) {
            continue;
        } else if(choice == 0)
            return;
        break;
    }
    tmp = First;
    for (int j = 1; j < choice; j++){
        tmp = tmp->Next;
    }
    freeAppointment(removeListElement(tmp, compareDateAndTimeIncreasing));
    free(tmp);
    countAppointments--;
}

void searchAppointment()
    {
        if (!countAppointments)
        {
            printFunctionHeader("Search appointment by description");
            printLine('=', 77);
            PrintNewLine(1);

            printf("\n  There are no appointments to search for in the calendar! ");
            waitForEnter();
            return;
        }

        printFunctionHeader("Search appointment by description");
        printLine('=', 77);
        printf("\n\n  Please enter the description of the appointment you are looking for:\n  -> ");

        sAppointment app;
        if (!newGetText(NULL, 100, &(app.Description), 0)) exit(EXIT_FAILURE);
        sListEntry * result = searchFirst(HashTable, &app, Sort_description);
        printf("\nSearchresult:\n");
        printLine('-', strlen("Searchresult:"));
        PrintNewLine(2);
        printLine('=', 77);
        PrintNewLine(2);
        if (result)
        {
            listOneAppointment(result->Appointment);
            while (result)
            {
                result = searchNext(HashTable, result->Appointment, Sort_description);
                if (result) listOneAppointment(result->Appointment);
            }
        }
        else printf("  No appointments were found that match the search criteria ...\n\n");
        waitForEnter();
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
        tmp = First;
        while (tmp){
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
        return i;
    }

void listOneAppointment(sAppointment * app)
    {
        printf("%s, %02d.%02d.%04i\n", getAppointmentDay(app->Date.DayOfWeek), app->Date.Day, app->Date.Month, app->Date.Year);
        printLine('-', 15);
        PrintNewLine(1);

        char * end_time = NULL;
        if (app->Duration) end_time = add_time(app);
        printf("  %02d:%02d %7s -> %-15s | ", app->Time.Hour, app->Time.Minute, app->Duration ? end_time : " ", (app->Location) ? app->Location : "No location set");
        printf(((app->Description ? strlen(app->Description) : 0) < 41) ? "%-40s" : "%-.36s ...", (app->Description) ? app->Description : "No description available ...");
        PrintNewLine(2);
        if (end_time) free(end_time);
    }

char * getAppointmentDay(eDayOfTheWeek dayOfTheWeek)
    {
        switch (dayOfTheWeek)
        {
            case 1: return "Mo";
            case 2: return "Tu";
            case 3: return "We";
            case 4: return "Th";
            case 5: return "Fr";
            case 6: return "Sa";
            case 7: return "Su";
            default: return "NotADay";
        }
    }

char * add_time(sAppointment * app)
    {
        sTime t;

        t.Second = app->Time.Second + app->Duration->Second;
        t.Minute = app->Time.Minute + app->Duration->Minute;
        t.Hour = app->Time.Hour + app->Duration->Hour;

        if (t.Second >= 60) {
            t.Minute += t.Second / 60;
            t.Second %= 60;
        }

        if (t.Minute >= 60) {
            t.Hour += t.Minute / 60;
            t.Minute %= 60;
        }

        t.Hour %= 24; // Limiting the hours to a 24-hour day
        // cannot interpret if the end time is on a new day, do not know in which way I would like to implement it (+1)

        char * time = malloc(8);
        if (time)
        {
            sprintf(time, "- %02d:%02d", t.Hour, t.Minute);
            return time;
        }
        else
        {
            waitForEnter();
            exit(EXIT_FAILURE);
        }
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
        tmp = First;
        while(tmp){
            freeAppointment(tmp);
            tmp = tmp->Next;
        }
    }

void ListHashTable()
{
    if (!countAppointments) // No arms no cookies
    {
        printFunctionHeader("Hash table");

        printf("\n  As there are no appointments in the calendar, there is also no hash table! ");
        waitForEnter();
        return;
    }

    printFunctionHeader("Hash table");
    printf("  %10s | %-14s | %-7s | %-51s\n  ", "Hash value", "Date", "Time", "Appointment description");
    printLine('-', 11);
    printf("|");
    printLine('-', 16);
    printf("|");
    printLine('-', 9);
    printf("|");
    printLine('-', 52);
    PrintNewLine(1);

    for (int i = 0; i < MAXINDEX; i++)
    {
        if (HashTable[i].First)
        {
            int isHashValuePrinted = 1;
            sListEntry * lE = HashTable[i].First;
            printf("  %10d | ", i + 1);
            do
            {
                if (!isHashValuePrinted) printf("  %11s| ", "");
                else isHashValuePrinted = 0;
                printf("%s, %02d.%02d.%04d |  %02d:%02d  | ", getAppointmentDay(lE->Appointment->Date.DayOfWeek), lE->Appointment->Date.Day, lE->Appointment->Date.Month, lE->Appointment->Date.Year, lE->Appointment->Time.Hour, lE->Appointment->Time.Minute);
                printf(((lE->Appointment->Description ? strlen(lE->Appointment->Description) : 0) <= 51) ? "%-51s\n" : "%-.47s ...\n", (lE->Appointment->Description));
                lE = lE->Next;
            } while (lE);
        }
    }
    PrintNewLine(2);
    waitForEnter();
};

void printFunctionHeader(char * title)
    {
        clearScreen();
        printf("%s\n", title);
        printLine('=', strlen(title));
        PrintNewLine(2);
    }

//void chooseSortingDirection(sAppointment *calendar, int sortingTypeID){
//    signed int directionModifier = 0;
//    int (*compareFunction)(sAppointment *, sAppointment *);
//    char *menuItems[] = {"Aufsteigend sortieren",
//                         "Absteigend sortieren",
//                         "Doch lieber anders Sortieren"};
//    char *sortAfter[] = { "Hallo, hoffe du hast nen schoenen Tag :)",
//                         " Datum / Uhrzeit",
//                         " Dauer / Datum / Uhrzeit",
//                         " Bezeichnung / Datum / Uhrzeit",
//                         " Ort / Datum / Uhrzeit"};
//
//    char *title = malloc(50);
//    if (title == NULL) {
//        fprintf(stderr, "Memory allocation error in Title\n");
//        exit(EXIT_FAILURE);
//    }
//    sprintf(title, "Sortieren nach %s", sortAfter[sortingTypeID]);
//    while ("Für Fortnite") {
//        switch (getMenu(title, menuItems, 3)) {
//            case 1: directionModifier = 1; break;
//            case 2: directionModifier = -1; break;
//            case 3: sortCalendar(calendar);break;
//        }
//        break;
//    }
//
//    directionModifier = directionModifier * sortingTypeID;
//    switch (directionModifier){
//        case  1: compareFunction = compareDateAndTimeIncreasing; break;
//        case -1: compareFunction = compareDateAndTimeDecreasing; break;
//        case  2: compareFunction = compareDurationAndDateAndTimeIncreasing; break;
//        case -2: compareFunction = compareDurationAndDateAndTimeDecreasing; break;
//        case  3: compareFunction = compareDescriptionAndDateAndTimeIncreasing; break;
//        case -3: compareFunction = compareDescriptionAndDateAndTimeDecreasing; break;
//        case  4: compareFunction = compareLocationAndDateAndTimeIncreasing; break;
//        case -4: compareFunction = compareLocationAndDateAndTimeDecreasing; break;
//        default: printf("Error, please try again!");return;
//    }
//
//    quickSort(calendar, countAppointments, compareFunction);
//    char *successMsg = malloc(100);  // Adjust the size as needed
//    if (successMsg == NULL) {
//        fprintf(stderr, "Memory allocation error for successMsg\n");
//        exit(EXIT_FAILURE);
//    }
//    sprintf(successMsg, "Der Kalender wurde erfolgreich nach %s Verglichen.", sortAfter[sortingTypeID]);
//    printLine('=', strlen(successMsg));
//    puts(successMsg);
//    printLine('=', strlen(successMsg));
//    waitForEnter();
//    free(successMsg);
//    free(title);
//}