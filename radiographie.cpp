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

Radiographie::Radiographie(int numero, string techno, int id, Medecin docteur, vector<int> jour, 
bool isDone, vector<Cliche> images):medecin{docteur},liste_cliche{images}
{
	NumExamen = numero;
	type = techno;
	id_patient = id;
	//medecin = docteur;
	date.jour = jour[0];
	date.mois = jour[1];
	date.annee = jour[2];
	etat = isDone;
	/*for (int i = 0; i < images.size(); i++)
	{
		liste_cliche.push_back(images[i]);
	}*/
};

string Radiographie::get_etat(){
	if(etat)return "Effectuée";
	else return "Planifiée";
}

Date Radiographie::get_date(){
	return date;
}

void Radiographie::get_liste_cliche(){
	for(int i=0; i<liste_cliche.size();i++){
		cout << "-\t";
		liste_cliche[i].get_cliche();
	}
}

void Radiographie::afficher_radio(){
	cout << "#############################################\n";
	cout << "N° d'examen: " << NumExamen;
	cout << "\t\tDate: " << date.jour << "/" << date.mois << "/" << date.annee <<endl;
	cout << "Type de radio: " << type << endl;
	cout << "N° patient: " << id_patient;
	cout << "Medecin:\n";
	medecin.afficher();
	cout << this -> get_etat();
	cout << "Liste des clichés:\n";
	this -> get_liste_cliche();
	cout << "#############################################\n";
}