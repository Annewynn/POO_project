/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: radiographie.cpp
###########################################*/
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "radiographie.hpp"
#include "profil.hpp"
#include "cliche.hpp"
using namespace std;

Radiographie::Radiographie(int numero, string techno, Patient pat, Medecin docteur, vector<int> jour, 
bool isDone, vector<Cliche> images):patient{pat},medecin{docteur},liste_cliche{images}
{
	NumExamen = numero;
	type = techno;
	patient = pat;
	medecin = docteur;
	date.jour = jour[0];
	date.mois = jour[1];
	date.annee = jour[2];
	etat = isDone;
}

string Radiographie::get_etat()
{
	if(etat)return "Effectuée";
	else return "Planifiée";
}

Date Radiographie::get_date(){
	return date;
}

string Radiographie::get_liste_cliche()
{
	string list_cliche = "";
	for(int i=0; i<liste_cliche.size();i++)
	{
		//list_cliche += "\t-";
		list_cliche += liste_cliche[i].get_cliche();
	}
	return list_cliche;
}

string Radiographie::afficher_radio()
{
	string radio_pretty = "";
	radio_pretty += "#############################################\n";
	radio_pretty += "N° d'examen: " + to_string(NumExamen);
	radio_pretty += "\t\tDate: " + to_string(date.jour) + "/" + to_string(date.mois) + "/" + to_string(date.annee) +"\n";
	radio_pretty += "Type de radio: " + type + '\n';
	radio_pretty += "N° patient: " + patient.get_id();
	radio_pretty += "\n\t" + patient.afficher();
	radio_pretty += "\nMedecin:\n\t";
	radio_pretty += medecin.consulter() + "\n";
	radio_pretty += this -> get_etat() + '\n';
	radio_pretty += "Liste des clichés:\n";
	radio_pretty += this -> get_liste_cliche() + '\n';
	radio_pretty += "#############################################\n";
	return radio_pretty;
}

string Radiographie::afficher_radio_as_table()
{
	string table = "";
	table += to_string(NumExamen) + '\t';
	table += patient.get_nom() + '\t' + patient.get_prenom() + '\t' + to_string(patient.get_age()) + '\t';
	table += type + '\t' + medecin.get_nom() + '\t' + medecin.get_prenom() +'\t';
	table += to_string(date.annee) + '/' + to_string(date.mois) + '/' + to_string(date.jour) + '\t';
	table += this -> get_etat() + '\t';
	for(int i=0;i<liste_cliche.size();i++){
		table += liste_cliche[i].return_cliche() + '\t';
	}
	return table;
}

void Radiographie::set_etat()
{
	etat = 1;
}

string Radiographie::get_id()
{
	return patient.get_id();
}

int Radiographie::get_numexam()
{
	return NumExamen;
}

//inspiré de sauvegarder_examen
void Radiographie::sauvegarder_radio(string chemin)
{
	string filename = chemin + "/" + to_string(NumExamen) + "_radio.txt";
	cout <<filename << " créé"  << endl;
	ofstream examen_file(filename);
	examen_file << "numéro\ttechnique\tpatient\tmedecin\tdate\tetat\n";
	examen_file << to_string(NumExamen) << "\t";
	examen_file << type << "\t";
	examen_file << patient.get_id() << "\t";
	examen_file << medecin.get_id() << "\t";
	examen_file << to_string(date.jour) << "/" << to_string(date.mois) << "/" << to_string(date.annee) << "\t";
	if (etat) examen_file << "EFFECTUEE\n";
	else examen_file << "PLANIFIEE";
	examen_file.close();
}

void Radiographie::sauvegarder_cliches(string chemin)
{
	string filename = chemin + "/" + to_string(NumExamen) + "_images.txt";
	cout <<filename << " créé"  << endl;
	ofstream examen_file(filename);
	for (int i=0; i<liste_cliche.size(); i++)
	{
		if (i <10) examen_file << "0" << to_string(i) << "\t";
		else examen_file << to_string(i) << "\t";
		examen_file << liste_cliche[i].get_path() << "\t";
		examen_file << liste_cliche[i].get_legende();
		//if (i != liste_cliche.size()-1) examen_file << "\n";
	}
	examen_file.close();
}