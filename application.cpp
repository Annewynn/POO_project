/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: application.cpp
###########################################*/

#include "application.hpp"
#include "fonctions.hpp"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

Application::Application()
{
	liste_radiographie = {};
}

void Application::ajouter(Radiographie radio)
{
	liste_radiographie.push_back(radio);
}


string Application::afficher_liste(vector<Radiographie> radios){
	/*On commence par initialiser la variable qui récupère le tableau
	de la liste des radios, et on ajoute un header.
	*/
	string liste_trier = "Numéro d'éxamen\tNom patient\tPrénom patient\tAge patient\t";
	liste_trier += "Type radio\tNom médecin\tPrénom médecin\tDate\tStatut\tListe des clichés (Numéro[Chemin]:Description)\n";
	cout << "\tQuel type de tri ?\n";
	cout << "\t[1] Par défaut\n\t[2] Par patient\n\t[3] Par date\n\t [4] Par numéro d'examen\n";
	int choix = input();
	switch(choix){
		case 1:
			cout << "Affichage par défaut:\n";
			for(int i=0;i<radios.size();i++){
				liste_trier += radios[i].afficher_radio_as_table() + "\n";
			}
			break;
		case 2:
			cout << "Affichage par patient:\n";
			sort(radios.begin(),radios.end(), comparePatient);
			for(int i=0;i<radios.size();i++){
				liste_trier += radios[i].afficher_radio_as_table() + "\n";
			}
			break;
		case 3:
			cout << "Affichage par date:\n";
			sort(radios.begin(),radios.end(), compareDate);
			for(int i=0;i<radios.size();i++){
				liste_trier += radios[i].afficher_radio_as_table() + "\n";
			}
			break;
		case 4:
			cout << "Affichage par numéro d'examen:\n";
			sort(radios.begin(),radios.end(), compareNumExam);
			for(int i=0;i<radios.size();i++){
				liste_trier += radios[i].afficher_radio_as_table() + "\n";
			}
			break;
		default:
			cout << "\033[1;31mSaisie incorrecte.\033[0m\n";
			break;
	}
	return liste_trier;
}