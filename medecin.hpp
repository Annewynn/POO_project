/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: medecin.hpp
###########################################*/

#include "patient.hpp"
#include <string>
using namespace std;

#ifndef MEDECIN_HPP
#define MEDECIN_HPP

class Medecin: public Profil
{
    public:
        Medecin(string name, string f_name, string idi, string pwd, int annee, char sex);
        Medecin();
        void ajouter(string nom, string prenom, string id, string mot_de_passe, int age, char sexe){
            Patient(nom, prenom, id, mot_de_passe, age, sexe);
        };
        void consulter();
};
#endif