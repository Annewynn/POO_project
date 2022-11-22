/*#########################################
## 28/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: profil.cpp
###########################################*/
#include "profil.hpp"
#include <iostream>
#include <string>

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
string Profil::consulter(){
	string profil_consult = "";
	profil_consult += "Enchanté " + nom + " " + prenom;
	return profil_consult;
}
string Profil::afficher(){
	string profil_print = "";
	profil_print += "Nom et prénom: " + nom + " " + prenom +'\n';
	profil_print += "Age: " + to_string(age) + "\t" + "Sexe: " + sexe + '\n';
	return profil_print;
}

string Profil::get_id()
{
    return id;
}

string Profil::get_mdp()
{
    return mdp;
}
string Profil::get_nom()
{
    return nom;
}
string Profil::get_prenom()
{
    return prenom;
}

int Profil::get_age()
{
    return age;
}
char Profil::get_sexe()
{
    return sexe;
} 