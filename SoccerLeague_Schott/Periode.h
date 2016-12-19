#pragma once
using namespace std;

class Periode{
private:
	int dureePeriode;
	int nbreButsEquipeLocale;
	int nbreButsEquipeInvitee;

public:
	//constructeurs/destructeurs
	Periode();
	Periode(int newDureePeriode, int newNbreButsLocale, int newNbreButsInvitee);
	~Periode();

	//accesseurs et modificateurs
	void setDureePeriode(int newDureePeriode);
	int getDureePeriode();

	void setNbreButsEquipeLocale(int newNbreButsLocale);
	int getNbreButsEquipeLocale();

	void setNbreButsEquipeInvitee(int newNbreButsInvitee);
	int getNbreButsEquipeInvitee();
};