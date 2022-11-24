/*#########################################
## 09/11/2022
## Par Elyna Bouchereau & Naelle Guillon
## Fichier: main.cpp
###########################################*/
#include "fonctions.hpp"
//fonctions inclut tous les packages nécessaires

using namespace std;

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
	int MenuPrincipal = 1;
	while(MenuPrincipal == 1){
		cout << "#############################################\n";
		cout << "##         Bienvenue sur P.O.O FM          ##\n";
		cout << "##     Gestionnaire de radiographies       ##\n";
		cout << "#############################################\n";
		cout << "## Menu principal:\n";
		cout << "   [1]: Admin, Medecin ou Patient\n";
		cout << "   [2]: Quitter\n";
		cin >> MenuPrincipal;
		switch(MenuPrincipal){
			case 1: cout << "[1]: Admin, Medecin ou Patient\n"; break;
			case 2: cout << "[2]: Quitter\n"; return 0;
			default: cout << "\033[1;31mSaisie incorrecte.\033[0m";continue;
		}

		//initialisation : instancier une application contenant une liste de radiographies
		Application app;

		//ouvrir bdd_patients_medecins.txt pour en récuppérer les profils
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
		cout << "## Menu de connection:\n";
		cout << "Votre identifiant : ";
		string id;
		cin >> id;
		cout << "Votre mot de passe : ";
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
					break;
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
					trouve = true;
					break;
				}
			}
		}
		else if (id[0] == 'a') {
			for (int i =0; i<admins.size(); i++)
			{
				if (admins[i].get_id() == id && admins[i].get_mdp() == mdp) 
				{
					user = &admins[i];
					trouve = true;
					break;
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
				int menu_examen = 1;
				while(menu_examen == 1){
					cout << "## Menu: consulter un examen\n";
					cout << "   [1]: Consulter/saisi\n";
					cout << "   [2]: Retour au menu principal\n";
					cin >> menu_examen;
					switch(menu_examen){
						case 1: {
							cout << "[1]: Consulter/saisi\n";
							//pour le médecin : accéder ou créer une radio
							acces_radio(app, user, admins,medecins,patients);
						} break;
						case 2: cout << "[2]: Retour au menu principal\n"; continue;
						default: cout << "\033[1;31mMauvaise entrée, retour au menu.\033[0m"; break;
					}					
				}
			}
			else cout << "\033[1;31mConnard :) essaie encore !\033[0m" <<endl;
	}
	
	
}