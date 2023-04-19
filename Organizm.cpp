#include "Organizm.h"

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