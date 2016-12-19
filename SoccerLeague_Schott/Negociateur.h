#pragma once
using namespace std;
#include "Club.h"
#include "Negociation.h"
#include <Windows.h>
#include <mutex>

class Negociateur abstract{
private:
	float montantDesire;
	float montantExtreme;//minimum pour vendeur et maximum pour acheteur
	float dureeNegociation=0;
	Club* clubRepresente;

	vector<Negociation> listeMessages;

public:

	Negociateur();
	~Negociateur();
	
	mutex unMutex;
	virtual void proposerOffre() abstract;
	virtual void accepterOffre() abstract;
	virtual void refuserOffre() abstract;

	virtual void updateMontantDesire(HANDLE unMutex, float tempsEcoule) abstract;


	void setMontantDesire(float newMontant);
	float getMontantDesire();

	void setMontantExtreme(float newMontant);
	float getMontantExtreme();

	void setDureeNegocation(float newDuree);
	float getDureeNegocation();	

	void ajouterMessage(Negociation newMessage);
	void supprimerMessage(int i);
	vector<Negociation> getListeMessages();
	vector<Negociation>::iterator debutListeMessages();
	vector<Negociation>::iterator finListeMessages();
	Negociation* getMessageFromList(int i);


};