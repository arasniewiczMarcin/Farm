#pragma once
#include "Organizm.h"

#define LEWO 1
#define PRAWO 2
#define GORA 3
#define DOL 4

#define X 0
#define Y 1


class Zwierze : public Organizm
{
public:
	void akcja(Swiat* swiat)override;
	void kolizja()override;
	void rysowanie()override;
	Zwierze(char pionek, int sila, int inicjatywa, int wiek, Swiat* swiat);
	~Zwierze();
};

