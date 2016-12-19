#include "Ecran.h"

//Menu principal
void Ecran::menuPrincipal(){
	int indexMenuPrincipal=0;
	cout << "\n" << "Menu Principal :" << "\n";

	//affiche les ligues
	afficherListeLigues();

	cout << "\n" << "Veuillez faire un choix (tapez 1 ou 2) :" << "\n";
	cout << "1. Sauvegarder" << "\n";
	cout << "2. Charger la sauvegarde" << "\n";
	cout << "3. Selectionner une ligue existante" << "\n";
	cout << "4. Creer une ligue et l'ajouter a la liste" << "\n";
	cin >> indexMenuPrincipal;

	while (indexMenuPrincipal){
		switch(indexMenuPrincipal){
		case 1:
			sauvegarderEtat();
			break;
		case 2:
			retablirEtat();
			break;
		case 3:
			if (listeLigues.size() != 0){
				cout << "Veuillez entrer l'ID de la ligue" << "\n";
				int ligueSelectionnee;
				cin >> ligueSelectionnee;
				menuLigue(&listeLigues[ligueSelectionnee]);
			}
			break;
		default:
			LigueSoccer temp; //Création de ligue temporaire			
			temp.setNom(saisieNomNouvelleLigue());
			listeLigues.push_back(temp);
			break;
		}
		menuPrincipal();
	}
}
//Menu de gestion de ligue
void Ecran::menuLigue(LigueSoccer* maLigue){
	int indexMenuLigue = 0;
	cout << "\n" << "Menu de Gestion de Ligue :" << "\n";
	cout << "Ligue selectionnee : " << maLigue->getNom() << "\n";
	//affiche les clubs de la ligue
	afficherListeClubs(*maLigue);

	cout << "\n" << "Veuillez faire un choix (tapez 1 a 6) :" << "\n";
	cout << "1. Changer le nom de la ligue" << "\n" << "\n";
	cout << "2. Selectionner un club existant dans la ligue" << "\n";
	cout << "3. Creer et ajouter un club a la ligue" << "\n";
	cout << "4. Supprimer un club de la ligue" << "\n" << "\n";
	cout << "5. Invoquer des requetes dans la ligue" << "\n";
	cout << "6. Gerer le calendrier des rencontres" << "\n";
	cout << "7. Retourner au menu principal" << "\n";
	cin >> indexMenuLigue;

	while (indexMenuLigue){
		switch (indexMenuLigue){
		case 1:
			maLigue->setNom(saisieNomNouvelleLigue());
			break;
		case 2:
			if (maLigue->getListeClubs().size() != 0){
				cout << "Veuillez entrer l'ID du club" << "\n";
				int clubSelectionne;
				cin >> clubSelectionne;
				menuClub(maLigue, maLigue->getClubFromList(clubSelectionne));
			}
			break;
		case 3:
			maLigue->ajouterClub(saisieNouveauClub());
			break;
		case 4:
			if (maLigue->getListeClubs().size() != 0){
				cout << "Veuillez entrer l'ID du club a supprimer" << "\n";
				int clubSelectionne;
				cin >> clubSelectionne;
				maLigue->supprimerClub(clubSelectionne);
			}
			break;
		case 5:
			cout << "\n" << "Veuillez faire un choix :" << "\n";
			cout << "1. Chercher le meilleur club" << "\n";
			cout << "2. Chercher le meilleur entraineur" << "\n";
			cout << "3. Chercher le montant de transfert encaisse par un club a une date" << "\n";
			int choixRequete;
			cin >> choixRequete;
			if (choixRequete == 1){
				chercherMeilleurClub(*maLigue);
			}
			if (choixRequete == 2){
				chercherMeilleurEntraineur(*maLigue);
			}
			if (choixRequete == 3)
			{
				chercherSommeClubDate(maLigue);
			}
			break;
		case 6:
			menuCalendrier(maLigue);
			break;
		default:
			menuPrincipal();
			break;
		}
		menuLigue(maLigue);
	}
}
//Menu de gestion du calendrier
void Ecran::menuCalendrier(LigueSoccer* maLigue){
	int indexMenuCalendrier = 0;
	cout << "\n" << "Menu de Gestion du calendrier des rencontres de la ligue :" << "\n";
	afficherListesRencontres(*maLigue);
	cout << "\n" << "Veuillez faire un choix (tapez 1 a 6) :" << "\n";
	cout << "1. Creer et ajouter une rencontre au calendrier" << "\n";
	cout << "2. Supprimer une rencontre du calendrier" << "\n" << "\n";
	cout << "3. Completer une rencontre avec un match" << "\n" << "\n";
	cout << "4. Afficher les rencontres d'un club" << "\n";
	cout << "5. Afficher le resultat d'un match a une date donnee" << "\n";
	cout << "6. Retourner au menuLigue" << "\n";
	cin >> indexMenuCalendrier;
	while (indexMenuCalendrier){
		switch (indexMenuCalendrier){
		case 1:
			if (maLigue->getListeClubs().size() > 1){
				maLigue->ajouterRencontre(saisieNouvelleRencontre(maLigue));
			}
			else{
				cout << "Pas assez de clubs pour organiser une rencontre" << "\n";
			}
			break;
		case 2:
			if (maLigue->getCalendrierRencontres().size() != 0){
				cout << "Veuillez entrer l'ID de la rencontre a supprimer" << "\n";
				int rencontreSelect;
				cin >> rencontreSelect;
				maLigue->supprimerRencontre(rencontreSelect);
			}
			break;
		case 3:
			if (maLigue->getCalendrierRencontres().size() != 0){
				cout << "Veuillez entrer l'ID de la rencontre a completer" << "\n";
				int rencontreSelect;
				cin >> rencontreSelect;
				if (maLigue->getRencontreFromList(rencontreSelect)->getClubLocal()->getListeJoueurs().size() > 0 && maLigue->getRencontreFromList(rencontreSelect)->getClubInvite()->getListeJoueurs().size()){
					maLigue->getRencontreFromList(rencontreSelect)->setMatchRencontre(saisieNouveauMatch(maLigue->getRencontreFromList(rencontreSelect)));
				}
				else{
					cout << "Pas assez de joueurs pour designer un capitaine" << "\n";
				}
			}
			break;
		case 4:
			if (maLigue->getCalendrierRencontres().size() == 0){
				cout << "\n" << "Aucune rencontre dans le calendrier" << "\n";
			}
			else{
				afficherListeClubs(*maLigue);
				cout << "Veuillez entrer l'ID du club a filtrer" << "\n";
				int clubSelect;
				cin >> clubSelect;
				cout << "\n" << "Les rencontres du calendrier de la ligue " << maLigue->getNom() << " du club : " << maLigue->getClubFromList(clubSelect)->getNom() << " sont : " << "\n";
				for (std::vector<Rencontre>::iterator it = maLigue->debutCalendrierRencontres(); it != maLigue->finCalendrierRencontres(); it++){
					if (maLigue->getClubFromList(clubSelect) == it->getClubInvite() || maLigue->getClubFromList(clubSelect) == it->getClubLocal()){
						cout << "Date : " << it->getDateRencontre().getJour() << " | " << it->getDateRencontre().getMois() << " | " << it->getDateRencontre().getAnnee() << " | ";
						cout << "Club Local : " << it->getClubLocal()->getNom() << " | ";
						cout << "Club Invite : " << it->getClubInvite()->getNom() << " | ";
						if (it->getMatchRencontre() != nullptr){
							cout << "Score Local : " << it->getMatchRencontre()->getResultat().getNbreTotalButsEquipeLocale() << " | ";
							cout << "Score Invite : " << it->getMatchRencontre()->getResultat().getNbreTotalButsEquipeInvitee() << "\n";
						}
						else{
							cout << "Match a venir" << "\n";
						}
						cout << "\n";
					}
				}
			}
			break;
		case 5:
			if (maLigue->getCalendrierRencontres().size() != 0){
				cout << "Veuillez entrer la date du match au format d m y" << "\n";
				int d, m, y;
				cin >> d >> m >> y;
				int matchs_trouves = 0;
				for (std::vector<Rencontre>::iterator it = maLigue->debutCalendrierRencontres(); it != maLigue->finCalendrierRencontres(); it++){
					if (it->getDateRencontre().getAnnee() == y && it->getDateRencontre().getMois() == m && it->getDateRencontre().getJour() == d){
						matchs_trouves++;
						cout << "Club Local : " << it->getClubLocal()->getNom() << " | ";
						cout << "Club Invite : " << it->getClubInvite()->getNom() << " | ";
						if (it->getMatchRencontre() != nullptr){
							cout << "Score Local : " << it->getMatchRencontre()->getResultat().getNbreTotalButsEquipeLocale() << " | ";
							cout << "Score Invite : " << it->getMatchRencontre()->getResultat().getNbreTotalButsEquipeInvitee() << "\n";
						}
						else{
							cout << "Match a venir" << "\n";
						}
						cout << "\n";
					}
				}
				if (matchs_trouves != 0){
					cout << "Match non trouve" << "\n";
				}
			}

			break;
		default:
			menuLigue(maLigue);
		}
		menuCalendrier(maLigue);
	}
}

