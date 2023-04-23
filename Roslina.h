#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
public:
	void akcja(Swiat* swiat)override;
	void kolizja(Swiat* swiat, Polozenie miejsceKolizji)override;
	void rozprzestrzenianie(Swiat* swiat);
	Roslina(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);
	~Roslina();
};



