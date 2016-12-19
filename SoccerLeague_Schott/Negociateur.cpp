#include "Negociateur.h"

Negociateur::Negociateur(){

}

Negociateur::~Negociateur(){

}

//accesseurs et modificateurs
void Negociateur::setMontantDesire(float newMontant){
	montantDesire = newMontant;
}
float Negociateur::getMontantDesire(){
	return montantDesire;
}

void Negociateur::setMontantExtreme(float newMontant){
	montantExtreme = newMontant;
}
float Negociateur::getMontantExtreme(){
	return montantExtreme;
}

void Negociateur::setDureeNegocation(float newDuree){
	dureeNegociation = newDuree;
}
float Negociateur::getDureeNegocation(){
	return dureeNegociation;
}

void Negociateur::ajouterMessage(Negociation newMessage){
	listeMessages.push_back(newMessage);
}
void Negociateur::supprimerMessage(int i){
	listeMessages.erase(debutListeMessages() + i);
}
vector<Negociation> Negociateur::getListeMessages(){
	return listeMessages;
}
vector<Negociation>::iterator Negociateur::debutListeMessages(){
	return listeMessages.begin();
}
vector<Negociation>::iterator Negociateur::finListeMessages(){
	return listeMessages.end();
}
Negociation* Negociateur::getMessageFromList(int i){
	return &listeMessages[i];
}