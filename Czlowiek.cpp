#include "Czlowiek.h"
#include <conio.h>

Czlowiek::Czlowiek(char pionek, int sila, int inicjatywa, int wiek, Swiat* swiat)
	: Zwierze(pionek, sila, inicjatywa, wiek, swiat) {
}
Czlowiek::~Czlowiek() {

}
void Czlowiek::akcja(Swiat* swiat) {
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