/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: examen.hpp
###########################################*/
#include "radiographie.hpp"
#include "compte_rendu_medical.hpp"
#include <string>

#ifndef EXAMEN
#define EXAMEN

class Examen
{
    private:
		int NumExam;
        Radiographie radio;
        Compte_rendu_medical crm;

    public:
        Examen(int numero, Radiographie R, Compte_rendu_medical CR):radio{R}, crm{CR}
        {};
		void sauvegarder_examen();
};

//https://www.learncpp.com/cpp-tutorial/composition/
#endif