#include "Zwierze.h"

Zwierze::Zwierze(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie)
:Organizm(pionek, sila, inicjatywa, ruch, swiat, polozenie){

}

void Zwierze::akcja(Swiat* swiat) {
	int kierunek, wektor[2] = {};
	while (true) {
		kierunek = wylosujKierunek();
		stworzWektor(wektor, kierunek);
		if (polozenie.x + wektor[X] < 0 || polozenie.x + wektor[X] >= swiat->zwrocSzerokosc() ||
			polozenie.y + wektor[Y] < 0 || polozenie.y + wektor[Y] >= swiat->zwrocWysokosc())
			continue; 
		//warunek do ponownego wylosowania kierunku
		else break;
	}
	zmienPolozenie(wektor, swiat);
}

void Zwierze::walka(Zwierze* atakujacy, Organizm* broniacy, Swiat* swiat, string& komentarz) {
	if (broniacy->umiejetnoscKolizja(atakujacy, komentarz)) {
		komentarz += " ginie ";

		if (atakujacy->sila >= broniacy->zwrocSile()) {

			Polozenie nowePolozenie = broniacy->zwrocPolozenie();
			swiat->usunOrganizm(broniacy);
			atakujacy->polozenie = nowePolozenie;
			gotoxy(this->zwrocPolozenie().x, this->zwrocPolozenie().y);
			gotoxy(0, swiat->zwrocWysokosc() + 1);
			gotoxy(0, swiat->zwrocWysokosc() + 10);

			komentarz.append(1, broniacy->zwrocPionek());
		}
		else if (atakujacy->sila < broniacy->zwrocSile()) {
			komentarz.append(1, atakujacy->zwrocPionek());
			swiat->usunOrganizm(atakujacy);
		}
		komentarz += "\n";
		swiat->tworzKomentarz(komentarz);
	}
}
void Zwierze::rozmnazanie(Swiat* swiat) {
	int kierunek = wylosujKierunek();
	Polozenie nowePolozenie = this->zwrocPolozenie();

	swiat->dodajOrganizm(new Zwierze(this->zwrocPionek(), this->zwrocSile(),
		this->zwrocInicjatywe(), false, swiat, this->zwrocPolozenie()));
}

void Zwierze::kolizja(Swiat* swiat, Polozenie miejsceKolizji) {
	string komentarz = "";
	komentarz += "Spotkanie pomiedzy: ";
	komentarz.append(1, this->zwrocPionek());
	komentarz += " a ";
	komentarz.append(1, swiat->zwrocOrganizm(miejsceKolizji)->zwrocPionek());

	if (this->pionek == swiat->zwrocOrganizm(miejsceKolizji)->zwrocPionek()) {
		//rozmnazanie
		komentarz+= " rozmnazanie ";
		komentarz.append(1, this->zwrocPionek());
		komentarz += "\n";
		swiat->tworzKomentarz(komentarz);

		if(this->zwrocRuch() == true && swiat->zwrocOrganizm(miejsceKolizji)->zwrocRuch() == true)
			rozmnazanie(swiat);
		this->ustawRuch(false);
		swiat->zwrocOrganizm(miejsceKolizji)->ustawRuch(false);
	}
	else {
		//walka	
		walka(this, swiat->zwrocOrganizm(miejsceKolizji), swiat, komentarz);
	}
}

Zwierze::~Zwierze() {

}