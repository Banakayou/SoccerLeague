#include "Negociation.h"

//constructeurs/destructeurs
Negociation::Negociation(){

}
Negociation::~Negociation(){

}

//accesseurs et modificateurs

void Negociation::setEmetteur(Negociateur* nego){
	emetteurMessage = nego;
}
Negociateur* Negociation::getEmetteur(){
	return emetteurMessage;
}

template <class T> void Negociation::changerSujet(T nouveauSujet){ //fonction template pour changer le sujet avec un parametre de plusieurs types possibles
	int* entier = dynamic_cast<int*>(T);
	if (entier != nullptr){
		if (i == 0){
			sujetMessage = offre;
		}
		else if (i == 1){
			sujetMessage = accept;
		}
		else if (i == 2){
			sujetMessage = reject;
		}
	}
	string* chaine = dynamic_cast<string*>(T);
	if (chaine != nullptr){
		if (chaine == offre){
			sujetMessage = offre;
		}
		else if (chaine == accept){
			sujetMessage = accept;
		}
		else if (chaine == reject){
			sujetMessage = reject;
		}
	}
	
}
string Negociation::getSujet(){
	return sujetMessage;
}

void Negociation::setMontantCourant(float newMontant){
	montantCourant = newMontant;
}
float Negociation::getMontantCourant(){
	return montantCourant;
}

void Negociation::setContratTemp(Contrat newContratTemp){
	*ContratTemp = newContratTemp;
}
Contrat* Negociation::getContratTemp(){
	return ContratTemp;
}
