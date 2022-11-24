/*#########################################
## 16/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: compte_rendu_medical.hpp
###########################################*/
#include <string>
#include "patient.hpp"

#ifndef COMPTE_RENDU_MEDICAL_HPP
#define COMPTE_RENDU_MEDICAL_HPP

class Compte_rendu_medical
{
    private:
        int NumExam;
        string mdp_cr;
        string texte;
        Patient patient;

    public:
        Compte_rendu_medical(int id, string mdp, Patient pat);
        //ouvrir un fichier et laisser le médecin y entrer le texte
		void get_Compte_Rendu();	// Rentrer dans le terminal le compte rendu.
		void get_Compte_Rendu(std::string compte_rendu);	// Prend en paramètre le compte rendu.
		bool print_Compte_Rendu();	// Permet d'afficher proprement le compte rendu
		std::string return_Compte_Rendu(); // Même fonction mais récupérer sous format de string et ne demande pas de mdp
		void modifier_Compte_Rendu();
		void sauvegarder_crm(string chemin);
};
#endif