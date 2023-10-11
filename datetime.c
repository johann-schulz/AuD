#include "datetime.h"
#include "datastructure.h"
#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int pYear){
    int ans = 0;

    if((pYear % 4 == 0) && ((pYear % 100 != 0)||(pYear % 400 == 0))){
        ans = 1;
    }
    else{
        ans = 0;
    }
    return ans;
}

int isDateValid(sDate *Date){
    int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ans = 0;
    int ansYear = 0;
    int ansMonth = 0;
    int ansDay = 0;
    int leap = isLeapYear(Date -> Year);

    if(Date -> Year > 0){
        ansYear = 1;
    }
    else if(Date -> Year < 0){
        ansYear = 0;
    }

    if((Date -> Month >= 1)&&(Date -> Month <= 12)){
        ansMonth = 1;
    }
    else{
        ansMonth = 0;
    }

    if((Date -> Day >= 1)&&(Date -> Day <= daysPerMonth[Date -> Month - 1])){
        ansDay = 1;
    }
    else if((Date -> Month == 2)&&(leap == 1)){
        ansDay = 1;
    }
    else{
        ansDay = 0;
    }

    if((ansYear == 1) && (ansMonth == 1) && (ansDay == 1)){
        ans = 1;
    }
    else{
        ans = 0;
    }

    return ans;
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


    return ans;
}
