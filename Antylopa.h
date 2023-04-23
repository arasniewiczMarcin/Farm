#pragma once
#include "Zwierze.h"
class Antylopa : public Zwierze{
	public:
	void akcja(Swiat* swiat)override;
	bool umiejetnoscKolizja(Organizm* atakujacy, string& komentarz)override;
	Antylopa(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);
	~Antylopa();
};

