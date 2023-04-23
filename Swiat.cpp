#define _CRT_SECURE_NO_WARNINGS
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
#include <typeinfo>

#define ILOSC_ORGANIZMOW 11
#define MAKS_INICJATYWA 7

int Swiat::zwrocWysokosc() {
	return wysokoscPlanszy;
}
int Swiat::zwrocSzerokosc() {
	return szerokoscPlanszy;
}
char Swiat::zwrocPole(int x, int y) {
	return plansza[y][x];
}
void Swiat::ustawSzerokosc(int szerokosc) {
	this->szerokoscPlanszy = szerokosc;
}
void Swiat::ustawWysokosc(int wysokosc) {
	this->wysokoscPlanszy = wysokosc;
}
void Swiat::usunOrganizm(Organizm* organizm) {
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->zwrocPolozenie().x == organizm->zwrocPolozenie().x &&
			organizmy[i]->zwrocPolozenie().y == organizm->zwrocPolozenie().y) {
			organizmy.erase(organizmy.begin() + i);
		}
	}
}

Polozenie Swiat::znajdzWolnePoleObok(Organizm* organizm) {
	Polozenie nowePolozenie;
	nowePolozenie.x = -1;
	nowePolozenie.y = -1;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (organizm->zwrocPolozenie().x + j >= 0 && organizm->zwrocPolozenie().x + j < zwrocSzerokosc() &&
				organizm->zwrocPolozenie().y + i >= 0 && organizm->zwrocPolozenie().y + i < zwrocWysokosc() &&
				sprawdzCzyPoleJestPuste(organizm->zwrocPolozenie().x + j, organizm->zwrocPolozenie().y + i)) {

				nowePolozenie.x = organizm->zwrocPolozenie().x + j;
				nowePolozenie.y = organizm->zwrocPolozenie().y + i;
				return nowePolozenie;
			}
		}
	}
	return nowePolozenie;
}

void Swiat::dodajOrganizm(Organizm* organizm) {
	organizm->ustawPolozenie(znajdzWolnePoleObok(organizm));
	if(organizm->zwrocPolozenie().x != -1)
		organizmy.push_back(organizm);
}

void Swiat::wlaczUmiejetnoscCzlowieka() {
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->zwrocPionek() == 'C') {
			if (organizmy[i]->zwrocCzasOdnowieniaUmiejetnosciC() == 0) {

				organizmy[i]->ustawUmiejetnoscC(true);
				organizmy[i]->ustawCzasOdnowieniaUmiejetnosciC(10);
				organizmy[i]->ustawCzasTrwaniaUmiejetnosciC(5);
			}
			else {
				cout << "Musisz poczekac " << organizmy[i]->zwrocCzasOdnowieniaUmiejetnosciC() <<
					" tur, aby wlaczyc umiejetnosc ponownie" << endl;
			}

		}
	}
}

Polozenie Swiat::wylosujPolozenie() {
	srand(time(NULL));
	int randomX, randomY, randomXtoMultiply, randomYtoMultiply;
	Polozenie p;
	while (true) {
		randomXtoMultiply = (rand() % 9) + 1;
		randomYtoMultiply = (rand() % 9) + 1;
		randomX = (rand() * randomXtoMultiply) % zwrocSzerokosc();
		randomY = (rand() * randomYtoMultiply) % zwrocWysokosc();
		if (sprawdzCzyPoleJestPuste(randomX, randomY) == true) {
			p.x = randomX;
			p.y = randomY;
			break;
		}
	}
	return p;
}

