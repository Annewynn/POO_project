/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: cliche.cpp
###########################################*/
#include <iostream>
#include "cliche.hpp"
using namespace std;
void Cliche::afficher_image(){
	cout << "Chemin d'accès: " << image << endl;
	cout << "Légende: " << legend << endl;
}