/*#########################################
## 27/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: patient.hpp
###########################################*/

#include "profil.hpp"
#include <string>

#ifndef PATIENT_HPP
#define PATIENT_HPP

class Patient: public Profil
{
    public:
        Patient(std::string nom, std::string prenom, std::string id, std::string mot_de_passe, int age, char sexe):Profil(nom, prenom, id, mot_de_passe, age, sexe){};
        int get_id_patient();
        std::string get_nom_patient();
        std::string get_prenom_patient();
        int get_age();
        char get_sexe();
        void consulter();
};
#endif