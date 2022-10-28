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
    ifstream file;
    file.open("bdd_patients_medecins.txt");
    
    if (id == "a01" && mdp == "miRNA")
    {
        cout << "vous pouvez consulter :)"
    }
}