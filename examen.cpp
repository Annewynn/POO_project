/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: examen.cpp
###########################################*/
#include "examen.hpp"
#include "radiographie.hpp"
#include "compte_rendu_medical.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Examen::Examen(int numero, Radiographie R, Compte_rendu_medical CR):radio{R}, crm{CR}
{
	NumExam = numero;
	radio = R;
	crm = CR; 
}

void Examen::sauvegarder_examen()
{
	string filename = to_string(NumExam);
	cout <<filename << " créé"  << endl;
	ofstream examen_file(filename + ".txt");
	examen_file << "######### Compte Rendu ########\n";
	examen_file << crm.return_Compte_Rendu() << '\n';
	examen_file << "######### Radiographies ########\n";
	examen_file << radio.afficher_radio() << '\n';
	examen_file.close();
}