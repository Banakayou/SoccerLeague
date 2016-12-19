#include "Secretaire.h"

void Secretaire::fonctionVirtuellePure(){ return; }

//constructeurs/destructeurs
Secretaire::Secretaire(){

}
Secretaire::Secretaire(string newNom, string newPrenom, int newAge) : Personne(newNom, newPrenom, newAge)
{
}

Secretaire::~Secretaire(){

}