//Menu de gestion de club
void Ecran::menuClub(LigueSoccer* maLigue, Club* monClub){
	int indexMenuClub = 0;
	cout << "\n" << "Menu de Gestion de Club :" << "\n";
	cout << "Club selectionne : " << monClub->getNom() << "\n";
	//affiche les listes du club
	afficherListeJoueurs(*monClub);
	afficherListeStaff(*monClub);
	afficherListePalmares(*monClub);
	afficherListeContrats(*monClub);

	cout << "\n" << "Veuillez faire un choix (tapez 1 a 15) :" << "\n";
	cout << "1. Changer les attributs du club (nom, adresse, stade, etc)" << "\n" << "\n";
	cout << "2. Selectionner un joueur existant" << "\n";;
	cout << "3. Creer et ajouter un joueur au club" << "\n";
	cout << "4. Supprimer un joueur" << "\n" << "\n";
	cout << "5. Selectionner un palmares existant" << "\n";
	cout << "6. Creer et ajouter un palmares au club" << "\n";
	cout << "7. Supprimer un palmares" << "\n" << "\n";
	cout << "8. Selectionner un membre du staff existant" << "\n";
	cout << "9. Creer et ajouter un membre du staff au club" << "\n";
	cout << "10.Supprimer un membre du staff" << "\n" << "\n";
	cout << "11.Selectionner un contrat d'engagement" << "\n";
	cout << "12.Creer et ajouter un contrat d'engagement" << "\n";
	cout << "13.Supprimer un contrat d'engagement" << "\n";
	cout << "14.Creer un contrat temporaire en vue d'une negociation" << "\n" << "\n";
	cout << "15. Retourner au menu de la ligue" << "\n";
	cin >> indexMenuClub;

	while (indexMenuClub){
		switch (indexMenuClub){
		case 1:
			*monClub = saisieNouveauClub();
			break;
		case 2:
			if (monClub->getListeJoueurs().size() != 0){
				cout << "Veuillez entrer l'ID du joueur" << "\n";
				int joueurSelectionne;
				cin >> joueurSelectionne;
				menuJoueur(maLigue, monClub, monClub->getJoueurFromList(joueurSelectionne));
			}
			break;
		case 3:
			monClub->ajouterJoueur(saisieNouveauJoueur());
			break;
		case 4:
			if (monClub->getListeJoueurs().size() != 0){
				cout << "Veuillez entrer l'ID du joueur" << "\n";
				int joueurSelectionne;
				cin >> joueurSelectionne;
				monClub->supprimerJoueur(joueurSelectionne);
			}
			break;
		case 5:
			if (monClub->getListePalmares().size() != 0){
				cout << "Veuillez entrer l'ID du palmares" << "\n";
				int palmaresSelectionne;
				cin >> palmaresSelectionne;
				menuPalmares(maLigue, monClub, monClub->getPalmaresFromList(palmaresSelectionne));
			}
			break;
		case 6:
			monClub->ajouterPalmares(saisieNouveauPalmares());
			break;
		case 7:
			if (monClub->getListePalmares().size() != 0){
				cout << "Veuillez entrer l'ID du palmares" << "\n";
				int palmaresSelectionne;
				cin >> palmaresSelectionne;
				monClub->supprimerPalmares(palmaresSelectionne);
			}
			break;
		case 8:
			if (monClub->getListeStaffTechnique().size() != 0){
				cout << "Veuillez entrer l'ID du staff" << "\n";
				int staffSelectionne;
				cin >> staffSelectionne;
				menuStaff(maLigue, monClub, monClub->getStaffFromList(staffSelectionne));
			}
			break;
		case 9:
			monClub->ajouterStaff(saisieNouveauStaff());
			break;
		case 10:
			if (monClub->getListeStaffTechnique().size() != 0){
				cout << "Veuillez entrer l'ID du staff" << "\n";
				int staffSelectionne;
				cin >> staffSelectionne;
				monClub->supprimerStaff(staffSelectionne);
			}
			break;
		case 11:
			if (monClub->getListeContrats().size() != 0){
				cout << "Veuillez entrer l'ID du contrat" << "\n";
				int contratSelectionne;
				cin >> contratSelectionne;
				menuContrat(maLigue, monClub, monClub->getContratFromList(contratSelectionne));
			}
			break;
		case 12:
			if (maLigue->getListeClubs().size() > 1) //on verifie qu'on a au moins 2 clubs
			{
				Club* newClubContractant = monClub;//creer un contrat dans un club implique que c'est celui ci le contractant

				afficherListeClubs(*maLigue);
				cout << "Veuillez entrer l'ID du club libere" << "\n";
				int clubLibereSelect;
				cin >> clubLibereSelect;
				Club* newClubLibere = maLigue->getClubFromList(clubLibereSelect);

				if (newClubLibere->getListeJoueurs().size() > 0){ // on verifie que le club a liberer contient un joueur

					Contrat temp = saisieNouveauContrat(maLigue, newClubContractant, newClubLibere);//On saisit un nouveau contrat mais il est temporaire

					//Si joueur non autonome, transfert si fin de contrat atteint
					JoueurNonAutonome* ptr_j_Nauto = dynamic_cast<JoueurNonAutonome*>(temp.getJoueur());
					if (ptr_j_Nauto != nullptr){
						Contrat* position_ancien_contrat = nullptr;
						if (temp.getClubLibere()->getListeContrats().size() != 0){
							for (std::vector<Contrat>::iterator it = temp.getClubLibere()->debutListeContrats(); it != temp.getClubLibere()->finListeContrats(); it++)
							{
								if (it->getJoueur() == temp.getJoueur()){
									position_ancien_contrat = &(*it);
									cout << "Ancien contrat trouve" << "\n";
								}
							}
						}

						if (position_ancien_contrat == nullptr){
							cout << "Le joueur n'a pas de contrat dans son club precedent" << "\n";
							//poursuite au transfert
						}
						else if (position_ancien_contrat != nullptr){
							if (position_ancien_contrat->getDateEntree().getAnnee() + position_ancien_contrat->getDuree() > temp.getDateEntree().getAnnee())//On vérifie le temps passé dans l'ancien club p/r à la date du nouveau contrat
							{
								cout << "Le joueur est encore lie a son ancien contrat" << "\n";
								break; // le contrat et le transfert ne sont pas effectués
							}
							else if (position_ancien_contrat->getDateEntree().getAnnee() + position_ancien_contrat->getDuree() == temp.getDateEntree().getAnnee())
							{
								if (position_ancien_contrat->getDateEntree().getMois() > temp.getDateEntree().getMois())
								{
									cout << "Le joueur est encore lie a son ancien contrat" << "\n";
									break; // le contrat et le transfert ne sont pas effectués
								}
								else if (position_ancien_contrat->getDateEntree().getMois() == temp.getDateEntree().getMois()){
									if (position_ancien_contrat->getDateEntree().getJour() > temp.getDateEntree().getJour()){
										cout << "Le joueur est encore lie a son ancien contrat" << "\n";
										break; // le contrat et le transfert ne sont pas effectués
									}
								}
							}
							cout << "Le joueur n'est plus lié à son ancien contrat" << "\n";
							//TODO : si le joueur non autonome n'est plus lié à son ancien club, on peut supprimer l'ancien contrat ?
						}
					}
					//si joueur autonome, rupture de contrat
					JoueurAutonome* ptr_j_auto = dynamic_cast<JoueurAutonome*>(temp.getJoueur());
					if (ptr_j_auto != nullptr){
						cout << "Veuillez entrer les raisons du depart" << "\n";
						string nouvelleRaison;
						cin >> nouvelleRaison;
						cout << "Veuillez entrer la penalite" << "\n";
						float nouvellePenalite;
						cin >> nouvellePenalite;

						Rupture nouvelleRupture(ptr_j_auto, nouvelleRaison, monClub, nouvellePenalite);
						temp.getClubLibere()->ajouterRupture(nouvelleRupture); // on ajoute la rupture a l'ancien club

						//poursuite au transfert
					}
					//Transfert
					temp.getClubContractant()->ajouterContrat(temp);//on ajoute le contrat au club contractant
					temp.getClubContractant()->ajouterJoueur(temp.getJoueur());//on ajoute le joueur au nouveau club
					//TODO : doit on mettre a jour le parcours du joueur ?

					int id = 0;
					int id_j_ancien_club = id;
					for (std::vector<Joueur*>::iterator it = temp.getClubLibere()->debutListeJoueurs(); it != temp.getClubLibere()->finListeJoueurs(); it++){
						if ((*it) == temp.getJoueur()){
							id_j_ancien_club = id;
							//on ne peut pas utiliser erase pendant le parcours de la meme liste
						}
						id++;
					}
					temp.getClubLibere()->supprimerJoueur(id_j_ancien_club);//on le supprime de l'ancien club


				}
				else{
					cout << "Pas assez de joueurs dans le club a liberer pour pouvoir etablir un contrat" << "\n";
				}
			}
			else{
				cout << "Pas assez de clubs dans la ligue pour pouvoir etablir un contrat" << "\n";
			}
			break;

		case 13:
			if (monClub->getListeContrats().size() != 0){
				cout << "Veuillez entrer l'ID du contrat" << "\n";
				int contratSelectionne;
				cin >> contratSelectionne;
				monClub->supprimerContrat(contratSelectionne);//on supprime du cote du club contractant
			}
			break;
		case 14:
			if (maLigue->getListeClubs().size() > 1) //on verifie qu'on a au moins 2 clubs
			{

				Club* newClubContractant = new Club();
				Club* newClubLibere = new Club();
				cout << "0 pour acheter, 1 pour vendre" << "\n";
				int choix;
				cin >> choix;
				afficherListeClubs(*maLigue);
				if (choix == 0){
					newClubContractant = monClub;
					cout << "Veuillez entrer l'ID du club libere" << "\n";
					int clubLibereSelect;
					cin >> clubLibereSelect;
					newClubLibere = maLigue->getClubFromList(clubLibereSelect);
				}
				else if (choix == 1){
					newClubLibere = monClub;
					cout << "Veuillez entrer l'ID du club contractant" << "\n";
					int clubContractantSelect;
					cin >> clubContractantSelect;
					newClubContractant = maLigue->getClubFromList(clubContractantSelect);
				}

				if (newClubLibere->getListeJoueurs().size() > 0){ // on verifie que le club a liberer contient un joueur
					Contrat temp = saisieNouveauContrat(maLigue, newClubContractant, newClubLibere);//On saisit un nouveau contrat mais il est temporaire

					cout << "Veuillez entrer la duree de la simulation en millisecondes" << "\n";
					int dureeNego;
					cin >> dureeNego;
					cout << "Veuillez entrer le montant desire par l'acheteur" << "\n";
					int mntAchat;
					cin >> mntAchat;
					cout << "Veuillez entrer le montant maximum de l'acheteur" << "\n";
					int mntMax;
					cin >> mntMax;
					cout << "Veuillez entrer le montant desire par le vendeur" << "\n";
					int mntVente;
					cin >> mntVente;
					cout << "Veuillez entrer le montant minimum du vendeur" << "\n";
					int mntMin;
					cin >> mntMin;

					//On cree les negociateurs de la simulation
					NegoAcheteur* negociateurClubAcheteur = new NegoAcheteur();
					negociateurClubAcheteur->setNom("Acheteur");
					negociateurClubAcheteur->setPrenom("Acheteur");
					negociateurClubAcheteur->setDureeNegocation(dureeNego);
					negociateurClubAcheteur->setMontantDesire(mntAchat);
					negociateurClubAcheteur->setMontantExtreme(mntMax);

					NegoVendeur* negociateurClubVendeur = new NegoVendeur();
					negociateurClubVendeur->setNom("Vendeur");
					negociateurClubVendeur->setPrenom("Vendeur");
					negociateurClubVendeur->setDureeNegocation(dureeNego);
					negociateurClubVendeur->setMontantDesire(mntVente);
					negociateurClubVendeur->setMontantExtreme(mntMin);

					//Objet de negociation qui va communiquer entre les negociateurs
					Negociation* newNego = new Negociation();
					newNego->setContratTemp(temp);
					newNego->setMontantCourant(temp.getReglement().getMontantTransfert());
					if (choix == 0){
						newNego->setEmetteur(negociateurClubAcheteur);
						negociateurClubVendeur->ajouterMessage(*newNego);
					}
					else if (choix == 1) {
						newNego->setEmetteur(negociateurClubVendeur);
						negociateurClubAcheteur->ajouterMessage(*newNego);
					}

					//lancement de la periode de negociation
					//garder en memoire le temps à cet instant t comme etant le debut de la simulation

					// while duree de negociation
					//on lance le mutex qui donne la main a tour de role au vendeur et a l'acheteur pour modifier linstance newNego
					//le vendeur et l'acheteur mettent à jour le montantCourant de la négociation chacun leur tour et reproposent l'offre
					//si les conditions sur le montant sont remplies on effectue le contrat/transfert

					if (1/*DUREE TERMINEE*/){
						if ((negociateurClubVendeur->getListeMessages().back().getMontantCourant() > negociateurClubAcheteur->getMontantDesire()) && (negociateurClubVendeur->getListeMessages().back().getMontantCourant() < negociateurClubAcheteur->getMontantExtreme())){
							negociateurClubAcheteur->proposerOffre();
						}

						if ((negociateurClubAcheteur->getListeMessages().back().getMontantCourant() > negociateurClubVendeur->getMontantExtreme()) && (negociateurClubAcheteur->getMontantDesire() < negociateurClubVendeur->getMontantDesire())){
							negociateurClubVendeur->accepterOffre();//on finalise les termes du ContratTemp stocké dans la classe Negociation
							monClub->ajouterContrat(*(negociateurClubVendeur->getListeMessages().back().getContratTemp()));// on ajoute le contrat
							//Transfert du joueur
							cout << "Les negociateurs ont trouve un terrain d'entente pour la somme de : " << (negociateurClubVendeur->getListeMessages().back().getContratTemp())->getReglement().getMontantTransfert() << "\n";

						}
					}

					if (1/*DUREE NON TERMINEE*/){
						if ((negociateurClubAcheteur->getListeMessages().back().getMontantCourant() < negociateurClubVendeur->getMontantExtreme())){
							negociateurClubVendeur->refuserOffre();//Le prix ne convient pas
							negociateurClubVendeur->proposerOffre();//on propose une contre offre avec un nouveau montant
						}
					}
					//

				}
				else{ cout << "Pas assez de joueurs dans le club a liberer pour pouvoir etablir un contrat" << "\n"; }
			}
			else{ cout << "Pas assez de clubs dans la ligue pour pouvoir etablir un contrat" << "\n"; }

			break;
		default:
			menuLigue(maLigue);
			break;
		}
		menuClub(maLigue, monClub);
	}
}
//Menu de gestion de joueur
void Ecran::menuJoueur(LigueSoccer* maLigue, Club* monClub, Joueur* monJoueur){
	int indexMenuJoueur = 0;
	cout << "\n" << "Menu de Gestion de Joueur :" << "\n";
	cout << "Joueur selectionne : " << monJoueur->getNom() << "\n";
	//affiche la liste de parcours
	afficherListeParcours(monJoueur);

	cout << "\n" << "Veuillez faire un choix (tapez 1 a 5) :" << "\n";
	cout << "1. Changer les attributs du joueur (nom, prenom, etc)" << "\n" << "\n";
	cout << "2. Selectionner un parcours existant" << "\n";
	cout << "3. Creer et ajouter un parcours a la liste de parcours du joueur" << "\n";
	cout << "4. Supprimer un parcours" << "\n" << "\n";
	cout << "5. Retourner au menuClub" << "\n";
	cin >> indexMenuJoueur;

	while (indexMenuJoueur){
		switch (indexMenuJoueur){
		case 1:
			monJoueur = saisieNouveauJoueur();
			break;
		case 2:
			if (monJoueur->getParcours().size() != 0){
				cout << "Veuillez entrer l'ID du parcours" << "\n";
				int parcoursSelectionne;
				cin >> parcoursSelectionne;
				menuParcours(maLigue, monClub, monJoueur, monJoueur->getParcoursFromList(parcoursSelectionne));
			}
			break;
		case 3:
			monJoueur->ajouterParcours(saisieNouveauParcours(maLigue));
			break;
		case 4:
			if (monClub->getListeJoueurs().size() != 0){
				cout << "Veuillez entrer l'ID du parcours" << "\n";
				int parcoursSelectionne;
				cin >> parcoursSelectionne;
				monJoueur->supprimerParcours(parcoursSelectionne);
			}
			break;
		default:
			menuClub(maLigue, monClub);
			break;
		}
		menuJoueur(maLigue, monClub, monJoueur);
	}
}
//Menu de gestion de staff
void Ecran::menuStaff(LigueSoccer* maLigue, Club* monClub, Personne* monStaff){
	int indexMenuStaff = 0;
	cout << "\n" << "Menu de Gestion de staff :" << "\n";
	cout << "Staff selectionne : " << monStaff->getNom() << " " << monStaff->getPrenom() << "\n";
	Entraineur* ptr_entraineur = dynamic_cast<Entraineur*>(monStaff);
	if (ptr_entraineur != nullptr){
		afficherListeTitres(*ptr_entraineur);//affiche la liste de titres si entraineur
	}
	cout << "\n" << "Veuillez faire un choix (tapez 1 a 5) :" << "\n";
	cout << "1. Changer les attributs du membre (nom, prenom, etc)" << "\n" << "\n";
	if (ptr_entraineur != nullptr){ // Options du menu apparaissent que si le staff selectionne est un entraineur
		cout << "2. Selectionner un titre existant" << "\n";
		cout << "3. Creer et ajouter un titre gagne a la liste de titres de l'entraineur" << "\n";
		cout << "4. Supprimer un titre" << "\n" << "\n";
	}
	cout << "5. Retourner au menuClub" << "\n";	

	cin >> indexMenuStaff;
	while (indexMenuStaff){
		switch (indexMenuStaff){
		case 1:
			monStaff = saisieNouveauStaff();
			break;
		case 2:
			if (ptr_entraineur != nullptr){
				cout << "Veuillez entrer l'ID du titre gagne" << "\n";
				int titreSelectionne;
				cin >> titreSelectionne;
				menuTitres(maLigue, monClub, ptr_entraineur, ptr_entraineur->getTitreFromList(titreSelectionne));
			}
			break;
		case 3:
			if (ptr_entraineur != nullptr){
				ptr_entraineur->ajouterTitre(saisieNouveauTitre(maLigue));
			}
			break;
		case 4:
			if (ptr_entraineur != nullptr){
				cout << "Veuillez entrer l'ID du titre" << "\n";
				int titreSelectionne;
				cin >> titreSelectionne;
				ptr_entraineur->supprimerTitre(titreSelectionne);
			}
			break;
		default:
			menuClub(maLigue, monClub);
			break;
		}
		menuStaff(maLigue, monClub, monStaff);
	}
}

