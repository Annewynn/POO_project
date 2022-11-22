/*#########################################
## 28/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: profil.hpp
###########################################*/
#include <string>
using namespace std;

/*
	Ceci est une classe qui gère les profils de manière simple pour
	les sous classes "patient" et "medecin".
	Elle joue aussi des rôles plus avancés pour l'admin.
*//*
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
*/
//
//typedef enum Ptype{patient, medecin, admin} Ptype;
#ifndef PROFIL_HPP
#define PROFIL_HPP

class Profil
{
    protected:
        string nom;
        string prenom;
        string id;
        string mdp;
        int age;
        char sexe;
    public:
        Profil(string nom, string prenom, string id, string mdp, int age, char sexe);
        Profil();
        Profil ajouter(string name, string first_name, string ident, string pwd, int years, char sex)
        {
            return Profil(name, first_name, ident, pwd, years, sex);
        };
		std::string virtual consulter();
        std::string afficher();
        string get_id();
		string get_mdp();
        string get_nom();
        string get_prenom();
        int get_age();
        char get_sexe();
};
#endif