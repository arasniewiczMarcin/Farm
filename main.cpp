#include <iostream>
#include <conio.h>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"



using namespace std;

int main()
{
    
    Swiat s;
    s.rysujSwiat();
    char command = ' ';
    char humanDirection[2];

    while (true) {
        cout << "Wcisnij n aby wykonac Ture" << endl;
        command = _getch();
        if (command == 'n') {
            s.wykonajTure();
            s.rysujSwiat();
        }
    }
    
    
}
