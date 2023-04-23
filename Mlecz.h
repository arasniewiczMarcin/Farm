#pragma once
#include "Roslina.h"
class Mlecz:public Roslina
{
	public:
	void akcja(Swiat* swiat)override;
	Mlecz(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);
	~Mlecz();
};