//Menus de gestions des titres
void Ecran::menuParcours(LigueSoccer* maLigue, Club* monClub, Joueur* monJoueur, Parcours* monParcours){
	int indexMenuParcours = 0;
	cout << "\n" << "Menu de Gestion de Parcours :" << "\n";
	cout << "Parcours selectionne : " << monParcours->getClub() << " | " << monParcours->getDate().getJour() << "/" << monParcours->getDate().getMois() << "/" << monParcours->getDate().getAnnee() << "\n";
	cout << "\n" << "Veuillez faire un choix:" << "\n";
	cout << "1. Changer les attributs du parcours (date et clubParcours)" << "\n" << "\n";
	cout << "2. Retourner au menuJoueur" << "\n";
	cin >> indexMenuParcours;

	while (indexMenuParcours){
		switch (indexMenuParcours){
		case 1:
			*monParcours = saisieNouveauParcours(maLigue);
			break;
		default:
			menuJoueur(maLigue, monClub, monJoueur);
			break;
		}
		menuParcours(maLigue, monClub, monJoueur, monParcours);
	}
}
void Ecran::menuPalmares(LigueSoccer* maLigue, Club* monClub, Palmares* monPalmares){
	int indexMenuPalmares = 0;
	cout << "\n" << "Menu de Gestion de Palmares :" << "\n";
	cout << "Palmares selectionne : " << monPalmares->getTitre() << " | " << monPalmares->getDate().getJour() << "/" << monPalmares->getDate().getMois() << "/" << monPalmares->getDate().getAnnee() << "\n";
	cout << "\n" << "Veuillez faire un choix:" << "\n";
	cout << "1. Changer les attributs du palmares (titre et date)" << "\n" << "\n";
	cout << "2. Retourner au menuClub" << "\n";
	cin >> indexMenuPalmares;

	while (indexMenuPalmares){
		switch (indexMenuPalmares){
		case 1:
			*monPalmares = saisieNouveauPalmares();
			break;
		default:
			menuClub(maLigue, monClub);
			break;
		}
		menuPalmares(maLigue, monClub, monPalmares);
	}
}
void Ecran::menuTitres(LigueSoccer* maLigue, Club* monClub, Entraineur* monEntraineur, TitreGagne* monTitre){
	int indexMenuTitres = 0;
	cout << "\n" << "Menu de Gestion de Titre :" << "\n";
	cout << "Titre selectionne : " << monTitre->getTitre() << " | club : " << monTitre->getClub()->getNom() << " | " << monTitre->getDate().getJour() << "/" << monTitre->getDate().getMois() << "/" << monTitre->getDate().getAnnee() << "\n";
	cout << "\n" << "Veuillez faire un choix:" << "\n";
	cout << "1. Changer les attributs du titre (titre date et club)" << "\n" << "\n";
	cout << "2. Retourner au menuStaff" << "\n";
	cin >> indexMenuTitres;

	while (indexMenuTitres){
		switch (indexMenuTitres){
		case 1:
			*monTitre = saisieNouveauTitre(maLigue);
			break;
		default:
			menuClub(maLigue, monClub);
			break;
		}
		menuTitres(maLigue, monClub, monEntraineur, monTitre);
	}
}

//Menu des contrats
void Ecran::menuContrat(LigueSoccer* maLigue, Club* monClub, Contrat* monContrat){
	int indexMenuContrat = 0;
	cout << "\n" << "Menu de Gestion de Contrat :" << "\n";
	cout << "Nom Joueur : " << monContrat->getJoueur()->getNom() << " | ";
	cout << "Date Contrat: " << monContrat->getDateContrat().getJour() << " | " << monContrat->getDateContrat().getMois() << " | " << monContrat->getDateContrat().getAnnee() << "\n";
	cout << "Date Entree : " << monContrat->getDateEntree().getJour() << " | " << monContrat->getDateEntree().getMois() << " | " << monContrat->getDateEntree().getAnnee() << " | ";
	cout << "Club contractant : " << monContrat->getClubContractant()->getNom() << " | ";
	cout << "Club libere : " << monContrat->getClubLibere()->getNom() << " | ";
	cout << "Duree : " << monContrat->getDuree() << "\n";
	cout << "Description reglement : " << monContrat->getReglement().getDescription() << " | ";
	cout << "Montant transfert : " << monContrat->getReglement().getMontantTransfert() << " | ";
	cout << "Montant club : " << monContrat->getReglement().getMontantClub() << " | ";
	cout << "Montant joueur : " << monContrat->getReglement().getMontantJoueur() << "\n";

	cout << "\n" << "Veuillez faire un choix:" << "\n";
	cout << "1. Changer les attributs du contrat" << "\n" << "\n";
	cout << "2. Retourner au menuClub" << "\n";
	cin >> indexMenuContrat;

	while (indexMenuContrat){
		switch (indexMenuContrat){
		case 1:
			*monContrat = saisieNouveauContrat(maLigue, monContrat->getClubContractant(), monContrat->getClubLibere());

			break;
		default:
			menuClub(maLigue, monClub);
			break;
		}
		menuContrat(maLigue, monClub, monContrat);
	}
}

