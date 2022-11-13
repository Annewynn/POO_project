/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: medecin.hpp
###########################################*/

#include "patient.hpp"
#include <string>

class Medecin: public Profil
{
    public:
        Medecin(std::string nom, std::string prenom, std::string id, std::string mot_de_passe, int age, char sexe):Profil(nom, prenom, id, mot_de_passe, age, sexe){};
        void ajouter(std::string nom, std::string prenom, std::string id, std::string mot_de_passe, int age, char sexe){
            Patient(nom, prenom, id, mot_de_passe, age, sexe);
        };
        void consulter();
};