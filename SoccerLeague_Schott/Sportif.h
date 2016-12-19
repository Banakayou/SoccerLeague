#pragma once
#include <vector>
#include "Personne.h"

class Sportif abstract : public Personne{ //classe abstraite pour faire h�riter Joueur, Entraineur, et Arbitre.
private:
	void fonctionVirtuellePure();
public:
	//constructeurs/destructeurs
	Sportif();
	Sportif(string newNom, string newPrenom, int newAge);
	~Sportif();
};
