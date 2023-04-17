#pragma once
#include <Windows.h>
#include "Swiat.h"


#define CZLOWIEK 'C'
#define WILK 'W'
#define OWCA 'O'
#define LIS 'L'
#define ZOLW 'Z'
#define ANTYLOPA 'A'
#define CYBEROWCA 'S'
#define TRAWA 'T'
#define MLECZ 'M'
#define GUARANA 'G'
#define WILCZE_JAGODY 'J'
#define BARSZCZ_SOSNOWSKIEGO 'B'


class Organizm
{

protected:
	char pionek;
	int sila;
	int inicjatywa;
	Polozenie polozenie;
	Swiat *swiat;
	
public:
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() = 0;
	Polozenie wylosujPolozenie(Swiat* swiat);
	Organizm(char pionek, int sila, int inicjatywa, Swiat* swiat);

	~Organizm();

};

