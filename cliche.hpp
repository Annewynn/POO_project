/*#########################################
## 27/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: cliche.hpp
###########################################*/

#include <string>

#ifndef CLICHE_HPP
#define CLICHE_HPP
//images des radiographies
class Cliche
{
    private:
        int num_prise;
        std::string image;
		std::string legend;	// Peut tenir sur plusieurs lignes.
	public:
		Cliche(int numero, std::string img_path, std::string text);
		virtual ~Cliche() = default;	// It just works !
		//################################################################
		/*
			Permet de retourner sous forme de strin (géré comme un cout)
			du chemin d'accès d'une image et sa légende.*/
		std::string afficher_image();

		//################################################################
		/*
			Utilise afficher_image() et ajoute  en plus le numéro de prise/cliché.*/
		std::string get_cliche();

		//################################################################
		/*
			Permet de retourner sous forme de string les informations d'un cliché
			en une ligne.*/
		std::string return_cliche();

		//################################################################
		/*
			Retourne le chemin d'accès d'une image.*/
		std::string get_path();
		//################################################################
		/*
			Retourne la légende d'un cliché.*/
		std::string get_legende();
};
#endif