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
} sAppointment;

#define MAXARTICLES 20
typedef struct{
    char *Description;
    double Amount;
    double NetPricePerUnit;
    enum KindOfTaxes {NoTax, HalfTax, FullTax} Tax;
}sArticle;

typedef struct{
    char *Customer;
    sDate Date;
    int ArticleCounter;
    sArticle Article[MAXARTICLES];
    double SumNetPrice;
    double SumTax;
    double SumGrossPrice;

}sInvoice;

extern int countAppointments;
extern sAppointment Calendar[MAXAPPOINTMENTS];

#endif /* datastructure_h */
