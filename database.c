#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "datastructure.h"
#include "calendar.h"
#include "tools.h"
#include "datetime.h"

int loadCalendar(sAppointment*Calendar) {
    sAppointment calendar[MAXAPPOINTMENTS];
    char line[101];
    FILE* file = fopen("calendar.xml", "rt");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    int appointmentCount = -1;
    sDate date;
    sTime time;
    char* description;
    char* location;
    sTime duration;

    while (fgets(line, sizeof(line), file) != NULL) {
        char* lineStart;
        lineStart = line;
        while ((*lineStart == ' ' || *lineStart == '\t') && *lineStart != '\0') {
            lineStart++;
        }

        if (strncmp(lineStart, "<Appointment>", 13) == 0) {
            if (appointmentCount >= MAXAPPOINTMENTS) {
                printf("Der Speicher ist voll. Es koennen keine weiteren Termine geladen werden\n");
                return -1;
            }
            appointmentCount++;
            // Initialisiere die Zeiger mit leeren Strings
            date.Day = 0;
            date.Month = 0;
            date.Year = 0;
            time.Hour = 0;
            time.Minute = 0;
            time.Second = 0;
            description = NULL;
            location = NULL;
            duration.Hour = 0;
            duration.Minute = 0;
            duration.Second = 0;

        }
        else if (strncmp(lineStart, "<Date>", 6) == 0) {
            unsigned len = strlen(lineStart + 6) - 7;
            if (strncmp(lineStart + 6 + len, "</Date>", 7) == 0) {
                char* tmp = malloc(sizeof(char) * (len + 1));
                if (!tmp)
                    return -1;
                strncpy(tmp, lineStart + 6, len);
                tmp[len] = '\0';
                getDateFromString(tmp, &date);
                free(tmp);
            }
        }
        else if (strncmp(lineStart, "<Time>", 6) == 0) {
            unsigned len = strlen(lineStart + 6) - 7;
            if (strncmp(lineStart + 6 + len, "</Time>", 7) == 0) {
                char* tmp = malloc(sizeof(char) * (len + 1));
                if (!tmp)
                    return -1;
                strncpy(tmp, lineStart + 6, len);
                tmp[len] = '\0';
                getTimeFromString(tmp, &time);
                free(tmp);
            }
        }
        else if (strncmp(lineStart, "<Description>", 13) == 0) {
            unsigned len = strlen(lineStart + 13) - 14;
            if (strncmp(lineStart + 13 + len, "</Description>", 14) == 0) {
                description = malloc(sizeof(char) * (len + 1));
                if (!description)
                    return -1;
                strncpy(description, lineStart + 13, len);
                description[len] = '\0';
            }
        }
        else if (strncmp(lineStart, "<Location>", 10) == 0) {
            unsigned len = strlen(lineStart + 10) - 11;
            if (strncmp(lineStart + 10 + len, "</Location>", 11) == 0) {
                location = malloc(sizeof(char) * (len + 1));
                if (!location)
                    return -1;
                strncpy(location, lineStart + 10, len);
                location[len] = '\0';
            }
        }
        else if (strncmp(lineStart, "<Duration>", 10) == 0) {
            unsigned len = strlen(lineStart + 10) - 11;
            if (strncmp(lineStart + 10 + len, "</Duration>", 11) == 0) {
                char* tmp = malloc(sizeof(char) * (len + 1));
                if (!tmp)
                    return -1;
                strncpy(tmp, lineStart + 10, len);
                tmp[len] = '\0';
                getTimeFromString(tmp, &duration);
                free(tmp);
            }
        }
        else if (strncmp(lineStart, "</Appointment>", 14) == 0) {
            // Speichert alle Werte im aktuellen Appointment
            if (appointmentCount >= 0) {
                calendar[appointmentCount].Date = date;
                calendar[appointmentCount].Time = time;
                calendar[appointmentCount].Description = description;
                calendar[appointmentCount].Location = location;
                calendar[appointmentCount].Duration = &duration;
            }
        }
    }
    listCalendar(calendar);
    fclose(file);
    return 1;
}

