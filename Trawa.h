#pragma once
#include "Roslina.h"
class Trawa : public Roslina
{
public:
	Trawa(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);
	~Trawa();
};

