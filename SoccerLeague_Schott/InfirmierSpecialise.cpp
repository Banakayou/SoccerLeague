#include "InfirmierSpecialise.h"

void InfirmierSpecialise::fonctionVirtuellePure(){ return; }
//constructeurs/destructeurs
InfirmierSpecialise::InfirmierSpecialise(){

}
InfirmierSpecialise::InfirmierSpecialise(string newNom, string newPrenom, int newAge) : Personne(newNom, newPrenom, newAge)
{
}

InfirmierSpecialise::~InfirmierSpecialise()
{

}
