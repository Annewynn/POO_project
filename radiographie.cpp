/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: radiographie.cpp
###########################################*/
#include <string>
#include <iostream>
#include <vector>
#include "radiographie.hpp"
#include "profil.hpp"
#include "cliche.hpp"
using namespace std;

Radiographie::Radiographie(int numero, string techno, string id, Medecin docteur, vector<int> jour, 
bool isDone, vector<Cliche> images):medecin{docteur},liste_cliche{images}
{
	NumExamen = numero;
	type = techno;
	id_patient = id;
	medecin = docteur;
	date.jour = jour[0];
	date.mois = jour[1];
	date.annee = jour[2];
	etat = isDone;
}

string Radiographie::get_etat(){
	if(etat)return "Effectuée";
	else return "Planifiée";
}

Date Radiographie::get_date(){
	return date;
}

string Radiographie::get_liste_cliche(){
	string list_cliche = "";
	for(int i=0; i<liste_cliche.size();i++){
		list_cliche += "\t-";
		liste_cliche[i].get_cliche();
	}
	return list_cliche;
}

string Radiographie::afficher_radio(){
	string radio_pretty = "";
	radio_pretty += "#############################################\n";
	radio_pretty += "N° d'examen: " + NumExamen;
	radio_pretty += "\t\tDate: " + to_string(date.jour) + "/" + to_string(date.mois) + "/" + to_string(date.annee) +"\n";
	radio_pretty += "Type de radio: " + type + '\n';
	radio_pretty += "N° patient: " + id_patient;
	radio_pretty += "\nMedecin:\n";
	radio_pretty += medecin.afficher() + "\n";
	radio_pretty += this -> get_etat() + '\n';
	radio_pretty += "Liste des clichés:\n";
	radio_pretty += this -> get_liste_cliche() + '\n';
	radio_pretty += "#############################################\n";
	return radio_pretty;
}

void Radiographie::set_etat()
{
	etat = 1;
}

string Radiographie::get_id()
{
	return id_patient;
}