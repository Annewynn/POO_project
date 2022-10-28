title 
*-*

#include <string>

class Medecin : public Profil
{
    public:
        Medecin(string nom, string prenom, string id, string mot_de_passe):Profil(nom, prenom, id, mot_de_passe){}
        void consulter();   //spécifique au medecin
        Patient ajouter(string nom, string prenom, string id, string mot_de_passe):Profil(nom, prenom, id, mot_de_passe){}
}