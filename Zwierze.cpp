#include "Zwierze.h"



Zwierze::Zwierze(char pionek, int sila, int inicjatywa, int wiek, Swiat* swiat)
:Organizm(pionek, sila, inicjatywa, wiek, swiat){

}

void Zwierze::akcja(Swiat* swiat) {
	int kierunek, wektor[2];
	while (true) {
		kierunek = wylosujKierunek();
		switch (kierunek) {
		case LEWO:
			wektor[X] = -1;
			wektor[Y] = 0;
			break;
		case PRAWO:
			wektor[X] = 1;
			wektor[Y] = 0;
			break;
		case GORA:
			wektor[X] = 0;
			wektor[Y] = 1;
			break;
		case DOL:
			wektor[X] = 0;
			wektor[Y] = -1;
			break;
		}
		//warunek do ponownego wylosowania kierunku
		break;
	}

	zmienPolozenie(wektor, swiat);
}
void Zwierze::kolizja() {

}
void Zwierze::rysowanie() {

}
Zwierze::~Zwierze() {

}