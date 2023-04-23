#pragma once
#include "Roslina.h"
class Barszcz_Sosnowskiego: public Roslina
{
	public:
	void akcja(Swiat* swiat)override;
	bool umiejetnoscKolizja(Organizm* atakujacy, string& komentarz)override;
	Barszcz_Sosnowskiego(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);
	~Barszcz_Sosnowskiego();
};

