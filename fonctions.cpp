/*#########################################
## 25/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: fonctions.cpp
###########################################*/
#include "application.hpp"
#include "compte_rendu_medical.hpp"
#include "patient.hpp"
#include "medecin.hpp"
#include "radiographie.hpp"
#include "cliche.hpp"
#include "examen.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <sys/stat.h>
#include <filesystem>
#include <random>

using namespace std;

//################################################################################################
/*
,---------. .-------.   .-./`)    .-'''-.                  ________   ___    _ ,---.   .--. 
\          \|  _ _   \  \ .-.')  / _     \                |        |.'   |  | ||    \  |  | 
 `--.  ,---'| ( ' )  |  / `-' \ (`' )/`--'                |   .----'|   .'  | ||  ,  \ |  | 
    |   \   |(_ o _) /   `-'`"`(_ o _).                   |  _|____ .'  '_  | ||  |\_ \|  | 
    :_ _:   | (_,_).' __ .---.  (_,_). '.                 |_( )_   |'   ( \.-.||  _( )_\  | 
    (_I_)   |  |\ \  |  ||   | .---.  \  :   _ _     _ _  (_ o._)__|' (`. _` /|| (_ o _)  | 
   (_(=)_)  |  | \ `'   /|   | \    `-'  |--( ' )---(_I_)-|(_,_)    | (_ (_) _)|  (_,_)\  | 
    (_I_)   |  |  \    / |   |  \       /  (_{;}_) (_(=)_)|   |      \ /  . \ /|  |    |  | 
    '---'   ''-'   `'-'  '---'   `-...-'  --(_,_)---(_I_)-'---'       ``-'`-'' '--'    '--' 
                                                                                            
*/
/// @brief Permet de comparer des noms en fonction de l'ordre alphabethique
/// @return Si le nom de a est après b, alors renvoie faux, sinon renvoie vrai.
bool comparePatient(Radiographie a, Radiographie b)
{
	if(a.patient.get_nom() < b.patient.get_nom())
	{
		return a.patient.get_prenom() < b.patient.get_prenom();
	} 
	else {return false;}
}

/// @brief Permet de comparer des dates
/// @return Si la date de a est après b, alors renvoie faux, sinon renvoie vrai.
bool compareDate( Radiographie a, Radiographie b)
{
	if(a.get_date().annee == b.get_date().annee)
	{
		if(a.get_date().mois == b.get_date().mois)
		{
			return a.get_date().jour < b.get_date().jour;
		}
		else return a.get_date().mois < b.get_date().mois;
	}
	else return a.get_date().annee < b.get_date().annee;
}

/// @brief Permet de comparer des numéros d'examen
/// @return Si le numéro de a est supérieur b, alors renvoie faux, sinon renvoie vrai.
bool compareNumExam(Radiographie a, Radiographie b)
{
	return a.get_numexam() < b.get_numexam();	
}

//#####################################################################################################
/*
.-------.    ,---.   .--.  .-_'''-.    
|  _ _   \   |    \  |  | '_( )_   \   
| ( ' )  |   |  ,  \ |  ||(_ o _)|  '  
|(_ o _) /   |  |\_ \|  |. (_,_)/___|  
| (_,_).' __ |  _( )_\  ||  |  .-----. 
|  |\ \  |  || (_ o _)  |'  \  '-   .' 
|  | \ `'   /|  (_,_)\  | \  `-'`   |  
|  |  \    / |  |    |  |  \        /  
''-'   `'-'  '--'    '--'   `'-...-'   
*/
/// @brief Produit un entier aléatoire entre deux limites choisies.
/// @param min Entier de la limite gauche.
/// @param max Entier de la limite droite.
/// @return Renvoie un entier aléatoire.
int rng(int min, int max)
{
    random_device dev;
    mt19937 randomng(dev());
    //rng= Random number generator
    uniform_int_distribution<mt19937::result_type> dist(min,max); // distribution in range [min, max]
    return dist(randomng);
}
//################################################################################################
/*
.-./`) ,---.   .--..-------.   ___    _ ,---------.  
\ .-.')|    \  |  |\  _(`)_ \.'   |  | |\          \ 
/ `-' \|  ,  \ |  || (_ o._)||   .'  | | `--.  ,---' 
 `-'`"`|  |\_ \|  ||  (_,_) /.'  '_  | |    |   \    
 .---. |  _( )_\  ||   '-.-' '   ( \.-.|    :_ _:    
 |   | | (_ o _)  ||   |     ' (`. _` /|    (_I_)    
 |   | |  (_,_)\  ||   |     | (_ (_) _)   (_(=)_)   
 |   | |  |    |  |/   )      \ /  . \ /    (_I_)    
 '---' '--'    '--'`---'       ``-'`-''     '---'    
*/
/// @brief Renvoie d'une manière propre un entier entré.
int input()
{
	string entree = "";
	cin >> entree;
	try{
		stoi(entree);
	} catch(exception &err){
		return 0;
	}
	return stoi(entree);
}

