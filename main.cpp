/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: main.cpp
###########################################*/
#include "compte_rendu_medical.hpp"
#include "patient.hpp"
#include "medecin.hpp"
#include "radiographie.hpp"
#include "cliche.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <sys/stat.h>
#include <filesystem>

using namespace std;

vector<string> trouver_profil_dans_bdd(vector<string> tokens, string id, string mdp, string mon_fichier)
{
      // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
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
    }
    else std::cout << "Le fichier source n'a pas pu être ouvert(id+mdp). Veuillez réessayer" <<endl;

    return tokens;
}

vector<string> trouver_profil_dans_bdd(vector<string> tokens, string id, string mon_fichier)
{
      // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
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
                if (tokens[0] == id)
                { 
                    break;
                }
                tokens.clear();
        }
    fichier.close();  // je referme le fichier
    }
    else std::cout << "Le fichier source n'a pas pu être ouvert(bdd 1 arg). Veuillez réessayer" <<endl;

    return tokens;
}

Medecin creer_med(vector<string> tokens)
{
    string nom = tokens[2];
    string prenom = tokens[3];
    string id = tokens[0];
    string mdp = tokens[1];
    int age = stoi(tokens[4]);
    const char *sexe= tokens[5].c_str();
    return Medecin (nom, prenom, id, mdp, age, sexe[0]);
}

vector<vector<string>> trouver_tous_profil_dans_bdd(vector<vector<string>> vect_tokens_images, string mon_fichier)
{
      // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
    ifstream fichier(mon_fichier.c_str(), ios::in);
    if(fichier)  // si l'ouverture a réussi
    {
        string ligne;  // déclaration d'une chaîne qui contiendra la ligne lue
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {   vector<string> tokens;
            //https://stackoverflow.com/questions/10617094/how-to-split-a-file-lines-with-space-and-tab-differentiation
            istringstream iss(ligne);
            string token;
            while(getline(iss, token, '\t'))  tokens.push_back(token);
            vect_tokens_images.push_back(tokens);
        }
    fichier.close();  // je referme le fichier
    }
    else std::cout << "Le fichier source n'a pas pu être ouvert (tous profils). Veuillez réessayer" <<endl;

    return vect_tokens_images;
}

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
    tokens = trouver_profil_dans_bdd(tokens, id, mdp, "bdd_patients_medecins.txt");
        if (tokens.size() != 0)
        {
            //bdd
            //ID	mot_de_passe	nom	prenom	age	sexe
            //profil
            //Profil(string nom, string prenom, string id, string mdp, int age, char sexe)
        
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
            //std::cin.ignore();
            cin >> num;
            //rechercher dans la liste des examens celle qui a le bon numéro
            filesystem::path cwd = filesystem::current_path();
            string s = cwd.generic_string() + "/examens/" + num;
            struct stat buffer;
            if (stat(s.c_str(), &buffer) == 0)
            {
                //on est dans le bon dossier : créer la radio correspondante
                vector<string> tokens_r;
                //lire le fichier num_radio.txt pour en faire un objet radio
                string mon_fichier = "examens/" + num + "/" + num + "_radio.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
                tokens_r = trouver_profil_dans_bdd(tokens_r, num, mon_fichier);
                //créer radiographie
                int numero = stoi(tokens_r[0]);
                string tech = tokens_r[1];
                string id_pat = tokens_r[2];
                //trouver le médecin à partir de son id
                vector<string> tokens_medecin;
                string medecin_id = tokens_r[3];
                tokens_medecin = trouver_profil_dans_bdd(tokens_medecin, medecin_id, "bdd_patients_medecins.txt");
                //créer médecin avec tokens_medecin
                Medecin medic = creer_med(tokens_medecin);
                //date
                istringstream iss(tokens_r[4]);
                vector<string> tokens;
                string token;
                while(getline(iss, token, '/'))  tokens.push_back(token);
                vector<int> date = {stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2])};
                //ouvrir num_images.txt pour en récuppérer les images
                vector<vector<string>> vect_tokens_images;
                string mon_fichier2 = "examens/" + num + "/" + num + "_images.txt";
                vector<Cliche> images;
                vect_tokens_images = trouver_tous_profil_dans_bdd(vect_tokens_images, mon_fichier2);
                for (int i =0; i<vect_tokens_images.size(); i++)
                {
                    string image_path = vect_tokens_images[i][1];
                    string legende = vect_tokens_images[i][2];
                    images.push_back(Cliche (i, image_path, legende));
                }
                if (user -> get_id()[0] == 'm' || user -> get_id()[0] == 'a' || user -> get_id() == id_pat){
                    Radiographie radio(numero, tech, id_pat, medic, date, false, images);
                    radio.afficher_radio();
					
					Compte_rendu_medical cpt_rendu(034513, "PIWI", pat);
					cpt_rendu.get_Compte_Rendu();
					cpt_rendu.print_Compte_Rendu();            
                } else {
                    cout << user -> get_id() << endl;
                    cout << "C'est pas toi, arrête ! >:(\n";
                }
            
            }
            else cout << "Ancun examen n'a ce numéro *-*" <<endl;

			
        }
        else cout << "connard :) essaie encore !" <<endl;
}