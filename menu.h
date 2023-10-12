#ifndef menu_h
#define menu_h

    /***************************************************************************
    *  Name: getMenu
    *  Beschreibung: Gibt ein Menu aus, fragt den Nutzer nach seiner Auswahl und gibt diese zurück
    *  Parameter: *menuTitle: der Titel des Menus,
    *             *menuItems[] eine Liste mit allen Menu-Unterpunkten,
    *             itemCount: die Länge der Liste der Unterpunkte.
    *  Ergebnis : der ausgewählte Menupunkt als int
    ***************************************************************************/
    int getMenu(char*, char**, int);

#endif /* menu_h */