//################################################################################################
/*
.___________..______        ______    __    __  ____    ____    .______   .______        ______    _______  __   __      
|           ||   _  \      /  __  \  |  |  |  | \   \  /   /    |   _  \  |   _  \      /  __  \  |   ____||  | |  |     
`---|  |----`|  |_)  |    |  |  |  | |  |  |  |  \   \/   /     |  |_)  | |  |_)  |    |  |  |  | |  |__   |  | |  |     
    |  |     |      /     |  |  |  | |  |  |  |   \      /      |   ___/  |      /     |  |  |  | |   __|  |  | |  |     
    |  |     |  |\  \----.|  `--'  | |  `--'  |    \    /       |  |      |  |\  \----.|  `--'  | |  |     |  | |  `----.
    |__|     | _| `._____| \______/   \______/      \__/        | _|      | _| `._____| \______/  |__|     |__| |_______|
                                                                                                                         
 */
/// @brief Trouve une ligne dans un fichier en fonction de l'id et mot de passe fournis
/// @param tokens Vecteur qui va stocker les infos de la ligne correspondant
/// @param mon_fichier fichier dans lequel chercher
/// @return tokens
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
    else cout << "Le fichier source n'a pas pu être ouvert(id+mdp). Veuillez réessayer" <<endl;

    return tokens;
}

//################################################################################################

/// @brief Trouve une ou plusieurs lignes dans un fichier, en fonction de l'id fourni. 
/// @param tokens Vecteur qui va stocker les infos de la ligne correspondant
/// @param mon_fichier fichier dans lequel chercher
/// @param isOnManyLines true si l'info recherchée est sur plusieurs lignes (légendes ou comptes-rendu)
/// @return tokens
vector<string> trouver_profil_dans_bdd(vector<string> tokens, string id, string mon_fichier, bool isOnManyLines)
{
      // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
    ifstream fichier(mon_fichier.c_str(), ios::in);
    if(fichier)  // si l'ouverture a réussi
    {
        string ligne;  // déclaration d'une chaîne qui contiendra la ligne lue
		int iLigne = 0;
		//éviter de lire le header
		if (mon_fichier == "bdd_compte_rendu_medical.txt") getline(fichier, ligne);
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
                //https://stackoverflow.com/questions/10617094/how-to-split-a-file-lines-with-space-and-tab-differentiation
                istringstream iss(ligne);
                string token;
				//si on est sur plusieurs lignes, iLigne peut ne pas être égal à 0
                if (iLigne == 0) 
				{
					while(getline(iss, token, '\t'))   // but we can specify a different one
					if (isOnManyLines) 
					{
						iLigne ++;
						tokens.push_back(token + "\n");
					}
					else tokens.push_back(token);
				}
				else if (isOnManyLines) 
				{
					getline(iss, token, '\n');  // but we can specify a different one
                    tokens.push_back(token + "\n");
				}
                if (tokens[0] == id && ! isOnManyLines) break;
				//si on est sur plusieurs lignes, il ne faut pas clear tokens
				if (! isOnManyLines) tokens.clear();
        }
    fichier.close();  // je referme le fichier
    }
    else cout << "Le fichier source n'a pas pu être ouvert(bdd 1 arg). Veuillez réessayer" <<endl;

    return tokens;
}

//################################################################################################
/*
  ______ .______       _______  _______ .______            .___  ___.  _______  _______  
 /      ||   _  \     |   ____||   ____||   _  \           |   \/   | |   ____||       \ 
|  ,----'|  |_)  |    |  |__   |  |__   |  |_)  |          |  \  /  | |  |__   |  .--.  |
|  |     |      /     |   __|  |   __|  |      /           |  |\/|  | |   __|  |  |  |  |
|  `----.|  |\  \----.|  |____ |  |____ |  |\  \----.      |  |  |  | |  |____ |  '--'  |
 \______|| _| `._____||_______||_______|| _| `._____| _____|__|  |__| |_______||_______/ 
                                                     |______|                            
 */
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

