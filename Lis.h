#pragma once
#include "Zwierze.h"
class Lis: public Zwierze
{
	public:
	void akcja(Swiat* swiat)override;
	Lis(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);
	~Lis();
};

