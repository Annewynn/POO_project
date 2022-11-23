/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: application.cpp
###########################################*/

#include "application.hpp"
#include <iostream>
#include <string>

using namespace std;

Application::Application()
{
	liste_radiographie = {};
}

void Application::ajouter(Radiographie radio)
{
	liste_radiographie.push_back(radio);
}

bool Application::comparePatient(Radiographie &a, Radiographie &b){
	if(a.patient.get_nom() < b.patient.get_nom()){
		return a.patient.get_prenom() < b.patient.get_prenom();
	} else {return false;}
}
bool compareDate(Radiographie &a, Radiographie &b){
	if(a.get_date().annee == b.get_date().annee){
		if(a.get_date().mois == b.get_date().mois){
			return a.get_date().jour < b.get_date().jour;
		}
		else return a.get_date().mois < b.get_date().mois;
	}
	else return a.get_date().annee < b.get_date().annee;
}
bool compareNumExam(Radiographie &a, Radiographie &b){
	return a.get_id() < b.get_id();	
}


void Application::afficher_liste(vector<Radiographie> radios){
	cout << "Quel type de tri ?\n";
	cout << "(Par défaut:1 , par patient: 2, par date: 3, par numéro d'axamen: 4)\n";
	
	for(int i=0;i<radios.size();i++){
		cout << radios[i].afficher_radio_as_table() << endl;
	}
}