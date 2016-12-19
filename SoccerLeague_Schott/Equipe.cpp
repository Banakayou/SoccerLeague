#include "Equipe.h"

//constructeurs/destructeurs
Equipe::Equipe()
{

}
Equipe::Equipe(Club* newClubDeLequipe, int newNbreJoueurs, int newNbreGardiens, Joueur* newCapitaine)
{
	clubDeLequipe = newClubDeLequipe;
	nbreJoueurs = newNbreJoueurs;
	nbreGardiens = newNbreGardiens;
	capitaine = newCapitaine;
}
Equipe::~Equipe(){

}

//accesseurs et modificateurs
void Equipe::setClub(Club* newClub)
{
	clubDeLequipe = newClub;
}
Club* Equipe::getClub()
{
	return clubDeLequipe;
}

void Equipe::setNbreJoueurs(int newNbreJ)
{
	nbreJoueurs = newNbreJ;
}
int Equipe::getNbreJoueurs()
{
	return nbreJoueurs;
}

void Equipe::setNbreGardiens(int newNbreG)
{
	nbreGardiens = newNbreG;
}
int Equipe::getNbreGardiens()
{
	return nbreGardiens;
}

void Equipe::setCapitaine(Joueur* newCapitaine)
{
	capitaine = newCapitaine;
}
Joueur* Equipe::getCapitaine()
{
	return capitaine;
}