//################################################################################################
/*
  ______ .______       _______  _______ .______            .______      ___   .___________.
 /      ||   _  \     |   ____||   ____||   _  \           |   _  \    /   \  |           |
|  ,----'|  |_)  |    |  |__   |  |__   |  |_)  |          |  |_)  |  /  ^  \ `---|  |----`
|  |     |      /     |   __|  |   __|  |      /           |   ___/  /  /_\  \    |  |     
|  `----.|  |\  \----.|  |____ |  |____ |  |\  \----.      |  |     /  _____  \   |  |     
 \______|| _| `._____||_______||_______|| _| `._____| _____| _|    /__/     \__\  |__|     
                                                     |______|                              
 */
Patient creer_pat(vector<string> tokens)
{
    string nom = tokens[2];
    string prenom = tokens[3];
    string id = tokens[0];
    string mdp = tokens[1];
    int age = stoi(tokens[4]);
    const char *sexe= tokens[5].c_str();
    return Patient (nom, prenom, id, mdp, age, sexe[0]);
}

Profil creer_adm(vector<string> tokens)
{
    string nom = tokens[2];
    string prenom = tokens[3];
    string id = tokens[0];
    string mdp = tokens[1];
    int age = stoi(tokens[4]);
    const char *sexe= tokens[5].c_str();
    return Profil (nom, prenom, id, mdp, age, sexe[0]);
}

void ajouter_bdd(Patient pat, string mon_fichier)
{
	ofstream patient_file;
	patient_file.open(mon_fichier, ios_base::app);
	patient_file << '\n'<< pat.get_id() << "\t" << pat.get_mdp() << "\t" << pat.get_nom();
	patient_file << "\t" << pat.get_prenom() << "\t" << pat.get_age() << "\t" << pat.get_sexe();
	patient_file.close();
}

void ajouter_bdd(vector<string> vec, string mon_fichier)
{
	ofstream file;
	file.open(mon_fichier, ios_base::app);
	file << "\n" << vec[0] << "\t" << vec[1];
	file.close();
}


//################################################################################################
/*
.___________..______        ______    __    __  ____    ____    .___________.  ______    __    __       _______.   .______   .______        ______    _______  __   __      
|           ||   _  \      /  __  \  |  |  |  | \   \  /   /    |           | /  __  \  |  |  |  |     /       |   |   _  \  |   _  \      /  __  \  |   ____||  | |  |     
`---|  |----`|  |_)  |    |  |  |  | |  |  |  |  \   \/   /     `---|  |----`|  |  |  | |  |  |  |    |   (----`   |  |_)  | |  |_)  |    |  |  |  | |  |__   |  | |  |     
    |  |     |      /     |  |  |  | |  |  |  |   \      /          |  |     |  |  |  | |  |  |  |     \   \       |   ___/  |      /     |  |  |  | |   __|  |  | |  |     
    |  |     |  |\  \----.|  `--'  | |  `--'  |    \    /           |  |     |  `--'  | |  `--'  | .----)   |      |  |      |  |\  \----.|  `--'  | |  |     |  | |  `----.
    |__|     | _| `._____| \______/   \______/      \__/            |__|      \______/   \______/  |_______/       | _|      | _| `._____| \______/  |__|     |__| |_______|
                                                                                                                                                                                           
*/
/// @brief Remplit un tableau 2d de strings avec celles qu'il récuppère dans un fichier type csv, avec tab pour délimiteur.
/// @param vect_tokens_images Tableau de strins à renvoyer
/// @param mon_fichier Chemin du fichier à lire
/// @param isOnManyLines Les informations à lire sont-elles par ligne ou sur plusieurs lignes ?
/// @return Renvoie un tableau à deux dimensions contenant la transcription du fichier.
vector<vector<string>> trouver_tous_profil_dans_bdd(vector<vector<string>> vect_tokens_images, string mon_fichier, bool isOnManyLines)
{
      // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
    ifstream fichier(mon_fichier.c_str(), ios::in);
    if(fichier)  // si l'ouverture a réussi
    {
        string ligne;  // déclaration d'une chaîne qui contiendra la ligne lue
		int iLigne = 0;
		vector<string> tokens;
		//oter la première ligne dans bdd patients médecins
		if (mon_fichier == "bdd_patients_medecins.txt") getline(fichier, ligne);
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        { 
            //https://stackoverflow.com/questions/10617094/how-to-split-a-file-lines-with-space-and-tab-differentiation
            istringstream iss(ligne);
            string token;
			//si on est sur plusieurs lignes, iLigne peut ne pas être égal à 0
			//si on peut getligne de tab, on le remet à 0 pour avoir toutes les infos
			if (iLigne != 0)
			{
				for(int i = 0; i < ligne.size(); ++i) 
				{
					if (ligne[i] == '\t') 
					{
						iLigne = 0; 
						if (isOnManyLines) vect_tokens_images.push_back(tokens);
						tokens.clear();
						break;
					}
				}
			}
			if (iLigne == 0) 
			{
				while(getline(iss, token, '\t')) tokens.push_back(token);
				if (isOnManyLines) {iLigne ++;
				}
			}
			else if (isOnManyLines) 
			{
				getline(iss, token, '\n');  // but we can specify a different one
				token = token + "\n";
				tokens.push_back(token);
			}
			if (! isOnManyLines) 
			{
				vect_tokens_images.push_back(tokens);
				tokens.clear();
			}
        }
	if (isOnManyLines) vect_tokens_images.push_back(tokens);
    fichier.close();  // je referme le fichier
    }
    else cout << "Le fichier source n'a pas pu être ouvert (tous profils). Veuillez réessayer" <<endl;
    return vect_tokens_images;
}

