#include "Swiat.h"
#include "Wilk.h"
#include "Czlowiek.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Owca.h"
#include "Lis.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Barszcz_Sosnowskiego.h"
#include "Wilcze_Jagody.h"

#define ILOSC_ORGANIZMOW 11

int Swiat::zwrocWysokosc() {
	return wysokoscPlanszy;
}
int Swiat::zwrocSzerokosc() {
	return szerokoscPlanszy;
}
void Swiat::ustawSzerokosc(int szerokosc) {
	this->szerokoscPlanszy = szerokosc;
}
void Swiat::ustawWysokosc(int wysokosc) {
	this->wysokoscPlanszy = wysokosc;
}
void Swiat::dodajNaPole(Polozenie polozenie, char pionek) {
	plansza[polozenie.y][polozenie.x] = pionek;
}
void Swiat::usunZPola(Polozenie polozenie) {
	plansza[polozenie.y][polozenie.x] = ' ';
}

void Swiat::dodajOrganizmyPoczatkowe(vector<Organizm*> organizmy, int wysokoscPlanszy, int szerokoscPlanszy) {
	string nazwyOrganizmow[ILOSC_ORGANIZMOW + 1] = { "Czlowiek", "Wilk", "Owca", "Lis", "Zolw", "Antylopa"
		, "Trawa", "Mlecz", "Guarana", "Wilcze Jagody", "Barszcz Sosnowskiego" };
	int ileOrganizmowPoszczegolnychGatunkow = ((wysokoscPlanszy * szerokoscPlanszy) / (10 * ILOSC_ORGANIZMOW)) + 1;
	for (int i = 0; i < ileOrganizmowPoszczegolnychGatunkow; i++) {

		organizmy.push_back(new Czlowiek('C', 5, 4, 0, this));
		organizmy.push_back(new Wilk('W', 9, 5, 0, this));
		organizmy.push_back(new Owca('O', 4, 4, 0, this));
		organizmy.push_back(new Lis('L', 3, 7, 0, this));
		organizmy.push_back(new Zolw('Z', 2, 1, 0, this));
		organizmy.push_back(new Antylopa('A', 4, 4, 0, this));
		//organizmy.push_back(new Trawa('T', 0, 0, this));
		//organizmy.push_back(new Mlecz('M', 0, 0, this));
		//organizmy.push_back(new Guarana('G', 0, 0, this));
		//organizmy.push_back(new Wilcze_Jagody('J', 99, 0, this));
		//organizmy.push_back(new Barszcz_Sosnowskiego('B', 10, 0, this));
	}
}

void Swiat::rysujSwiat() {
	char bokPlanszy = BOCZNE_OBRAMOWANIE;
	char dolGoraPlanszy = GORNE_DOLNE_OBRAMOWANIE;
	char lewyGornyRogPlanszy = LEWY_GORNY_ROG_PLANSZY;
	char prawyGornyRogPlanszy = PRAWY_GORNY_ROG_PLANSZY;
	char lewyDolnyRogPlanszy = LEWY_DOLNY_ROG_PLANSZY;
	char prawyDolnyRogPlanszy = PRAWY_DOLNY_ROG_PLANSZY;

	system("cls");
	cout << "Marcin Arasniewicz, 188857" << endl << endl;
	cout << lewyGornyRogPlanszy;
	for (int i = 1; i < zwrocSzerokosc(); i++) cout << dolGoraPlanszy;
	cout << prawyGornyRogPlanszy;
	cout << endl;

	for (int i = 0; i < zwrocWysokosc() ; i++) {
		for (int j = -1; j < zwrocSzerokosc(); j++) {
			if (j == -1 || j == zwrocSzerokosc() - 1)cout << bokPlanszy;
			else cout << this->plansza[i][j];
		}
		cout << endl;
	}
	cout << lewyDolnyRogPlanszy;
	for (int i = 1; i < zwrocSzerokosc(); i++) cout << dolGoraPlanszy;
	cout << prawyDolnyRogPlanszy;
	cout << endl;
}

Swiat::Swiat() {
	int wysokosc, szerokosc;
	cout << "Wpisz wysokosc planszy: ";
	cin >> wysokosc;
	ustawWysokosc(wysokosc);
	cout << "Wpisz szerokosc planszy: ";
	cin >> szerokosc;
	ustawSzerokosc(szerokosc);

	plansza = new char* [wysokosc];
	for (int i = 0; i < wysokosc; i++)
		plansza[i] = new char[szerokosc];


	for (int i = 0; i < zwrocWysokosc(); i++) {
		for (int j = 0; j < zwrocSzerokosc(); j++)
			this->plansza[i][j] = ' ';
	}

	dodajOrganizmyPoczatkowe(organizmy, wysokosc, szerokosc);
	rysujSwiat();
}

void Swiat::wykonajTure() {

}
bool Swiat::sprawdzCzyPoleJestPuste(int x, int y) {
	if(plansza[y][x] == ' ')
		return true;
	else
		return false;
}

Swiat::~Swiat() {

	for (int i = 0; i < zwrocWysokosc(); i++)
		delete[] plansza[i];

	delete[] plansza;

	organizmy.erase(organizmy.begin(), organizmy.end());

	
}