#include "Periode.h"

//constructeurs/destructeurs
Periode::Periode(){

}
Periode::Periode(int newDureePeriode, int newNbreButsLocale, int newNbreButsInvitee){
	dureePeriode = newDureePeriode;
	nbreButsEquipeLocale = newNbreButsLocale;
	nbreButsEquipeInvitee = newNbreButsInvitee;
}
Periode::~Periode(){

}

//accesseurs et modificateurs
void Periode::setDureePeriode(int newDureePeriode)
{
	dureePeriode = newDureePeriode;
}
int Periode::getDureePeriode()
{
	return dureePeriode;
}

void Periode::setNbreButsEquipeLocale(int newNbreButsLocale)
{
	nbreButsEquipeLocale = newNbreButsLocale;
}
int Periode::getNbreButsEquipeLocale()
{
	return nbreButsEquipeLocale;
}

void Periode::setNbreButsEquipeInvitee(int newNbreButsInvitee)
{
	nbreButsEquipeInvitee = newNbreButsInvitee;
}
int Periode::getNbreButsEquipeInvitee()
{
	return nbreButsEquipeInvitee;
}