#include "datetime.h"
#include "datastructure.h"
#include "tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLeapYear(int pYear){
    if((pYear % 4 == 0) && ((pYear % 100 != 0)||(pYear % 400 == 0))){
        return 1;
    }
    return 0;
}

int isDateValid(sDate *Date){
    int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ansYear = 0;
    int ansMonth = 0;
    int ansDay = 0;
    int leap = isLeapYear(Date -> Year);

    // Ueberprueft, ob das Jahr gueltig ist
    if(Date -> Year > 0){
        ansYear = 1;
    }
    else if(Date -> Year < 0){
        ansYear = 0;
    }

    // Ueberprueft, ob der Monat gueltig ist
    if((Date -> Month >= 1)&&(Date -> Month <= 12)){
        ansMonth = 1;
    }
    else{
        ansMonth = 0;
    }

    // Ueberprueft, ob der Tag gueltig ist
    if((Date -> Day >= 1)&&(Date -> Day <= daysPerMonth[Date -> Month - 1])){
        ansDay = 1;
    }
    else if((Date -> Month == 2)&&(leap == 1) && (Date -> Day <=29)){
        ansDay = 1;
    }
    else{
        ansDay = 0;
    }

    // Nur wenn Jahr, Monat und Tag gueltig sind, wird 1 zurueckgegeben
    if((ansYear == 1) && (ansMonth == 1) && (ansDay == 1)){
        return 1;
    }
    return 0;
}

int getDateFromString(char str[], sDate *Date){

    char day[10];
    char month[10];
    char year[10];

    char *input = str;
    char *pDay = day;
    char *pMonth = month;
    char *pYear = year;

    while((*input) && (*input != '.')){
        *pDay = *input;
        pDay++;
        input++;
    }
    *pDay = '\0';
    input++;

    while((*input) && (*input != '.')){
        *pMonth = *input;
        pMonth++;
        input++;
    }
    *pMonth = '\0';
    input++;

    while(*input){
        *pYear = *input;
        pYear++;
        input++;
    }

    int Day = atoi(day);
    int Month = atoi(month);
    int Year = atoi(year);

    Date -> Day = Day;
    Date -> Month = Month;
    Date -> Year = Year;

    int ans = isDateValid(Date);

    if (ans == 1) {
        int d = Date->Day;
        int m = (Date->Month < 3) ? Date->Month + 12 : Date->Month;
        int y = (Date->Month > 3) ? Date->Year - 1 : Date->Year;

        int h = (d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7;

        Date->DayOfWeek = h + 1;
    }

    return ans;
}

int getTimeFromString(char str[], sTime *time){
    if(str[0] == '\n'){
        return 1;
    }

    char hour[10];
    char minute[10] = "0";
    char second[10] = "0";

    char *input = str;
    char *pHour = hour;
    char *pMinute = minute;
    char *pSecond = second;

    while((*input) && (*input != ':')){
        *pHour = *input;
        pHour++;
        input++;
    }
    *pHour = '\0';
    input++;

    while((*input) && (*input != ':')){
        *pMinute = *input;
        pMinute++;
        input++;
    }
    *pMinute = '\0';
    input++;

    while(*input){
        *pSecond = *input;
        pSecond++;
        input++;
    }

    int Hour = atoi(hour);
    int Minute = atoi(minute);
    int Second = atoi(second);

    time -> Hour = Hour;
    time -> Minute = Minute;
    time -> Second = Second;

    return (Hour >= 0 && Hour < 24) &&
           (Minute >= 0 && Minute < 60) &&
           (Second >= 0 && Second < 60);
}

void getDate(char *promptMessage, sDate *datePtr){
    char input[20];

    printf("%s", promptMessage);
    do{
    scanf("%[^\n]", input);
    clearBuffer();
    getDateFromString(input, datePtr);
    if(!getDateFromString(input, datePtr)){
        printf("Kein gültiges Datum. Neuer Versuch!\n");
    }
    } while(!getDateFromString(input, datePtr));
}

void getTime(char *promptMessage, sTime **timePtr) {
    char input[20];
    sTime tempTime;
    int result = 0;

    printf("%s", promptMessage);
    do {
        fgets(input, sizeof(input), stdin);

        if(input[0] == '\n'){
            *timePtr = NULL;
            return;
        }

        result = getTimeFromString(input, &tempTime);

        if(result == 0) {
            printf("Keine gültige Zeit. Neuer Versuch!\n");
        }
    } while(result == 0);

    *timePtr = (sTime *) malloc(sizeof(sTime));
    if (*timePtr == NULL) {
        printf("Speicher konnte nicht reserviert werden.");
        exit(1);
    }
    **timePtr = tempTime;
}




void printDate(sDate date){
    printf("%02d.%02d.%04d\n", date.Day, date.Month, date.Year);
}

void printTime(sTime time){
    printf("%02d:%02d", time.Hour, time.Minute);
}

void printAppointment(sAppointment *appointment){
    printTime(appointment->Time);
    printf(" -> ");

    if (appointment->Location != NULL){
        printf("%s      | ", appointment->Location);
    }

    if(strlen(appointment->Description) > 48){
        char desc[45];
        strncpy(desc, appointment->Description, 44);
        desc[44] = '\0';
        printf("%s ...\n", desc);
    }
    else{
        printf("%s\n", appointment->Description);
    }
}

char* dayOfWeekToString(eDayOfTheWeek dayOfWeek) {
    switch (dayOfWeek) {
        case Mo:
            return "Mo";
        case Tu:
            return "Di";
        case We:
            return "Mi";
        case Th:
            return "Do";
        case Fr:
            return "Fr";
        case Sa:
            return "Sa";
        case Su:
            return "So";
        default:
            return "Uk";
    }
}

int isSameDate(sDate currentDate, sDate calendarDate){
    if(currentDate.Day == calendarDate.Day &&
       currentDate.Month == calendarDate.Month &&
       currentDate.Year == calendarDate.Year){
        return 1;
    }
    else{
        return 0;
    }
}