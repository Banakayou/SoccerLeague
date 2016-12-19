#include "Stade.h"

//constructeurs/destructeurs
Stade::Stade(){

}
Stade::Stade(int newCapacite=0, string newQualite="pelouse", string newNom="Stade", string newAdresse="Adresse")
{
	capacite = newCapacite;
	qualite = newQualite;
	nom = newNom;
	adresse = newAdresse;
}
Stade::~Stade(){

}

//accesseurs et modificateurs
void Stade::setCapacite(int nouvelleCapacite){
	capacite = nouvelleCapacite;
}
int Stade::getCapacite(){
	return capacite;
}

void Stade::setQualite(string nouvelleQualite)
{
	qualite = nouvelleQualite;
}
string Stade::getQualite()
{
	return qualite;
}

void Stade::setNom(string nouveauNom)
{
	nom = nouveauNom;
}
string Stade::getNom()
{
	return nom;
}

void Stade::setAdresse(string nouvelleAdresse)
{
	adresse = nouvelleAdresse;
}
string Stade::getAdresse()
{
	return adresse;
}