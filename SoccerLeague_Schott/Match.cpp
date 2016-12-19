#include "Match.h"

//constructeurs/destructeurs
Match::Match()
{

}
Match::Match(Equipe newEquipeLocale, Equipe newEquipeInvitee, Resultat newResultatFinal){
	equipeLocale = newEquipeLocale;
	equipeInvitee = newEquipeInvitee;
	resultatFinal = newResultatFinal;
}
Match::~Match(){

}

//accesseurs et modificateurs
void Match::setEquipeLocale(Equipe newEquipeLocale)
{
	equipeLocale = newEquipeLocale;
}
Equipe Match::getEquipeLocale()
{
	return equipeLocale;
}

void Match::setEquipeInvitee(Equipe newEquipeInvitee)
{
	equipeInvitee = newEquipeInvitee;
}
Equipe Match::getEquipeInvitee()
{
	return equipeInvitee;
}

void Match::setResultat(Resultat newResultatFinal)
{
	resultatFinal = newResultatFinal;
}
Resultat Match::getResultat()
{
	return resultatFinal;
}

void Match::ajouterPeriode(Periode nouvellePeriode)
{
	listePeriodes.push_back(nouvellePeriode);
}
void Match::supprimerPeriode(int i)
{
	listePeriodes.erase(debutListePeriodes() + i);
}
vector<Periode> Match::getListePeriodes()
{
	return listePeriodes;
}
vector<Periode>::iterator Match::debutListePeriodes()
{
	return listePeriodes.begin();
}
vector<Periode>::iterator Match::finListePeriodes()
{
	return listePeriodes.end();
}
Periode* Match::getPeriodeFromList(int i)
{
	return &listePeriodes[i];
}