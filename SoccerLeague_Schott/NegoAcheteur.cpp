#include "NegoAcheteur.h"

NegoAcheteur::NegoAcheteur() : Personne(), Negociateur(){

}

NegoAcheteur::~NegoAcheteur(){

}

void NegoAcheteur::fonctionVirtuellePure(){

}

void NegoAcheteur::proposerOffre(){

}
void NegoAcheteur::accepterOffre(){

}
void NegoAcheteur::refuserOffre(){

}

void NegoAcheteur::updateMontantDesire(HANDLE unMutex, float tempsEcoule){
	//thread d'augmentation du montant desire
	//catch mutex
	setMontantDesire(getMontantDesire() + tempsEcoule);
	//release mutex	
}