#pragma once
#include "Zwierze.h"
class Wilk : public Zwierze
{
	public:
	Wilk(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);
	~Wilk();
};

