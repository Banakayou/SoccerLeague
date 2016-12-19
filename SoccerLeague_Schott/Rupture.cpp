#include "Rupture.h"

//constructeurs/destructeurs
Rupture::Rupture(){

}
Rupture::Rupture(Joueur* newJoueurParti, string newRaisonsDepart, Club* newClub, float newPenalite){
	joueurParti = newJoueurParti;
	raisonsDepart = newRaisonsDepart;
	nouveauClub = newClub;
	penalite = newPenalite;
}
Rupture::~Rupture(){

}

//accesseurs et modificateurs
void Rupture::setJoueur(Joueur* newJoueurParti){
	joueurParti = newJoueurParti;
}
Joueur* Rupture::getJoueur()
{
	return joueurParti;
}

void Rupture::setRaisons(string newRaisonsDepart)
{
	raisonsDepart = newRaisonsDepart;
}
string Rupture::getRaisons()
{
	return raisonsDepart;
}

void Rupture::setClub(Club* newClub)
{
	nouveauClub = newClub;
}
Club* Rupture::getClub()
{
	return nouveauClub;
}

void Rupture::setPenalite(float newPenalite)
{
	penalite = newPenalite;
}
float Rupture::getPenalite()
{
	return penalite;
}