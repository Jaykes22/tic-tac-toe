#pragma once
#include "KiK.h"



    KiK::KiK(int rozmiar) {
        this->rozmiar = rozmiar;
        plansza = new char* [rozmiar]; ///alokuje pamięć na tablicę
        for (int i = 0; i < rozmiar; i++) {
            plansza[i] = new char[rozmiar];
            for (int j = 0; j < rozmiar; j++) {
                plansza[i][j] = ' '; ///inicjalizuje puste pola
            }
        }
        aktGracz = 'X';
        botOn = true;
    }
    KiK::~KiK() { ///zwalnianie pamieci
        for (int i = 0; i < rozmiar; i++) {
            delete[] plansza[i];
        }
        delete[] plansza;
    }

    void KiK::graj(int rzad, int kol) {
        if (plansza[rzad - 1][kol - 1] == ' ') {    ///sprawdzanie czy miejsce jest wolne
            plansza[rzad - 1][kol - 1] = aktGracz; ///ustawienie symbolu aktualnego gracza na polu
            ostRzad = rzad - 1;     ///zapamiętanie ostatniej pozycji symbolu (dla bota)
            ostKol = kol - 1;
            if (aktGracz == 'X') {      ///zmiana gracza
                aktGracz = 'O';
            }
            else {
                aktGracz = 'X';
            }
        }
        else {
            cout << "To pole jest zajete / nie wlasciwa komenda!" << endl;
        }
    }


    void KiK::botGraj() {      
        int rzad = ostRzad;     ///ostatnia pozycja gracza
        int kol = ostKol;
        int dx = rand() % 3 - 1;    ///losowanie odległości od gracza
        int dy = rand() % 3 - 1;
        if (rzad + dx >= 0 && rzad + dx < rozmiar && kol + dy >= 0 && kol + dy < rozmiar) { ///sprawdzenie czy pole jest w planszy
            rzad += dx;
            kol += dy;
        }
        if (plansza[rzad][kol] == ' ') {    ///sprawdza czy pole jest puste
            plansza[rzad][kol] = aktGracz;  ///ustawia symbol bota na punkcie
            if (aktGracz == 'X') { ///zmiana gracza
                aktGracz = 'O';
            }
            else {
                aktGracz = 'X';
            }
        }
    }

    bool KiK::sprWygr() {
        /// sprawdza rzedy
        for (int i = 0; i < rozmiar; i++) {
            for (int j = 0; j < 6; j++) {   ///przechodzimy po kolei od [i][j] do [i][j+4]
                if (plansza[i][j] != ' ' && plansza[i][j] == plansza[i][j + 1] && plansza[i][j + 1] == plansza[i][j + 2] && plansza[i][j + 2] == plansza[i][j + 3] && plansza[i][j + 3] == plansza[i][j + 4]) {
                    zwyciezca = plansza[i][j];
                    return true;
                }
            }
        }

        /// sprawdza kolumny
        for (int i = 0; i < rozmiar; i++) {
            for (int j = 0; j < 6; j++) {   ///przechodzimy po kolei od [i][j] do [i+4][j]
                if (plansza[j][i] != ' ' && plansza[j][i] == plansza[j + 1][i] && plansza[j + 1][i] == plansza[j + 2][i] && plansza[j + 2][i] == plansza[j + 3][i] && plansza[j + 3][i] == plansza[j + 4][i]) {
                    zwyciezca = plansza[j][i];
                    return true;
                }
            }
        }

        /// sprawdza po skosie 
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {   ///przechodzimy po kolei od [i][j] do [i+4][j+4]
                if (plansza[i][j] != ' ' && plansza[i][j] == plansza[i + 1][j + 1] && plansza[i + 1][j + 1] == plansza[i + 2][j + 2] && plansza[i + 2][j + 2] == plansza[i + 3][j + 3] && plansza[i + 3][j + 3] == plansza[i + 4][j + 4]) {
                    zwyciezca = plansza[i][j];
                    return true;
                }                           ///przechodzimy po kolei po skosie zaczynając w [i][j+4] kończąc w [i+4][j] i 
                if (plansza[i][j + 4] != ' ' && plansza[i][j + 4] == plansza[i + 1][j + 3] && plansza[i + 1][j + 3] == plansza[i + 2][j + 2] && plansza[i + 2][j + 2] == plansza[i + 3][j + 1] && plansza[i + 3][j + 1] == plansza[i + 4][j]) {
                    zwyciezca = plansza[i][j + 4];
                    return true;
                }
            
            }
        }
        return false;
    }

    char KiK::sprZwyc() {  ///zwraca zwyciezce
        return zwyciezca;   
    }


    void KiK::pokazPlansze() {
        ///wyświetla numery kolumn
        cout << "   ";
        for (int i = 1; i <= rozmiar; i++) {
            if (i < 10) {
                cout << i << "   "; ///przy <10 oddziela dłuższymi przerwami
            }
            else cout << i << "  "; ///oddiela krótszymi
        }
        cout << endl;
        ///rysuje ----------- u góry
        cout << "  ";
        for (int i = 0; i < rozmiar; i++) {
            for (int j = 0; j < 4; j++) {
                cout << "_";
            }
            cout << "";
        }
        cout << endl;
        ///rysuje kolumny
        for (int i = 0; i < rozmiar; i++) {
            if (i < 9) {
                cout << i + 1 << " |";
            }
            else cout << i + 1 << "|";
            for (int j = 0; j < rozmiar; j++) {
                cout << " " << plansza[i][j] << " |";
            }
            cout << endl;
            ///rysuje ------ pomiedzy rzędami
            cout << "  ";
            for (int j = 0; j < rozmiar; j++) {
                for (int k = 0; k < 4; k++) {
                    cout << "_";
                }
                cout << "";
            }
            cout << endl;
        }
    }

    char KiK::sprAktGracza() {///zwraca aktualnego gracza
        return aktGracz;
    }

    void KiK::ustawBotaOn(bool on) { ///załącza bota
        botOn = on;
    }

    bool KiK::czyBotOn() { ///zwraca stan bota (po rundzie sprawdzamy czy następny ruch należy do przeciwnego gracza czy bota)
        return botOn;
    }
