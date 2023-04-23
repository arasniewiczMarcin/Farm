#pragma once
#include <conio.h>
#include "Organizm.h"


#define X 0
#define Y 1


class Zwierze : public Organizm
{
public:

	void akcja(Swiat* swiat)override;
	void kolizja(Swiat* swiat, Polozenie miejsceKolizji)override;
	void walka(Zwierze* atakujacy, Organizm* broniacy, Swiat* swiat, string& komentarz);
	void rozmnazanie(Swiat* swiat);

	Zwierze(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);
	~Zwierze();
};

