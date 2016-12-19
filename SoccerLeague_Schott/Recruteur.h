#pragma once
#include "Personne.h"

class Recruteur : public Personne{
private:
	void fonctionVirtuellePure();
public:
	//constructeurs/destructeurs
	Recruteur();
	Recruteur(string newNom, string newPrenom, int newAge);
	~Recruteur();
};
