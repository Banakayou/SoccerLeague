#pragma once
using namespace std;
#include "Negociateur.h"
#include "Personne.h"

class NegoAcheteur : public Personne, public Negociateur{
private:
	void fonctionVirtuellePure();
public:
	NegoAcheteur();
	~NegoAcheteur();

	void proposerOffre();
	void accepterOffre();
	void refuserOffre();

	void updateMontantDesire(HANDLE unMutex, float tempsEcoule);

};