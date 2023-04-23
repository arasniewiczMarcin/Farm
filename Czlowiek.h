#pragma once
#include "Zwierze.h"

#define ARROW -32
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_RIGHT 77
#define ARROW_LEFT 75

class Czlowiek : public Zwierze
{
private:

	public:

	Czlowiek(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);
	~Czlowiek();
	
	void akcja(Swiat* swiat)override;
	void ustaw();
};

