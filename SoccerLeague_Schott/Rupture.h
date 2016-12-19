#pragma once
using namespace std;
#include "Joueur.h"

class Club;
class Rupture{
private:
	Joueur* joueurParti;
	string raisonsDepart;
	Club* nouveauClub;
	float penalite;

public:
	//constructeurs/destructeurs
	Rupture();
	Rupture(Joueur* newJoueurParti, string newRaisonsDepart, Club* newClub, float newPenalite);
	~Rupture();

	//accesseurs et modificateurs
	void setJoueur(Joueur* newJoueurParti);
	Joueur* getJoueur();

	void setRaisons(string newRaisonsDepart);
	string getRaisons();

	void setClub(Club* newClub);
	Club* getClub();

	void setPenalite(float newPenalite);
	float getPenalite();
};