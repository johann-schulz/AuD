#ifndef datastructure_h
#define datastructure_h
#define MAXINDEX 307


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
typedef struct sAppointment{
    sDate Date;
    sTime Time;
    char* Description;
    char* Location;
    sTime* Duration;
    struct sAppointment *Next;
    struct sAppointment *Prev;
} sAppointment;

typedef struct sLE
{
    sAppointment * Appointment;
    struct sLE * Next;
} sListEntry;

typedef struct
{
    sListEntry * First, * Last;
} sHashEntry;

extern sHashEntry HashTable[MAXINDEX];
extern int countAppointments;
#endif /* datastructure_h */
