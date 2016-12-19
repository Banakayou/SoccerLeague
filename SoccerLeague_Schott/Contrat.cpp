#include "Contrat.h"

//constructeurs/destructeurs
Contrat::Contrat(){

}
Contrat::Contrat(Joueur* newJoueurContractant, Club* newClubContractant, Club* newClubLibere, int newDuree, int newAnneeEntree, int newMoisEntree, int newJourEntree, Reglement newReglement, int newAnneeContrat, int newMoisContrat, int newJourContrat)
{
	joueurContractant = newJoueurContractant;
	clubContractant = newClubContractant;
	clubLibere = newClubLibere;
	dureeContrat = newDuree;
	setDateEntree(newAnneeEntree, newMoisEntree, newJourEntree);
	reglement = newReglement;
	setDateContrat(newAnneeContrat, newMoisContrat, newJourContrat);
}
Contrat::~Contrat(){

}

//accesseurs et modificateurs
void Contrat::setJoueur(Joueur* newJoueur)
{
	joueurContractant = newJoueur;
}
Joueur* Contrat::getJoueur()
{
	return joueurContractant;
}

void Contrat::setClubContractant(Club* newClub)
{
	clubContractant = newClub;
}

Club* Contrat::getClubContractant()
{
	return clubContractant;
}

void Contrat::setClubLibere(Club* newClub)
{
	clubLibere = newClub;
}
Club* Contrat::getClubLibere()
{
	return clubLibere;
}

void Contrat::setDuree(int newDuree)
{
	dureeContrat = newDuree;
}
int Contrat::getDuree()
{
	return dureeContrat;
}

void Contrat::setDateEntree(int anneeEntree, int moisEntree, int jourEntree)
{
	dateEntree.setAnnee(anneeEntree);
	dateEntree.setMois(moisEntree);
	dateEntree.setJour(jourEntree);
}
Date Contrat::getDateEntree()
{
	return dateEntree;
}

void Contrat::setReglement(Reglement newReglement)
{
	reglement = newReglement;
}
Reglement Contrat::getReglement()
{
	return reglement;
}

void Contrat::setDateContrat(int anneeContrat, int moisContrat, int jourContrat)
{
	dateContrat.setAnnee(anneeContrat);
	dateContrat.setMois(moisContrat);
	dateContrat.setJour(jourContrat);
}
Date Contrat::getDateContrat()
{
	return dateContrat;
}