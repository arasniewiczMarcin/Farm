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
	vector<Organizm*> organizmy;
	int wysokoscPlanszy;
	int szerokoscPlanszy;
	char** plansza;
	string komentarz;
public:

	int zwrocWysokosc();
	int zwrocSzerokosc();
	char zwrocPole(int x, int y);

	void ustawWysokosc(int wysokosc);
	void ustawSzerokosc(int szerokosc);

	void dodajOrganizm(Organizm* organizm);
	void wykonajTure();
	void rysujOrganizmy();
	void rysujSwiat();
	bool sprawdzCzyPoleJestPuste(int x, int y);
	void dodajOrganizmyPoczatkowe(int wysokoscPlanszy, int szerokoscPlanszy);
	void usunOrganizm(Organizm* organizm);
	void wlaczUmiejetnoscCzlowieka();

	void tworzKomentarz(string komentarz);
	void dodajKomentarz();
	void zapiszSwiat();
	void wczytajSwiat();
	void wczytajOrganizm(char p, int s, int ini, int x, int y);
	void stworzPlansze();

	Polozenie znajdzWolnePoleObok(Organizm* organizm);
	Polozenie wylosujPolozenie();
	Organizm* zwrocOrganizm(Polozenie polozenie);
	Swiat();
	~Swiat();

};

