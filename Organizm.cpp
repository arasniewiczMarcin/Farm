#include "Organizm.h"

Polozenie Organizm::wylosujPolozenie(Swiat* swiat) {
	srand(time(NULL));
	int randomX, randomY;
	Polozenie p;
	while (true) {
		randomX = rand() % swiat->zwrocSzerokosc();
		randomY = rand() % swiat->zwrocWysokosc();
		if (swiat->sprawdzCzyPoleJestPuste(randomX, randomY) == true) {

			p.x = randomX;
			p.y = randomY; 
			break;
		}
	}

	
	return p;

}

Organizm::Organizm(char pionek, int sila, int inicjatywa, Swiat* swiat) {
	this->pionek = pionek;
	this->sila = sila;
	this->swiat = swiat;
	this->inicjatywa = inicjatywa;
	this->polozenie = wylosujPolozenie(swiat);
	this->swiat->dodajNaPole(this->polozenie, 'W');
	swiat->rysujSwiat();
}
Organizm::~Organizm() {
}