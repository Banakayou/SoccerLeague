using namespace std;
#include <iostream>
#include "LigueSoccer.h"
#include "Ecran.h"


void main(){
	//On instancie un ecran contenant les méthodes de recherche et d'affichage (afin de faciliter la transition GUI)
	Ecran* ecran1 = new Ecran();
	cout << "Bienvenue dans le logiciel de gestion des ligues" << "\n";

	//lancement menu principal
	ecran1->menuPrincipal();
}
