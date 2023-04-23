#include "Roslina.h"

Roslina::Roslina(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie)
	:Organizm(pionek, sila, inicjatywa, ruch, swiat, polozenie)
{

}
void Roslina::rozprzestrzenianie(Swiat* swiat) {
	
	int kierunek = wylosujKierunek();
	Polozenie nowePolozenie = this->zwrocPolozenie();

	swiat->dodajOrganizm(new Roslina(this->zwrocPionek(), this->zwrocSile(),
		this->zwrocInicjatywe(), false, swiat, this->zwrocPolozenie()));

}
void Roslina::akcja(Swiat* swiat) {
	Sleep(3);
	int losowy = rand() % 10;

	if (losowy < 1) {
		string komentarz = "";
		komentarz += " rozprzestrzenianie ";
		komentarz.append(1, this->zwrocPionek());
		komentarz += ", ";
		swiat->tworzKomentarz(komentarz);
		rozprzestrzenianie(swiat);
	}
}
void Roslina::kolizja(Swiat* swiat, Polozenie miejsceKolizji) {

}
Roslina::~Roslina() {

}