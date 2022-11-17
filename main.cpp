/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: main.cpp
###########################################*/

#include "patient.hpp"
#include "medecin.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    cout << "id : ";
    string id;
    cin >> id;
    cout << "mot de passe : ";
    string mdp;
    cin >> mdp;

    vector<string> tokens;
    //lire le fichier bdd_patients_medecins.txt pour y vérifier la véracité des informations entrées
    string mon_fichier = "bdd_patients_medecins.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
    ifstream fichier(mon_fichier.c_str(), ios::in);
    if(fichier)  // si l'ouverture a réussi
    {
        string ligne;  // déclaration d'une chaîne qui contiendra la ligne lue
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
                //https://stackoverflow.com/questions/10617094/how-to-split-a-file-lines-with-space-and-tab-differentiation
                istringstream iss(ligne);
                string token;
                while(getline(iss, token, '\t'))  { // but we can specify a different one
                    tokens.push_back(token);
                    }
                   
                if (tokens[0] == id && tokens[1] == mdp)
                { 
                    break;
                }
                tokens.clear();
        }
        fichier.close();  // je referme le fichier
        if (tokens.size() != 0)
        {
            //bdd
            //ID	mot_de_passe	nom	prenom	age	sexe
            //profil
            //Profil(string nom, string prenom, string id, string mdp,Ptype type_profil, int age, char sexe)
            /*typedef enum Ptype{patient, medecin, admin} Ptype;
            Ptype typeprofil;
            char char_profil = tokens[0][0];
            if (char_profil == 'p') typeprofil = patient;
            else if (char_profil == 'm') typeprofil = medecin;
            else typeprofil = admin;*/

            string nom = tokens[2];
            string prenom = tokens[3];
            string id = tokens[0];
            string mdp = tokens[1];
            int age = stoi(tokens[4]);
            const char *sexe= tokens[5].c_str();

            Medecin med(nom, prenom, id, mdp, age, sexe[0]);
            Patient pat(nom, prenom, id, mdp, age, sexe[0]);
            Profil adm(nom, prenom, id, mdp, age, sexe[0]);
            Medecin *pmed;
            pmed = &med;
            Patient *ppat;
            ppat = &pat;
            Profil *user;
            user = &adm;
            
            if (tokens[0][0] == 'm') user = pmed;
            else if (tokens[0][0] == 'p') user = ppat;
            user -> afficher();
            user -> consulter();

            //si user est un admin : 
                //il peut voir les radiographies mais pas les crm
                //il peut ajouter un médecin
            //si user est médecin : 
                //il peut ajouter un patient
                //il peut voir les radios et les crm si il a le mp
            //si user est patient : 
                //il voit les radios qui lui sont associées
                //il peut accéder aux clichés mais pas au crm

            //entrer un numéro d'examen :
            cout << "Entrer un numéro d'examen : ";
            string num;
            cin >> num;
            cout << num <<endl;
        }
        else cout << "connard :) essaie encore !" <<endl;
    }
}