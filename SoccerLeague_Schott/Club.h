#pragma once
using namespace std;
#include <iostream>
#include <vector>

#include "Date.h"
#include "Personne.h"
#include "President.h"
#include "Recruteur.h"
#include "Secretaire.h"
#include "InfirmierSpecialise.h"
#include "Sportif.h"
#include "Entraineur.h"
#include "Joueur.h"
#include "JoueurAutonome.h"
#include "JoueurNonAutonome.h"
#include "Parcours.h"
#include "Palmares.h"
#include "TitreGagne.h"
#include "Stade.h"
#include "Contrat.h"
#include "Rupture.h"


class Club{
private:
	string nomClub;
	string villeClub;
	string couleurClub;
	Date anneeCreation;
	string histoireClub;
	Stade stadeClub;
	string adresseClub;
	vector<Joueur*> listeJoueurs;
	vector<Palmares> listePalmares;
	vector<Personne*> listeStaffTechnique;
	vector<Contrat> listeContratsEngagement;
	vector<Rupture> listeRupturesContrats;

public:
	//constructeurs/destructeurs
	Club();
	Club(string newNomClub, string newVilleClub, string newCouleurClub,	/**/int y/*annee de creation*/, string newHistoireClub, Stade newStadeClub, string newAdresseClub);
	~Club();

	//accesseurs et modificateurs
	void setNom(string nouveauNom);
	string getNom();

	void setVille(string nouvelleVille);
	string getVille();

	void setCouleur(string nouvelleCouleur);
	string getCouleur();

	void setAnnee(int y);
	Date getAnnee();

	void setHistoire(string nouvelleHistoire);
	string getHistoire();

	void setStade(Stade nouveauStade);
	Stade getStade();

	void setAdresse(string nouvelleAdresse);
	string getAdresse();

	void ajouterJoueur(Joueur* nouveauJoueur);
	void supprimerJoueur(int i);
	vector<Joueur*> getListeJoueurs();
	vector<Joueur*>::iterator debutListeJoueurs();
	vector<Joueur*>::iterator finListeJoueurs();
	Joueur* getJoueurFromList(int i);

	void ajouterPalmares(Palmares nouveauPalmares);
	void supprimerPalmares(int i);
	vector<Palmares> getListePalmares();
	vector<Palmares>::iterator debutListePalmares();
	vector<Palmares>::iterator finListePalmares();
	Palmares* getPalmaresFromList(int i);

	void ajouterStaff(Personne* nouveauStaff);
	void supprimerStaff(int i);
	vector<Personne*> getListeStaffTechnique();
	vector<Personne*>::iterator debutListeStaffTechnique();
	vector<Personne*>::iterator finListeStaffTechnique();
	Personne* getStaffFromList(int i);

	void ajouterContrat(Contrat nouveauContrat);
	void supprimerContrat(int i);
	vector<Contrat> getListeContrats();
	vector<Contrat>::iterator debutListeContrats();
	vector<Contrat>::iterator finListeContrats();
	Contrat* getContratFromList(int i);

	void ajouterRupture(Rupture nouvelleRupture);
	void supprimerRupture(int i);
	vector<Rupture> getListeRuptures();
	vector<Rupture>::iterator debutListeRuptures();
	vector<Rupture>::iterator finListeRuptures();
	Rupture* getRuptureFromList(int i);	
};