//################################################################################################
/*
.___________..______        ______    __    __  ____    ____    .______          ___       _______   __    ______   
|           ||   _  \      /  __  \  |  |  |  | \   \  /   /    |   _  \        /   \     |       \ |  |  /  __  \  
`---|  |----`|  |_)  |    |  |  |  | |  |  |  |  \   \/   /     |  |_)  |      /  ^  \    |  .--.  ||  | |  |  |  | 
    |  |     |      /     |  |  |  | |  |  |  |   \      /      |      /      /  /_\  \   |  |  |  ||  | |  |  |  | 
    |  |     |  |\  \----.|  `--'  | |  `--'  |    \    /       |  |\  \----./  _____  \  |  '--'  ||  | |  `--'  | 
    |__|     | _| `._____| \______/   \______/      \__/        | _| `._____/__/     \__\ |_______/ |__|  \______/  
                                                                                                                    */
/// @brief Cherche un radiographie existante dans la base de donnée et l'instancie.
/// @param num Numéro d'examen pour la radiographie associée.
/// @param admins Liste des administrateurs sous forme de vecteur de Profil.
/// @param medecins Liste des médecins sous forme de vecteur d'objets Medecin.
///
/// @return Retourne une instance de Radiographie, celle trouvée avec grâce à son numéro d'examen
Radiographie trouver_radio(string num, vector<Profil> admins,vector<Medecin> medecins,vector<Patient> patients){
	//on est dans le bon dossier : créer la radio correspondante
	vector<string> tokens_r;
	//lire le fichier num_radio.txt pour en faire un objet radio
	string mon_fichier = "examens/" + num + "/" + num + "_radio.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
	tokens_r = trouver_profil_dans_bdd(tokens_r, num, mon_fichier, false);
	//créer radiographie
	int numero = stoi(tokens_r[0]);
	string tech = tokens_r[1];
	//trouver le bon patient à partir de son id
	string id_pat = tokens_r[2];
	Patient pat = patients[0];
	for (int i=0; i<patients.size(); i++)
	{
		if (patients[i].get_id() == id_pat)
		{
			pat = patients[i];
			break;
		}
	}
	//trouver le médecin à partir de son id
	string medecin_id = tokens_r[3];
	Medecin medic = medecins[0];
	for (int i=0; i<medecins.size(); i++)
	{
		if (medecins[i].get_id() == medecin_id)
		{
			medic = medecins[i];
			break;
		}
	}
	//date
	istringstream iss(tokens_r[4]);
	vector<string> tokens;
	string token;
	while(getline(iss, token, '/'))  tokens.push_back(token);
	vector<int> date = {stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2])};
	//etat
	bool etat = false;
	if (tokens_r[5] == "EFFECTUEE") etat = true;
	//ouvrir num_images.txt pour en récuppérer les images
	vector<vector<string>> vect_tokens_images;
	string mon_fichier2 = "examens/" + num + "/" + num + "_images.txt";
	vector<Cliche> images;
	//les légendes sont suceptibles d'être sur plusieurs lignes
	vect_tokens_images = trouver_tous_profil_dans_bdd(vect_tokens_images, mon_fichier2, true);
	for (int i =0; i<vect_tokens_images.size(); i++)
	{
		string image_path = vect_tokens_images[i][1];
		//légende : de 2 à size()
		string legende;
		for (int j=2; j<vect_tokens_images[i].size(); j++)
		{
			legende += vect_tokens_images[i][j];
		}
		images.push_back(Cliche (i, image_path, legende));
	}
	Radiographie radio(numero, tech, pat, medic, date, etat, images); 
	return radio;
}