//Méthodes statiques d'affichage
void Ecran::afficherListeLigues()
{
	if (listeLigues.size() == 0){
		cout << "\n" << "Aucune ligue existante" << "\n";
	}
	else{
		int id_ligue = 0;
		cout << "\n" << "Les ligues existantes sont : " << "\n";
		for (std::vector<LigueSoccer>::iterator it = listeLigues.begin(); it != listeLigues.end(); it++){
			cout << "ID : " << id_ligue << " | ";
			cout << "Nom : " << it->getNom() << "\n";
			cout << "Nombre de clubs : " << it->getListeClubs().size() << " | ";
			cout << "\n";
			id_ligue++;
		}
	}
}
void Ecran::afficherListeClubs(LigueSoccer maLigue)
{
	if (maLigue.getListeClubs().size() == 0){
		cout << "\n" << "Aucun club existant" << "\n";
	}
	else{
		int id_club = 0;
		cout << "\n" << "Les clubs existants sont : " << "\n";
		for (std::vector<Club>::iterator it = maLigue.debutListeClub(); it != maLigue.finListeClub(); it++){
			cout << "ID : " << id_club << " | ";
			cout << "Nom : " << it->getNom() << "\n";
			cout << "Ville : " << it->getVille() << " | ";
			cout << "Couleur : " << it->getCouleur() << " | ";
			cout << "Annee de creation : " << it->getAnnee().getAnnee() << "\n";
			cout << "Histoire du club : " << it->getHistoire() << " | ";
			cout << "Adresse du Club : " << it->getAdresse() << "\n";
			cout << "Nom du stade : " << it->getStade().getNom() << " | ";
			cout << "Capacite du stade : " << it->getStade().getCapacite() << "\n";
			cout << "Qualite du stade : " << it->getStade().getQualite() << " | ";
			cout << "Adresse du stade : " << it->getStade().getAdresse() << "\n";
			cout << "\n";
			id_club++;
		}
	}
}
void Ecran::afficherListeJoueurs(Club monClub)
{
	if (monClub.getListeJoueurs().size() == 0){
		cout << "\n" << "Aucun joueur dans ce club" << "\n";
	}
	else{
		int id_joueur = 0;
		cout << "\n" << "Les joueurs du club " << monClub.getNom() << " sont : " << "\n";
		for (std::vector<Joueur*>::iterator it = monClub.debutListeJoueurs(); it != monClub.finListeJoueurs(); it++){
			cout << "ID : " << id_joueur << " | ";
			cout << "Nom : " << (*it)->getNom() << " | ";
			cout << "Prenom : " << (*it)->getPrenom() << "\n";
			cout << "Age : " << (*it)->getAge() << " | ";
			cout << "Taille : " << (*it)->getTaille() << " | ";
			cout << "Poids : " << (*it)->getPoids() << " | ";
			cout << "Ville : " << (*it)->getVille() << " | ";
			cout << "\n";
			id_joueur++;
		}		
	}
}
void Ecran::afficherListeStaff(Club monClub)
{
	if (monClub.getListeStaffTechnique().size() == 0){
		cout << "\n" << "Aucun staff dans ce club" << "\n";
	}
	else{
		int id_staff = 0;
		cout << "\n" << "Les membres du staff du club " << monClub.getNom() << " sont : " << "\n";
		for (std::vector<Personne*>::iterator it = monClub.debutListeStaffTechnique(); it != monClub.finListeStaffTechnique(); it++){
			cout << "ID : " << id_staff << " | ";
			Entraineur* ptr_entraineur = dynamic_cast<Entraineur*>(*it);
			if (ptr_entraineur != nullptr){
				cout << " Entraineur | ";
			}
			cout << "Nom : " << (*it)->getNom() << " | ";
			cout << "Prenom : " << (*it)->getPrenom() << " | ";
			cout << "Age : " << (*it)->getAge() << " | ";
			cout << "\n";
			id_staff++;
		}
	}
}
void Ecran::afficherListePalmares(Club monClub)
{
	if (monClub.getListePalmares().size() == 0){
		cout << "\n" << "Aucun palmares dans ce club" << "\n";
	}
	else{
		int id_palmares = 0;
		cout << "\n" << "Les palmares du club " << monClub.getNom() << " sont : " << "\n";
		for (std::vector<Palmares>::iterator it = monClub.debutListePalmares(); it != monClub.finListePalmares(); it++){
			cout << "ID : " << id_palmares << " | ";
			cout << "Titre : " << it->getTitre() << " | ";
			cout << "Date : " << it->getDate().getJour() << " | " << it->getDate().getMois() << " | " << it->getDate().getAnnee() << " | ";
			cout << "\n";
			id_palmares++;
		}
	}
}
void Ecran::afficherListeParcours(Joueur* monJoueur)
{
	if (monJoueur->getParcours().size() == 0){
		cout << "\n" << "Ce joueur n'a pas de parcours" << "\n";
	}
	else{
		int id_parcours = 0;
		cout << "\n" << "Le parcours du joueur est : " << "\n";
		for (std::vector<Parcours>::iterator it = monJoueur->debutListeParcours(); it != monJoueur->finListeParcours(); it++){
			cout << "ID : " << id_parcours << " | ";
			cout << "Club : " << it->getClub() << " | ";
			cout << "Date : " << it->getDate().getJour() << " | " << it->getDate().getMois() << " | " << it->getDate().getAnnee() << " | ";
			cout << "\n";
			id_parcours++;
		}
	}
}
void Ecran::afficherListeTitres(Entraineur monEntraineur)
{
	if (monEntraineur.getTitres().size() == 0){
		cout << "Cet entraineur n'a pas de titres" << "\n";
	}
	else{
		int id_titres = 0;
		cout << "\n" << "Les titres de l'entraineur sont : " << "\n";
		for (std::vector<TitreGagne>::iterator it = monEntraineur.debutListeTitres(); it != monEntraineur.finListeTitres(); it++){
			cout << "ID : " << id_titres << " | ";
			cout << "Titre : " << it->getTitre() << " | ";
			if (it->getClub() != nullptr){
				cout << "Club : " << it->getClub()->getNom() << " | ";
			}
			cout << "Date : " << it->getDate().getJour() << " | " << it->getDate().getMois() << " | " << it->getDate().getAnnee() << " | ";
			cout << "\n";
			id_titres++;
		}
	}
}
void Ecran::afficherListeContrats(Club monClub)
{
	if (monClub.getListeContrats().size() == 0){
		cout << "\n" << "Aucun contrat dengagement dans ce club" << "\n";
	}
	else{
		int id_contrat = 0;
		cout << "\n" << "Les contrats dengagement du club " << monClub.getNom() << " sont : " << "\n";
		for (std::vector<Contrat>::iterator it = monClub.debutListeContrats(); it != monClub.finListeContrats(); it++){
			cout << "ID : " << id_contrat << " | ";
			if (it->getJoueur() != nullptr){
				cout << "Nom Joueur : " << it->getJoueur()->getNom() << " | ";
			}
			cout << "Date Contrat: " << it->getDateContrat().getJour() << " | " << it->getDateContrat().getMois() << " | " << it->getDateContrat().getAnnee() << "\n";
			cout << "Date Entree : " << it->getDateEntree().getJour() << " | " << it->getDateEntree().getMois() << " | " << it->getDateEntree().getAnnee() << " | ";
			if (it->getClubContractant() != nullptr && it->getClubLibere() != nullptr){
				cout << "Club contractant : " << it->getClubContractant()->getNom() << " | ";
				cout << "Club libere : " << it->getClubLibere()->getNom() << " | ";
			}			
			cout << "Duree : " << it->getDuree()<< "\n";
			cout << "Description reglement : " << it->getReglement().getDescription() << " | ";
			cout << "Montant transfert : " << it->getReglement().getMontantTransfert() << " | ";
			cout << "Montant club : " << it->getReglement().getMontantClub() << " | ";
			cout << "Montant joueur : " << it->getReglement().getMontantJoueur() << "\n";
			cout << "\n";
			id_contrat++;
		}
	}
}
void Ecran::afficherListesRencontres(LigueSoccer maLigue)
{
	if (maLigue.getCalendrierRencontres().size() == 0){
		cout << "\n" << "Aucune rencontre dans le calendrier" << "\n";
	}
	else{
		int id_rencontre = 0;
		cout << "\n" << "Les rencontres du calendrier de la ligue " << maLigue.getNom() << " sont : " << "\n";
		for (std::vector<Rencontre>::iterator it = maLigue.debutCalendrierRencontres(); it != maLigue.finCalendrierRencontres(); it++){
			cout << "ID : " << id_rencontre << " | ";
			cout << "Date : " << it->getDateRencontre().getJour() << " | " << it->getDateRencontre().getMois() << " | " << it->getDateRencontre().getAnnee() << " | ";
			if (it->getClubLocal() != nullptr && it->getClubInvite() != nullptr){
				cout << "Club Local : " << it->getClubLocal()->getNom() << " | ";
				cout << "Club Invite : " << it->getClubInvite()->getNom() << " | ";
			}
			if (it->getMatchRencontre() != nullptr){
				cout << "Score Local : " << it->getMatchRencontre()->getResultat().getNbreTotalButsEquipeLocale() << " | ";
				cout << "Score Invite : " << it->getMatchRencontre()->getResultat().getNbreTotalButsEquipeInvitee() << "\n";
			}
			else{
				cout << "Match a venir" << "\n";
			}
			cout << "\n";
			id_rencontre++;
		}
	}
}

//Méthodes statiques de saisie
string Ecran::saisieNomNouvelleLigue(){
	cout << "Veuillez entrer le nom de la ligue" << "\n";
	string name;
	cin >> name;
	return name;
}
Club Ecran::saisieNouveauClub(){
	cout << "Veuillez entrer le nom du nouveau club" << "\n";
	string nomClub;
	cin >> nomClub;
	cout << "Veuillez entrer la ville du nouveau club" << "\n";
	string ville;
	cin >> ville;
	cout << "Veuillez entrer la couleur du nouveau club" << "\n";
	string couleur;
	cin >> couleur;
	cout << "Veuillez entrer lhistoire du nouveau club" << "\n";
	string histoire;
	cin >> histoire;
	cout << "Veuillez entrer l'annee de creation du nouveau club" << "\n";
	int annee;
	cin >> annee;
	cout << "Veuillez entrer ladresse du club" << "\n";
	string adresse;
	cin >> adresse;

	Stade *nouveauStade = saisieNouveauStade();	
	Club *nouveauClub = new Club(nomClub, ville, couleur, annee, histoire, *nouveauStade, adresse);
	return *nouveauClub;
}
Stade* Ecran::saisieNouveauStade(){
	cout << "Veuillez entrer le nom du stade" << "\n";
	string nomStade;
	cin >> nomStade;
	cout << "Veuillez entrer la capacite du stade" << "\n";
	int capacite;
	cin >> capacite;
	cout << "Veuillez entrer la qualite du stade" << "\n";
	string qualite;
	cin >> qualite;
	cout << "Veuillez entrer ladresse du stade" << "\n";
	string adresseStade;
	cin >> adresseStade;
	Stade *nouveauStade = new Stade(capacite, qualite, nomStade, adresseStade);
	return nouveauStade;
}
Joueur* Ecran::saisieNouveauJoueur(){
	cout << "Veuillez entrer le nom du nouveau joueur" << "\n";
	string nomJoueur;
	cin >> nomJoueur;
	cout << "Veuillez entrer le prenom du nouveau joueur" << "\n";
	string prenom;
	cin >> prenom;
	cout << "Veuillez entrer lage du nouveau joueur" << "\n";
	int age;
	cin >> age;
	cout << "Veuillez entrer le poids" << "\n";
	float poids;
	cin >> poids;
	cout << "Veuillez entrer la taille" << "\n";
	float taille;
	cin >> taille;
	cout << "Veuillez entrer la ville du joueur" << "\n";
	string ville;
	cin >> ville;

	bool typeJoueur;
	cout << "Veuillez entrer 0 pour un joueur autonome, ou 1 pour un joueur non-autonome" << "\n";
	cin >> typeJoueur;
	if (typeJoueur == 0){
		JoueurAutonome *nouveauJoueur = new JoueurAutonome(nomJoueur, prenom, age, taille, poids, ville);
		return nouveauJoueur;
	}
	if (typeJoueur == 1){
		JoueurNonAutonome *nouveauJoueur = new JoueurNonAutonome(nomJoueur, prenom, age, taille, poids, ville);
		return nouveauJoueur;
	}
	return nullptr;
}
Personne* Ecran::saisieNouveauStaff()
{
	cout << "Veuillez entrer le nom du nouveau staff" << "\n";
	string nomStaff;
	cin >> nomStaff;
	cout << "Veuillez entrer le prenom du nouveau staff" << "\n";
	string prenom;
	cin >> prenom;
	cout << "Veuillez entrer lage du nouveau staff" << "\n";
	int age;
	cin >> age;

	int role=0;
	while (role <= 0 || role > 5){
		cout << "Veuillez entrer le role du nouveau staff (1=President, 2=Recruteur, 3= Secretaire, 4=Infirmier Specialise, 5=Entraineur" << "\n";
		cin >> role;
		if (role == 1){ 
			President *nouveauStaff = new President(nomStaff, prenom, age); return nouveauStaff;
		}
		else if (role == 2){ 
			Recruteur *nouveauStaff = new Recruteur(nomStaff, prenom, age); return nouveauStaff;
		}
		else if (role == 3){ 
			Secretaire *nouveauStaff = new Secretaire(nomStaff, prenom, age); return nouveauStaff; 
		}
		else if (role == 4){ 
			InfirmierSpecialise *nouveauStaff = new InfirmierSpecialise(nomStaff, prenom, age); return nouveauStaff;
		}
		else if (role == 5){
			cout << "Veuillez entrer le lieu de graduation de l'entraineur" << "\n";
			string lieu;
			cin >> lieu;
			Entraineur *nouveauStaff = new Entraineur(nomStaff, prenom, age, lieu);
			return nouveauStaff;
		}
	}
	return nullptr;
}
Parcours Ecran::saisieNouveauParcours(LigueSoccer* maLigue)
{
	afficherListeClubs(*maLigue);
	cout << "Veuillez entrer l'ID du club du nouveau parcours" << "\n";
	int clubSelect;
	cin >> clubSelect;
	Club* newClubParcours = maLigue->getClubFromList(clubSelect);
	cout << "Veuillez entrer la date de passage au format dd mm yy" << "\n";
	int d; int m; int y;
	cin >> d >> m >> y;

	Parcours *nouveauParcours = new Parcours(d, m, y, newClubParcours->getNom()); //Création de parcours temporaire
	return *nouveauParcours;
}
Palmares Ecran::saisieNouveauPalmares()
{
	cout << "Veuillez entrer le nom du nouveau palmares" << "\n";
	string nom;
	cin >> nom;
	cout << "Veuillez entrer la date de passage au format d m y" << "\n";
	int d; int m; int y;
	cin >> d >> m >> y;

	Palmares *nouveauPalmares = new Palmares(nom, d, m, y); //Création de palmares temporaire
	return *nouveauPalmares;
}
TitreGagne Ecran::saisieNouveauTitre(LigueSoccer* maLigue)
{
	afficherListeClubs(*maLigue);
	cout << "Veuillez entrer l'ID du club du nouveau titre" << "\n";
	int clubSelect;
	cin >> clubSelect;
	Club* newClubTitre = maLigue->getClubFromList(clubSelect);
	cout << "Veuillez entrer le nom du nouveau titre" << "\n";
	string titre;
	cin >> titre;
	cout << "Veuillez entrer la date du titre au format d m y" << "\n";
	int d; int m; int y;
	cin >> d >> m >> y;

	TitreGagne *nouveauTitre = new TitreGagne(titre, d, m, y, newClubTitre); //Création de titre temporaire
	return *nouveauTitre;
}
Contrat Ecran::saisieNouveauContrat(LigueSoccer* maLigue, Club* newClubContractant, Club* newClubLibere)
{
	afficherListeJoueurs(*newClubLibere);
	cout << "Veuillez entrer l'ID du joueur contractant" << "\n";
	int joueurSelect;
	cin >> joueurSelect;
	Joueur* newJoueurContrat = newClubLibere->getJoueurFromList(joueurSelect);
	
	cout << "Veuillez entrer la date du contrat au format d m y" << "\n";
	int d; int m; int y;
	cin >> d >> m >> y;
	cout << "Veuillez entrer la date d'entree au format d m y" << "\n";
	int de; int me; int ye;
	cin >> de >> me >> ye;
	cout << "Veuillez entrer la duree du contrat" << "\n";
	int newDuree;
	cin >> newDuree;
	Reglement nouveauReglement = saisieNouveauReglement();
	Contrat* nouveauContrat = new Contrat(newJoueurContrat, newClubContractant, newClubLibere, newDuree, ye, me, de, nouveauReglement, y, m, d);
	return *nouveauContrat;
}
Reglement Ecran::saisieNouveauReglement()
{
	cout << "Veuillez entrer la description du reglement" << "\n";
	string newDescription;
	cin >> newDescription;
	cout << "Veuillez entrer le montant du transfert du reglement" << "\n";
	float newMontantTransfert;
	cin >> newMontantTransfert;
	cout << "Veuillez entrer le montant du club du reglement" << "\n";
	float newMontantClub;
	cin >> newMontantClub;
	cout << "Veuillez entrer le montant du joueur du reglement" << "\n";
	float newMontantJoueur;
	cin >> newMontantJoueur;
	Reglement nouveauReglement(newDescription, newMontantTransfert, newMontantClub, newMontantJoueur);
	return nouveauReglement;
}
Rencontre Ecran::saisieNouvelleRencontre(LigueSoccer* maLigue){
	afficherListeClubs(*maLigue);
	cout << "Veuillez entrer l'ID du club local" << "\n";
	int clubLocalSelect;
	cin >> clubLocalSelect;
	Club* newClubLocal = maLigue->getClubFromList(clubLocalSelect);
	cout << "Veuillez entrer l'ID du club invite" << "\n";
	int clubInviteSelect;
	cin >> clubInviteSelect;
	Club* newClubInvite = maLigue->getClubFromList(clubInviteSelect);
	cout << "Veuillez entrer la date de la rencontre au format d m y" << "\n";
	int d; int m; int y;
	cin >> d >> m >> y;
	Date newDateRencontre(y, m, d);

	Rencontre* nouvelleRencontre = new Rencontre(newDateRencontre, newClubLocal, newClubInvite);
	return *nouvelleRencontre;
}
Match* Ecran::saisieNouveauMatch(Rencontre* maRencontre){
	cout << "Club Local : " << maRencontre->getClubLocal()->getNom() << "\n";
	cout << "Veuillez entrer le nombre de joueurs de l'equipe locale" << "\n";
	int newNbreJL;
	cin >> newNbreJL;
	cout << "Veuillez entrer le nombre de gardiens de l'equipe locale" << "\n";
	int newNbreGL;
	cin >> newNbreGL;
	afficherListeJoueurs(*maRencontre->getClubLocal());
	cout << "Veuillez entrer l'ID du joueur capitaine" << "\n";
	int capitaineSelectL;
	cin >> capitaineSelectL;
	Joueur* newCapitaineLocal = maRencontre->getClubLocal()->getJoueurFromList(capitaineSelectL);
	Equipe* newEquipeLocale = new Equipe(maRencontre->getClubLocal(), newNbreJL, newNbreGL, newCapitaineLocal);


	cout << "Club Invite : " << maRencontre->getClubInvite()->getNom() << "\n";
	cout << "Veuillez entrer le nombre de joueurs de l'equipe invitee" << "\n";
	int newNbreJI;
	cin >> newNbreJI;
	cout << "Veuillez entrer le nombre de gardiens de l'equipe invitee" << "\n";
	int newNbreGI;
	cin >> newNbreGI;
	afficherListeJoueurs(*maRencontre->getClubInvite());
	cout << "Veuillez entrer l'ID du joueur capitaine" << "\n";
	int capitaineSelectI;
	cin >> capitaineSelectI;
	Joueur* newCapitaineInvite = maRencontre->getClubInvite()->getJoueurFromList(capitaineSelectI);
	Equipe* newEquipeInvitee = new Equipe(maRencontre->getClubInvite(), newNbreJI, newNbreGI, newCapitaineInvite);
	Resultat newResultat = saisieNouveauResultat(maRencontre);

	Match* nouveauMatch = new Match(*newEquipeLocale, *newEquipeInvitee, newResultat);
	return nouveauMatch;
}
Resultat Ecran::saisieNouveauResultat(Rencontre* maRencontre){
	cout << "Club Local : " << maRencontre->getClubLocal()->getNom() << "\n";
	cout << "Veuillez entrer le score total de l'equipe locale" << "\n";
	int newScoreL;
	cin >> newScoreL;
	cout << "Club Invite : " << maRencontre->getClubInvite()->getNom() << "\n";
	cout << "Veuillez entrer le score total de l'equipe invitee" << "\n";
	int newScoreI;
	cin >> newScoreI;

	Resultat* nouveauResultat = new Resultat(newScoreL, newScoreI);
	return *nouveauResultat;
}

