/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: main.cpp
###########################################*/
#include "profil.hpp"
#include "patient.hpp"
#include "medecin.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    cout << "id : ";
    string id;
    cin >> id;
    cout << "mot de passe : ";
    string mdp;
    cin >> mdp;

    //lire le fichier bdd_patients_medecins.txt pour y vérifier la véracité des informations entrées
    string mon_fichier = "bdd_patients_medecins.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
     ifstream fichier(mon_fichier.c_str(), ios::in);
     if(fichier)  // si l'ouverture a réussi
     {
        string ligne;  // déclaration d'une chaîne qui contiendra la ligne lue
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
                cout << ligne << endl;  // on l'affiche
        }

        fichier.close();  // je referme le fichier
     }

    if (id == "a01" && mdp == "miRNA")
    {
        cout << "vous pouvez consulter :)"
    }
}