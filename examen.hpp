/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: examen.hpp
###########################################*/
#include "radiographie.hpp"
#include "compte_rendu_medical.hpp"
#include <string>

class Examen
{
    private:
        Radiographie radio;
        Compte_rendu_medical crm;

    public:
        Examen(Radiographie R, Compte_rendu_medical CR):radio{R}, crm{CR}
        {};
};

//https://www.learncpp.com/cpp-tutorial/composition/