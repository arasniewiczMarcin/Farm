#include "Czlowiek.h"
#include <conio.h>

Czlowiek::Czlowiek(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie)
	: Zwierze(pionek, sila, inicjatywa, ruch, swiat, polozenie) {
   ustaw();
}
Czlowiek::~Czlowiek() {

}
void Czlowiek::ustaw() {
    this->ustawCzasOdnowieniaUmiejetnosciC(0);
    this->ustawCzasTrwaniaUmiejetnosciC(5);
    this->ustawUmiejetnoscC(false);
}

void Czlowiek::akcja(Swiat* swiat) {
    srand(time(NULL));
    int licznikRuchow = 1;
    if (this->zwrocUmiejetnoscC() == true) {
        if(this->zwrocCzasTrwaniaUmiejetnosciC() > 2)
            licznikRuchow = 2;
        else if (this->zwrocCzasTrwaniaUmiejetnosciC() <= 2 &&
            this->zwrocCzasTrwaniaUmiejetnosciC() > 0) {

            int szansa = rand() % 2;
            if (szansa == 1)licznikRuchow = 2;
            else licznikRuchow = 1;
        }
        this->zmniejszCzasTrwaniaUmiejetnosciC();
    }
    if(czasOdnowieniaUmiejetnosciC > 0)
        this->zmniejszCzasOdnowieniaUmiejetnosciC();

    for (int i = 0; i < licznikRuchow; i++) {
        swiat->rysujSwiat();
        char arrow1 = ' ', arrow2 = ' ';
        int wektor[2];
        cout << "Wybierz kierunek ruchu czlowieka przy uzyciu strzalek" << endl;
        while (true) {
            arrow1 = _getch();
            if (arrow1 != ARROW)continue;
            arrow2 = _getch();
            if (arrow2 == ARROW_UP || arrow2 == ARROW_DOWN || arrow2 == ARROW_LEFT || arrow2 == ARROW_RIGHT)break;
        }

        switch (arrow2) {
        case ARROW_UP:
            wektor[X] = 0;
            wektor[Y] = -1;
            break;
        case ARROW_DOWN:
            wektor[X] = 0;
            wektor[Y] = 1;
            break;
        case ARROW_RIGHT:
            wektor[X] = 1;
            wektor[Y] = 0;
            break;
        case ARROW_LEFT:
            wektor[X] = -1;
            wektor[Y] = 0;
            break;
        }
        zmienPolozenie(wektor, swiat);
    }
    
}