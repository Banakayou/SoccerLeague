#include "Sportif.h"

void Sportif::fonctionVirtuellePure(){ return; }

Sportif::Sportif(){

}
Sportif::Sportif(string newNom, string newPrenom, int newAge) : Personne(newNom, newPrenom, newAge)
{
}

Sportif::~Sportif(){
}