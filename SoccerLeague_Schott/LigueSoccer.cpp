#include "LigueSoccer.h"

//constructeurs/destructeurs
LigueSoccer::LigueSoccer(){

}
LigueSoccer::LigueSoccer(string newNom)
{
	nomLigue = newNom;
}

LigueSoccer::~LigueSoccer()
{
}

//accesseurs et modificateurs
void LigueSoccer::setNom(string nouveauNom)
{
	nomLigue = nouveauNom;
}
string LigueSoccer::getNom()
{
	return nomLigue;
}

void LigueSoccer::ajouterClub(Club newClub)
{
	listeClubs.push_back(newClub);
}
void LigueSoccer::supprimerClub(int i)
{
	listeClubs.erase(debutListeClub() + i);
}
vector<Club> LigueSoccer::getListeClubs()
{
	return listeClubs;
}
vector<Club>::iterator LigueSoccer::debutListeClub()
{
	return listeClubs.begin();
}
vector<Club>::iterator LigueSoccer::finListeClub()
{ 
	return listeClubs.end(); 
}
Club* LigueSoccer::getClubFromList(int i)
{
	return &listeClubs[i];
}

void LigueSoccer::ajouterRencontre(Rencontre newRencontre)
{
	calendrierRencontres.push_back(newRencontre);
}
void LigueSoccer::supprimerRencontre(int i)
{
	calendrierRencontres.erase(debutCalendrierRencontres() + i);
}
vector<Rencontre> LigueSoccer::getCalendrierRencontres()
{
	return calendrierRencontres;
}
vector<Rencontre>::iterator LigueSoccer::debutCalendrierRencontres()
{
	return calendrierRencontres.begin();
}
vector<Rencontre>::iterator LigueSoccer::finCalendrierRencontres()
{
	return calendrierRencontres.end();
}
Rencontre* LigueSoccer::getRencontreFromList(int i)
{
	return &calendrierRencontres[i];
}