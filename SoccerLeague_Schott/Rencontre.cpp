#include "Rencontre.h"

//constructeurs/destructeurs
Rencontre::Rencontre(){

}
Rencontre::Rencontre(Date newDateRencontre, Club* newClubLocal, Club* newClubInvite){
	dateRencontre = newDateRencontre;
	clubLocal = newClubLocal;
	clubInvite = newClubInvite;
}
Rencontre::~Rencontre(){

}

//accesseurs et modificateurs
void Rencontre::setDateRencontre(Date newDate)
{
	dateRencontre = newDate;
}
Date Rencontre::getDateRencontre()
{
	return dateRencontre;
}

void Rencontre::setClubLocal(Club* newClubLocal)
{
	clubLocal = newClubLocal;
}
Club* Rencontre::getClubLocal()
{
	return clubLocal;
}

void Rencontre::setClubInvite(Club* newClubInvite)
{
	clubInvite = newClubInvite;
}
Club* Rencontre::getClubInvite()
{
	return clubInvite;
}

void Rencontre::setMatchRencontre(Match* newMatchRencontre)
{
	matchRencontre = newMatchRencontre;
}
Match* Rencontre::getMatchRencontre()
{
	return matchRencontre;
}