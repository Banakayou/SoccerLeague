#pragma once
using namespace std;
#include "Equipe.h"
#include "Periode.h"
#include "Resultat.h"

class Match{
private: 
	Equipe equipeLocale;
	Equipe equipeInvitee;
	Resultat resultatFinal;
	vector<Periode> listePeriodes;

public:
	//constructeurs/destructeurs
	Match();
	Match(Equipe newEquipeLocale, Equipe newEquipeInvitee, Resultat newResultatFinal);
	~Match();

	//accesseurs et modificateurs
	void setEquipeLocale(Equipe newEquipeLocale);
	Equipe getEquipeLocale();

	void setEquipeInvitee(Equipe newEquipeInvitee);
	Equipe getEquipeInvitee();

	void setResultat(Resultat newResultatFinal);
	Resultat getResultat();

	void ajouterPeriode(Periode nouvellePeriode);
	void supprimerPeriode(int i);
	vector<Periode> getListePeriodes();
	vector<Periode>::iterator debutListePeriodes();
	vector<Periode>::iterator finListePeriodes();
	Periode* getPeriodeFromList(int i);
};