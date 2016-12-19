#pragma once
#include <iostream>
using namespace std;

class Reglement
{
private:
	string descriptionDroitsJoueur;
	float montantTransfert; //montant total
	float montantClub; //montant encaisse par l'ancien club
	float montantJoueur; // montant restant encaisse par le joueur
public:
	//constructeurs/destructeurs
	Reglement();
	Reglement(string newDescription, float newMontantT, float newMontantC, float newMontantJ);
	~Reglement();

	//accesseurs et modificateurs
	void setDescription(string newDesc);
	string getDescription();

	void setMontantTransfert(float newMontant);
	float getMontantTransfert();

	void setMontantClub(float newMontant);
	float getMontantClub();

	void setMontantJoueur(float newMontant);
	float getMontantJoueur();
};