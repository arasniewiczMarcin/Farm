#pragma once
#include "Zwierze.h"
class Owca : public Zwierze
{
public:
	Owca(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);
	~Owca();

};

