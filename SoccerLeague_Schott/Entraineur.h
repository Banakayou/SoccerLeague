#pragma once
#include "Sportif.h"
#include "TitreGagne.h"

class Entraineur : public Sportif{
private:
	string lieuGraduation;
	vector<TitreGagne> titres;

public:
	//constructeurs/destructeurs
	Entraineur();
	Entraineur(string newNom, string newPrenom, int newAge, string newLieuGraduation);
	~Entraineur();

	//accesseurs et modificateurs
	void setLieu(string nouveauLieu);
	string getLieu();

	void ajouterTitre(TitreGagne newTitre);
	void supprimerTitre(int i);
	vector<TitreGagne> getTitres();
	vector<TitreGagne>::iterator debutListeTitres();
	vector<TitreGagne>::iterator finListeTitres();
	TitreGagne* getTitreFromList(int i);
};