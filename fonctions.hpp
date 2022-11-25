
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

//################################################################################################
/*
	Série de fonctions permettant de comparer soit des noms, soit des dates
	et soit des numéros d'examens. Elles sont utiliser ensuite par la fonction
	sort() du package <algorithm> pour trier des vecteurs de Radiographie.
*/
bool comparePatient(Radiographie a, Radiographie b);
bool compareDate(Radiographie a, Radiographie b);
bool compareNumExam(Radiographie a, Radiographie b);

//################################################################################################
/*
	Petits wrappers autour de fonctions de C++ pour faciliter l'utilisation des fonctions
	associées.
	- La 1ere permet de facilement obtenir un entier aléatoire.
	- La 2nd permet de retourner 0 si "cin <<" casse quand l'utilisateur rentre
	n'importe quoi au clavier (espace, caractères spéciaux).
*/
int rng(int min, int max);
int input();

//################################################################################################
std::vector<std::string> trouver_profil_dans_bdd(std::vector<std::string> tokens, std::string id, std::string mdp, std::string mon_fichier);
std::vector<std::string> trouver_profil_dans_bdd(std::vector<std::string> tokens, std::string id, std::string mon_fichier, bool isOnManyLines);

//################################################################################################
/*
	Permet d'instancier les classes Medecin, Patient et Profil à partir
	d'un vecteur représentant une ligne du fichier bdd_patients_medecins.txt
*/
Medecin creer_med(std::vector<std::string> tokens);
Patient creer_pat(std::vector<std::string> tokens);
Profil creer_adm(std::vector<std::string> tokens);

//################################################################################################
/*
	Deux fonctions pour lire le fichier contenant les médecins, patients et admin
	(bdd_patients_medecins.txt) et renvoi soit un vecteur pour instancier ensuite
	un Profil, Medecin, Patient, ou pour directement instancier un Patient.
*/
void ajouter_bdd(Patient pat, std::string mon_fichier);
void ajouter_bdd(vector<string> vec, string mon_fichier);

//################################################################################################
/// @brief Remplit un tableau 2d de std::strings avec celles qu'il récuppère dans un fichier type csv, avec tab pour délimiteur.
/// @param vect_tokens_images Tableau de strins à renvoyer
/// @param mon_fichier Chemin du fichier à lire
/// @return Renvoie un tableau à deux dimensions contenant la transcription du fichier.
std::vector<std::vector<std::string>> trouver_tous_profil_dans_bdd(std::vector<std::vector<std::string>> vect_tokens_images, std::string mon_fichier, bool isOnManyLines);

//################################################################################################
/*
	Deux fonctions permettant d'instancier une Radiographie ou une liste de radios
	à partir de la base de données.
*/
vector<Radiographie> trouver_radios_dans_bdd(string mon_fichier, vector<Profil> admins,vector<Medecin> medecins,vector<Patient> patients);
/// @brief Cherche un radiographie existante dans la base de donnée et l'instancie.
/// @param num Numéro d'examen pour la radiographie associée.
/// @param admins Liste des administrateurs sous forme de vecteur de Profil.
/// @param medecins Liste des médecins sous forme de vecteur d'objets Medecin.
Radiographie trouver_radio(string num, vector<Profil> admins,vector<Medecin> medecins,vector<Patient> patients);

//################################################################################################
/*
	Permet de choisir un patient dans la base de donnée lors de la création d'un examen.
	Si plusieurs patients ont le même nom et prénom, alors la fonction affiche les
	patients correspondants et demande à l'utilisateur de choisir le bon dans l'ordre.
	Si le patient n'est pas présent dans la base donnée, alors la fonction permet
	d'ajouter un patient à la base donnée.
	La fonction renvoie une instance de Patient.
*/
Patient choix_patient(std::vector<Patient> &patients);

//################################################################################################
/*
	Cette fonction a pour rôle d'stancier une Radiographie à partir du numéro d'examen
	correspondant. Si elle n'est pas présente dans la base de donnée, alors la fonction
	suivante permet d'ajouter une radiographie à la base de donnée (créant le dossier de
	l'examen correspondant).
*/
/// @brief Interface pour créer une radio. accessible uniquement à un médecin
/// @param numero Numéro d'examen
/// @param med Médecin en charge de la radiographie
/// @param patients Vecteur de tous les patients
/// @return Renvoie une radiographie.
Radiographie creer_radio(std::string numero, Medecin med, std::vector<Patient> &patients);
/*
	Lors de la création de l'examen on peut choisir si la radio est prévu ou réalisée.
*/
void creer_nouvelle_radio(Radiographie radio, Compte_rendu_medical cpt_rendu);

//################################################################################################
/*
	Fonction utilisée pour permettre à un médecin d'accéder ou de créer une radio
	en utilisant les deux fonctions précédantes entre autres.
*/
void acces_radio(Application app, Profil* user, std::vector<Profil> admins,std::vector<Medecin> medecins,std::vector<Patient> patients);