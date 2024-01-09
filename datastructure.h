#ifndef datastructure_h
#define datastructure_h


#define MAXAPPOINTMENTS 100

// Beinhaltet alle Wochentage nummeriert: 0 ist kein Wochentag, 1 ist Montag, 2 ist Dienstag usw.
typedef enum {
    NotADay = 0,
    Mo,Tu,We,Th,Fr,Sa,Su
}eDayOfTheWeek;

// Ein Datum besteht aus Tag, Monat, Jahr und Wochentag
typedef struct{
    int Day;
    int Month;
    int Year;
    eDayOfTheWeek DayOfWeek;
} sDate;

// Zeit besteht aus Stunde, Minute und Sekunde
typedef struct {
    int Hour;
    int Minute;
    int Second;
}sTime;

// Ein Termin besteht aus Datum, Uhrzeit, Beschreibung, Ort und Dauer
typedef struct {
    sDate Date;
    sTime Time;
    char* Description;
    char* Location;
    sTime* Duration;
    struct sAppointment *Next;
    struct sAppointment *Prev;
} sAppointment;

extern int countAppointments;
extern sAppointment Calendar[MAXAPPOINTMENTS];

#endif /* datastructure_h */
