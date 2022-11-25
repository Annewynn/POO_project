<a name="readme-top"></a>
<!-- PROJECT SHIELDS -->
<!-- PROJECT TITLE -->
<br />
<div align="center">
  <a href="https://github.com/Annewynn/POO_project">
    <img src="images/POO_FM_alt.png" alt="Logo" width="150" height="150">
  </a>

  <h1 align="center"></h1>

  <p align="center">
    Une application pour la consultations d'examens réalisées, et des radiographies associées, ainsi que la saisie de nouvelles radiographies.
    <br />
    <a href="https://github.com/Annewynn/POO_project">Home</a>
    ·
    <a href="https://github.com/Annewynn/POO_project/issues">Report de bugs</a>
    ·
    <a href="https://github.com/Annewynn/POO_project/issues">Requêtes de fonctionnalités</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
- [Projet en Programmation Orientée Objet: _Logiciel pour un centre de radiologie_](#projet-en-programmation-orientée-objet-logiciel-pour-un-centre-de-radiologie)
	- [Schéma U.M.L. de l'architecture du logiciel](#schéma-uml-de-larchitecture-du-logiciel)
	- [Documentation](#documentation)
		- [Construction du logiciel:](#construction-du-logiciel)
		- [Utilisation du logiciel](#utilisation-du-logiciel)
		- [Dépendances nécessaires](#dépendances-nécessaires)
	- [Plan de finalisation du logiciel](#plan-de-finalisation-du-logiciel)
	- [Disclaimer \& Copyright](#disclaimer--copyright)
	- [Références](#références)

# Projet en Programmation Orientée Objet: _Logiciel pour un centre de radiologie_
Dans un cabinet de radiologie, il est nécessaire de pouvoir facilement consulter des radiographies associées à des examens sur une base de données numériques. Il est également nécessaire de pouvoir y enregistrer des examens, avec les contre-rendu et la radiographies associées.  
Pour se faire nous proposons ce logiciel, **P.O.O FM**, utilisable simplement à partir d'un terminal et sans avoir besoin d'accéder manuellement aux fichiers de la base de données. 

## Schéma U.M.L. de l'architecture du logiciel
Pour faciliter la compréhension et la lisibilité du code du logiciel, un schéma récapitulatif en UML a été réalisé.  

Le logiciel est centré sur l'utilisation de classes pour les différents éléments de la base de donnée à gérer. L'organisation et les relations entre ces différentes classes est réprésentées sous la form de lien d'hérédité, de composition ou encore de relation simple. Il est également indiqué la composition et les actions possibles de chaqu'une des instances de ces différentes classes.

```mermaid
classDiagram
Radiographie *-- Cliché : 1-------*
Radiographie --* Examen : 1------1
Application o-- Radiographie : 1------0..*
Compte_rendu_medical -- Patient : 0..*------1
Examen *-- Compte_rendu_medical : *------1
Medecin -- Compte_rendu_medical : 1------0..*
Medecin -- Radiographie : 1------0..*
Profil -- Radiographie
Profil <|-- Patient
Profil <|-- Medecin
Profil -- Application

Radiographie: int NumExamen
Radiographie: string type
Radiographie: Medecin medecin
Radiographie: Patient patient [public]
Radiographie: Date date
Radiographie: bool etat
Radiographie: vector<Cliché> liste_cliché
Radiographie: string get_type()
Radiographie: Medecin get_medecin()
Radiographie: Date get_date()
Radiographie: string get_etat()
Radiographie: set_etat()
Radiographie: string get_liste_cliche()
Radiographie: string get_id()
Radiographie: string afficher_radio()
Radiographie: string afficher_radio_as_table()
Radiographie: int get_numexam()
Radiographie: sauvegarder_radio(string chemin)
Radiographie: sauvegarder_cliches(string chemin)

Cliché: int NumPrise
Cliché: string chemin_accès_image
Cliché: string légende
Cliché: string afficher_image()
Cliché: string get_cliche()
Cliché: string return_cliche()
Cliché: string get_path()
Cliché: string get_legende()

Compte_rendu_medical: int NumExam
Compte_rendu_medical: string mot_de_passe
Compte_rendu_medical: string texte
Compte_rendu_medical: Patient patient
Compte_rendu_medical: get_Compte_Rendu()
Compte_rendu_medical: print_Compte_Rendu()
Compte_rendu_medical: return_Compte_Rendu()
Compte_rendu_medical: modifier_Compte_Rendu()
Compte_rendu_medical: sauvegarder_crm(string chemin)

Application: vector<Radiographie> liste_radiographie
Application: connexion()
Application: sauvegarder_liste_radios()
Application: string afficher_liste(vector<Radiographie> radios)
Application: vector<Radiographie> afficher_liste_examen_Patient()
Application: vector<Radiographie> afficher_liste_examen_date()
Application: vector<Radiographie> afficher_liste_examen_NumExam()

Examen: int numero_exam
Examen: Radiographie radio
Examen: Compte_rendu_medical crm
Examen: sauvegarder_examen()
Examen: sauvegarder_examen_restreint()

Profil: string nom
Profil: string prenom
Profil: string id
Profil: string mot_de_passe
Profil: int age
Profil: char sexe
Profil: Profil ajouter()
Profil: string virtual consulter()
Profil: string afficher()
Profil: string get_id()
Profil: string get_mdp()
Profil: string get_nom()
Profil: string get_prenom()
Profil: int get_age()
Profil: char get_sexe()

Patient: consulter()

Medecin: ajouter_Patient()
Medecin: string consulter()
```

## Documentation
### Construction du logiciel:
* [![C++][C++-shield]][C++-url]
* [![Mermaid][mermaid-shield]][mermaid-url]

### Utilisation du logiciel
Ce utilise uniquement le language C++ et ne nécessite donc aucuns prérequis. Il suffit de lancer le fichier _main_.
```bash
./main
```

### Dépendances nécessaires
Les packages utilisées ne sont pas des packages extérieurs. Leur liste:
- iostream
- string
- fstream
- sstream
- vector
- sys/stat.h
- filesystem

## Plan de finalisation du logiciel
- [ ] Fonctionnalités élémentaires
  - [x] Interface de connection lors du lancement.
  - [x] Pouvoir accéder aux examens (radiographies et clichés associés + compte rendu)
  - [x] Menu de navigation au sein du logiciel
  - [x] Pouvoir créer et sauvegarder des examens/radiographies.
  - [x] Pouvoir écrire/changer un compte rendu
  - [x] Pouvoir changer le statut d'un examen  
  - [x] Pouvoir créer un examen
  - [x] Pouvoir afficher la liste des examens/radiographies.
  - [x] Pouvoir trier la liste des radiographies et l'exporter.
  - [ ]	Afficher liste radio d'un patient
  - [ ] Utilise les bases de données de radios et de profils si passer en paramètre
- [ ] Fonctionnalités supplémentaires
  - [ ] Ajouter des fonctionnalités pour les patients
  - [ ] Affichage des clichés associés aux radiographies
  - [ ] Utilisation d'un racourcie pour éviter de passer par le terminal.

Pour avoir une liste des fonctionnalités proposées (et bugs découverts), suivé ce [lien](https://github.com/Annewynn/POO_project/issues).

## Disclaimer & Copyright
P.O.O FM est une application en développement.  
Les auteurs demandent que tout travail nécessitant l'utilisation de cette application incorpore une référence au [github](https://github.com/Annewynn/POO_project), ainsi que les références suivantes:  
  _BOUCHEREAU E., GUILLON N._ "P.O.O FM: Logiciel de gestion de radiographies", 2022

## Références
<a href="https://www.flaticon.com/fr/icones-gratuites/mri" title="mri icônes">Mri icônes créées par mavadee - Flaticon</a>

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[C++-shield]: https://img.shields.io/badge/C++-Orient%C3%A9_objet-blue.svg?style=for-the-badge&logo=c%2B%2B
[C++-url]: https://cplusplus.com/
[mermaid-shield]: https://img.shields.io/badge/mermaid-UML-blue.svg?style=for-the-badge&logo=JavaScript
[mermaid-url]: https://mermaid-js.github.io/
