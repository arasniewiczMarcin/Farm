#include "Organizm.h"



int Organizm::zwrocInicjatywe() {
	return inicjatywa;
}
int Organizm::zwrocSile() {
	return sila;
}
char Organizm::zwrocPionek() {
	return pionek;
}
int Organizm::zwrocWiek() {
	return wiek;
}
Polozenie Organizm::wylosujPolozenie(Swiat* swiat) {
	srand(time(NULL));
	int randomX, randomY, randomXtoMultiply, randomYtoMultiply;
	Polozenie p;
	while (true) {
		randomXtoMultiply = (rand() % 9) + 1;
		randomYtoMultiply = (rand() % 9) + 1;
		randomX = (rand() * randomXtoMultiply) % swiat->zwrocSzerokosc();
		randomY = (rand() * randomYtoMultiply) % swiat->zwrocWysokosc();
		if (swiat->sprawdzCzyPoleJestPuste(randomX, randomY) == true) {

			p.x = randomX;
			p.y = randomY; 
			break;
		}
	}
	return p;
}
Polozenie Organizm::zwrocPolozenie() {
	return polozenie;
}
void Organizm::zmienPolozenie(int wektor[], Swiat* swiat) {

	Polozenie nowePolozenie;
	nowePolozenie.x = this->polozenie.x + wektor[X];
	nowePolozenie.y = this->polozenie.y + wektor[Y];
	if (swiat->sprawdzCzyPoleJestPuste(nowePolozenie.x, nowePolozenie.y) == true) {
		swiat->usunZPola(zwrocPolozenie());
		swiat->dodajNaPole(nowePolozenie, this->pionek);
		this->polozenie = nowePolozenie;
	}
	else {
		//kolizja
		swiat->usunZPola(zwrocPolozenie());

		this->kolizja(swiat, nowePolozenie); 

		
	}
}
int Organizm::wylosujKierunek() {
	int kierunek = ((rand() * 3) % 4) + 1;
	return kierunek;
}

Organizm::Organizm(char pionek, int sila, int inicjatywa, int wiek, Swiat* swiat) {
	this->pionek = pionek;
	this->sila = sila;
	this->swiat = swiat;
	this->inicjatywa = inicjatywa;
	this->wiek = wiek;
	this->polozenie = wylosujPolozenie(swiat);
	this->swiat->dodajNaPole(this->polozenie, pionek);
}
Organizm::~Organizm() {
}