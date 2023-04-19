#pragma once
#include <iostream>
#include <string.h>
#include <iomanip>
#include <vector>

#define BOCZNE_OBRAMOWANIE 0xBA
#define GORNE_DOLNE_OBRAMOWANIE 0xCD
#define LEWY_GORNY_ROG_PLANSZY 201
#define PRAWY_GORNY_ROG_PLANSZY 187
#define LEWY_DOLNY_ROG_PLANSZY 200
#define PRAWY_DOLNY_ROG_PLANSZY 188

using namespace std;
struct Polozenie {
	int x;
	int y;
};
class Organizm;

class Swiat
{
private:
	/*enum organizmy {CZLOWIEK, WILK, OWCA, LIS, ZOLW, ANTYLOPA, CYBEROWCA,
		TRAWA, MLECZ, GUARANA, WILCZE_JAGODY, BARSZCZ_SOSNOWSKIEGO};*/
	vector<Organizm*> organizmy;
	int wysokoscPlanszy;
	int szerokoscPlanszy;
	char** plansza;
public:
	void wykonajTure();
	void rysujSwiat();
	void dodajNaPole(Polozenie polozenie, char pionek);
	void usunZPola(Polozenie polozenie);
	int zwrocWysokosc();
	int zwrocSzerokosc();
	bool sprawdzCzyPoleJestPuste(int x, int y);
	void ustawWysokosc(int wysokosc);
	void ustawSzerokosc(int szerokosc);
	void dodajOrganizmyPoczatkowe(vector<Organizm*> organizmy, int wysokoscPlanszy, int szerokoscPlanszy);
	Swiat();
	~Swiat();

};

