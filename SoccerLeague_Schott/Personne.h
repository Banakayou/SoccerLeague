#pragma once
using namespace std;
#include <iostream>

class Personne abstract//Classe de base pour hériter de tous les types de personnes
{
protected:
	string nom;
	string prenom;
	int age;
	virtual void fonctionVirtuellePure() abstract;

public:
	//constructeurs/destructeurs
	Personne();
	Personne(string newNom, string newPrenom, int newAge);
	~Personne();

	//accesseurs et modificateurs
	void setNom(string nouveauNom);
	string getNom();

	void setPrenom(string nouveauPrenom);
	string getPrenom();

	void setAge(int nouvelAge);
	int getAge();
};
