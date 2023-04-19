#pragma once
#include "Zwierze.h"

#define ARROW -32
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_RIGHT 77
#define ARROW_LEFT 75

class Czlowiek : public Zwierze
{
	public:
	Czlowiek(char pionek, int sila, int inicjatywa, int wiek, Swiat* swiat);
	~Czlowiek();
	void akcja(Swiat* swiat);
};

