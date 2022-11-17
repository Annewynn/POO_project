/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: compte_rendu_medical.cpp
###########################################*/
#include "compte_rendu_medical.hpp"

Compte_rendu_medical::Compte_rendu_medical(int id, string mdp, string text, Patient pat):patient{pat}
{
    NumExam = id;
    mdp_cr = mdp;
    texte = text;
}