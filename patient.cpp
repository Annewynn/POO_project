/*#########################################
## 27/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: patient.cpp
###########################################*/

//classe Patient

#include "patient.hpp"
#include <iostream>
#include <string>
using namespace std;

string Patient::consulter()
{
    string patient_consult = "";
	patient_consult += "patient " + nom + " " + prenom;
	return patient_consult;
}

