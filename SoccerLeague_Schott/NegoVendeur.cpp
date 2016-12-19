#include "NegoVendeur.h"

NegoVendeur::NegoVendeur() : Personne(), Negociateur(){

}

NegoVendeur::~NegoVendeur(){

}

void NegoVendeur::fonctionVirtuellePure(){
}

void NegoVendeur::proposerOffre(){

}
void NegoVendeur::accepterOffre(){

}
void NegoVendeur::refuserOffre(){

}

void NegoVendeur::updateMontantDesire(HANDLE unMutex, float tempsEcoule){
	//thread de diminution du montant desire
	//catch mutex
	setMontantDesire(getMontantDesire() - tempsEcoule);
	//release mutex	
}