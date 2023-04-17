#include "Swiat.h"

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
	//dodanie organizmow
	int poczatkowaSumaOrganizmowJednegoRodzaju = ((wysokosc * szerokosc) / (10 * ILOSC_ORGANIZMOW));

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
}