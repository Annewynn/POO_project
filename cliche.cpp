/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: cliche.cpp
###########################################*/
#include <iostream>
#include "cliche.hpp"
using namespace std;

Cliche::Cliche(int numero, string img_path, string text)
{
	num_prise = numero;
	image = img_path;
	legend = text;
}
void Cliche::afficher_image(){
	cout << "\tChemin d'accès: " << image << endl;
	cout << "\tLégende: " << legend << endl;
}

void Cliche::get_cliche(){
	cout << "\tN°: " << num_prise << endl;
	this -> afficher_image();
}