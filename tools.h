#ifndef tools_h
    #define tools_h

    /***************************************************************************
    *  clearBuffer
    *  Loescht den Tastaturpuffer
    *  Parameter: -
    *  Ergebnis : -
    ***************************************************************************/
    void clearBuffer(void);

    /***************************************************************************
    *  waitForEnter
    *  wartet auf Enter oder so
    *  Parameter: -
    *  Ergebnis : -
    ***************************************************************************/
    void waitForEnter(void);

    /***************************************************************************
    *  clearScreen
    *  Loescht alle sichtbare Ausgabe im Konsolen-Fenster
    *  Parameter: -
    *  Ergebnis : -
    ***************************************************************************/
    void clearScreen(void);

    /***************************************************************************
    *  askYesOrNo
    *  Fragt ab, ob yes oder no, validiert Benutzereingabe
    *  Parameter: *Question: Text, der gefragt werden soll
    *  Ergebnis : Gibt ja: 1 oder nein: 0 zurueck
    ***************************************************************************/
    int askYesOrNo(char *);

#endif /* tools_h */
