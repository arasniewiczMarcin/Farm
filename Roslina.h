#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
public:
	void akcja()override;
	void kolizja()override;
	void rysowanie()override;
	Roslina();
	~Roslina();
};



