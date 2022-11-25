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
*/
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