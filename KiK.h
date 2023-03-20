#pragma once
#include <iostream>
using namespace std;

class KiK {
private:
    char** plansza;    ///tablica 2D reprezentująca planszę
    char aktGracz;    ///aktualny gracz///
    char zwyciezca;  ///zwyciezca gry//
    int ostRzad;    ///ostatni rząd w jakim został postawiony symbol
    int ostKol;     ///ostatnia kolumna w jakiej został postawiony symbol
    bool botOn;     ///ustawienie bota
    int rozmiar;    ///rozmiar planszy

public:                                 ///konstruktor domyślny, alokuje pamięć na planszę i inicjalizuje puste pola
    KiK(int rozmiar);                   ///destruktor zwalniający pamieć po tablicy
    ~KiK();                             ///metoda odpowiadająca za ustawiane symbolu na planszy
    void graj(int rzad, int kol);       ///metoda która na podstawie ostatniego ruchu gracza ustawia przeciwny symbol w pobliżu
    void botGraj();                     ///sprawdza rzędy, kolumny i skosy w celu znalezienia 5 symboli pod rząd
    bool sprWygr();                     ///zwraca zwyciezce
    char sprZwyc();                     ///rysuje planszę oraz numery rzędów i kolumn na tej planszy
    void pokazPlansze();                ///zwraca aktualnego gracza
    char sprAktGracza();                ///ustawia bota na true
    void ustawBotaOn(bool on);          ///metoda pomocnicza sprawdza po rundzie czy bot jest włączony
    bool czyBotOn();                

};
