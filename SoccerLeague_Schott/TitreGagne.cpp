#include "TitreGagne.h"

//constructeurs/destructeurs
TitreGagne::TitreGagne(){

}
TitreGagne::TitreGagne(string newTitre, /**/int d, int m, int y/*date*/, Club* newClub) : Palmares(newTitre, d, m, y)
{
	clubTitre = newClub;
}
TitreGagne::~TitreGagne(){

}

//accesseurs et modificateurs
void TitreGagne::setClub(Club* nouveauClub)
{
	clubTitre = nouveauClub;
}
Club* TitreGagne::getClub()
{
	return clubTitre;
}