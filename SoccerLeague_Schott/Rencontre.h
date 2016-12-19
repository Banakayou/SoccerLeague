#pragma once
using namespace std;
#include "Date.h"
#include "Club.h"
#include "Match.h"

class Rencontre{
private:
	Date dateRencontre;
	Club* clubLocal;
	Club* clubInvite;
	Match* matchRencontre = nullptr;
public:
	//constructeurs/destructeurs
	Rencontre();
	Rencontre(Date newDateRencontre, Club* newClubLocal, Club* newClubInvite);
	~Rencontre();

	//accesseurs et modificateurs
	void setDateRencontre(Date newDate);
	Date getDateRencontre();

	void setClubLocal(Club* newClubLocal);
	Club* getClubLocal();

	void setClubInvite(Club* newClubInvite);
	Club* getClubInvite();

	void setMatchRencontre(Match* newMatchRencontre);
	Match* getMatchRencontre();

};