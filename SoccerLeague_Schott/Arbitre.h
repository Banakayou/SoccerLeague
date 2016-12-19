#pragma once
#include "Sportif.h"

class Arbitre : public Sportif{
private:
	string lieuGraduation;
	int experienceArbitrage;

public:
	//constructeurs/destructeurs
	Arbitre();
	Arbitre(string newNom, string newPrenom, int newAge, string newLieuGraduation, int newExp);
	~Arbitre();

	//accesseurs et modificateurs
	void setLieu(string nouveauLieu);
	string getLieu();

	void setExp(int newExp);
	int getExp();
};