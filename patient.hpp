/*#########################################
## 27/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: patient.hpp
###########################################*/

#include <string>
#include "profil.hpp"

class Patient: public Profil
{
    private:
        int age;
        char sexe;

    public:
        Patient(int id, std::string nom, std::string prenom, std::string mot_de_passe, int age, char sexe):Profil(nom, prenom, id, mot_de_passe)
        {
            this -> age = age;
            this -> sexe = sexe;
        }
        int get_id_patient();
        std::string get_nom_patient();
        std::string get_prenom_patient();
        int get_age();
        char get_sexe();
};