#include "Club.h"

//constructeurs/destructeurs
Club::Club(){

}
Club::Club(string newNomClub, string newVilleClub, string newCouleurClub,	/**/int y/*annee de creation*/, string newHistoireClub, Stade newStadeClub, string newAdresseClub)
{
	nomClub = newNomClub;
	villeClub = newVilleClub;
	couleurClub = newCouleurClub;
	anneeCreation.setAnnee(y);
	histoireClub = newHistoireClub;
	stadeClub = newStadeClub;
	adresseClub = newAdresseClub;
}

Club::~Club()
{
}

//accesseurs et modificateurs
void Club::setNom(string nouveauNom)
{
	nomClub = nouveauNom;
}
string Club::getNom()
{
	return nomClub;
}

void Club::setVille(string nouvelleVille)
{
	villeClub = nouvelleVille;
}
string Club::getVille()
{
	return villeClub;
}

void Club::setCouleur(string nouvelleCouleur)
{
	couleurClub = nouvelleCouleur;
}
string Club::getCouleur()
{
	return couleurClub;
}

void Club::setAnnee(int y)
{
	anneeCreation.setAnnee(y);
}
Date Club::getAnnee()
{
	return anneeCreation;
}

void Club::setHistoire(string nouvelleHistoire)
{
	histoireClub = nouvelleHistoire;
}
string Club::getHistoire()
{
	return histoireClub;
}

void Club::setStade(Stade nouveauStade)
{
	stadeClub = nouveauStade;
}
Stade Club::getStade()
{
	return stadeClub;
}

void Club::setAdresse(string nouvelleAdresse)
{
	adresseClub = nouvelleAdresse;
}
string Club::getAdresse()
{
	return adresseClub;
}


void Club::ajouterJoueur(Joueur* nouveauJoueur)
{
	listeJoueurs.push_back(nouveauJoueur);
}
void Club::supprimerJoueur(int i)
{
	listeJoueurs.erase(debutListeJoueurs() + i);
}
vector<Joueur*> Club::getListeJoueurs()
{
	return listeJoueurs;
}
vector<Joueur*>::iterator Club::debutListeJoueurs()
{
	return listeJoueurs.begin();
}
vector<Joueur*>::iterator Club::finListeJoueurs()
{
	return listeJoueurs.end();
}
Joueur* Club::getJoueurFromList(int i)
{
	return listeJoueurs[i];
}

void Club::ajouterPalmares(Palmares nouveauPalmares)
{
	listePalmares.push_back(nouveauPalmares);
}
void Club::supprimerPalmares(int i)
{
	listePalmares.erase(debutListePalmares() + i);
}
vector<Palmares> Club::getListePalmares()
{
	return listePalmares;
}
vector<Palmares>::iterator Club::debutListePalmares()
{
	return listePalmares.begin();
}
vector<Palmares>::iterator Club::finListePalmares()
{
	return listePalmares.end();
}
Palmares* Club::getPalmaresFromList(int i)
{
	return &listePalmares[i];
}

void Club::ajouterStaff(Personne* nouveauStaff)
{
	listeStaffTechnique.push_back(nouveauStaff);
}
void Club::supprimerStaff(int i)
{
	listeStaffTechnique.erase(debutListeStaffTechnique() + i);
}
vector<Personne*> Club::getListeStaffTechnique()
{
	return listeStaffTechnique;
}
vector<Personne*>::iterator Club::debutListeStaffTechnique()
{
	return listeStaffTechnique.begin();
}
vector<Personne*>::iterator Club::finListeStaffTechnique()
{
	return listeStaffTechnique.end();
}
Personne* Club::getStaffFromList(int i)
{
	return listeStaffTechnique[i];
}

void Club::ajouterContrat(Contrat nouveauContrat)
{
	listeContratsEngagement.push_back(nouveauContrat);
}
void Club::supprimerContrat(int i)
{
	listeContratsEngagement.erase(debutListeContrats() + i);
}
vector<Contrat> Club::getListeContrats()
{
	return listeContratsEngagement;
}
vector<Contrat>::iterator Club::debutListeContrats()
{
	return listeContratsEngagement.begin();
}
vector<Contrat>::iterator Club::finListeContrats()
{
	return listeContratsEngagement.end();
}
Contrat* Club::getContratFromList(int i)
{
	return &listeContratsEngagement[i];
}

void Club::ajouterRupture(Rupture nouvelleRupture)
{
	listeRupturesContrats.push_back(nouvelleRupture);
}
void Club::supprimerRupture(int i)
{
	listeRupturesContrats.erase(debutListeRuptures() + i);
}
vector<Rupture> Club::getListeRuptures()
{
	return listeRupturesContrats;
}
vector<Rupture>::iterator Club::debutListeRuptures()
{
	return listeRupturesContrats.begin();
}
vector<Rupture>::iterator Club::finListeRuptures()
{
	return listeRupturesContrats.end();
}
Rupture* Club::getRuptureFromList(int i)
{
	return &listeRupturesContrats[i];
}
