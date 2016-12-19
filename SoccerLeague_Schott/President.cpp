#include "President.h"

void President::fonctionVirtuellePure(){ return; }
//constructeurs/destructeurs
President::President(){

}
President::President(string newNom, string newPrenom, int newAge) : Personne(newNom, newPrenom, newAge)
{
}

President::~President(){

}