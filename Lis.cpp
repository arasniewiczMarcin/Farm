#include "Lis.h"

void Lis::akcja(Swiat* swiat) {
	int kierunek, wektor[2] = {};
	while (true) {
		kierunek = wylosujKierunek();
		stworzWektor(wektor, kierunek);
		Polozenie nowePolozenie = { polozenie.x + wektor[X], polozenie.y + wektor[Y] };
		if (polozenie.x + wektor[X] < 0 || polozenie.x + wektor[X] >= swiat->zwrocSzerokosc() ||
			polozenie.y + wektor[Y] < 0 || polozenie.y + wektor[Y] >= swiat->zwrocWysokosc() ||
			(swiat->zwrocOrganizm(nowePolozenie) != NULL  && swiat->zwrocOrganizm(nowePolozenie)->zwrocSile() > this->zwrocSile()))
			continue;
		//warunek do ponownego wylosowania kierunku
		else break;
	}

	zmienPolozenie(wektor, swiat);
}
Lis::Lis(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie)
	: Zwierze(pionek, sila, inicjatywa, ruch, swiat, polozenie) {
}
Lis::~Lis() {
}
