#pragma once
#include "Joueur.h"

class JoueurAutonome : public Joueur{
private:
public:
	//constructeurs/destructeurs
	JoueurAutonome();
	JoueurAutonome(string newNom, string newPrenom, int newAge, float newTaille, float newPoids, string newVilleNaissance);
	~JoueurAutonome();
};