//Méthodes statiques de recherche
void Ecran::chercherMeilleurEntraineur(LigueSoccer maLigue) // Chercher l'entraineur ayant le plus de titres
{
	if (maLigue.getListeClubs().size() != 0){
		unsigned int maxTitres = 0;
		Entraineur* ptr_MeilleurEntraineur = nullptr;
		for (std::vector<Club>::iterator itClub = maLigue.debutListeClub(); itClub != maLigue.finListeClub(); itClub++){//Pour chaque club
			if (itClub->getListeStaffTechnique().size() != 0){
				for (std::vector<Personne*>::iterator itStaff = itClub->debutListeStaffTechnique(); itStaff != itClub->finListeStaffTechnique(); itStaff++){//et pour chaque membre du staff
					Entraineur* ptr_entraineur = dynamic_cast<Entraineur*>(*itStaff);
					if (ptr_entraineur != nullptr && ptr_entraineur->getTitres().size() > maxTitres){ //si cet entraineur possède plus de titres gagnes
						maxTitres = ptr_entraineur->getTitres().size(); //mise à jour du plus grand nombre de titres
						ptr_MeilleurEntraineur = ptr_entraineur; //on enregistre dans un pointeur le meilleur entraineur
					}
				}
			}
		}
		if (ptr_MeilleurEntraineur != nullptr){ //Si on a trouve un meilleur entraineur
			cout << "L'entraineur ayant le plus de titres gagnes est : " << "\n";
			cout << "Nom : " << ptr_MeilleurEntraineur->getNom() << "\n";
			cout << "Prenom : " << ptr_MeilleurEntraineur->getPrenom() << "\n";
			cout << "Age : " << ptr_MeilleurEntraineur->getAge() << "\n";
			cout << "Lieu de graduation : " << ptr_MeilleurEntraineur->getLieu() << "\n";
			cout << "Nombre de Titres Gagnes : " << ptr_MeilleurEntraineur->getTitres().size() << "\n";
			afficherListeTitres(*ptr_MeilleurEntraineur);
			cout << "\n";
		}
	}
	else {
		cout << "La ligue ne contient aucun club !" << "\n";
	}
}

void Ecran::chercherMeilleurClub(LigueSoccer maLigue) //Chercher le club avec le plus de palmares
{
	if (maLigue.getListeClubs().size() != 0){
		unsigned int maxPalmares = 0;
		Club* ptr_MeilleurClub = 0;
		for (std::vector<Club>::iterator itClub = maLigue.debutListeClub(); itClub != maLigue.finListeClub(); itClub++){//Pour chaque club
			if (itClub->getListePalmares().size() != 0 && itClub->getListePalmares().size() > maxPalmares){//si ce club a plus de titres
				maxPalmares = itClub->getListePalmares().size(); //maj du plus grd nbre de palmares
				ptr_MeilleurClub = &*itClub; //on sauvegarde le meilleur club dans un pointeur
			}
		}
		if (ptr_MeilleurClub != 0){// si on a trouvé un meilleur club
			cout << "Le club au plus gros palmares est : " << "\n";
			cout << "Nom : " << ptr_MeilleurClub->getNom() << "\n";
			cout << "Ville : " << ptr_MeilleurClub->getVille() << "\n";
			afficherListePalmares(*ptr_MeilleurClub);
			cout << "\n";
		}
	}
	else {
		cout << "La ligue ne contient aucun club !" << "\n";
	}
}

void Ecran::chercherSommeClubDate(LigueSoccer* maLigue){
	// un club a gagné de l'argent si il a vendu un joueur donc si il est le club libere d'un contrat possede par un club contractant
	if (maLigue->getListeClubs().size() > 1)
	{
		afficherListeClubs(*maLigue);
		cout << "Veuillez entrer l'ID du club" << "\n";
		int clubSelect;
		cin >> clubSelect;
		cout << "Veuillez entrer la date du contrat au format d m y" << "\n";
		int d, m, y;
		cin >> d >> m >> y;

		float sommeTotale = 0;

		for (std::vector<Club>::iterator it_club = maLigue->debutListeClub(); it_club != maLigue->finListeClub(); it_club++)//Pour chaque club
		{
			if (it_club->getListeContrats().size() > 0)
			{
				for (std::vector<Contrat>::iterator it_contrat = it_club->debutListeContrats(); it_contrat != it_club->finListeContrats(); it_contrat++)//pour chaque contrat de ce club
				{
					if (it_contrat->getClubLibere() == maLigue->getClubFromList(clubSelect)){ // si le club libere du contrat est celui qu'on a selectionne
						if (it_contrat->getDateContrat().getAnnee() == y && it_contrat->getDateContrat().getMois() == m && it_contrat->getDateContrat().getJour() == d){//si la date correspond
							sommeTotale += it_contrat->getReglement().getMontantClub();
							cout << it_contrat->getReglement().getMontantClub() << " $DOLLARS$ pour le contrat suivant : " << "\n";
							cout << "Nom Joueur : " << it_contrat->getJoueur()->getNom() << " | ";
							cout << "Date Contrat: " << it_contrat->getDateContrat().getJour() << " | " << it_contrat->getDateContrat().getMois() << " | " << it_contrat->getDateContrat().getAnnee() << "\n";
							cout << "Date Entree : " << it_contrat->getDateEntree().getJour() << " | " << it_contrat->getDateEntree().getMois() << " | " << it_contrat->getDateEntree().getAnnee() << " | ";
							cout << "Club contractant : " << it_contrat->getClubContractant()->getNom() << " | ";
							cout << "Club libere : " << it_contrat->getClubLibere()->getNom() << " | ";
							cout << "Duree : " << it_contrat->getDuree() << "\n";
							cout << "Description reglement : " << it_contrat->getReglement().getDescription() << " | ";
							cout << "Montant transfert : " << it_contrat->getReglement().getMontantTransfert() << " | ";
							cout << "Montant club : " << it_contrat->getReglement().getMontantClub() << " | ";
							cout << "Montant joueur : " << it_contrat->getReglement().getMontantJoueur() << "\n";
							cout << "\n";
						}
					}

				}
			}
		}
		if (sommeTotale != 0){
			cout << "\n" << "Le " << d << "/" << m << "/" << y << "\n";
			cout << "Le club " << maLigue->getClubFromList(clubSelect)->getNom() << " a encaisse une somme totale de : " << sommeTotale << "\n";
		}
		else if (sommeTotale == 0){
			cout << "\n" << "Le " << d << "/" << m << "/" << y << ", Le club " << maLigue->getClubFromList(clubSelect)->getNom() << " n'a rien encaisse " << "\n";
		}
	}
}


