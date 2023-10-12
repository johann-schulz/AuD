#ifndef datastructure_h
#define datastructure_h

#define MAXARTICLES 20
#define MAXAPPOINTMENTS 100


typedef enum {
    NotADay = 0,
    Mo,Tu,We,Th,Fr,Sa,Su
}eDayOfTheWeek;

typedef struct{
    int Day;
    int Month;
    int Year;
    eDayOfTheWeek DayOfWeek;
} sDate;

typedef struct {
    int Hour;
    int Minute;
    int Second;
}sTime;

typedef struct {
    sDate Date;
    sTime Time;
    char* Description;
    char* Location;
    sTime* Duration;
} sAppointment;

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
