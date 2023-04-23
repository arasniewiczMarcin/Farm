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
Polozenie Organizm::zwrocPolozenie() {
	return polozenie;
}
void Organizm::ustawSile(int sila) {
	this->sila = sila;
}
void Organizm::ustawPolozenie(Polozenie nowePolozenie) {
	this->polozenie.x = nowePolozenie.x;
	this->polozenie.y = nowePolozenie.y;
}

void Organizm::stworzWektor(int wektor[2], int kierunek) {
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
}

void Organizm::zmienPolozenie(int wektor[], Swiat* swiat) {

	Polozenie nowePolozenie;
	if (this->polozenie.x + wektor[X] >= 0 && this->polozenie.x + wektor[X] < swiat->zwrocSzerokosc() &&
		this->polozenie.y + wektor[Y] >= 0 && this->polozenie.y + wektor[Y] < swiat->zwrocWysokosc()) {
		nowePolozenie.x = this->polozenie.x + wektor[X];
		nowePolozenie.y = this->polozenie.y + wektor[Y];
		if (swiat->sprawdzCzyPoleJestPuste(nowePolozenie.x, nowePolozenie.y) == true) {
			this->polozenie = nowePolozenie;
		}
		else {
			//kolizja
			this->kolizja(swiat, nowePolozenie);
		}
	}
}
bool Organizm::zwrocRuch() {
	return ruch;
}
void Organizm::ustawRuch(bool ruch) {
	this->ruch = ruch;
}
void Organizm::ustawUmiejetnoscC(bool wlaczona) {
	this->umiejetnoscWlaczonaC = wlaczona;
}
void Organizm::zmniejszCzasOdnowieniaUmiejetnosciC() {
	this->czasOdnowieniaUmiejetnosciC--;
}
void Organizm::zmniejszCzasTrwaniaUmiejetnosciC() {
	this->czasTrwaniaUmiejetnosciC--;
}
void Organizm::ustawCzasOdnowieniaUmiejetnosciC(int czas) {
	this->czasOdnowieniaUmiejetnosciC = czas;
}
void Organizm::ustawCzasTrwaniaUmiejetnosciC(int czas) {
	this->czasTrwaniaUmiejetnosciC = czas;
}
int Organizm::zwrocCzasOdnowieniaUmiejetnosciC() {
	return czasOdnowieniaUmiejetnosciC;
}
int Organizm::zwrocCzasTrwaniaUmiejetnosciC() {
	return czasTrwaniaUmiejetnosciC;
}
bool Organizm::zwrocUmiejetnoscC() {
	return umiejetnoscWlaczonaC;
}
int Organizm::wylosujKierunek() {
	int kierunek = ((rand() * 3) % 4) + 1;
	return kierunek;
}

void Organizm::rysowanie(Swiat* swiat) {
	gotoxy(this->zwrocPolozenie().x, this->zwrocPolozenie().y);
	cout << zwrocPionek();
	gotoxy(0, swiat->zwrocWysokosc() + 1);
}

bool Organizm::umiejetnoscKolizja(Organizm* atakujacy, string& komentarz) {
	return true;
}

Organizm::Organizm(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie) {
	this->pionek = pionek;
	this->sila = sila;
	this->swiat = swiat;
	this->inicjatywa = inicjatywa;
	this->ruch = ruch;
	this->polozenie = polozenie;
	this->umiejetnoscWlaczonaC = false;
	this->czasOdnowieniaUmiejetnosciC = -1;
	this->czasTrwaniaUmiejetnosciC = -1;

}
void Organizm::gotoxy(int x, int y) {
	printf("\033[%d;%dH", y + 4, x + 2);
}
Organizm::~Organizm() {
}