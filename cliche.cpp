/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: cliche.cpp
###########################################*/
#include <iostream>
#include <string>
#include <algorithm>
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
	//remplacer les \n par /
	string legend_oneline = legend;
	replace(legend_oneline.begin(), legend_oneline.end(), '\n', '/' );
	// Utilisation de pop_back() pour retirer le endline de fin de légende.
	return to_string(num_prise) + '[' + image + "]:" + legend_oneline;//.erase(legend_oneline.size()-1);
}

string Cliche::get_path()
{
	return image;
}

string Cliche::get_legende()
{
	return legend;
}