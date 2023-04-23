#include "Guarana.h"

bool Guarana::umiejetnoscKolizja(Organizm* atakujacy, string &komentarz) {
	atakujacy->ustawSile(atakujacy->zwrocSile() + 3);
	return true;
}
Guarana::Guarana(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie)
	:Roslina(pionek, sila, inicjatywa, ruch, swiat, polozenie)
{
}
Guarana::~Guarana()
{
}