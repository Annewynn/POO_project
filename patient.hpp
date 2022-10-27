/*#########################################
## 27/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: patient.hpp
###########################################*/

#include <string>

class Patient
{
    private:
        int id_patient;
        string nom;
        string prenom;
        int age;
        char sexe;

    public:
        Patient(int id, string nom, string prenom, int age, char sexe);
        int get_id_patient();
        string get_nom_patient();
        string get_prenom_patient();
        int get_age();
        char get_sexe();
};