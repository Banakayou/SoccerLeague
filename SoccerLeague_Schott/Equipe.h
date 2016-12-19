#pragma once
using namespace std;
#include "Club.h"

class Equipe{
private:
	Club* clubDeLequipe;
	int nbreJoueurs;
	int nbreGardiens;
	Joueur* capitaine;

public:
	//constructeurs/destructeurs
	Equipe();
	Equipe(Club* newClubDeLequipe, int newNbreJoueurs, int newNbreGardiens, Joueur* newCapitaine);
	~Equipe();

	//accesseurs et modificateurs
	void setClub(Club* newClub);
	Club* getClub();

	void setNbreJoueurs(int newNbreJ);
	int getNbreJoueurs();

	void setNbreGardiens(int newNbreG);
	int getNbreGardiens();

	void setCapitaine(Joueur* newCapitaine);
	Joueur* getCapitaine();
};