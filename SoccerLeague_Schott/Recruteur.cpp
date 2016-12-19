#include "Recruteur.h"

void Recruteur::fonctionVirtuellePure(){ return; }
//constructeurs/destructeurs
Recruteur::Recruteur()
{
}
Recruteur::Recruteur(string newNom, string newPrenom, int newAge) : Personne(newNom, newPrenom, newAge)
{
}

Recruteur::~Recruteur(){

}