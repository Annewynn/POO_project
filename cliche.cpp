/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: cliche.cpp
###########################################*/
#include <iostream>
#include <string>
#include "cliche.hpp"
using namespace std;

Cliche::Cliche(int numero, string img_path, string text)
{
	num_prise = numero;
	image = img_path;
	legend = text;
}

string Cliche::afficher_image(){
	string img = "";
	img += "\tChemin d'accès: " + image + '\n';
	img += "\tLégende: " + legend + '\n';
	return img;
}

string Cliche::get_cliche(){
	string clicher = "";
	clicher += "N°: " + to_string(num_prise) + '\n';
	clicher += this -> afficher_image();
	return clicher;
}

string Cliche::return_cliche(){
	return to_string(num_prise) + '[' + image + "]:" + legend;
}