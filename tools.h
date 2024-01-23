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

    /***************************************************************************
    *  printLine
    *  prints char int times in one line, ends with \n
    *  Parameter:
    *  Ergebnis : -
    ***************************************************************************/
    void printLine(char, int);

    /***************************************************************************
    *  getText
    *  get text from user
    *  Parameter: as for text with char* message with the maximum length of int max
    *  to be written into **Pointer with the option to set AllowEmpty to 1
    *  which makes it possible to skip the input
    *  Ergebnis : true or false (success or fail)
    ***************************************************************************/
    int getText (char *, unsigned , char **, int);

    /***************************************************************************
    *  ToUpper
    *  Converts a lower case character to a upper case character.
    *  Parameter:
    *      - c: The lower case character which is to be changed to upper case
    *         and returned.
    *  Result: Returns the as parameter given lower case char as upper case or
    *     0 if the parameter given was not a lower case character (ascii 97-122).
    ***************************************************************************/
    char ToUpper(char c);

    void PrintNewLine(unsigned short count);
    int newGetText(char* prompt, int maxLen, char** text, int isEmptyInputAllowed);

#endif /* tools_h */