void Swiat::dodajOrganizmyPoczatkowe(int wysokoscPlanszy, int szerokoscPlanszy) {
	string nazwyOrganizmow[ILOSC_ORGANIZMOW + 1] = { "Czlowiek", "Wilk", "Owca", "Lis", "Zolw", "Antylopa"
		, "Trawa", "Mlecz", "Guarana", "Wilcze Jagody", "Barszcz Sosnowskiego" };
	int ileOrganizmowPoszczegolnychGatunkow = ((wysokoscPlanszy * szerokoscPlanszy) / (10 * ILOSC_ORGANIZMOW)) + 1;

	organizmy.push_back(new Czlowiek('C', 5, 4, true, this, this->wylosujPolozenie()));
	for (int i = 0; i < ileOrganizmowPoszczegolnychGatunkow; i++) {
		organizmy.push_back(new Antylopa('A', 4, 4, true, this, this->wylosujPolozenie()));
		organizmy.push_back(new Wilk('W', 9, 5, true, this, this->wylosujPolozenie()));
		organizmy.push_back(new Barszcz_Sosnowskiego('B', 10, 0, true, this, this->wylosujPolozenie()));
		organizmy.push_back(new Owca('O', 4, 4, true, this, this->wylosujPolozenie()));
		organizmy.push_back(new Guarana('G', 0, 0, true, this, this->wylosujPolozenie()));
		organizmy.push_back(new Lis('L', 3, 7, true, this, this->wylosujPolozenie()));
		organizmy.push_back(new Trawa('T', 0, 0, true, this, this->wylosujPolozenie()));
		organizmy.push_back(new Wilcze_Jagody('J', 99, 0, true, this, this->wylosujPolozenie()));
		organizmy.push_back(new Mlecz('M', 0, 0, true, this, this->wylosujPolozenie()));
		organizmy.push_back(new Zolw('Z', 2, 1, true, this, this->wylosujPolozenie()));

	}

}

void Swiat::rysujOrganizmy() {
	for (int i = 0; i < organizmy.size(); i++) {
		organizmy[i]->rysowanie(this);
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
	for (int i = 1; i < zwrocSzerokosc() + 1; i++) cout << dolGoraPlanszy;
	cout << prawyGornyRogPlanszy;
	cout << endl;

	for (int i = 0; i < zwrocWysokosc() ; i++) {
		for (int j = -1; j <= zwrocSzerokosc(); j++) {
			if (j == -1 || j == zwrocSzerokosc())cout << bokPlanszy;
			else cout << this->plansza[i][j];
		}
		cout << endl;
	}
	cout << lewyDolnyRogPlanszy;
	for (int i = 1; i < zwrocSzerokosc() + 1; i++) cout << dolGoraPlanszy;
	cout << prawyDolnyRogPlanszy << endl;
	rysujOrganizmy();
}

void Swiat::stworzPlansze() {
	int wysokosc, szerokosc;
	cout << "Wpisz wysokosc planszy: ";
	cin >> wysokosc;
	ustawWysokosc(wysokosc);
	cout << "Wpisz szerokosc planszy: ";
	cin >> szerokosc;
	ustawSzerokosc(szerokosc);

	this->wysokoscPlanszy = wysokosc;
	this->szerokoscPlanszy = szerokosc;

	this->plansza = new char* [wysokosc];
	for (int i = 0; i < wysokosc; i++)
		this->plansza[i] = new char[szerokosc];


	for (int i = 0; i < zwrocWysokosc(); i++) {
		for (int j = 0; j < zwrocSzerokosc(); j++)
			this->plansza[i][j] = ' ';
	}
	dodajOrganizmyPoczatkowe(zwrocWysokosc(), zwrocWysokosc());
}
Swiat::Swiat() {
	
	this->wysokoscPlanszy = 20;
	this->szerokoscPlanszy = 20;

	this->plansza = new char* [this->wysokoscPlanszy];
	for (int i = 0; i < this->wysokoscPlanszy; i++)
		this->plansza[i] = new char[this->szerokoscPlanszy];

	for (int i = 0; i < zwrocWysokosc(); i++) {
		for (int j = 0; j < zwrocSzerokosc(); j++)
			this->plansza[i][j] = ' ';
	}
	this->komentarz = "";
	this->organizmy = vector<Organizm*>();
	
}

void Swiat::tworzKomentarz(string komentarz) {
	this->komentarz += komentarz;
}

Organizm* Swiat::zwrocOrganizm(Polozenie polozenie) {
	for (int i = 0; i < organizmy.size(); i++) {
		if (polozenie.x == organizmy[i]->zwrocPolozenie().x &&
			polozenie.y == organizmy[i]->zwrocPolozenie().y) {
			return organizmy[i];
		}
	}
	return NULL;
}

void Swiat::wykonajTure() {
	srand(time(NULL));

	for (int i = MAKS_INICJATYWA; i >= 0 ; i--) {
		for (int j = 0; j < organizmy.size(); j++) {
			if (organizmy[j]->zwrocRuch() == true && organizmy[j]->zwrocInicjatywe() == i) {
				organizmy[j]->akcja(this);
			}
		}
	}
	
	for (int j = 0; j < organizmy.size(); j++)
		organizmy[j]->ustawRuch(true);
}
void Swiat::dodajKomentarz() {
	organizmy[0]->gotoxy(-1, zwrocWysokosc() + 1);
	cout << " Wcisnij n aby wykonac Ture" << endl;
	cout << " Wcisnij u aby wlaczyc specjalna umiejetnosc Czlowieka" << endl << endl;
	cout << " Wcisnij s zapisac gre" << endl;
	cout << komentarz;
	komentarz = "";
}
bool Swiat::sprawdzCzyPoleJestPuste(int x, int y) {
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->zwrocPolozenie().x == x && organizmy[i]->zwrocPolozenie().y == y) {
			return false;
		}
	}
	return true;

}

