#pragma once
#include <iostream>
#include "Contrat.h"
using namespace std;

class Negociateur;
class Negociation{
private:
	Negociateur* emetteurMessage;
	string sujetMessage = offre;

	float montantCourant;

	Contrat* ContratTemp;

public:
	string offre = "OFFRE";
	string accept = "ACCEPT";
	string reject = "REJECT";

	//constructeurs/destructeurs
	Negociation();
	~Negociation();

	//accesseurs et modificateurs
	void setEmetteur(Negociateur* nego);
	Negociateur* getEmetteur();

	template <class T> void changerSujet(T nouveauSujet);
	string getSujet();

	void setMontantCourant(float newMontant);
	float getMontantCourant();

	void setContratTemp(Contrat newContratTemp);
	Contrat* getContratTemp();
};