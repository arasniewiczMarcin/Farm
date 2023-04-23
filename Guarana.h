#pragma once
#include "Roslina.h"
class Guarana: public Roslina
{
	public:
	bool umiejetnoscKolizja(Organizm* atakujacy, string &komentarz)override;
	Guarana(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);
	~Guarana();
};

