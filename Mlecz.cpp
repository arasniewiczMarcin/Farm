#include "Mlecz.h"

void Mlecz::akcja(Swiat* swiat) {
	Roslina::akcja(swiat);
	Roslina::akcja(swiat);
	Roslina::akcja(swiat);
}
Mlecz::Mlecz(char pionek, int sila, int inicjatywa, bool ruch, Swiat* swiat, Polozenie polozenie)
	:Roslina(pionek, sila, inicjatywa, ruch, swiat, polozenie)
{
}
Mlecz::~Mlecz() {

}