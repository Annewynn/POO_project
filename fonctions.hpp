
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

std::vector<std::string> trouver_profil_dans_bdd(std::vector<std::string> tokens, std::string id, std::string mdp, std::string mon_fichier);

std::vector<std::string> trouver_profil_dans_bdd(std::vector<std::string> tokens, std::string id, std::string mon_fichier);

Medecin creer_med(std::vector<std::string> tokens);

Patient creer_pat(std::vector<std::string> tokens);

Profil creer_adm(std::vector<std::string> tokens);

void ajouter_bdd(Patient pat, std::string mon_fichier);

/// @brief Remplit un tableau 2d de std::strings avec celles qu'il récuppère dans un fichier type csv, avec tab pour délimiteur.
/// @param vect_tokens_images Tableau de strins à renvoyer
/// @param mon_fichier Chemin du fichier à lire
/// @return Renvoie un tableau à deux dimensions contenant la transcription du fichier.
std::vector<std::vector<std::string>> trouver_tous_profil_dans_bdd(std::vector<std::vector<std::string>> vect_tokens_images, std::string mon_fichier);
int rng(int min, int max);

Patient choix_patient(std::vector<Patient> &patients);

/// @brief Interface pour créer une radio. accessible uniquement à un médecin
/// @param numero Numéro d'examen
/// @param med Médecin en charge de la radiographie
/// @param patients Vecteur de tous les patients
/// @return Renvoie une radiographie.
Radiographie creer_radio(std::string numero, Medecin med, std::vector<Patient> &patients);

void acces_radio(Application app, Profil* user, std::vector<Profil> admins,std::vector<Medecin> medecins,std::vector<Patient> patients);