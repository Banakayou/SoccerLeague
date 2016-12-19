#include "Resultat.h"

//constructeurs/destructeurs
Resultat::Resultat()
{

}
Resultat::Resultat(int newNbreTotalButsEquipeLocale, int newNbreTotalButsEquipeInvitee)
{
	nbreTotalButsEquipeLocale = newNbreTotalButsEquipeLocale;
	nbreTotalButsEquipeInvitee = newNbreTotalButsEquipeInvitee;
}
Resultat::~Resultat()
{

}

//accesseurs et modificateurs
void Resultat::setNbreTotalButsEquipeLocale(int newNbreTotalButsEquipeLocale)
{
	nbreTotalButsEquipeLocale = newNbreTotalButsEquipeLocale;
}
int Resultat::getNbreTotalButsEquipeLocale()
{
	return nbreTotalButsEquipeLocale;
}

void Resultat::setNbreTotalButsEquipeInvitee(int newNbreTotalButsEquipeInvitee)
{
	nbreTotalButsEquipeInvitee = newNbreTotalButsEquipeInvitee;
}
int Resultat::getNbreTotalButsEquipeInvitee()
{
	return nbreTotalButsEquipeInvitee;
}