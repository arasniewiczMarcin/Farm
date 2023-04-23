#pragma once
#include "Zwierze.h"
class Zolw : public Zwierze
{
	public:
	void akcja(Swiat* swiat)override;
	bool umiejetnoscKolizja(Organizm* atakujacy, string& komentarz)override;
	Zolw(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);
	~Zolw();
};

