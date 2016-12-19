#pragma once
#include "Joueur.h"

class JoueurNonAutonome : public Joueur{
private:
public:
	//constructeurs/destructeurs
	JoueurNonAutonome();
	JoueurNonAutonome(string newNom, string newPrenom, int newAge, float newTaille, float newPoids, string newVilleNaissance);
	~JoueurNonAutonome();
};