//Sauvegarde & Chargement
void Ecran::sauvegarderEtat()
{
	ofstream sortie("Sauvegarde.txt", ios::out);//Chaque classe est sauvegardée en paires de lignes	
	try{
		if (sortie.is_open()){
			for (std::vector<LigueSoccer>::iterator it_ligues = listeLigues.begin(); it_ligues != listeLigues.end(); it_ligues++){//Sauvegarde des ligues
				sortie.write("LIGUE", 5);//Premiere ligne identifie les informations et le nombre d'infos de la 2eme ligne
				sortie.write("\n", 1);
				sortie.write(it_ligues->getNom().c_str(), (streamsize)it_ligues->getNom().size());
				sortie.write("%", 1);
				sortie.write("\n", 1);
				//Sauvegarde liste des clubs
				for (std::vector<Club>::iterator it_clubs = it_ligues->debutListeClub(); it_clubs != it_ligues->finListeClub(); it_clubs++){//Sauvegarde des clubs de la ligue
					sortie.write("CLUB", 4);
					sortie.write("\n", 1);
					sortie.write(it_clubs->getNom().c_str(), (streamsize)it_clubs->getNom().size());
					sortie.write("%", 1);
					sortie.write(it_clubs->getVille().c_str(), (streamsize)it_clubs->getVille().size());
					sortie.write("%", 1);
					sortie.write(it_clubs->getCouleur().c_str(), (streamsize)it_clubs->getCouleur().size());
					sortie.write("%", 1);
					sortie.write(std::to_string(it_clubs->getAnnee().getAnnee()).c_str(), (streamsize)std::to_string(it_clubs->getAnnee().getAnnee()).size());
					sortie.write("%", 1);
					sortie.write(it_clubs->getHistoire().c_str(), (streamsize)it_clubs->getHistoire().size());
					sortie.write("%", 1);
					sortie.write(std::to_string(it_clubs->getStade().getCapacite()).c_str(), (streamsize)std::to_string(it_clubs->getStade().getCapacite()).size());
					sortie.write("%", 1);
					sortie.write(it_clubs->getStade().getQualite().c_str(), (streamsize)it_clubs->getStade().getQualite().size());
					sortie.write("%", 1);
					sortie.write(it_clubs->getStade().getNom().c_str(), (streamsize)it_clubs->getStade().getNom().size());
					sortie.write("%", 1);
					sortie.write(it_clubs->getStade().getAdresse().c_str(), (streamsize)it_clubs->getStade().getAdresse().size());
					sortie.write("%", 1);
					sortie.write(it_clubs->getAdresse().c_str(), (streamsize)it_clubs->getAdresse().size());
					sortie.write("%", 1);
					sortie.write("\n", 1);

					//Sauvegarde de la liste des joueurs
					for (std::vector<Joueur*>::iterator it_player = it_clubs->debutListeJoueurs(); it_player != it_clubs->finListeJoueurs(); it_player++){
						JoueurAutonome* ptr_joueur = dynamic_cast<JoueurAutonome*>(*it_player);
						if (ptr_joueur != nullptr){
							sortie.write("JOUEUR-AUTONOME", 15);
						}
						else if (ptr_joueur == nullptr){
							sortie.write("JOUEUR-NON-AUTONOME", 19);
						}
						sortie.write("\n", 1);
						sortie.write((*it_player)->getNom().c_str(), (streamsize)(*it_player)->getNom().size());
						sortie.write("%", 1);
						sortie.write((*it_player)->getPrenom().c_str(), (streamsize)(*it_player)->getPrenom().size());
						sortie.write("%", 1);
						sortie.write(std::to_string((*it_player)->getAge()).c_str(), (streamsize)std::to_string((*it_player)->getAge()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string((*it_player)->getTaille()).c_str(), (streamsize)std::to_string((*it_player)->getTaille()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string((*it_player)->getPoids()).c_str(), (streamsize)std::to_string((*it_player)->getPoids()).size());
						sortie.write("%", 1);
						sortie.write((*it_player)->getVille().c_str(), (streamsize)(*it_player)->getVille().size());
						sortie.write("%", 1);
						sortie.write("\n", 1);

						// sauvegarde liste parcours
						for (std::vector<Parcours>::iterator it_parcours = (*it_player)->debutListeParcours(); it_parcours != (*it_player)->finListeParcours(); it_parcours++){
							sortie.write("PARCOURS", 8);
							sortie.write("\n", 1);
							sortie.write(it_parcours->getClub().c_str(), (streamsize)it_parcours->getClub().size());
							sortie.write("%", 1);
							sortie.write(std::to_string(it_parcours->getDate().getJour()).c_str(), (streamsize)std::to_string(it_parcours->getDate().getJour()).size());
							sortie.write("%", 1);
							sortie.write(std::to_string(it_parcours->getDate().getMois()).c_str(), (streamsize)std::to_string(it_parcours->getDate().getMois()).size());
							sortie.write("%", 1);
							sortie.write(std::to_string(it_parcours->getDate().getAnnee()).c_str(), (streamsize)std::to_string(it_parcours->getDate().getAnnee()).size());
							sortie.write("%", 1);
							sortie.write("\n", 1);
						}
					}
					//Sauvegarde liste palmares
					for (std::vector<Palmares>::iterator it_palmares = it_clubs->debutListePalmares(); it_palmares != it_clubs->finListePalmares(); it_palmares++){
						sortie.write("PALMARES", 8);
						sortie.write("\n", 1);
						sortie.write(it_palmares->getTitre().c_str(), (streamsize)it_palmares->getTitre().size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_palmares->getDate().getJour()).c_str(), (streamsize)std::to_string(it_palmares->getDate().getJour()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_palmares->getDate().getMois()).c_str(), (streamsize)std::to_string(it_palmares->getDate().getMois()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_palmares->getDate().getAnnee()).c_str(), (streamsize)std::to_string(it_palmares->getDate().getAnnee()).size());
						sortie.write("%", 1);
						sortie.write("\n", 1);
					}
					//Sauvegarde liste Staff
					for (std::vector<Personne*>::iterator it_staff = it_clubs->debutListeStaffTechnique(); it_staff != it_clubs->finListeStaffTechnique(); it_staff++){
						Entraineur* ptr_Entraineur = dynamic_cast<Entraineur*>(*it_staff);
						if (ptr_Entraineur != nullptr){
							sortie.write("ENTRAINEUR", 10);
							sortie.write("\n", 1);
							sortie.write(ptr_Entraineur->getLieu().c_str(), (streamsize)ptr_Entraineur->getLieu().size());
							sortie.write("%", 1);
							sortie.write((*it_staff)->getNom().c_str(), (streamsize)(*it_staff)->getNom().size());
							sortie.write("%", 1);
							sortie.write((*it_staff)->getPrenom().c_str(), (streamsize)(*it_staff)->getPrenom().size());
							sortie.write("%", 1);
							sortie.write(std::to_string((*it_staff)->getAge()).c_str(), (streamsize)std::to_string((*it_staff)->getAge()).size());
							sortie.write("%", 1);
							sortie.write("\n", 1);
							//Sauvegarde liste titres gagnés
							for (std::vector<TitreGagne>::iterator it_titres = ptr_Entraineur->debutListeTitres(); it_titres != ptr_Entraineur->finListeTitres(); it_titres++){
								sortie.write("TITRE", 5);
								sortie.write("\n", 1);
								sortie.write(it_titres->getTitre().c_str(), (streamsize)it_titres->getTitre().size());
								sortie.write("%", 1);
								sortie.write(std::to_string(it_titres->getDate().getJour()).c_str(), (streamsize)std::to_string(it_titres->getDate().getJour()).size());
								sortie.write("%", 1);
								sortie.write(std::to_string(it_titres->getDate().getMois()).c_str(), (streamsize)std::to_string(it_titres->getDate().getMois()).size());
								sortie.write("%", 1);
								sortie.write(std::to_string(it_titres->getDate().getAnnee()).c_str(), (streamsize)std::to_string(it_titres->getDate().getAnnee()).size());
								sortie.write("%", 1);
								sortie.write(it_titres->getClub()->getNom().c_str(), (streamsize)it_titres->getClub()->getNom().size());
								sortie.write("%", 1);
								sortie.write("\n", 1);
							}

						}
						else {
							InfirmierSpecialise* ptr_Infirmier = dynamic_cast<InfirmierSpecialise*>(*it_staff);;
							if (ptr_Infirmier != nullptr){
								sortie.write("INFIRMIER", 9);
								sortie.write("\n", 1);
							}
							else{
								President* ptr_President = dynamic_cast<President*>(*it_staff);;
								if (ptr_President != nullptr){
									sortie.write("PRESIDENT", 9);
									sortie.write("\n", 1);
								}
								else{
									Recruteur* ptr_Recruteur = dynamic_cast<Recruteur*>(*it_staff);;
									if (ptr_Recruteur != nullptr){
										sortie.write("RECRUTEUR", 9);
										sortie.write("\n", 1);
									}
									else{
										Secretaire* ptr_Secretaire = dynamic_cast<Secretaire*>(*it_staff);;
										if (ptr_Secretaire != nullptr){
											sortie.write("SECRETAIRE", 10);
											sortie.write("\n", 1);
										}
									}
								}
							}
							sortie.write((*it_staff)->getNom().c_str(), (streamsize)(*it_staff)->getNom().size());
							sortie.write("%", 1);
							sortie.write((*it_staff)->getPrenom().c_str(), (streamsize)(*it_staff)->getPrenom().size());
							sortie.write("%", 1);
							sortie.write(std::to_string((*it_staff)->getAge()).c_str(), (streamsize)std::to_string((*it_staff)->getAge()).size());
							sortie.write("%", 1);
							sortie.write("\n", 1);
						}
					}

					//Sauvegarde liste Contrats
					for (std::vector<Contrat>::iterator it_contrat = it_clubs->debutListeContrats(); it_contrat != it_clubs->finListeContrats(); it_contrat++){
						sortie.write("CONTRAT", 7);
						sortie.write("\n", 1);
						sortie.write(it_contrat->getClubContractant()->getNom().c_str(), (streamsize)it_contrat->getClubContractant()->getNom().size());
						sortie.write("%", 1);
						sortie.write(it_contrat->getClubLibere()->getNom().c_str(), (streamsize)it_contrat->getClubLibere()->getNom().size());
						sortie.write("%", 1);
						//sortie.write(it_contrat->getJoueur()->getNom().c_str(), (streamsize)it_contrat->getJoueur()->getNom().size());
						//sortie.write("%", 1);
						sortie.write(std::to_string(it_contrat->getDuree()).c_str(), (streamsize)std::to_string(it_contrat->getDuree()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_contrat->getDateEntree().getJour()).c_str(), (streamsize)std::to_string(it_contrat->getDateEntree().getJour()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_contrat->getDateEntree().getMois()).c_str(), (streamsize)std::to_string(it_contrat->getDateEntree().getMois()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_contrat->getDateEntree().getAnnee()).c_str(), (streamsize)std::to_string(it_contrat->getDateEntree().getAnnee()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_contrat->getDateContrat().getJour()).c_str(), (streamsize)std::to_string(it_contrat->getDateContrat().getJour()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_contrat->getDateContrat().getMois()).c_str(), (streamsize)std::to_string(it_contrat->getDateContrat().getMois()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_contrat->getDateContrat().getAnnee()).c_str(), (streamsize)std::to_string(it_contrat->getDateContrat().getAnnee()).size());
						sortie.write("%", 1);
						sortie.write(it_contrat->getReglement().getDescription().c_str(), (streamsize)it_contrat->getReglement().getDescription().size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_contrat->getReglement().getMontantTransfert()).c_str(), (streamsize)std::to_string(it_contrat->getReglement().getMontantTransfert()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_contrat->getReglement().getMontantClub()).c_str(), (streamsize)std::to_string(it_contrat->getReglement().getMontantClub()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_contrat->getReglement().getMontantJoueur()).c_str(), (streamsize)std::to_string(it_contrat->getReglement().getMontantJoueur()).size());
						sortie.write("%", 1);

						sortie.write("\n", 1);
					}

					//Sauvegarde liste Ruptures
					for (std::vector<Rupture>::iterator it_rupture = it_clubs->debutListeRuptures(); it_rupture != it_clubs->finListeRuptures(); it_rupture++){
						sortie.write("RUPTURE", 7);
						sortie.write("\n", 1);
						sortie.write(it_rupture->getClub()->getNom().c_str(), (streamsize)it_rupture->getClub()->getNom().size());
						sortie.write("%", 1);
						//sortie.write(it_rupture->getJoueur()->getNom().c_str(), (streamsize)it_rupture->getJoueur()->getNom().size());
						//sortie.write("%", 1);
						sortie.write(it_rupture->getRaisons().c_str(), (streamsize)it_rupture->getRaisons().size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_rupture->getPenalite()).c_str(), (streamsize)std::to_string(it_rupture->getPenalite()).size());
						sortie.write("%", 1);
						sortie.write("\n", 1);
					}
				}

				//Sauvegarde du calendrier de la ligue
				for (std::vector<Rencontre>::iterator it_renc = it_ligues->debutCalendrierRencontres(); it_renc != it_ligues->finCalendrierRencontres(); it_renc++){
					sortie.write("RENCONTRE", 9);
					sortie.write("\n", 1);
					sortie.write(std::to_string(it_renc->getDateRencontre().getJour()).c_str(), (streamsize)std::to_string(it_renc->getDateRencontre().getJour()).size());
					sortie.write("%", 1);
					sortie.write(std::to_string(it_renc->getDateRencontre().getMois()).c_str(), (streamsize)std::to_string(it_renc->getDateRencontre().getMois()).size());
					sortie.write("%", 1);
					sortie.write(std::to_string(it_renc->getDateRencontre().getAnnee()).c_str(), (streamsize)std::to_string(it_renc->getDateRencontre().getAnnee()).size());
					sortie.write("%", 1);
					sortie.write(it_renc->getClubLocal()->getNom().c_str(), (streamsize)it_renc->getClubLocal()->getNom().size());
					sortie.write("%", 1);
					sortie.write(it_renc->getClubInvite()->getNom().c_str(), (streamsize)it_renc->getClubInvite()->getNom().size());
					sortie.write("%", 1);
					sortie.write("\n", 1);
					//Sauvegarde du Match
					if (it_renc->getMatchRencontre() != nullptr){
						sortie.write("MATCH", 5);
						sortie.write("\n", 1);
						//Sauvegarde Equipe Locale
						sortie.write(it_renc->getMatchRencontre()->getEquipeLocale().getClub()->getNom().c_str(), (streamsize)it_renc->getMatchRencontre()->getEquipeLocale().getClub()->getNom().size());
						sortie.write("%", 1);
						//sortie.write(it_renc->getMatchRencontre()->getEquipeLocale().getCapitaine()->getNom().c_str(), (streamsize)it_renc->getMatchRencontre()->getEquipeLocale().getCapitaine()->getNom().size());
						//sortie.write("%", 1);
						sortie.write(std::to_string(it_renc->getMatchRencontre()->getEquipeLocale().getNbreJoueurs()).c_str(), (streamsize)std::to_string(it_renc->getMatchRencontre()->getEquipeLocale().getNbreJoueurs()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_renc->getMatchRencontre()->getEquipeLocale().getNbreGardiens()).c_str(), (streamsize)std::to_string(it_renc->getMatchRencontre()->getEquipeLocale().getNbreGardiens()).size());
						sortie.write("%", 1);
						//Sauvegarde Equipe Invitee
						sortie.write(it_renc->getMatchRencontre()->getEquipeInvitee().getClub()->getNom().c_str(), (streamsize)it_renc->getMatchRencontre()->getEquipeInvitee().getClub()->getNom().size());
						sortie.write("%", 1);
						//sortie.write(it_renc->getMatchRencontre()->getEquipeInvitee().getCapitaine()->getNom().c_str(), (streamsize)it_renc->getMatchRencontre()->getEquipeInvitee().getCapitaine()->getNom().size());
						//sortie.write("%", 1);
						sortie.write(std::to_string(it_renc->getMatchRencontre()->getEquipeInvitee().getNbreJoueurs()).c_str(), (streamsize)std::to_string(it_renc->getMatchRencontre()->getEquipeInvitee().getNbreJoueurs()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_renc->getMatchRencontre()->getEquipeInvitee().getNbreGardiens()).c_str(), (streamsize)std::to_string(it_renc->getMatchRencontre()->getEquipeInvitee().getNbreGardiens()).size());
						sortie.write("%", 1);
						//Sauvegarde Resultat
						sortie.write(std::to_string(it_renc->getMatchRencontre()->getResultat().getNbreTotalButsEquipeLocale()).c_str(), (streamsize)std::to_string(it_renc->getMatchRencontre()->getResultat().getNbreTotalButsEquipeLocale()).size());
						sortie.write("%", 1);
						sortie.write(std::to_string(it_renc->getMatchRencontre()->getResultat().getNbreTotalButsEquipeInvitee()).c_str(), (streamsize)std::to_string(it_renc->getMatchRencontre()->getResultat().getNbreTotalButsEquipeInvitee()).size());
						sortie.write("%", 1);
						sortie.write("\n", 1);
						//Sauvegarde listePeriodes
						for (std::vector<Periode>::iterator it_periode = it_renc->getMatchRencontre()->debutListePeriodes(); it_periode != it_renc->getMatchRencontre()->finListePeriodes(); it_periode++){
							sortie.write("PERIODE", 7);
							sortie.write("\n", 1);
							sortie.write(std::to_string(it_periode->getDureePeriode()).c_str(), (streamsize)std::to_string(it_periode->getDureePeriode()).size());
							sortie.write("%", 1);
							sortie.write(std::to_string(it_periode->getNbreButsEquipeLocale()).c_str(), (streamsize)std::to_string(it_periode->getNbreButsEquipeLocale()).size());
							sortie.write("%", 1);
							sortie.write(std::to_string(it_periode->getNbreButsEquipeInvitee()).c_str(), (streamsize)std::to_string(it_periode->getNbreButsEquipeInvitee()).size());
							sortie.write("%", 1);
							sortie.write("\n", 1);
						}
					}
				}
			}
		}
		else { int e = 1; throw e; }
		sortie.close();
		cout << "Sauvegarde terminee" << "\n";
	}
	catch (int e){
		if (e == 1){
			cout << "probleme d'ouverturde du ficher sauvegarde.txt" << "\n";
		}
	}
}

