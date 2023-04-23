#include <iostream>
#include <conio.h>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"



using namespace std;

int main()
{
    
    char command = ' ';
    cout << " Wcisnij r aby rozpoczac gre" << endl;
    cout << " Wcisnij l aby wczytac gre" << endl;
    while(command != 'r' && command != 'l') command = _getch();
    Swiat s;
    if (command == 'l') {
        s.wczytajSwiat();
    }
    else {
        s.stworzPlansze();
        
    }
    
    s.rysujSwiat();
    cout << " Wcisnij n aby wykonac Ture" << endl;
    cout << " Wcisnij u aby wlaczyc specjalna umiejetnosc Czlowieka" << endl;
    cout << " Wcisnij s zapisac gre" << endl;
    while (true) {

        command = _getch();
        if (command == 'n') {
            s.wykonajTure();
            s.rysujSwiat();
            s.dodajKomentarz();
        }
        else if (command == 'u') {
            s.wlaczUmiejetnoscCzlowieka();
        }
        else if (command == 's') {
            s.zapiszSwiat();
        }
    }
    
    
}
