/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: medecin.hpp
###########################################*/

#include "profil.hpp"
#include <string>

class Medecin
{
    public:
        Medecin(std::string nom, std::string prenom, std::string id, std::string mot_de_passe):Profil(nom, prenom, id, mot_de_passe);
        void consulter();   //spécifique au medecin
        void ajouter(std::string nom, std::string prenom, std::string id, std::string mot_de_passe):Profil(nom, prenom, id, mot_de_passe);
};