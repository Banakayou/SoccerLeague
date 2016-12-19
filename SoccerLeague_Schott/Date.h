#pragma once
using namespace std;
#include <iostream>

class Date {
private:
	int annee;
	int mois;
	int jour;
public:
	//constructeurs/destructeurs
	Date();
	Date(int newAnnee, int newMois,	int newJour);
	~Date();

	//accesseurs et modificateurs
	void setAnnee(int newAnnee);
	int getAnnee();

	void setMois(int newMois);
	int getMois();

	void setJour(int newJour);
	int getJour();
};