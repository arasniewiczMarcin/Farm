#include "Antylopa.h"

void Antylopa::akcja(Swiat* swiat) {
	Polozenie p = this->zwrocPolozenie();
	Zwierze::akcja(swiat);
	Zwierze::akcja(swiat);
	if(this->polozenie.x == p.x && this->polozenie.y == p.y)
		Antylopa::akcja(swiat);
}
bool Antylopa::umiejetnoscKolizja(Organizm* atakujacy, string& komentarz) {
	srand(time(NULL));
	int szansa = rand() % 2;
	if (szansa == 1) {
		atakujacy->ustawPolozenie(this->polozenie);
		this->akcja(swiat);
		komentarz += "Antylopa ucieka przed walka\n";
		swiat->tworzKomentarz(komentarz);
		return false;
	}
	else {
		
		return true;
	}
}
Antylopa::Antylopa(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie)
	: Zwierze(pionek, sila, inicjatywa, ruch, swiat, polozenie) {
}
Antylopa::~Antylopa() {

}