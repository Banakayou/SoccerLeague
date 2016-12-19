#pragma once
using namespace std;
#include <iostream>

class Stade{
private:
	int capacite;
	string qualite;
	string nom;
	string adresse;

public:
	//constructeurs/destructeurs
	Stade();
	Stade(int newCapacite, string newQualite, string newNom, string newAdresse);
	~Stade();

	//accesseurs et modificateurs
	void setCapacite(int nouvelleCapacite);
	int getCapacite();

	void setQualite(string nouvelleQualite);
	string getQualite();

	void setNom(string nouveauNom);
	string getNom();

	void setAdresse(string nouvelleAdresse);
	string getAdresse();
};