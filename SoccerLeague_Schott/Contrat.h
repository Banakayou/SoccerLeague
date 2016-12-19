#pragma once
using namespace std;
#include "Joueur.h"
#include "Reglement.h"
#include "Date.h"
class Club;
class Contrat
{
private:
	Joueur* joueurContractant;
	Club* clubContractant; //nouveau club
	Club* clubLibere; //ancien club
	int dureeContrat;
	Date dateEntree;
	Reglement reglement;
	Date dateContrat;
	
public:
	//constructeurs/destructeurs
	Contrat();
	Contrat(Joueur* newJ, Club* newClubContractant, Club* newClubLibere, int newDuree, int anneeEntree, int moisEntree, int jourEntree, Reglement nouveauReglement, int anneeContrat, int moisContrat, int jourContrat);
	~Contrat();

	//accesseurs et modificateurs
	void setJoueur(Joueur* newJoueur);
	Joueur* getJoueur();

	void setClubContractant(Club* newClub);
	Club* getClubContractant();

	void setClubLibere(Club* newClub);
	Club* getClubLibere();

	void setDuree(int newDuree);
	int getDuree();

	void setDateEntree(int anneeEntree, int moisEntree, int jourEntree);
	Date getDateEntree();

	void setReglement(Reglement newReglement);
	Reglement getReglement();

	void setDateContrat(int anneeContrat, int moisContrat, int jourContrat);
	Date getDateContrat();
};
