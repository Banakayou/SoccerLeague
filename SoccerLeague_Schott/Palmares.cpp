#include "Palmares.h"

//constructeurs/destructeurs
Palmares::Palmares(){

}
Palmares::Palmares(string newTitre, /**/int d, int m, int y/*date*/)
{
	titre = newTitre;
	setDate(d, m, y);
}

Palmares::~Palmares(){

}

//accesseurs et modificateurs
void Palmares::setTitre(string nouveauTitre)
{
	titre = nouveauTitre;
}
string Palmares::getTitre()
{
	return titre;
}

void Palmares::setDate(int d, int m, int y)
{
	date.setJour(d);
	date.setMois(m);
	date.setAnnee(y);
}
Date Palmares::getDate()
{
	return date;
}