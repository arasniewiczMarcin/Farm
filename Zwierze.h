#pragma once
#include "Organizm.h"

class Zwierze : public Organizm
{
public:
	void akcja()override;
	void kolizja()override;
	void rysowanie()override;
	Zwierze(char pionek, int sila, int inicjatywa, int wiek, Swiat* swiat);
	~Zwierze();
};

