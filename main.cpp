#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"



using namespace std;

int main()
{
    
    Swiat s;
    char command = ' ';
    char humanDirection[2];
    while (true) {
        command = getchar();
        if (command == 'n') s.wykonajTure();
       
    }
    
    
}
