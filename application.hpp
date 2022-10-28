/*#########################################
## 28/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: application.hpp
###########################################*/
#include <string>
#include <vector>
//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
using namespace std;


class application{
	private:
		vector <radiographie> liste_radiographie;
	public:
		application();		//charger le fichier avec la liste des radiographies
							//Equivalent à charger_liste_radios()
		~application();
		void connexion();
		void sauvegarder_liste_radios();
		vector <radiographie> trier_liste();
		void afficher_liste(trier_liste());
};