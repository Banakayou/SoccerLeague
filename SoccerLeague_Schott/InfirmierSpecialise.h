#pragma once
#include "Personne.h"

class InfirmierSpecialise : public Personne{
private:
	void fonctionVirtuellePure();
public:
	//constructeurs/destructeurs
	InfirmierSpecialise();
	InfirmierSpecialise(string newNom, string newPrenom, int newAge);
	~InfirmierSpecialise();
};
