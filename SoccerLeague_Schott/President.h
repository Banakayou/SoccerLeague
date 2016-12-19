#pragma once
#include "Personne.h"

class President : public Personne{
private:
	void fonctionVirtuellePure();
public:
	//constructeurs/destructeurs
	President();
	President(string newNom, string newPrenom, int newAge);
	~President();
};
