/*#########################################
## 28/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: profil.cpp
###########################################*/
#include "profil.hpp"
#include <iostream>

using namespace std;

Profil::Profil(string name, string f_name, string idi, string pwd, int annee, char sex)
        {
            nom = name;
            prenom = f_name;
            id = idi;
            mdp = pwd;
            age = annee;
            sexe = sex;
        }
void Profil::consulter(){
	cout << "Enchanté " << nom << " " << prenom <<endl;
}
void Profil::afficher(){
	cout << "Nom et prénom: " << nom << " " << prenom << endl;
	cout << "Age: " << age << "\t" << "Sexe: " << sexe << endl;
}