void Ecran::retablirEtat()
{
	listeLigues.clear(); //on nettoie la liste pour repartir de zero en recreant tous les items

	char *nxtok, *line = new char[500];
	ifstream entree("Sauvegarde.txt", ios::in);

	const string L = "LIGUE";
	const string C = "CLUB";
	const string JA = "JOUEUR-AUTONOME";
	const string JNA = "JOUEUR-NON-AUTONOME";
	const string PARC = "PARCOURS";
	const string PALMA = "PALMARES";
	const string ENT = "ENTRAINEUR";
	const string TI = "TITRE";
	const string INF = "INFIRMIER";
	const string PRES = "PRESIDENT";
	const string REC = "RECRUTEUR";
	const string SEC = "SECRETAIRE";
	const string CO = "CONTRAT";
	const string RUP = "RUPTURE";
	const string RENC = "RENCONTRE";
	const string M = "MATCH";
	const string PER = "PERIODE";
	try {
		if (entree.is_open()){
			while (!entree.eof()){
				entree.getline(line, 500);//La premiere ligne identifie le contenu de la suivante dans la paire
				string ligne = line;//des strings pour resoudre les conflits

				if (strlen(line) > 0){
					if (ligne == L){//si la premiere ligne de la paire est LIGUE
						entree.getline(line, 500);// on prend la ligne suivante qui contient les infos de la ligue
						LigueSoccer* LigueTemp = new LigueSoccer();
						LigueTemp->setNom(strtok_s(line, "%", &nxtok));
						listeLigues.push_back(*LigueTemp);
					}

					if (ligne == C){//si la premiere ligne de la paire est CLUB
						entree.getline(line, 500);// on prend la ligne suivante qui contient les infos du club
						Stade* StadeTemp = new Stade();
						Club* ClubTemp = new Club();
						ClubTemp->setNom(strtok_s(line, "%", &nxtok));
						ClubTemp->setVille(strtok_s(NULL, "%", &nxtok));
						ClubTemp->setCouleur(strtok_s(NULL, "%", &nxtok));
						ClubTemp->setAnnee(atoi(strtok_s(NULL, "%", &nxtok)));
						ClubTemp->setHistoire(strtok_s(NULL, "%", &nxtok));
						StadeTemp->setCapacite(atoi(strtok_s(NULL, "%", &nxtok)));
						StadeTemp->setQualite(strtok_s(NULL, "%", &nxtok));
						StadeTemp->setNom(strtok_s(NULL, "%", &nxtok));
						StadeTemp->setAdresse(strtok_s(NULL, "%", &nxtok));
						ClubTemp->setStade(*StadeTemp);
						ClubTemp->setAdresse(strtok_s(NULL, "%", &nxtok));

						(listeLigues.end() - 1)->ajouterClub(*ClubTemp);//On enregistre le club dans la derniere ligue créée
					}

					if (ligne == JA || ligne == JNA){
						Joueur* JoueurTemp;
						if (ligne == JA){// si la premiere ligne de la paire est JOUEUR-AUTONOME
							JoueurTemp = new JoueurAutonome();
						}
						else /*if (ligne == JNA)*/ {// si la premiere ligne de la paire est JOUEUR-NON-AUTONOME
							JoueurTemp = new JoueurNonAutonome();
						}
						entree.getline(line, 500);// on prend la ligne suivante qui contient les infos du joueur
						JoueurTemp->setNom(strtok_s(line, "%", &nxtok));
						JoueurTemp->setPrenom(strtok_s(NULL, "%", &nxtok));
						JoueurTemp->setAge(atoi(strtok_s(NULL, "%", &nxtok)));
						JoueurTemp->setTaille(atof(strtok_s(NULL, "%", &nxtok)));
						JoueurTemp->setPoids(atof(strtok_s(NULL, "%", &nxtok)));
						JoueurTemp->setVille(strtok_s(NULL, "%", &nxtok));

						((listeLigues.end() - 1)->finListeClub() - 1)->ajouterJoueur(JoueurTemp);
					}

					if (ligne == PARC){
						entree.getline(line, 500);
						Parcours* ParcoursTemp = new Parcours();
						ParcoursTemp->setClub(strtok_s(line, "%", &nxtok));
						ParcoursTemp->setDate(atoi(strtok_s(NULL, "%", &nxtok)), atoi(strtok_s(NULL, "%", &nxtok)), atoi(strtok_s(NULL, "%", &nxtok)));
						((listeLigues.end() - 1)->finListeClub() - 1)->getListeJoueurs().back()->ajouterParcours(*ParcoursTemp);
					}

					if (ligne == PALMA){
						entree.getline(line, 500);
						Palmares* PalmaresTemp = new Palmares();
						PalmaresTemp->setTitre(strtok_s(line, "%", &nxtok));
						PalmaresTemp->setDate(atoi(strtok_s(NULL, "%", &nxtok)), atoi(strtok_s(NULL, "%", &nxtok)), atoi(strtok_s(NULL, "%", &nxtok)));

						((listeLigues.end() - 1)->finListeClub() - 1)->ajouterPalmares(*PalmaresTemp);
					}

					if (ligne == ENT || ligne == INF || ligne == PRES || ligne == REC || ligne == SEC){
						if (ligne == ENT){
							Entraineur* ENTTemp = new Entraineur();
							entree.getline(line, 500);
							ENTTemp->setLieu(strtok_s(line, "%", &nxtok));
							ENTTemp->setNom(strtok_s(NULL, "%", &nxtok));
							ENTTemp->setPrenom(strtok_s(NULL, "%", &nxtok));
							ENTTemp->setAge(atoi(strtok_s(NULL, "%", &nxtok)));
							((listeLigues.end() - 1)->finListeClub() - 1)->ajouterStaff(ENTTemp);
						}
						if (ligne == INF){
							InfirmierSpecialise* INFTemp = new InfirmierSpecialise();
							entree.getline(line, 500);
							INFTemp->setNom(strtok_s(line, "%", &nxtok));
							INFTemp->setPrenom(strtok_s(NULL, "%", &nxtok));
							INFTemp->setAge(atoi(strtok_s(NULL, "%", &nxtok)));
							((listeLigues.end() - 1)->finListeClub() - 1)->ajouterStaff(INFTemp);
						}
						if (ligne == PRES){
							President* PRESTemp = new President();
							entree.getline(line, 500);
							PRESTemp->setNom(strtok_s(line, "%", &nxtok));
							PRESTemp->setPrenom(strtok_s(NULL, "%", &nxtok));
							PRESTemp->setAge(atoi(strtok_s(NULL, "%", &nxtok)));
							((listeLigues.end() - 1)->finListeClub() - 1)->ajouterStaff(PRESTemp);
						}
						if (ligne == REC){
							Recruteur* RECTemp = new Recruteur();
							entree.getline(line, 500);
							RECTemp->setNom(strtok_s(line, "%", &nxtok));
							RECTemp->setPrenom(strtok_s(NULL, "%", &nxtok));
							RECTemp->setAge(atoi(strtok_s(NULL, "%", &nxtok)));
							((listeLigues.end() - 1)->finListeClub() - 1)->ajouterStaff(RECTemp);
						}
						if (ligne == SEC){
							Secretaire* SECTemp = new Secretaire();
							entree.getline(line, 500);
							SECTemp->setNom(strtok_s(line, "%", &nxtok));
							SECTemp->setPrenom(strtok_s(NULL, "%", &nxtok));
							SECTemp->setAge(atoi(strtok_s(NULL, "%", &nxtok)));
							((listeLigues.end() - 1)->finListeClub() - 1)->ajouterStaff(SECTemp);
						}
					}

					if (ligne == TI){
						entree.getline(line, 500);
						TitreGagne* TitreTemp = new TitreGagne();
						TitreTemp->setTitre(strtok_s(line, "%", &nxtok));
						TitreTemp->setDate(atoi(strtok_s(NULL, "%", &nxtok)), atoi(strtok_s(NULL, "%", &nxtok)), atoi(strtok_s(NULL, "%", &nxtok)));

						Club* ptr = new Club();
						ptr->setNom(strtok_s(NULL, "%", &nxtok));
						for (std::vector<Club>::iterator it_club = listeLigues.back().debutListeClub(); it_club != listeLigues.back().finListeClub(); it_club++){
							if (ptr->getNom() == it_club->getNom()){
								*ptr = *it_club;
							}
						}
						TitreTemp->setClub(ptr);

						Entraineur* ptr_last_entraineur = dynamic_cast<Entraineur*>(((listeLigues.end() - 1)->finListeClub() - 1)->getListeStaffTechnique().back());
						if (ptr_last_entraineur != nullptr){
							ptr_last_entraineur->ajouterTitre(*TitreTemp);
						}
					}

					if (ligne == CO){
						entree.getline(line, 500);
						Contrat* ContratTemp = new Contrat();
						Reglement* ReglementTemp = new Reglement();

						Club* CC = new Club();
						Club* CL = new Club();
						CC->setNom(strtok_s(line, "%", &nxtok));
						CL->setNom(strtok_s(NULL, "%", &nxtok));
						for (std::vector<Club>::iterator it_club = listeLigues.back().debutListeClub(); it_club != listeLigues.back().finListeClub(); it_club++){
							if (CC->getNom() == it_club->getNom()){
								*CC = *it_club;
							}
							if (CL->getNom() == it_club->getNom()){
								*CL = *it_club;
							}
						}
						ContratTemp->setClubContractant(CC);
						ContratTemp->setClubLibere(CL);/*
						Joueur* JL=nullptr;
						JL->setNom(strtok_s(NULL, "%", &nxtok));
						for (std::vector<Club>::iterator it_club = listeLigues.back().debutListeClub(); it_club != listeLigues.back().finListeClub(); it_club++){
						for (std::vector<Joueur*>::iterator it_j = it_club->debutListeJoueurs(); it_j != it_club->finListeJoueurs(); it_j++){
						if (JL->getNom() == (*it_j)->getNom()){
						*JL = *(*it_j);
						}
						}
						}
						ContratTemp->setJoueur(JL);*/

						ContratTemp->setDuree(atoi(strtok_s(NULL, "%", &nxtok)));
						ContratTemp->setDateEntree(atoi(strtok_s(NULL, "%", &nxtok)), atoi(strtok_s(NULL, "%", &nxtok)), atoi(strtok_s(NULL, "%", &nxtok)));
						ContratTemp->setDateContrat(atoi(strtok_s(NULL, "%", &nxtok)), atoi(strtok_s(NULL, "%", &nxtok)), atoi(strtok_s(NULL, "%", &nxtok)));
						ReglementTemp->setDescription(strtok_s(NULL, "%", &nxtok));
						ReglementTemp->setMontantTransfert(atoi(strtok_s(NULL, "%", &nxtok)));
						ReglementTemp->setMontantClub(atoi(strtok_s(NULL, "%", &nxtok)));
						ReglementTemp->setMontantJoueur(atoi(strtok_s(NULL, "%", &nxtok)));

						ContratTemp->setReglement(*ReglementTemp);
						((listeLigues.end() - 1)->finListeClub() - 1)->ajouterContrat(*ContratTemp);
					}

					if (ligne == RUP){
						entree.getline(line, 500);
						Rupture* RuptureTemp = new Rupture();

						Club* ptr_c = new Club();
						ptr_c->setNom(strtok_s(line, "%", &nxtok));
						for (std::vector<Club>::iterator it_club = listeLigues.back().debutListeClub(); it_club != listeLigues.back().finListeClub(); it_club++){
							if (ptr_c->getNom() == it_club->getNom()){
								*ptr_c = *it_club;
							}
						}
						RuptureTemp->setClub(ptr_c);

						/*Joueur* JP=nullptr;
						JP->setNom(strtok_s(NULL, "%", &nxtok));
						for (std::vector<Club>::iterator it_club = listeLigues.back().debutListeClub(); it_club != listeLigues.back().finListeClub(); it_club++){
						for (std::vector<Joueur*>::iterator it_j = it_club->debutListeJoueurs(); it_j != it_club->finListeJoueurs(); it_j++){
						if (JP->getNom() == (*it_j)->getNom()){
						*JP = *(*it_j);
						}
						}
						}
						RuptureTemp->setJoueur(JP);*/

						RuptureTemp->setRaisons(strtok_s(NULL, "%", &nxtok));
						RuptureTemp->setPenalite(atof(strtok_s(NULL, "%", &nxtok)));

						((listeLigues.end() - 1)->finListeClub() - 1)->ajouterRupture(*RuptureTemp);
					}


					if (ligne == RENC){
						entree.getline(line, 500);
						Rencontre* RencontreTemp = new Rencontre();
						Date* DateTemp = new Date();
						DateTemp->setJour(atoi(strtok_s(line, "%", &nxtok)));
						DateTemp->setMois(atoi(strtok_s(NULL, "%", &nxtok)));
						DateTemp->setAnnee(atoi(strtok_s(NULL, "%", &nxtok)));

						Club* ptr_cl = new Club();
						ptr_cl->setNom(strtok_s(NULL, "%", &nxtok));
						for (std::vector<Club>::iterator it_club = listeLigues.back().debutListeClub(); it_club != listeLigues.back().finListeClub(); it_club++){
							if (ptr_cl->getNom() == it_club->getNom()){
								*ptr_cl = *it_club;
							}
						}
						RencontreTemp->setClubLocal(ptr_cl);
						Club* ptr_ci = new Club();
						ptr_ci->setNom(strtok_s(NULL, "%", &nxtok));
						for (std::vector<Club>::iterator it_club = listeLigues.back().debutListeClub(); it_club != listeLigues.back().finListeClub(); it_club++){
							if (ptr_ci->getNom() == it_club->getNom()){
								*ptr_ci = *it_club;
							}
						}
						RencontreTemp->setClubInvite(ptr_ci);

						RencontreTemp->setDateRencontre(*DateTemp);
						(listeLigues.end() - 1)->ajouterRencontre(*RencontreTemp);
					}
					if (ligne == M){
						entree.getline(line, 500);
						Match* MatchTemp = new Match();
						Equipe* EquipeLocaleTemp = new Equipe();
						Equipe* EquipeInviteeTemp = new Equipe();
						Resultat* ResultatTemp = new Resultat();

						Club* ptr_cl = new Club();
						ptr_cl->setNom(strtok_s(line, "%", &nxtok));
						for (std::vector<Club>::iterator it_club = listeLigues.back().debutListeClub(); it_club != listeLigues.back().finListeClub(); it_club++){
							if (ptr_cl->getNom() == it_club->getNom()){
								*ptr_cl = *it_club;
							}
						}
						EquipeLocaleTemp->setClub(ptr_cl);/*
						Joueur* cap_local=0;
						cap_local->setNom(strtok_s(NULL, "%", &nxtok));
						for (std::vector<Club>::iterator it_club = listeLigues.back().debutListeClub(); it_club != listeLigues.back().finListeClub(); it_club++){
						for (std::vector<Joueur*>::iterator it_j = it_club->debutListeJoueurs(); it_j != it_club->finListeJoueurs(); it_j++){
						if (cap_local->getNom() == (*it_j)->getNom()){
						*cap_local = *(*it_j);
						}
						}
						}
						EquipeLocaleTemp->setCapitaine(cap_local);*/

						EquipeLocaleTemp->setNbreJoueurs(atoi(strtok_s(NULL, "%", &nxtok)));
						EquipeLocaleTemp->setNbreGardiens(atoi(strtok_s(NULL, "%", &nxtok)));

						Club* ptr_ci = new Club();
						ptr_ci->setNom(strtok_s(NULL, "%", &nxtok));
						for (std::vector<Club>::iterator it_club = listeLigues.back().debutListeClub(); it_club != listeLigues.back().finListeClub(); it_club++){
							if (ptr_ci->getNom() == it_club->getNom()){
								*ptr_ci = *it_club;
							}
						}
						EquipeInviteeTemp->setClub(ptr_ci);/*
						Joueur* cap_invit=0;
						cap_invit->setNom(strtok_s(NULL, "%", &nxtok));
						for (std::vector<Club>::iterator it_club = listeLigues.back().debutListeClub(); it_club != listeLigues.back().finListeClub(); it_club++){
						for (std::vector<Joueur*>::iterator it_j = it_club->debutListeJoueurs(); it_j != it_club->finListeJoueurs(); it_j++){
						if (cap_invit->getNom() == (*it_j)->getNom()){
						*cap_invit = *(*it_j);
						}
						}
						}
						EquipeInviteeTemp->setCapitaine(cap_invit);*/

						EquipeInviteeTemp->setNbreJoueurs(atoi(strtok_s(NULL, "%", &nxtok)));
						EquipeInviteeTemp->setNbreGardiens(atoi(strtok_s(NULL, "%", &nxtok)));

						ResultatTemp->setNbreTotalButsEquipeLocale(atoi(strtok_s(NULL, "%", &nxtok)));
						ResultatTemp->setNbreTotalButsEquipeInvitee(atoi(strtok_s(NULL, "%", &nxtok)));

						MatchTemp->setEquipeLocale(*EquipeLocaleTemp);
						MatchTemp->setEquipeInvitee(*EquipeInviteeTemp);
						MatchTemp->setResultat(*ResultatTemp);
						((listeLigues.end() - 1)->finCalendrierRencontres() - 1)->setMatchRencontre(MatchTemp);
					}
					if (ligne == PER){
						entree.getline(line, 500);
						Periode* PeriodeTemp = new Periode();
						PeriodeTemp->setDureePeriode(atoi(strtok_s(line, "%", &nxtok)));
						PeriodeTemp->setNbreButsEquipeLocale(atoi(strtok_s(NULL, "%", &nxtok)));
						PeriodeTemp->setNbreButsEquipeInvitee(atoi(strtok_s(NULL, "%", &nxtok)));

						((listeLigues.end() - 1)->finCalendrierRencontres() - 1)->getMatchRencontre()->ajouterPeriode(*PeriodeTemp);
					}
				}
			}
		}
		else{ int e = 1; throw e; }
		entree.close();
		delete[] line;
		cout << "Chargement termine" << "\n";
	}
	catch (int e){
		if (e == 1){
			cout << "probleme d'ouverturde du ficher sauvegarde.txt" << "\n";
		}
	}
};