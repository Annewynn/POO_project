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
        string nom;
        string prenom;
    
    private:
        void ajouter();  //ajouter les medecins (spécifique à l'admin)

    public: 
        Profil(string nom, string prenom)
        {
            this -> nom = nom;
            this -> prenom = prenom;
        }
        string get_nom(){return nom;}
        string get_prenom(){return prenom;}
        void consulter();    //spécifique à l'admin
};