/// @brief Instencie l'ensemble des radiographies répertoriées à partit d'un fichier tsv.
/// @param mon_fichier Chemin du fichier à lire
/// @return Renvoie un vecteur de l'ensemble des radiographies trouvées.
vector<Radiographie> trouver_radios_dans_bdd(string mon_fichier, vector<Profil> admins,vector<Medecin> medecins,vector<Patient> patients)
{
	vector<string> vect_tokens_radios;
	vector<Radiographie> liste_radios;
	string num;
      // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
    ifstream fichier(mon_fichier.c_str(), ios::in);
    if(fichier)  // si l'ouverture a réussi
    {
        string ligne;  // déclaration d'une chaîne qui contiendra la ligne lue
		//oter la première ligne dans bdd patients médecins
		if (mon_fichier == "bdd_compte_rendu_medical.txt") getline(fichier, ligne);
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {   vector<string> tokens;
            //https://stackoverflow.com/questions/10617094/how-to-split-a-file-lines-with-space-and-tab-differentiation
            istringstream iss(ligne);
            string token;
            while(getline(iss, token, '\t')) tokens.push_back(token);
            vect_tokens_radios.push_back(tokens[0]);
        }
    fichier.close();  // je referme le fichier
    }
    else cout << "Le fichier source n'a pas pu être ouvert (tous profils). Veuillez réessayer" <<endl;
	for(int i=0;i<vect_tokens_radios.size();i++)
	{
		num = vect_tokens_radios[i];
		liste_radios.push_back(trouver_radio(num, admins, medecins, patients));
	}
    return liste_radios;
}


//aller chercher le patient par son id dans bdd patients médecins
Patient trouve_pat(vector<Patient> patients, string id)
{
	for (int i=0; i<patients.size(); i++)
	{
		if (patients[i].get_id() == id) return patients[i];
	}
	return patients[0];
}
				

//################################################################################################
/*______  __    __    ______    __  ___   ___       .______      ___   .___________. __   _______ .__   __. .___________.
 /      ||  |  |  |  /  __  \  |  | \  \ /  /       |   _  \    /   \  |           ||  | |   ____||  \ |  | |           |
|  ,----'|  |__|  | |  |  |  | |  |  \  V  /        |  |_)  |  /  ^  \ `---|  |----`|  | |  |__   |   \|  | `---|  |----`
|  |     |   __   | |  |  |  | |  |   >   <         |   ___/  /  /_\  \    |  |     |  | |   __|  |  . `  |     |  |     
|  `----.|  |  |  | |  `--'  | |  |  /  .  \        |  |     /  _____  \   |  |     |  | |  |____ |  |\   |     |  |     
 \______||__|  |__|  \______/  |__| /__/ \__\  _____| _|    /__/     \__\  |__|     |__| |_______||__| \__|     |__|     
                                              |______|                                                                   
*/
Patient choix_patient(vector<Patient> &patients){
	string nom, prenom;
	vector<Patient> patients_trouver;
	int choix=0;
	int cpt=0;
	cout << "Saisir un nom: ";
	cin >> nom;
	cout << "Saisir un prenom: ";
	cin >> prenom;
	for(int i=0;i < patients.size();i++){
		if(patients[i].get_nom() == nom){
			if(patients[i].get_prenom() == prenom){
				patients_trouver.push_back(patients[i]);
				cpt ++;
			}
		}
	}
	if(cpt > 1){
		cout << "Plusieurs patients avec le nom et prénom.\n";
		for(int i=0;i<patients_trouver.size();i++){
			cout << "Patient "<< i << endl;;
			cout << patients_trouver[i].afficher() << endl;
		}
		cout << "Quel patient choisi (sur " << patients_trouver.size() << ") ? Entrez le nombre correspondant.\n";
		choix = input();
		return patients_trouver[choix];
	}
	if (cpt == 1) 
	{
		//demander si le patient saisi est bien celui qu'on veut
		cout << patients_trouver[0].afficher();
		cout << "Ce patient est-il le bon ? (oui : o, non : n) ";
		string rep;
		cin >> rep;
		if (rep == "o") return patients_trouver[0];
	}
	vector<string> tokens_pat;
	cout << "Patient pas encore dans la base de données. Veuillez entrer ses informations." <<endl;;
	//id
	cout << "Id: ";
	string id;
	cin >> id;
	tokens_pat.push_back(id);
	//mdp
	//généré aléatoirement
	string mdp;
	for (int i = 0; i< 4; i++)
	{
		mdp += to_string(rng(0, 9));
	}
	tokens_pat.push_back(mdp);
	//nom
	tokens_pat.push_back(nom);
	//prenom
	tokens_pat.push_back(prenom);
	//age
	cout << "Age: ";
	int age_pat;
	cin >> age_pat;
	tokens_pat.push_back(to_string(age_pat));
	//sexe
	cout << "Sexe: ";
	char sexe_pat;
	cin >> sexe_pat;
	string s{sexe_pat};
	tokens_pat.push_back(s);
	Patient pat = creer_pat(tokens_pat);
	ajouter_bdd(pat, "bdd_patients_medecins.txt");
	//maj du vecteur patient
	patients.push_back(pat);
	return pat;
}
//################################################################################################
/*
  ______ .______       _______  _______ .______            .______          ___       _______   __    ______   
 /      ||   _  \     |   ____||   ____||   _  \           |   _  \        /   \     |       \ |  |  /  __  \  
|  ,----'|  |_)  |    |  |__   |  |__   |  |_)  |          |  |_)  |      /  ^  \    |  .--.  ||  | |  |  |  | 
|  |     |      /     |   __|  |   __|  |      /           |      /      /  /_\  \   |  |  |  ||  | |  |  |  | 
|  `----.|  |\  \----.|  |____ |  |____ |  |\  \----.      |  |\  \----./  _____  \  |  '--'  ||  | |  `--'  | 
 \______|| _| `._____||_______||_______|| _| `._____| _____| _| `._____/__/     \__\ |_______/ |__|  \______/  
                                                     |______|                                                  
 */
