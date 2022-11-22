/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: compte_rendu_medical.cpp
###########################################*/
#include "compte_rendu_medical.hpp"
#include <iostream>
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
void Compte_rendu_medical::print_Compte_Rendu(){
	string mdp;
	int cpt = 0;
	cout << "Entrez le mot de passe du compte rendu: "; cin >> mdp; cout << endl;
	while(mdp_cr != mdp && cpt<3){
		cout << "\033[1;31mMot de passe incorrect\033[0m\n";
		cin >> mdp;
		cpt++;
	}
	if(cpt < 3 && mdp_cr == mdp){
		cout << "#############################################\n";
		cout << "Numéro d'examen: " << NumExam << endl;
		patient.consulter();
		cout << "Compte rendu:\n"<< texte << endl;
		cout << "#############################################\n";
	} else {cout << "\033[1;31mNombre d'essais dépassé.\033[0m\n";}
}