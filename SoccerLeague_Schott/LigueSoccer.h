#pragma once
using namespace std;
#include <iostream>

#include "Club.h"
#include "Rencontre.h"


class LigueSoccer{
private:
	string nomLigue;
	vector<Club> listeClubs;
	vector<Rencontre> calendrierRencontres;

public:
	//constructeurs/destructeurs
	LigueSoccer();
	LigueSoccer(string newNom);
	~LigueSoccer();

	//accesseurs et modificateurs
	void setNom(string newNom);
	string getNom();

	void ajouterClub(Club newClub);
	void supprimerClub(int i);
	vector<Club> getListeClubs();
	vector<Club>::iterator debutListeClub();
	vector<Club>::iterator finListeClub();
	Club* getClubFromList(int i);

	void ajouterRencontre(Rencontre newRencontre);
	void supprimerRencontre(int i);
	vector<Rencontre> getCalendrierRencontres();
	vector<Rencontre>::iterator debutCalendrierRencontres();
	vector<Rencontre>::iterator finCalendrierRencontres();
	Rencontre* getRencontreFromList(int i);
};