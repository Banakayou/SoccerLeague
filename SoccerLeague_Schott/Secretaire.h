#pragma once
#include "Personne.h"

class Secretaire : public Personne{
private:
	void fonctionVirtuellePure();
public:
	//constructeurs/destructeurs
	Secretaire();
	Secretaire(string newNom, string newPrenom, int newAge);
	~Secretaire();
};