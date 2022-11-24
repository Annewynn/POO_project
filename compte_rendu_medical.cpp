/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: compte_rendu_medical.cpp
###########################################*/
#include "compte_rendu_medical.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

Compte_rendu_medical::Compte_rendu_medical(int id, string mdp, Patient pat):patient{pat}
{
    NumExam = id;
    mdp_cr = mdp;
}

void Compte_rendu_medical::get_Compte_Rendu(){
    string line;
    cout << "Veuillez saisir le compte rendu médical:\n";
	cin.ignore();	// Nécessite de clear "cin" car utilisé précédement et sinon casse getline()
    while ( getline(cin, line) && !line.empty() ){
		texte += line + "\n" ;
	}
}

void Compte_rendu_medical::modifier_Compte_Rendu()
{
	string line;
    cout << "Veuillez saisir le compte rendu médical:\n";
	cin.ignore();	// Nécessite de clear "cin" car utilisé précédement et sinon casse getline()
    while ( getline(cin, line) && !line.empty() ){
		texte += line + "\n" ;
	}
}

void Compte_rendu_medical::get_Compte_Rendu(std::string compte_rendu){
	texte = compte_rendu;
}

/// @brief Permet d'afficher proprement le compte rendu
bool Compte_rendu_medical::print_Compte_Rendu(){
	string mdp;
	int cpt;
	cpt = 0;
	cout << "Entrez le mot de passe du compte rendu: "; 
	cin >> mdp; 
	cout << endl;
	while(mdp_cr != mdp && cpt<3){
		cout << "\033[1;31mMot de passe incorrect\033[0m\n";
		cin >> mdp;
		cpt++;
	}
	if(cpt < 3 && mdp_cr == mdp){
		cout << "#############################################\n";
		cout << "Numéro d'examen: " << to_string(NumExam) << endl;
		cout << patient.consulter() << endl;
		cout << "Compte rendu:\n"<< texte << endl;
		cout << "#############################################\n";
		return true;
	} else 
	{
		cout << "\033[1;31mNombre d'essais dépassé.\033[0m\n";
		return false;
	}
}

/// @brief Permet de renvoyer sous forme de string le compte rendu medical sans demaner le mot de passe
/// @return string Le compte rendu de manière jolie
string Compte_rendu_medical::return_Compte_Rendu(){
	string CompteRendu = "";
	CompteRendu += "#############################################\n";
	CompteRendu += "Numéro d'examen: " + to_string(NumExam);
	cout << patient.consulter() << endl;
	CompteRendu += "Compte rendu:\n" + texte;
	CompteRendu += "\n#############################################\n";
	return CompteRendu;
}

//inspiré de examen
void Compte_rendu_medical::sauvegarder_crm(string chemin)
{
	string filename = chemin + "/" + to_string(NumExam) + "_crm.txt";
	cout <<filename << " créé"  << endl;
	ofstream examen_file(filename);
	examen_file << to_string(NumExam) << "\t";
	examen_file << patient.get_id() << "\t";
	examen_file << texte;
	examen_file.close();
}