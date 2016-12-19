#pragma once
using namespace std;
#include "Negociateur.h"
#include "Personne.h"

class NegoVendeur : public Personne, public Negociateur{
private:
	void fonctionVirtuellePure();
public:

	NegoVendeur();
	~NegoVendeur();

	void proposerOffre();
	void accepterOffre();
	void refuserOffre();

	void updateMontantDesire(HANDLE unMutex, float tempsEcoule);

};