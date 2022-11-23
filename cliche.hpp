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
		std::string legend;
	public:
		Cliche(int numero, std::string img_path, std::string text);
		virtual ~Cliche() = default;	// It just works !
		void afficher_image();
		void get_cliche();
		std::string return_cliche();
};
#endif