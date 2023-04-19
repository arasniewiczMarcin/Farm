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
		if (polozenie.x + wektor[X] < 0 || polozenie.x + wektor[X] >= swiat->zwrocSzerokosc() ||
			polozenie.y + wektor[Y] < 0 || polozenie.y + wektor[Y] >= swiat->zwrocWysokosc())
			continue; 
		//warunek do ponownego wylosowania kierunku
		else break;
	}

	zmienPolozenie(wektor, swiat);
}

void Zwierze::walka(Zwierze* atakujacy, Organizm* broniacy) {
	if (atakujacy->sila >= broniacy->zwrocSile()) {
		//wygrana i atakujacy dostaje nowe polozenie
		atakujacy->polozenie = broniacy->zwrocPolozenie();
		//usunOrganizm(broniacy);
	}
	else if (atakujacy->sila < broniacy->zwrocSile()) {
		//przegrana
		//usunOrganizm(atakujacy);
		//usunZPola(atakujacy)

	}
}

void Zwierze::kolizja(Swiat* swiat, Polozenie miejsceKolizji) {
	if (this->pionek == swiat->zwrocPole(miejsceKolizji.x, miejsceKolizji.y)) {
		//rozmnazanie
		//rozmnazanie(this->pionek, swiat);
	}
	else {
		//walka
		walka(this, swiat->zwrocOrganizm(miejsceKolizji));
	}
}
void Zwierze::rysowanie() {

}
Zwierze::~Zwierze() {

}