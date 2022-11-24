/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: medecin.cpp
###########################################*/
#include <iostream>
#include <string>
#include "medecin.hpp"
using namespace std;

Medecin::Medecin(string name, string f_name, string idi, string pwd, int annee, char sex):Profil(name, f_name, idi, pwd, annee, sex)
{
	nom = name;
	prenom = f_name;
	id = idi;
	mdp = pwd;
	age = annee;
	sexe = sex;
};

string Medecin::consulter()
{
	//string medecin_consult = "";
    //medecin_consult += nom + " " + prenom;
	return nom + " " + prenom;
}