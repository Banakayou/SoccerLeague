#include "Entraineur.h"

//constructeurs/destructeurs
Entraineur::Entraineur(){

}
Entraineur::Entraineur(string newNom, string newPrenom, int newAge, string newLieuGraduation) : Sportif(newNom, newPrenom, newAge)
{
	lieuGraduation=newLieuGraduation;
}

Entraineur::~Entraineur(){
}

//accesseurs et modificateurs
void Entraineur::setLieu(string nouveauLieu)
{
	lieuGraduation = nouveauLieu;
}
string Entraineur::getLieu()
{
	return lieuGraduation;
}

void Entraineur::ajouterTitre(TitreGagne newTitre)
{
	titres.push_back(newTitre);
}
void Entraineur::supprimerTitre(int i)
{
	titres.erase(debutListeTitres() + i);
}
vector<TitreGagne> Entraineur::getTitres()
{
	return titres; 
}
vector<TitreGagne>::iterator Entraineur::debutListeTitres()
{
	return titres.begin();
}
vector<TitreGagne>::iterator Entraineur::finListeTitres()
{
	return titres.end();
}
TitreGagne* Entraineur::getTitreFromList(int i)
{
	return &titres[i];
}