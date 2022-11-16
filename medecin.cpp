/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: medecin.cpp
###########################################*/
#include <iostream>
#include "medecin.hpp"
using namespace std;

Medecin::Medecin(string name, string f_name, string idi, string pwd, int annee, char sex):Profil(name, f_name, idi, pwd, annee, sex)
{

};

void Medecin::consulter()
{
    cout << nom << prenom <<endl;
}