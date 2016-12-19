#include "Arbitre.h"

//constructeurs/destructeurs
Arbitre::Arbitre(){

}
Arbitre::Arbitre(string newNom, string newPrenom, int newAge, string newLieuGraduation, int newExp) : Sportif(newNom, newPrenom, newAge)
{
	lieuGraduation = newLieuGraduation;
	experienceArbitrage = newExp;
}

Arbitre::~Arbitre(){
}

//accesseurs et modificateurs
void Arbitre::setLieu(string nouveauLieu)
{
	lieuGraduation = nouveauLieu;
}
string Arbitre::getLieu()
{
	return lieuGraduation;
}

void Arbitre::setExp(int newExp)
{
	experienceArbitrage = newExp;
}
int Arbitre::getExp()
{
	return experienceArbitrage;
}