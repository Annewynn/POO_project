/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: main.cpp
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
/*_                                                     __ _ _        _                     _         _     _ 
 | |_ _ __ ___  _   ___   _____ _ __   _ __  _ __ ___  / _(_) |    __| | __ _ _ __  ___    | |__   __| | __| |
 | __| '__/ _ \| | | \ \ / / _ \ '__| | '_ \| '__/ _ \| |_| | |   / _` |/ _` | '_ \/ __|   | '_ \ / _` |/ _` |
 | |_| | | (_) | |_| |\ V /  __/ |    | |_) | | | (_) |  _| | |  | (_| | (_| | | | \__ \   | |_) | (_| | (_| |
  \__|_|  \___/ \__,_| \_/ \___|_|____| .__/|_|  \___/|_| |_|_|___\__,_|\__,_|_| |_|___/___|_.__/ \__,_|\__,_|
                                |_____|_|                    |_____|                  |_____|                 
 */
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

//################################################################################################
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

//################################################################################################
/*
  _                                  _                                        __ _ _        _                     _         _     _ 
 | |_ _ __ ___  _   ___   _____ _ __| |_ ___  _   _ ___      _ __  _ __ ___  / _(_) |    __| | __ _ _ __  ___    | |__   __| | __| |
 | __| '__/ _ \| | | \ \ / / _ \ '__| __/ _ \| | | / __|    | '_ \| '__/ _ \| |_| | |   / _` |/ _` | '_ \/ __|   | '_ \ / _` |/ _` |
 | |_| | | (_) | |_| |\ V /  __/ |  | || (_) | |_| \__ \    | |_) | | | (_) |  _| | |  | (_| | (_| | | | \__ \   | |_) | (_| | (_| |
  \__|_|  \___/ \__,_| \_/ \___|_|___\__\___/ \__,_|___/____| .__/|_|  \___/|_| |_|_|___\__,_|\__,_|_| |_|___/___|_.__/ \__,_|\__,_|
                                |_____|               |_____|_|                    |_____|                  |_____|                 
*/
/// @brief Remplit un tableau 2d de strings avec celles qu'il récuppère dans un fichier type csv, avec tab pour délimiteur.
/// @param vect_tokens_images Tableau de strins à renvoyer
/// @param mon_fichier Chemin du fichier à lire
/// @return Renvoie un tableau à deux dimensions contenant la transcription du fichier.
vector<vector<string>> trouver_tous_profil_dans_bdd(vector<vector<string>> vect_tokens_images, string mon_fichier)
{
      // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
    ifstream fichier(mon_fichier.c_str(), ios::in);
    if(fichier)  // si l'ouverture a réussi
    {
        string ligne;  // déclaration d'une chaîne qui contiendra la ligne lue
		//oter la première ligne dans bdd patients médecins
		if (mon_fichier == "bdd_patients_medecins.txt") getline(fichier, ligne);
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
/// @param id_profil Id du médecin en charge de la radiographie (donc de user)
/// @param med Médecin en charge de la radiographie
/// @return Renvoie une radiographie.
Radiographie creer_radio(string numero, string id_profil, Medecin med)
{
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
	cout << "N° Patient : ";
	string id_patient;
	cin >> id_patient;
	//vérifier si ce patient existe : 
	vector<string> tokens_pat;
	tokens_pat = trouver_profil_dans_bdd(tokens_pat, id_patient, "bdd_patients_medecins.txt");
	//si la patient n'a pas été trouvé dans la bdd on le crée
	if (tokens_pat.size() == 0)
	{
		cout << "Patient pas encore dans la base de données. Veuillez entrer ses informations." <<endl;;
		//id
		tokens_pat.push_back(id_patient);
		//mdp
		//généré aléatoirement
		string mdp;
		for (int i = 0; i< 4; i++)
		{
			mdp += to_string(rng(0, 9));
		}
		tokens_pat.push_back(mdp);
		//nom
		cout << "Nom: ";
		string nom_pat;
		cin >> nom_pat;
		tokens_pat.push_back(nom_pat);
		//prenom
		cout << "Prénom: ";
		string prenom_pat;
		cin >> prenom_pat;
		tokens_pat.push_back(prenom_pat);
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
	}
	Patient pat = creer_pat(tokens_pat);
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
	Radiographie radio(num, rtype, id_patient, med, date, etat, images);
	cout << radio.afficher_radio() << endl;
	return radio;
	//créer un fichier crm.txt vide
	//créer un fichier radio.txt comprennant tout ce qu'il y a dans la radio
}

//################################################################################################
/*                                                                
MMMMMMMM               MMMMMMMM               AAA               IIIIIIIIIINNNNNNNN        NNNNNNNN
M:::::::M             M:::::::M              A:::A              I::::::::IN:::::::N       N::::::N
M::::::::M           M::::::::M             A:::::A             I::::::::IN::::::::N      N::::::N
M:::::::::M         M:::::::::M            A:::::::A            II::::::IIN:::::::::N     N::::::N
M::::::::::M       M::::::::::M           A:::::::::A             I::::I  N::::::::::N    N::::::N
M:::::::::::M     M:::::::::::M          A:::::A:::::A            I::::I  N:::::::::::N   N::::::N
M:::::::M::::M   M::::M:::::::M         A:::::A A:::::A           I::::I  N:::::::N::::N  N::::::N
M::::::M M::::M M::::M M::::::M        A:::::A   A:::::A          I::::I  N::::::N N::::N N::::::N
M::::::M  M::::M::::M  M::::::M       A:::::A     A:::::A         I::::I  N::::::N  N::::N:::::::N
M::::::M   M:::::::M   M::::::M      A:::::AAAAAAAAA:::::A        I::::I  N::::::N   N:::::::::::N
M::::::M    M:::::M    M::::::M     A:::::::::::::::::::::A       I::::I  N::::::N    N::::::::::N
M::::::M     MMMMM     M::::::M    A:::::AAAAAAAAAAAAA:::::A      I::::I  N::::::N     N:::::::::N
M::::::M               M::::::M   A:::::A             A:::::A   II::::::IIN::::::N      N::::::::N
M::::::M               M::::::M  A:::::A               A:::::A  I::::::::IN::::::N       N:::::::N
M::::::M               M::::::M A:::::A                 A:::::A I::::::::IN::::::N        N::::::N
MMMMMMMM               MMMMMMMMAAAAAAA                   AAAAAAAIIIIIIIIIINNNNNNNN         NNNNNNN
*/
int main()
{
	//initialisation : instancier une application contenant une liste de radiographies
	Application app;

	//ouvrir bdd_patients_medecins.txt pour en récuppérer les images
	vector<vector<string>> vect_tokens_profils;
	string mon_fichier = "bdd_patients_medecins.txt";
	vector<Profil> admins;
	vector<Medecin> medecins;
	vector<Patient> patients;
	vect_tokens_profils = trouver_tous_profil_dans_bdd(vect_tokens_profils, mon_fichier);
	for (int i =0; i<vect_tokens_profils.size(); i++)
	{
		/*for (int j = 0; j<vect_tokens_profils[i].size(); j++)
		{
			cout << vect_tokens_profils[i][j] <<endl;
		}*/
		if (vect_tokens_profils[i][0][0] == 'a')
			admins.push_back(creer_adm(vect_tokens_profils[i]));
		else if (vect_tokens_profils[i][0][0] == 'm')
			medecins.push_back(creer_med(vect_tokens_profils[i]));
		else patients.push_back(creer_pat(vect_tokens_profils[i]));
	}

	cout << "id : ";
    string id;
    cin >> id;
    cout << "mot de passe : ";
    string mdp;
    cin >> mdp;
	//aller chercher dans le bon tableau (id[0]) les id/mdp entrées
	Medecin *pmed;
	pmed = &medecins[0];
	Patient *ppat;
	ppat = &patients[0];
	Profil *user;
	user = &admins[0];
	bool trouve = false;
	if (id[0] == 'm') {
		for (int i =0; i<medecins.size(); i++)
		{
			if (medecins[i].get_id() == id && medecins[i].get_mdp() == mdp) 
			{
				pmed = &medecins[i];
				user = pmed; 
				trouve = true;
			}
		}
	}
	else if (id[0] == 'p') {
		for (int i =0; i<patients.size(); i++)
		{
			if (patients[i].get_id() == id && patients[i].get_mdp() == mdp) 
			{
				ppat = &patients[i];
				user = ppat; 
				trouve = true;}
		}
	}
	else if (id[0] == 'a') {
		for (int i =0; i<admins.size(); i++)
		{
			if (admins[i].get_id() == id && admins[i].get_mdp() == mdp) 
			{
				user = &admins[i];
				trouve = true;
			}
		}
	}

	/*
	vector<string> tokens;
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
            cout << user -> afficher() << endl;
            cout << user -> consulter() << endl;

            //si user est un admin : 
                //il peut voir les radiographies mais pas les crm : ok
                //il peut ajouter un médecin
            //si user est médecin : 
                //il peut ajouter un patient : ok
                //il peut voir les radios et les crm si il a le mp : ok
            //si user est patient : 
                //il voit les radios qui lui sont associées : ok
                //il peut accéder aux clichés mais pas au crm : ok
		*/
		if (trouve)
		{
			//profil reconnu
			cout << user -> afficher() << endl;
    		cout << user -> consulter() << endl;
			//pour le médecin : accéder ou créer une radio
			if (user->get_id()[0] == 'm')
			{
				cout << "Entrez un numéro d'examen pour afficher ou créer cet examen : ";
			}
            //entrer un numéro d'examen :
            else cout << "Entrer un numéro d'examen : ";
            string num;
            //std::cin.ignore();
            cin >> num;
            //rechercher dans la liste des examens celle qui a le bon numéro
            filesystem::path cwd = filesystem::current_path();
            string s = cwd.generic_string() + "/examens/" + num;
            struct stat buffer;
			//dossier de l'examen existe déjà
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
                    cout << radio.afficher_radio() << endl;
					//on va chercher le crm si user est un médecin
					if (radio.get_etat() == "Effectuée" && user->get_id()[0] == 'm')
					{
						//trouver le crm à partir de son id
                		vector<string> tokens_crm;
                		tokens_crm = trouver_profil_dans_bdd(tokens_crm, to_string(numero), "bdd_compte_rendu_medical.txt");
						string mdp = tokens_crm[2];
						//patient correspondant au crm : id_path
						//aller chercher le patient par son id dans bdd patients médecins
						vector<string> tokens_pat;
                		tokens_pat = trouver_profil_dans_bdd(tokens_pat, id_pat, "bdd_patients_medecins.txt");
						Patient pat = creer_pat(tokens_pat);
						//créer crm
						Compte_rendu_medical cpt_rendu(numero, mdp, pat);
						cpt_rendu.print_Compte_Rendu();
						Examen dossier(numero, radio, cpt_rendu);
						dossier.sauvegarder_examen();
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
                		tokens_crm = trouver_profil_dans_bdd(tokens_crm, to_string(numero), "bdd_compte_rendu_medical.txt");
						string mdp = tokens_crm[2];
						//patient correspondant au crm : id_path
						//aller chercher le patient par son id dans bdd patients médecins
						vector<string> tokens_pat;
                		tokens_pat = trouver_profil_dans_bdd(tokens_pat, id_pat, "bdd_patients_medecins.txt");
						Patient pat = creer_pat(tokens_pat);
						//créer crm
						Compte_rendu_medical cpt_rendu(numero, mdp, pat);
						//veut-on créer un crm ?
						if (rep == "y")
						//passer etat à 1, et écrire le crm
						{
							radio.set_etat();
							cpt_rendu.get_Compte_Rendu();
							cpt_rendu.print_Compte_Rendu();
							Examen dossier(numero, radio, cpt_rendu);
							dossier.sauvegarder_examen();
						}
						else cpt_rendu.print_Compte_Rendu();
					}
					            
                } else {
                    cout << user -> get_id() << endl;
                    cout << "\033[1;31mC'est pas toi, arrête ! >:(\033[0m\n";
                }
            
            }
            else if (user -> get_id()[0] != 'm') cout << "\033[1;31mAncun examen n'a ce numéro *-*\033[0m" <<endl;
				else 
				{
					Radiographie radio = creer_radio(num, user -> get_id(), medecins[0]);
					app.ajouter(radio);
					//créer crm
					//mdp
					cout << "Mot de passe du compte-rendu ? ";
					string mdp;
					cin >> mdp;
					string patientid = radio.get_id();
					//Patient pat = 
					//Compte_rendu_medical cpt_rendu(num, mdp, pat);
				}
			
        }
        else cout << "\033[1;31mConnard :) essaie encore !\033[0m" <<endl;
		*/
}