/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: examen.cpp
###########################################*/
#include "examen.hpp"
#include "radiographie.hpp"
#include "compte_rendu_medical.hpp"
#include <iostream>
#include <fstream>
using namespace std;

/*
Examen::Examen(int numero, string techno, int id, Medecin docteur, vector<int> jour, bool isDone, vector<Cliche> images, int id_crm, string mdp, string text, Patient pat):Radiographie(numero, techno, id, docteur, jour, isDone, images)
{
    radio = Radiographie(numero, techno, id, docteur, jour, isDone, images);
    crm = Compte_rendu_medical(id_crm, mdp, text, pat);
};*/

void Examen::sauvegarder_examen(){
	ofstream examen_file(to_string(NumExam));
	//examen_file;
	examen_file.close();
}