/*#########################################
## 27/10/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: cliche.hpp
###########################################*/

#include <string>

class Cliche
{
    private:
        int num_prise;
        std::string image;
		std::string legend;
	public:
		Cliche(int numero, std::string img_path, std::string text){
			num_prise = numero;
			image = img_path;
			legend = text;
		}
		~Cliche();
		void afficher_image();
};