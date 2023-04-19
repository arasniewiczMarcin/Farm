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


#define X 0
#define Y 1


class Organizm
{

protected:
	char pionek;
	int sila;
	int inicjatywa;
	Polozenie polozenie;
	Swiat *swiat;
	int wiek;
	
public:
	virtual void akcja(Swiat* swiat) = 0;
	virtual void kolizja(Swiat* swiat, Polozenie miejsceKolizji) = 0;
	virtual void rysowanie() = 0;

	Polozenie zwrocPolozenie();
	int zwrocInicjatywe();
	int zwrocSile();
	char zwrocPionek();
	int wylosujKierunek();
	int zwrocWiek();

	Polozenie wylosujPolozenie(Swiat* swiat);
	void zmienPolozenie(int wektor[], Swiat* swiat);
	Organizm(char pionek, int sila, int inicjatywa, int wiek, Swiat* swiat);

	~Organizm();

};

