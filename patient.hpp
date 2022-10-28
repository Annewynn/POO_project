/*#########################################
## 27/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: patient.hpp
###########################################*/

#include <string>

class Patient : public Profil
{
    private:
        int age;
        char sexe;

    public:
        Patient(int id, string nom, string prenom, string mot_de_passe, int age, char sexe):Profil(nom, prenom, id, mot_de_passe)
        {
            this -> age = age;
            this -> sexe = sexe;
        }
        int get_id_patient();
        string get_nom_patient();
        string get_prenom_patient();
        int get_age();
        char get_sexe();
};