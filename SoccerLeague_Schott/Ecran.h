#pragma once
#include "Club.h"
#include "LigueSoccer.h"
#include "Negociation.h"
#include "NegoAcheteur.h"
#include "NegoVendeur.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <sstream>

class Ecran{

public:
	//On stocke ici toutes les ligues créées
	//Ce n'est qu'une solution temporaire avant l'introduction du GUI et de la sauvegarde.
	vector<LigueSoccer> listeLigues;

	void menuPrincipal();//Menu principal
	//Permet de :
	//1. Sauvegarder
	//2. Charger la sauvegarde
	//3. Selectionner une ligue existante (dans ce cas lance le menuLigue);
	//4. Créer une ligue et l'ajouter à la listeCharger la sauvegarde

	void menuLigue(LigueSoccer* ligueSelectionnee);//Menu de gestion de ligue
	//(Apres selection d'une ligue existante)
	//Permet de :
	//1. Changer le nom de la ligue
	//2. Sélectionner un club existant dans la ligue (dans ce cas lance le menuClub)
	//3. Créer et ajouter un club à la ligue
	//4. Supprimer un club
	//5. Invoquer des requêtes (ex: trouver meilleur entraineur, etc)
	//		1.Trouver le club au plus grand palmares
	//		2.Trouver l'entraineur le plus titre
	//		3.Affichage des montants de transfert encaissés par un club par rapport à une date donnée
	//6. Gerer le calendrier des rencontres (dans ce cas lance le menuCalendrier)
	//7. Retourner au menu principal

	void menuCalendrier(LigueSoccer* maLigue);
	//Permet de voir le calendrier des rencontres et :
	//1. Creer et ajouter une rencontre au calendrier
	//2. Supprimer une rencontre du calendrier
	//3. Completer une rencontre avec un match
	//4. Afficher les rencontres d'un club
	//5. Afficher le resultat d'un match a une date donnee
	//6. Retourner au menuLigue

	void menuClub(LigueSoccer* maLigue, Club* monClub);//Menu de gestion de club
	//(Apres selection d'un club dans une ligue)
	//Permet de :
	//1. Changer les attributs du club (nom, adresse, stade, etc)
	//2. Sélectionner un joueur existant (dans ce cas lance le menuJoueur)
	//3. Créer et ajouter un joueur au club
	//4. Supprimer un joueur
	//5. Sélectionner un palmares existant (dans ce cas lance le menuPalmares)
	//6. Créer et ajouter un palmares au club
	//7. Supprimer un palmares
	//8. Sélectionner un membre du staff existant (dans ce cas lance le menuStaff)
	//9. Créer et ajouter un membre du staff au club
	//10.Supprimer un membre du staff
	//11.Selectionner un contrat dengagement (dans ce cas lance le menuContrat)
	//12.Creer et ajouter un contrat dengagement
	//13.Supprimer un contrat dengagement
	//14. Retourner au menu de la ligue

	void menuJoueur(LigueSoccer* maLigue, Club* monClub, Joueur* monJoueur);//Menu de gestion de joueur
	//(Apres selection d'un joueur dans un club)
	//Permet de :
	//1. Changer les attributs du joueur (nom, prenom, etc)
	//2. Selectionner un parcours existant (dans ce cas lance le menuParcours())
	//3. Créer et ajouter un parcours à la liste de parcours du joueur
	//4. Supprimer un joueur
	//5. Retourner au menuClub

	void menuStaff(LigueSoccer* maLigue, Club* monClub, Personne* monStaff);//Menu de gestion de staff
	//(Apres selection d'un membre du staff dans un club)
	//Permet de :
	//1. Changer les attributs du membre (nom, prenom, age, et titres si c'est un entraineur)
	//2. Si Entraineur : Selectionner un titre existant (dans ce cas lance le menuTitres())
	//3. Si Entraineur : Créer et ajouter un titre gagné à la liste de titres de l'entraineur
	//4. Si Entraineur : Supprimer un titre existant
	//5. Retourner au menuClub

	//Menus de gestions des titres
	//Permet de modifier un titre/parcours/palmares
	void menuParcours(LigueSoccer* maLigue, Club* monClub, Joueur* monJoueur, Parcours* monParcours);
	//(Apres selection d'un parcours dans une liste de parcours d'un joueurs)
	//Permet de :
	//1. Changer les attributs du parcours (date et clubParcours)
	//2. Retourner au menuJoueur

	void menuPalmares(LigueSoccer* maLigue, Club* monClub, Palmares* monPalmares);
	//(Apres selection d'un palmares dans la liste de palmares d'un club)
	//Permet de :
	//1. Changer les attributs du palmares (titre et date)
	//2. Retourner au menuClub

	void menuTitres(LigueSoccer* maLigue, Club* monClub, Entraineur* monEntraineur, TitreGagne* monTitre);
	//(Apres selection d'un titre dans la liste des titres d'un entraineur)
	//Permet de :
	//1. Changer les attributs du titre (titre date et club)
	//2. Retourner au menuStaff

	//Menu des contrats
	void menuContrat(LigueSoccer* maLigue, Club* monClub, Contrat* monContrat);
	//(Apres selection d'un contrat d'engagement dans la liste des contrats d'un club)
	//Permet de :
	//1. Changer les attributs du contrat
	//2. Retourner au menuClub

	void menuMercato(LigueSoccer* maLigue);

	//Méthodes statiques de saisie
	string saisieNomNouvelleLigue();
	Club saisieNouveauClub();
	Stade* saisieNouveauStade();
	Joueur* saisieNouveauJoueur();
	Personne* saisieNouveauStaff();
	Parcours saisieNouveauParcours(LigueSoccer* maLigue);
	Palmares saisieNouveauPalmares();
	TitreGagne saisieNouveauTitre(LigueSoccer* maLigue);
	Contrat saisieNouveauContrat(LigueSoccer* maLigue, Club* newClubContractant, Club* newClubLibere);
	Reglement saisieNouveauReglement();
	Rencontre saisieNouvelleRencontre(LigueSoccer* maLigue);
	Match* saisieNouveauMatch(Rencontre* maRencontre);
	Resultat saisieNouveauResultat(Rencontre* maRencontre);

	//Méthodes statiques d'affichage
	void afficherListeLigues();
	static void afficherListesRencontres(LigueSoccer maLigue);
	static void afficherListeClubs(LigueSoccer maLigue);
	static void afficherListeJoueurs(Club monClub);
	static void afficherListeStaff(Club monClub);
	static void afficherListePalmares(Club monClub);
	static void afficherListeParcours(Joueur* monJoueur);
	static void afficherListeTitres(Entraineur monEntraineur);
	static void afficherListeContrats(Club monClub);

	//Méthodes statiques de recherche
	static void chercherMeilleurEntraineur(LigueSoccer maLigue);
	static void chercherMeilleurClub(LigueSoccer maLigue);
	static void chercherSommeClubDate(LigueSoccer* maLigue);

	//Sauvegarde & Chargement
	void sauvegarderEtat();
	void retablirEtat();
};