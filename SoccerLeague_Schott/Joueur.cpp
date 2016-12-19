#include "Joueur.h"

//constructeurs/destructeurs
Joueur::Joueur(){

}
Joueur::Joueur(string newNom, string newPrenom, int newAge, float newTaille, float newPoids, string newVilleNaissance) : Sportif(newNom, newPrenom, newAge)
{
	taille = newTaille;
	poids = newPoids;
	villeNaissance = newVilleNaissance;
}
Joueur::~Joueur(){

}

//accesseurs
void Joueur::setTaille(float nouvelleTaille)
{
	taille = nouvelleTaille;
}
float Joueur::getTaille()
{
	return taille;
}

void Joueur::setPoids(float nouveauPoids)
{
	poids = nouveauPoids;
}
float Joueur::getPoids()
{
	return poids;
}

void Joueur::setVille(string nouvelleVille)
{
	villeNaissance = nouvelleVille;
}
string Joueur::getVille()
{
	return villeNaissance;
}

void Joueur::ajouterParcours(Parcours nouveauParcours)
{
	parcoursJoueur.push_back(nouveauParcours);
}
void Joueur::supprimerParcours(int i)
{
	parcoursJoueur.erase(debutListeParcours() + i);
}
vector<Parcours> Joueur::getParcours()
{
	return parcoursJoueur;
}
vector<Parcours>::iterator Joueur::debutListeParcours()
{
	return parcoursJoueur.begin();
}
vector<Parcours>::iterator Joueur::finListeParcours()
{
	return parcoursJoueur.end();
}
Parcours* Joueur::getParcoursFromList(int i)
{
	return &parcoursJoueur[i];
}