/*#########################################
## 28/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: profil.hpp
###########################################*/
#include <string>


/*
	Ceci est une classe qui gère les profils de manière simple pour
	les sous classes "patient" et "medecin".
	Elle joue aussi des rôles plus avancés pour l'admin.
*/
class Profil
{
    protected: 
        std::string nom;
        std::string prenom;
		std::string id;
		std::string mot_de_passe;
    
    private:
        void ajouter();  //ajouter les medecins (spécifique à l'admin)

    public: 
        Profil(std::string nom, std::string prenom, std::string id, std::string mot_de_passe)
        {
            nom = nom;
            prenom = prenom;
            id = id;
            mot_de_passe = mot_de_passe;
        }
        std::string get_nom(){return nom;};
        std::string get_prenom(){return prenom;};
        void consulter();    //spécifique à l'admin
        
};