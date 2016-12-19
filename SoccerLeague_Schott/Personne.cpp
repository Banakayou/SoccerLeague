#include "Personne.h"
//constructeurs/destructeurs
Personne::Personne(){

}
Personne::Personne(string newNom, string newPrenom, int newAge)
{
	nom = newNom;
	prenom = newPrenom;
	age = newAge;
}
Personne::~Personne(){

}

//accesseurs et modificateurs
void Personne::setNom(string nouveauNom)
{
	nom = nouveauNom;
}
string Personne::getNom()
{
	return nom;
}

void Personne::setPrenom(string nouveauPrenom)
{
	prenom = nouveauPrenom;
}
string Personne::getPrenom()
{
	return prenom;
}

void Personne::setAge(int nouvelAge)
{
	age = nouvelAge;
}
int Personne::getAge()
{
	return age; 
}