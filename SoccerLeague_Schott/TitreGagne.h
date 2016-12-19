#pragma once
#include "Palmares.h"

class Club;
class TitreGagne : public Palmares{
private :
	Club* clubTitre;
public:
	//constructeurs/destructeurs
	TitreGagne();
	TitreGagne(string newTitre, /**/int d, int m, int y/*date*/, Club* newClub);
	~TitreGagne();

	//accesseurs et modificateurs
	void setClub(Club* nouveauClub);
	Club* getClub();
};
