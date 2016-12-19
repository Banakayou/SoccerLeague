#pragma once
#include "Sportif.h"
#include "Parcours.h"

class Joueur abstract : public Sportif{
private:
	float taille;
	float poids;
	string villeNaissance;
	vector<Parcours> parcoursJoueur;

public:
	//constructeurs/destructeurs
	Joueur();
	Joueur(string newNom, string newPrenom, int newAge, float newTaille, float newPoids, string newVilleNaissance);
	~Joueur();

	//accesseurs
	void setTaille(float nouvelleTaille);
	float getTaille();

	void setPoids(float nouveauPoids);
	float getPoids();

	void setVille(string nouvelleVille);
	string getVille();

	void ajouterParcours(Parcours nouveauParcours);
	void supprimerParcours(int i);
	vector<Parcours> getParcours();
	vector<Parcours>::iterator debutListeParcours();
	vector<Parcours>::iterator finListeParcours();
	Parcours* getParcoursFromList(int i);
};


