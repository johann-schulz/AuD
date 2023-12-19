#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "datastructure.h"
#include "calendar.h"
#include "tools.h"
#include "datetime.h"

int loadCalendar(sAppointment *calendar) {
    char line[101];
    FILE *file = fopen("calendar.xml", "rt");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    int localAppointmentCount = 0;
    sDate date;
    sTime time;
    char *description;
    char *location;
    sTime duration;
    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        char *lineStart;
        lineStart = line;
        while ((*lineStart == ' ' || *lineStart == '\t') && *lineStart != '\0') {
            lineStart++;
        }
        if ((i == 0) && (strncmp(lineStart, "<Calendar>", 10) != 0)) {
            printf("Quelldatei hat kein Format, was ausgewertet werden kann.\n");
            waitForEnter();
            fclose(file);
            return -1;
        }
        i++;

        if (strncmp(lineStart, "<Appointment>", 13) == 0) {
            localAppointmentCount++;
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

        } else if (strncmp(lineStart, "<Date>", 6) == 0) {
            unsigned len = strlen(lineStart + 6) - 7;
            if (strncmp(lineStart + 5 + len, "</Date>", 7) == 0) {
                char *tmp = malloc(sizeof(char) * len);
                if (!tmp) {
                    fclose(file);
                    return -1;
                }
                strncpy(tmp, lineStart + 6, len - 1);
                tmp[len - 1] = '\0';
                getDateFromString(tmp, &date);
                free(tmp);
            }
        } else if (strncmp(lineStart, "<Time>", 6) == 0) {
            unsigned len = strlen(lineStart + 6) - 7;
            if (strncmp(lineStart + 5 + len, "</Time>", 7) == 0) {
                char *tmp = malloc(sizeof(char) * len);
                if (!tmp) {
                    fclose(file);
                    return -1;
                }
                strncpy(tmp, lineStart + 6, len - 1);
                tmp[len - 1] = '\0';
                getTimeFromString(tmp, &time);
                free(tmp);
            }
        } else if (strncmp(lineStart, "<Description>", 13) == 0) {
            unsigned len = strlen(lineStart + 13) - 14;
            if (strncmp(lineStart + 12 + len, "</Description>", 14) == 0) {
                description = malloc(sizeof(char) * len);
                if (!description) {
                    fclose(file);
                    return -1;
                }
                strncpy(description, lineStart + 13, len - 1);
                description[len - 1] = '\0';
            }
        } else if (strncmp(lineStart, "<Location>", 10) == 0) {
            unsigned len = strlen(lineStart + 10) - 11;
            if (strncmp(lineStart + 9 + len, "</Location>", 11) == 0) {
                location = malloc(sizeof(char) * len);
                if (!location) {
                    fclose(file);
                    return -1;
                }
                strncpy(location, lineStart + 10, len - 1);
                location[len - 1] = '\0';
            }
        } else if (strncmp(lineStart, "<Duration>", 10) == 0) {
            unsigned len = strlen(lineStart + 10) - 11;
            if (strncmp(lineStart + 9 + len, "</Duration>", 11) == 0) {
                char *tmp = malloc(sizeof(char) * len);
                if (!tmp) {
                    fclose(file);
                    return -1;
                }
                strncpy(tmp, lineStart + 10, len - 1);
                tmp[len - 1] = '\0';
                getTimeFromString(tmp, &duration);
                free(tmp);
            }
        } else if (strncmp(lineStart, "</Appointment>", 14) == 0) {
            if (localAppointmentCount > 0) {
                if (countAppointments >= MAXAPPOINTMENTS) {
                    printf("Der Speicher ist voll. Es koennen keine weiteren Termine geladen werden\n");
                    fclose(file);
                    return -1;
                }
                // Speichert alle Werte im aktuellen Appointment
                calendar[countAppointments].Date = date;
                calendar[countAppointments].Time = time;
                calendar[countAppointments].Description = description;
                calendar[countAppointments].Location = location;
                if (calendar[countAppointments].Duration == NULL) {
                    // Fehler beim Speichern von Duration
                    fclose(file);
                    printf("Speicher für Duration nicht korrekt reserviert\n");
                    exit(-1);
                }
                calendar[countAppointments].Duration->Hour = duration.Hour;
                calendar[countAppointments].Duration->Minute = duration.Minute;
                calendar[countAppointments].Duration->Second = duration.Second;
                countAppointments++;
            }
        }
    }
    fclose(file);
    return 1;
}


int saveCalendar(sAppointment *calendar) {
    FILE *file = fopen("calendar.xml", "w");
    if (!file) {
        perror("Error opening/ creating file");
        return -1;
    }
    // Success if there is nothing to remove
    if (!calendar)
        return 1;

    fprintf(file, "<Calendar>\n");

    for (int i = 0; i < countAppointments; i++) {
        if (!saveAppointment(&calendar[i], file))
            break;
    }

    fprintf(file, "</Calendar>");
    fclose(file);
    return 1;
}


int saveAppointment(sAppointment *appointment, FILE *file) {
    if (appointment == NULL)
        return 0;

    fprintf(file, "\t<Appointment>\n");
    fprintf(file, "\t\t<Date>%02d.%02d.%04d</Date>\n", appointment->Date.Day, appointment->Date.Month,
            appointment->Date.Year);
    fprintf(file, "\t\t<Time>%02d:%02d:%02d</Time>\n", appointment->Time.Hour, appointment->Time.Minute,
            appointment->Time.Second);
    if (appointment->Description != NULL)
        fprintf(file, "\t\t<Description>%s</Description>\n", appointment->Description);
    if (appointment->Location != NULL)
        fprintf(file, "\t\t<Location>%s</Location>\n", appointment->Location);
    if (appointment->Duration != NULL)
        fprintf(file, "\t\t<Duration>%02d:%02d</Duration>\n", appointment->Duration->Hour,
                appointment->Duration->Minute);
    fprintf(file, "\t</Appointment>\n");

    return 1;
}
