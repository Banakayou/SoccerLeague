#pragma once
using namespace std;
#include <iostream>
#include "Date.h"

class Palmares{
protected:
	string titre;
	Date date; 

public:
	//constructeurs/destructeurs
	Palmares();
	Palmares(string newTitre, /**/int d, int m, int y/*date*/);
	~Palmares();

	//accesseurs et modificateurs
	void setTitre(string nouveauTitre);
	string getTitre();

	void setDate(int d, int m, int y);
	Date getDate();
};

