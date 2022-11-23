/*#########################################
## 28/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: application.hpp
###########################################*/
#include <string>
#include <vector>
#include "radiographie.hpp"
using namespace std;

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

class Application{
	private:
		vector<Radiographie> liste_radiographie;
		bool comparePatient(const vector<Radiographie> &a, const vector<Radiographie> &b);
		bool compareDate(const vector<Radiographie> &a, const vector<Radiographie> &b);
		bool compareNumExam(const vector<Radiographie> &a, const vector<Radiographie> &b);
	public:
		Application();		//charger le fichier avec la liste des radiographies
							//Equivalent à charger_liste_radios()
		void connexion();
		void sauvegarder_liste_radios();
		vector<Radiographie> trier_liste();
		void afficher_liste(vector<Radiographie> radios);
		void ajouter(Radiographie radio);
		vector<Radiographie> afficher_liste_examen_Patient();
		vector<Radiographie> afficher_liste_examen_date();
		vector<Radiographie> afficher_liste_examen_NumExam();
};
#endif