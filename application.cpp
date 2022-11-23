/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: application.cpp
###########################################*/

#include "application.hpp"
#include <iostream>
#include <string>

using namespace std;

Application::Application()
{
	liste_radiographie = {};
}

void Application::ajouter(Radiographie radio)
{
	liste_radiographie.push_back(radio);
}

bool Application::comparePatient(const vector<Radiographie> &a, const vector<Radiographie> &b){
	if ()
}
bool compareDate(const vector<Radiographie> &a, const vector<Radiographie> &b){
	return a.get_date() < b.get_date();
}
bool compareNumExam(const vector<Radiographie> &a, const vector<Radiographie> &b){
	return a.get_id() < b.get_id();	
}