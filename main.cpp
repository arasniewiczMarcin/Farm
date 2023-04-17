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
    //for(int i = 0; i < 5; i++)
    Wilk w('W', 9, 5, &s);
    Wilk w2('W', 9, 5, &s);
    Wilk w3('W', 9, 5, &s);

    s.rysujSwiat();
    
}
