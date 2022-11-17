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
        Compte_rendu_medical(int id, string mdp, string text, Patient pat);
        //ouvrir un fichier et laisser le médecin y entrer le texte
};
#endif