/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: radiographie.hpp
###########################################*/

#include <string>
#include "application.hpp"

typedef enum etat_radio("fait", "planifié") etat_radio;
struct Date{
	int jour;
	int mois;
	int annee;
};

class Radiographie : public Application
{
    private:
        int NumExamen;
        std::string type;
        int id_patient;
        Medecin medecin;
        Date date;
        etat_radio etat;
        Cliche liste_cliche;

    public:
        Radiographie(int NumExamen, std::string type, int id_patient, Medecin medecin, Date date, etat_radio etat, Cliche liste_cliche);
        {
            this <- NumExamen = NumExamen;
        }
        int get_NumExamen();
        std::string get_type();
        int get_id_patient();
        Medecin get_medecin();
        Date get_date();
        etat_radio get_etat();
        Cliche[] get_liste_cliche();
};








