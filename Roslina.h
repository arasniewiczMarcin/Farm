#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
public:
	void akcja(Swiat* swiat)override;
	void kolizja()override;
	void rysowanie()override;
	Roslina(char pionek, int sila, int inicjatywa, int wiek, Swiat* swiat);
	~Roslina();
};



