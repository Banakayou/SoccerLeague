#pragma once
using namespace std;

class Resultat{
private:
	int nbreTotalButsEquipeLocale;
	int nbreTotalButsEquipeInvitee;
public:
	//constructeurs/destructeurs
	Resultat();
	Resultat(int newNbreTotalButsEquipeLocale, int newNbreTotalButsEquipeInvitee);
	~Resultat();

	//accesseurs et modificateurs
	void setNbreTotalButsEquipeLocale(int newNbreTotalButsEquipeLocale);
	int getNbreTotalButsEquipeLocale();

	void setNbreTotalButsEquipeInvitee(int newNbreTotalButsEquipeInvitee);
	int getNbreTotalButsEquipeInvitee();
};