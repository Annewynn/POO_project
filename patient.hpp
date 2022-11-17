/*#########################################
## 27/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: patient.hpp
###########################################*/

#include "profil.hpp"
#include <string>
using namespace std;

#ifndef PATIENT_HPP
#define PATIENT_HPP

class Patient: public Profil
{
    public:
        Patient(string nom, string prenom, string id, string mot_de_passe, int age, char sexe):Profil(nom, prenom, id, mot_de_passe, age, sexe){};
        Patient();
        int get_id_patient();
        string get_nom_patient();
        string get_prenom_patient();
        int get_age();
        char get_sexe();
        void consulter();
};
#endif