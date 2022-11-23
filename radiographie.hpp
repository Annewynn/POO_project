/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: radiographie.hpp
###########################################*/

#include <string>
#include <vector>
#include "medecin.hpp"
#include "cliche.hpp"
#include "patient.hpp"

#ifndef RADIOGRAPHIE_HPP
#define RADIOGRAPHIE_HPP

// typedef enum etat_radio("effectuée", "planifié") etat_radio;
struct Date
{
    int jour;
    int mois;
    int annee;
};

class Radiographie
{
protected:
    int NumExamen;
    std::string type; // Rayon X, IRM, ultrason
    Medecin medecin;
    Date date;
    bool etat;
    vector<Cliche> liste_cliche;

public:
	Patient patient;	// Permet à Application d'accéder facilement aux méthodes de la classe patient.
    Radiographie(int numero, std::string techno, Patient pat, Medecin docteur, vector<int> jour, bool isDone, vector<Cliche> images);
    std::string get_type();
    Medecin get_medecin();
    Date get_date();
    std::string get_etat();
	void set_etat();
    std::string get_liste_cliche();
	std::string get_id();
    std::string afficher_radio();
	std::string afficher_radio_as_table();
};
#endif
