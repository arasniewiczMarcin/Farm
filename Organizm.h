#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
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

#define LEWO 1
#define PRAWO 2
#define GORA 3
#define DOL 4



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
	bool ruch = true;

	bool umiejetnoscWlaczonaC;
	int czasOdnowieniaUmiejetnosciC;
	int czasTrwaniaUmiejetnosciC;
	
public:
	virtual void akcja(Swiat* swiat) = 0;
	virtual void kolizja(Swiat* swiat, Polozenie miejsceKolizji) = 0;
	virtual bool umiejetnoscKolizja(Organizm* atakujacy, string& komentarz);

	void rysowanie(Swiat* swiat);
	Polozenie zwrocPolozenie();
	int zwrocInicjatywe();
	int zwrocSile();
	char zwrocPionek();
	bool zwrocRuch();
	int wylosujKierunek();
	void gotoxy(int x, int y);
	void ustawSile(int sila);
	void stworzWektor(int wektor[2], int kierunek);
	void ustawPolozenie(Polozenie nowePolozenie);
	void ustawRuch(bool ruch);

	
	void zmienPolozenie(int wektor[], Swiat* swiat);
	Organizm(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie);

	~Organizm();

	void ustawUmiejetnoscC(bool wlaczona);
	void ustawCzasTrwaniaUmiejetnosciC(int czas);
	void ustawCzasOdnowieniaUmiejetnosciC(int czas);
	bool zwrocUmiejetnoscC();
	int zwrocCzasTrwaniaUmiejetnosciC();
	int zwrocCzasOdnowieniaUmiejetnosciC();
	void zmniejszCzasTrwaniaUmiejetnosciC();
	void zmniejszCzasOdnowieniaUmiejetnosciC();

};