void Swiat::zapiszSwiat() {
	FILE* plik;
	plik = fopen("zapis.txt", "w");
	fprintf(plik, "%d %d\n", zwrocWysokosc(), zwrocSzerokosc());
	for (int i = 0; i < organizmy.size(); i++) {
		fprintf(plik, "%c %d %d %d %d\n", organizmy[i]->zwrocPionek(), organizmy[i]->zwrocSile(), organizmy[i]->zwrocInicjatywe(),
			organizmy[i]->zwrocPolozenie().x, organizmy[i]->zwrocPolozenie().y);
	}
	fclose(plik);
}
void Swiat::wczytajOrganizm(char pi, int s, int ini, int x, int y) {
	Polozenie p;
	p.x = x;
	p.y = y;
	switch (pi) {
		case 'A': 
			organizmy.push_back(new Antylopa(pi, s, ini, true, this, p));
			break;
		case 'B':
			organizmy.push_back(new Barszcz_Sosnowskiego(pi, s, ini, true, this, p));
			break;
		case 'C':
			organizmy.push_back(new Czlowiek(pi, s, ini, true, this, p));
			break;
		case 'G':
			organizmy.push_back(new Guarana(pi, s, ini, true, this, p));
			break;
		case 'L':
			organizmy.push_back(new Lis(pi, s, ini, true, this, p));
			break;
		case 'M':
			organizmy.push_back(new Mlecz(pi, s, ini, true, this, p));
			break;
		case 'O':
			organizmy.push_back(new Owca(pi, s, ini, true, this, p));
			break;
		case 'T':
			organizmy.push_back(new Trawa(pi, s, ini, true, this, p));
			break;
		case 'J':
			organizmy.push_back(new Wilcze_Jagody(pi, s, ini, true, this, p));
			break;
		case 'W':
			organizmy.push_back(new Wilk(pi, s, ini, true, this, p));
			break;
		case 'Z':
			organizmy.push_back(new Zolw(pi, s, ini, true, this, p));
			break;
	}
}
void Swiat::wczytajSwiat() {
	FILE* plik = fopen("zapis.txt", "r");
	this->organizmy.clear();

	for (int i = 0; i < zwrocWysokosc(); i++)
		delete[] plansza[i];

	delete[] plansza;
	
	if (plik != NULL) {
		//Swiat nowySwiat;
		int wysokosc, szerokosc, s, ini, x, y, i = 0;
		char pi;
		fscanf(plik, "%d %d", &wysokosc, &szerokosc);

		this->wysokoscPlanszy = wysokosc;
		this->szerokoscPlanszy = szerokosc;
		plansza = new char* [wysokosc];
		for (int i = 0; i < wysokosc; i++)
			plansza[i] = new char[szerokosc];

		for (int i = 0; i < zwrocWysokosc(); i++) {
			for (int j = 0; j < zwrocSzerokosc(); j++)
				this->plansza[i][j] = ' ';
		}

		while (fscanf(plik, "%c %d %d %d %d", &pi, &s, &ini, &x, &y) > 0) {
			wczytajOrganizm(pi, s, ini, x, y);
		}
	}

}

Swiat::~Swiat() {

	for (int i = 0; i < zwrocWysokosc(); i++)
		delete[] plansza[i];

	delete[] plansza;

	organizmy.erase(organizmy.begin(), organizmy.end());
	organizmy.~vector();

	
}