/// @brief Interface pour créer une radio. accessible uniquement à un médecin
/// @param numero Numéro d'examen
/// @param med Médecin en charge de la radiographie
/// @param patients Vecteur de tous les patients
/// @return Renvoie une radiographie.
Radiographie creer_radio(string numero, Medecin med, vector<Patient> &patients)
{
	string id_profil = med.get_id();
	cout << "#############################################\n";
	//numéro d'examen
	cout << "N° d'examen: " << numero;
	//date
	int jour;
	int mois;
	int annee;
	string jma;
	cout << "\t\tDate de l'examen jj/mm/aaaa : ";
	cin >> jma;
	vector<string> tokens;
	istringstream iss(jma);
	string token;
	while(getline(iss, token, '/'))  tokens.push_back(token);
	jour = stoi(tokens[0]);
	mois = stoi(tokens[1]);
	annee = stoi(tokens[2]);
	vector<int> date = {jour, mois, annee};
	//type de radio
	string rtype;
	cout << "Type de radio (Rayons X, IRM ou échographie à ultrasons): ";
	cin.ignore();
	getline(cin, rtype, '\n');
	cout << endl;
	//patient : 
	cout << "  Patient: \n";
	Patient pat = choix_patient(patients);
	cout << "  Medecin: ";
	cout << id_profil << endl;
	cout << "Plannifée\n";
	bool etat = 0;
	cout << "Liste des clichés:\n";
	//interface des clichés : 
	cout << "Entrer un chemin d'image pour en ajouter une ou 0 pour finir" <<endl;
	string interface_crea_cliches;
	cin >> interface_crea_cliches;
	vector<Cliche> images;
	while (interface_crea_cliches != "0")
	{
		string image_path = "examens/" + numero + "/" + interface_crea_cliches;
		string legende;
		string line;
		cout << "Légende: \n";
		cin.ignore();	// Nécessite de clear "cin" car utilisé précédement et sinon casse getline()
		while (getline(cin, line) && !line.empty()){
			legende += line + "\n" ;
			}
		images.push_back(Cliche (images.size(), image_path, legende));
		//redemander si on veut continuer
		cout << "Entrer un chemin d'image pour en ajouter une ou 0 pour finir" <<endl;
		cin >> interface_crea_cliches;
	}
	//créer un dossier num
	//créer un fichier num_images.txt pour y conserver les images
	if (images.size() != 0)
	{
		//copier les images dans le dossier num avec le bon nom
	}
	cout << "#############################################\n";
	int num = stoi(numero);
	//Radiographie(int numero, string techno, string id, Medecin docteur, vector<int> jour, 
	//bool isDone, vector<Cliche> images)
	Radiographie radio(num, rtype, pat, med, date, etat, images);
	cout << radio.afficher_radio() << endl;
	return radio;
}

//crée l'arborescence, les fichiers et leur contenu pour une nouvelle radiographie
void creer_nouvelle_radio(Radiographie radio, Compte_rendu_medical cpt_rendu, bool isTextInitialized)
{
	//créer un dossier dans examens
	string num = to_string(radio.get_numexam());
	string new_path = "examens/"+num;
	filesystem::create_directory(new_path);
	//créer le fichier de la radio, le remplir
	radio.sauvegarder_radio(new_path);
	//créer le fichier des images, le remplir
	radio.sauvegarder_cliches(new_path);
	//créer le fichier du crm et le remplir. si text n'a pas été rentré, entrer ""
	if (isTextInitialized) cpt_rendu.sauvegarder_crm(new_path);
	else 
	{
		cpt_rendu.get_Compte_Rendu("");
		cpt_rendu.sauvegarder_crm(new_path);
	}
}

