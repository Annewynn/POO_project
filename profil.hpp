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
		string id;
		string mot_de_passe;
    
    private:
        void ajouter();  //ajouter les medecins (spécifique à l'admin)

    public: 
        Profil(string nom, string prenom, string id, string mot_de_passe)
        {
            this -> nom = nom;
            this -> prenom = prenom;
            this -> id = id;
            this -> mot_de_passe = mot_de_passe;
        }
        string get_nom(){return nom;}
        string get_prenom(){return prenom;}
        string consulter();    //spécifique à l'admin
};