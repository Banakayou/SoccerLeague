#include "Date.h"

//constructeurs/destructeurs
Date::Date(){}
Date::Date(int newAnnee, int newMois = 01, int newJour = 01){
	annee = newAnnee;
	mois = newMois;
	jour = newJour;
}
Date::~Date(){}

//accesseurs et modificateurs
void Date::setAnnee(int newAnnee){
	annee = newAnnee;
}
int Date::getAnnee(){
	return annee;
}

void Date::setMois(int newMois){
	mois = newMois;
}
int Date::getMois(){
	return mois;
}

void Date::setJour(int newJour){
	jour = newJour;
}
int Date::getJour(){
	return jour;
}