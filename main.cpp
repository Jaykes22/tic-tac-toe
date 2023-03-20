#include "KiK.h"


int main() {

    int rzad, kol, rozmiar; ///zmienne
    char bot;

    cout << "Podaj rozmiar tablicy wiekszy lub rowny 10: ";

    cin >> rozmiar;     ///wczytujemy i ustawiamy rozmiar tablicy
    while (rozmiar < 10) {
        cout << "Wartosc musi byc wieksza lub rowna 10: ";
        cin >> rozmiar;
    }

    KiK runda(rozmiar);     ///utworzenie obiektu runda w którym będziemy prowadzić rozgrywkę
    cout << "Czy chcesz grac przeciwko botowi? t/n: "; ///ustawienie bota
    cin >> bot;
    if (bot == 'n') {
        runda.ustawBotaOn(false);
    }

    while (!runda.sprWygr()) { ///gra się toczy do momentu zwrócenia true przez metodę sprWygr
        runda.pokazPlansze();
        if (runda.sprAktGracza() == 'X') {      ///warunek jeśli ruch wykonuje gracz X (tryb jednosobowy)
            cout << "Gracz: " << runda.sprAktGracza() << ",Podaj numer rzedu (y) i kolumny(x) oddzielone spacja: ";
            cin >> rzad >> kol;
            runda.graj(rzad, kol);
        }
        else {
            if (runda.czyBotOn())       ///po rundzie sprawdzamy czy gra z botem jest aktywna, jeśli nie to następuje zmiana graczy
            {
                cout << "Komputer oblicza ruch" << endl;
                runda.botGraj();
            }
            else
            {
                cout << "Gracz " << runda.sprAktGracza() << ",Podaj numer rzedu (y) i kolumny(x) oddzielone spacja: ";
                cin >> rzad >> kol;
                runda.graj(rzad, kol);
            }
        }
    }
    runda.pokazPlansze();       ///po zakończonej rundzie jeszcze raz rysuje planszę i wyświetla komunikat końcowy
    cout << "Gracz " << runda.sprZwyc() << " Wygrywa!" << endl;
    system("pause");
    return 0;
}