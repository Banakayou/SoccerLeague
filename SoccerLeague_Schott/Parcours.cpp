#include "Parcours.h"

//constructeurs/destructeurs
Parcours::Parcours(){

}
Parcours::Parcours(int d, int m, int y, string newClub)
{
	setDate(d, m, y);
	clubParcours = newClub;
}
Parcours::~Parcours(){

}

//accesseurs et modificateurs
void Parcours::setDate(int d, int m, int y)
{
	date.setAnnee(y);
	date.setMois(m);
	date.setJour(d);
}
Date Parcours::getDate()
{
	return date;
}

void Parcours::setClub(string nouveauClub)
{
	clubParcours = nouveauClub;
}
string Parcours::getClub()
{
	return clubParcours;
}