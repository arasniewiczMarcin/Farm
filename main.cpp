#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Wilk.h"


using namespace std;

int main()
{
    int i = 0;
    Swiat s;
    Wilk w('W', 9, 5, &s);


    s.rysujSwiat();
    
}
