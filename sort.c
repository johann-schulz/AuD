#include "sort.h"
#include "datastructure.h"
#include <string.h>
#include <stdio.h>

extern sAppointment *First, *Last;

//partition englisch für aufteilen
int partition (sAppointment *pCalendar, int lowerLimit, int upperLimit, int (*compfunction) (sAppointment *, sAppointment *)) {
    sAppointment *comperator = pCalendar + lowerLimit; //comp ist der zu vergleichende grenzwert
    int i = lowerLimit + 1, j = upperLimit;

    while (i <= j) {
        // nachstes Element > *comp von links suchen (im linken Teil)
        while ((i <= j) && (compfunction (pCalendar + i, comperator) <= 0))
            i++;
        while ((j >= i) && (compfunction (pCalendar + j, comperator) >= 0))
            j--;
        if(i < j){
            swapAppointmentPointer(pCalendar + i, pCalendar + j);
            i++;
            j--;
        }
    }
    i--;
    swapAppointmentPointer(comperator, pCalendar + i);

    return i;
}

void Qsort(sAppointment *pCalendar, int lowerLimit, int upperLimit, int (*compFunction) (sAppointment *, sAppointment *)){
    int newComperator;
    if(lowerLimit >= upperLimit)
        return;
    else{
        newComperator = partition(pCalendar, lowerLimit, upperLimit, compFunction);
        Qsort(pCalendar, lowerLimit            , newComperator - 1, compFunction);
        Qsort(pCalendar, newComperator + 1, upperLimit, compFunction);
        printf("Momentan wird mit dem grenzwert verglichen: %d\nBitte haben sie etwas Geduld\n",newComperator);
    }
}

void quickSort(sAppointment *pCalendar, int count, int (*compFunction) (sAppointment *, sAppointment *)){
    Qsort(pCalendar, 0, count - 1, compFunction );
}


void swapAppointmentPointer(sAppointment *pointer1, sAppointment *pointer2){
    sAppointment temp;
    temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}

int Sort_description(sAppointment * app1, sAppointment * app2)
{
    if (app1->Description && app2->Description) // both pointers are set <==> both have descriptions
    {
        int cmp_result = text_cmp(app1->Description, app2->Description); // descriptions are checked char by char (note that upper case in ascii is < than lower case)
        if (cmp_result) return cmp_result; // if they were not equal, a value >0 is returned if the first different character in str1 was greater than in str2, a value <0 if it was less than in str2
        else // the description were equal text_cmp returned 0
        {
            cmp_result = date_cmp(app1->Date, app2->Date); // dates are checked for difference in order year > month > day
            if (cmp_result) return cmp_result; // if date1 is smaller -1 is returned, elif date1 is greater 1, in case of equality 0.
            else // case 0
            {
                cmp_result = time_cmp(app1->Time, app2->Time); // time is checked for difference in order hour > minute > second
                if (cmp_result) return cmp_result; // if time1 is smaller -1 is returned, elif time1 is greater 1, in case of equality 0.
                else return 0; // no further investigation for inequality, 0 is returned which basically count as app1 < app2 => while loop continuous to search for an app with a greater value in the sorting field
            }
        }
    }
    else if (!app1->Description && app2->Description) return -1; // no description was set for app1 => pointer is NULL => it is counted in a way that app1 is < app2
    else if (app1->Description) return 1; // no description was set for app2 => pointer is NULL => it is counted in a way that app1 is > app2
    else return 0; // no descriptions were set for apps => pointers are both NULL => it is counted in a way that app1 is = app2, which just continuous the while loop to search for a greater value in the sorting field
}

int text_cmp(char * s1, char * s2)
{
    return strcmp(s1, s2);
}

int date_cmp(sDate d1, sDate d2)
{
    int diff = int_cmp(d1.Year, d2.Year);
    if (diff) return diff;
    else
    {
        diff = int_cmp(d1.Month, d2.Month);
        if (diff) return diff;
        else
        {
            diff = int_cmp(d1.Day, d2.Day);
            if (diff) return diff;
            else return 0;
        }
    }
}

int time_cmp(sTime t1, sTime t2)
{
    int diff = int_cmp(t1.Hour, t2.Hour);
    if (diff) return diff;
    else
    {
        diff = int_cmp(t1.Minute, t2.Minute);
        if (diff) return diff;
        else
        {
            diff = int_cmp(t1.Second, t2.Second);
            if (diff) return diff;
            else return 0;
        }
    }
}

int int_cmp(int a, int b)
{
    return a - b;
}

