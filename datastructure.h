#ifndef datastructure_h
#define datastructure_h

#define MAXARTICLES 20

typedef struct{
    int Day;
    int Month;
    int Year;
} sDate;

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

#endif /* datastructure_h */
