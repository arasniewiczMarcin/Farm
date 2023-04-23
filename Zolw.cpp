#include "Zolw.h"


void Zolw::akcja(Swiat* swiat) {
	srand(time(NULL));
	int szansa = rand() % 4;
	if (szansa == 0) {
		Zwierze::akcja(swiat);
	}
}
bool Zolw::umiejetnoscKolizja(Organizm* atakujacy, string& komentarz) {
	if (atakujacy->zwrocSile() < 5) {
		komentarz += " Zolw odbil atak\n";
		swiat->tworzKomentarz(komentarz);
		return false;
	}
}
Zolw::Zolw(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie)
	: Zwierze(pionek, sila, inicjatywa,ruch, swiat, polozenie) {
}
Zolw::~Zolw() {

}