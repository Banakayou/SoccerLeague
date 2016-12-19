#include "Reglement.h"


//constructeurs/destructeurs
Reglement::Reglement()
{
}

Reglement::Reglement(string newDescription, float newMontantT, float newMontantC, float newMontantJ)
{
	descriptionDroitsJoueur = newDescription;
	montantTransfert = newMontantT;
	montantClub = newMontantC;
	montantJoueur = newMontantJ;
}

Reglement::~Reglement()
{

}
//accesseurs et modificateurs
void Reglement::setDescription(string newDesc)
{
	descriptionDroitsJoueur = newDesc;
}
string Reglement::getDescription()
{
	return descriptionDroitsJoueur;
}

void Reglement::setMontantTransfert(float newMontant)
{
	montantTransfert = newMontant;
}
float Reglement::getMontantTransfert()
{
	return montantTransfert;
}

void Reglement::setMontantClub(float newMontant)
{
	montantClub = newMontant;
}
float Reglement::getMontantClub()
{
	return montantClub;
}

void Reglement::setMontantJoueur(float newMontant)
{
	montantJoueur = newMontant;
}
float Reglement::getMontantJoueur()
{
	return montantJoueur;
}