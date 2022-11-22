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