//################################################################################################
/*
     ___       ______   ______  _______     _______.      .______          ___       _______   __    ______   
    /   \     /      | /      ||   ____|   /       |      |   _  \        /   \     |       \ |  |  /  __  \  
   /  ^  \   |  ,----'|  ,----'|  |__     |   (----`      |  |_)  |      /  ^  \    |  .--.  ||  | |  |  |  | 
  /  /_\  \  |  |     |  |     |   __|     \   \          |      /      /  /_\  \   |  |  |  ||  | |  |  |  | 
 /  _____  \ |  `----.|  `----.|  |____.----)   |         |  |\  \----./  _____  \  |  '--'  ||  | |  `--'  | 
/__/     \__\ \______| \______||_______|_______/     _____| _| `._____/__/     \__\ |_______/ |__|  \______/  
                                                    |______|                                                  
*/
// Pour le médecin: accéder ou créer une radio
void acces_radio(Application app, Profil* user, vector<Profil> admins,vector<Medecin> medecins,vector<Patient> patients)
{
	//si médecin : il peut créer un examen. sinon : peut juste consulter
	if (user->get_id()[0] == 'm') cout << "Entrez un numéro d'examen pour afficher ou créer cet examen : ";
	else cout << "Entrer un numéro d'examen : ";
	string num;
	cin >> num;
	//rechercher dans la liste des examens celle qui a le bon numéro
	filesystem::path cwd = filesystem::current_path();
	string s = cwd.generic_string() + "/examens/" + num;
	struct stat buffer;
	//dossier de l'examen existe déjà
	if (stat(s.c_str(), &buffer) == 0)
	{
		Radiographie radio = trouver_radio(num, admins, medecins, patients);
		int numero = radio.get_numexam();
		if (user -> get_id()[0] == 'm' || user -> get_id()[0] == 'a' || user -> get_id() == radio.get_id()){
			cout << radio.afficher_radio() << endl;
			//on va chercher le crm si user est un médecin
			if (radio.get_etat() == "Effectuée" && user->get_id()[0] == 'm')
			{
				//trouver le crm à partir de son id
				vector<string> tokens_crm;
				tokens_crm = trouver_profil_dans_bdd(tokens_crm, to_string(numero), "bdd_compte_rendu_medical.txt", false);
				string mdp = tokens_crm[1];
				//patient correspondant au crm : id_path
				//aller chercher le patient par son id dans bdd patients médecins
				Patient pat = trouve_pat(patients, radio.get_id());
				//créer crm
				Compte_rendu_medical cpt_rendu(numero, mdp, pat);
				//le texte est dans le fichier num_crm.txt
				string fichier_crm = "examens/" + num + "/" + num + "_crm.txt";
				vector<string> tokens_tcrm;
				tokens_tcrm = trouver_profil_dans_bdd(tokens_tcrm, to_string(numero), fichier_crm, true);
				//de 2 à size() c'est le texte
				string text;
				for (int i=2; i<tokens_tcrm.size(); i++)
				{
					text += tokens_tcrm[i];
				}
				cpt_rendu.get_Compte_Rendu(text);
				bool shittyflute = cpt_rendu.print_Compte_Rendu();
				//modifier le crm écrit : 
				if (shittyflute) 
				{
					cout << "Modifier le compte_rendu ? (y/n) ";
					string rep_modif;
					cin >> rep_modif;
					if (rep_modif == "y") 
					{
						cpt_rendu.modifier_Compte_Rendu();
						//sauvegarder le contenu du compte rendu
						string chemin = "examens/" + num;
						cpt_rendu.sauvegarder_crm(chemin);
					}
				}
				Examen dossier(numero, radio, cpt_rendu);
				//demander si on veut sauvegarder l'exam au format txt :
				cout << "Enregistrer cet examen au format txt (y/n) ? ";
				string rep_sauv;
				cin >> rep_sauv;
				if (rep_sauv == "y" && shittyflute) dossier.sauvegarder_examen();
				else if (rep_sauv == "y" && ! shittyflute) dossier.sauvegarder_examen_restreint();
			}
			else if (radio.get_etat() == "Planifiée" && user->get_id()[0] == 'm')
			{
				//demander au med si il il veut écrire le compte_rendu
				cout << "Ecrire le compte-rendu ? (y/n) ";
				string rep;
				cin >> rep;
				//donner au médecin la possibilité d'écrire le crm
				//trouver le crm à partir de son id
				vector<string> tokens_crm;
				tokens_crm = trouver_profil_dans_bdd(tokens_crm, to_string(numero), "bdd_compte_rendu_medical.txt", false);
				string mdp = tokens_crm[1];
				//patient correspondant au crm : id_path
				//aller chercher le patient par son id dans bdd patients médecins
				Patient pat = trouve_pat(patients, radio.get_id());
				//créer crm
				Compte_rendu_medical cpt_rendu(numero, mdp, pat);
				//veut-on créer un crm ?
				if (rep == "y")
				//passer etat à 1, et écrire le crm
				{
					radio.set_etat();
					cpt_rendu.get_Compte_Rendu();
					//sauvegarder le contenu du compte rendu
					string chemin = "examens/" + num;
					cpt_rendu.sauvegarder_crm(chemin);
					bool shittyflute = cpt_rendu.print_Compte_Rendu();
					Examen dossier(numero, radio, cpt_rendu);
					//demander si on veut sauvegarder l'exam au format txt :
					cout << "Enregistrer cet examen au format txt (y/n) ? ";
					string rep_sauv;
					cin >> rep_sauv;
					if (rep_sauv == "y" && shittyflute) dossier.sauvegarder_examen();
					else if (rep_sauv == "y" && ! shittyflute) dossier.sauvegarder_examen_restreint();
				}
				else 
				{
					Examen dossier(numero, radio, cpt_rendu);
					//demander si on veut sauvegarder l'exam au format txt :
					cout << "Enregistrer cet examen au format txt (y/n) ? ";
					string rep_sauv;
					cin >> rep_sauv;
					if (rep_sauv == "y") dossier.sauvegarder_examen_restreint();
				}
			}      
		} 
		else 
		{
			cout << user -> get_id() << endl;
			cout << "\033[1;31mC'est pas toi, arrête ! >:(\033[0m\n";
		}
	}
	else 
	{
		if (user -> get_id()[0] != 'm') 
		{
			cout << "\033[1;31mAncun examen n'a ce numéro *-*\033[0m" <<endl;
		}
		else 
		{
			//créer une radiographie et son dossier, ses fichiers...
			vector<string> tokens;
			tokens.push_back(user-> get_id());
			tokens.push_back(user -> get_mdp());
			tokens.push_back(user-> get_nom());
			tokens.push_back(user-> get_prenom());
			tokens.push_back(to_string(user -> get_age()));
			tokens.push_back(string{user -> get_sexe()});
			Medecin med = creer_med(tokens);
			Radiographie radio = creer_radio(num, med, patients);
			//radio ajoutée à application
			app.ajouter(radio);
			//créer crm
			//mdp
			cout << "Mot de passe du compte-rendu ? ";
			string mdp;
			cin >> mdp;
			//stocker le mdp et l'id dans la bdd compte rendu
			vector<string> infos;
			infos.push_back(num);
			infos.push_back(mdp);
			ajouter_bdd(infos, "bdd_compte_rendu_medical.txt");
			//patient
			Patient pat = trouve_pat(patients, radio.get_id());
			int id_exam_radio_crm = stoi(num);
			Compte_rendu_medical cpt_rendu(id_exam_radio_crm, mdp, pat);
			//demander au med si il il veut écrire le compte_rendu
			cout << "Ecrire le compte-rendu ? (y/n) ";
			string rep;
			cin >> rep;
			if (rep == "y")
			//passer etat à 1, et écrire le crm
			{
				radio.set_etat();
				cpt_rendu.get_Compte_Rendu();
				//sauvegarder le contenu du compte rendu
				string chemin = "examens/" + num;
				cpt_rendu.sauvegarder_crm(chemin);
				//le mot de passe a déjà été donné auparevent, et pas besoin de réafficher le crm, on vient de le rentrer
				bool shittyflute = true;
				Examen dossier(id_exam_radio_crm, radio, cpt_rendu);
				//créer le dossier, fichiers... et les remplir
				creer_nouvelle_radio(radio, cpt_rendu, true);
				//demander si on veut sauvegarder l'exam au format txt :
				cout << "Enregistrer cet examen au format txt (y/n) ? ";
				string rep_sauv;
				cin >> rep_sauv;
				if (rep_sauv == "y") dossier.sauvegarder_examen();
			}
			//créer le dossier, fichiers... et les remplir
			else creer_nouvelle_radio(radio, cpt_rendu, false);
		}
	}
}