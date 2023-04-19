#pragma once
#include "Zwierze.h"
class Czlowiek : public Zwierze
{
	public:
	Czlowiek(char pionek, int sila, int inicjatywa, int wiek, Swiat* swiat);
	~Czlowiek();
};

