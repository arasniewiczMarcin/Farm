#include "Barszcz_Sosnowskiego.h"

bool Barszcz_Sosnowskiego::umiejetnoscKolizja(Organizm* atakujacy, string& komentarz) {
	atakujacy->ustawSile(1);

	return true;
}
void Barszcz_Sosnowskiego::akcja(Swiat* swiat) {
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if ((i != 0 || j != 0) && swiat->sprawdzCzyPoleJestPuste(this->polozenie.x + j, this->polozenie.y + i) == false) {
				Polozenie p;
				p.x = this->zwrocPolozenie().x + j;
				p.y = this->zwrocPolozenie().y + i;
				if(swiat->zwrocOrganizm(p)->zwrocInicjatywe() > 0)
					swiat->usunOrganizm(swiat->zwrocOrganizm(p));
			}
		}
	}
	Roslina::akcja(swiat);
}
Barszcz_Sosnowskiego::Barszcz_Sosnowskiego(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie)
	: Roslina(pionek, sila, inicjatywa, ruch, swiat, polozenie)
{
}

Barszcz_Sosnowskiego::~Barszcz_Sosnowskiego()
{
}