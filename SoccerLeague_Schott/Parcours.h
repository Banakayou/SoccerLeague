#pragma once
using namespace std;
#include <iostream>
#include "Date.h"


class Parcours{
private:
	Date date; 
	string clubParcours;

public:
	//constructeurs/destructeurs
	Parcours();
	Parcours(int d, int m, int y, string newClub);
	~Parcours();

	//accesseurs et modificateurs
	void setDate(int d, int m, int y);
	Date getDate();

	void setClub(string nouveauClub);
	string getClub();
};