// das sind meine CMPFCT(compare function) funktionen
int compareDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2){
    if(pointer1->Date.Year - pointer2->Date.Year != 0)
        return pointer1->Date.Year - pointer2->Date.Year;
    else if(pointer1->Date.Month - pointer2->Date.Month != 0)
        return pointer1->Date.Month - pointer2->Date.Month;
    else if(pointer1->Date.Day - pointer2->Date.Day != 0)
        return pointer1->Date.Day - pointer2->Date.Day;
    else if(pointer1->Time.Hour - pointer2->Time.Hour != 0)
        return pointer1->Time.Hour - pointer2->Time.Hour;
    else if(pointer1->Time.Minute - pointer2->Time.Minute != 0)
        return pointer1->Time.Minute - pointer2->Time.Minute;
    else //if(pointer1->Time.Second - pointer2->Time.Second != 0)
        return pointer1->Time.Second - pointer2->Time.Second;

}
int compareDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2){
    if(pointer2->Date.Year - pointer1->Date.Year != 0)
        return pointer2->Date.Year - pointer1->Date.Year;
    else if(pointer2->Date.Month - pointer1->Date.Month != 0)
        return pointer2->Date.Month - pointer1->Date.Month;
    else if(pointer2->Date.Day - pointer1->Date.Day != 0)
        return pointer2->Date.Day - pointer1->Date.Day;
    else if(pointer2->Time.Hour - pointer1->Time.Hour != 0)
        return pointer2->Time.Hour - pointer1->Time.Hour;
    else if(pointer2->Time.Minute - pointer1->Time.Minute != 0)
        return pointer2->Time.Minute - pointer1->Time.Minute;
    else //if(pointer2->Time.Second - pointer1->Time.Second  != 0)
        return pointer2->Time.Second - pointer1->Time.Second;
}

int compareDurationAndDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2){
    if(pointer1->Duration->Hour - pointer2->Duration->Hour != 0)
        return pointer1->Duration->Hour - pointer2->Duration->Hour;
    else if(pointer1->Duration->Minute - pointer2->Duration->Minute != 0)
        return pointer1->Duration->Minute - pointer2->Duration->Minute;
    else if(pointer1->Duration->Second - pointer2->Duration->Second != 0)
        return pointer1->Duration->Second - pointer2->Duration->Second;
    else
        return compareDateAndTimeIncreasing(pointer1,pointer2);
}

int compareDurationAndDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2){
    if(pointer2->Duration->Hour - pointer1->Duration->Hour != 0)
        return pointer2->Duration->Hour - pointer1->Duration->Hour;
    else if(pointer2->Duration->Minute - pointer1->Duration->Minute != 0)
        return pointer2->Duration->Minute - pointer1->Duration->Minute;
    else if(pointer2->Duration->Second - pointer1->Duration->Second != 0)
        return pointer2->Duration->Second - pointer1->Duration->Second;
    else
        return compareDateAndTimeIncreasing(pointer1,pointer2);
}

int compareDescriptionAndDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2){
    if (pointer1->Description && pointer2->Description && strcmp(pointer1->Description, pointer2->Description) != 0){
        return strcmp(pointer1->Description,pointer2->Description);
    }else {
        return compareDateAndTimeIncreasing(pointer1, pointer2);
    }
}

int compareDescriptionAndDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2){
    if (strcmp(pointer1->Description, pointer2->Description) != 0){
        return strcmp(pointer1->Description,pointer2->Description);
    }else
        return compareDateAndTimeDecreasing(pointer1,pointer2);
}

int compareLocationAndDateAndTimeIncreasing(sAppointment *pointer1, sAppointment *pointer2){
    if (pointer1->Location && pointer2->Location && strcmp(pointer1->Location, pointer2->Location) != 0 ){

        return strcmp(pointer1->Location,pointer2->Location);
    }else
        return compareDateAndTimeIncreasing(pointer1,pointer2);
}

int compareLocationAndDateAndTimeDecreasing(sAppointment *pointer1, sAppointment *pointer2){
    if (pointer1->Location && pointer2->Location && strcmp(pointer1->Location, pointer2->Location) != 0){
        return strcmp(pointer2->Location,pointer1->Location);
    }else
        return compareDateAndTimeDecreasing(pointer1,pointer2);
}

// sollten diese Funktionen in "sort.c" stehen habe ich vergessen sie in "calendar.c" zu schieben,
// ist für mein Verständniss nur einfacher gewesen

// den Sinn, dass ein Modul einen Zwiger auf eine Funktion bekommt,
// welche das Modul gar nicht kennt (ohne "#include" Anweisung) habe ich aber erkannts