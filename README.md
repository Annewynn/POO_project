<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Annewynn/POO_project">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Gestionnaire d'examen</h3>

  <p align="center">
    An awesome README template to jumpstart your projects!
    <br />
    <a href="https://github.com/othneildrew/Best-README-Template"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/othneildrew/Best-README-Template">View Demo</a>
    ·
    <a href="https://github.com/othneildrew/Best-README-Template/issues">Report Bug</a>
    ·
    <a href="https://github.com/othneildrew/Best-README-Template/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>
# Projet en Programmation orientée objet
## Logiciel pour un centre de radiologie


```mermaid
classDiagram
radiographie *-- cliché : 1-------*
radiographie --* examen : 1------1
application o-- radiographie : 1------0..*
compte_rendu_medical -- patient : 0..*------1
examen *-- compte_rendu_medical : *------1
medecin -- compte_rendu_medical : 1------0..*
medecin -- radiographie : 1------0..*
profil -- radiographie
profil <|-- patient
profil <|-- medecin
profil -- application

radiographie: NumExamen
radiographie: type
radiographie: id_patient
radiographie: medecin
radiographie: date
radiographie: etat
radiographie: liste_cliché
radiographie: ajouter()
radiographie: supprimer()
radiographie: afficher()

cliché: NumPrise
cliché: image
cliché: légende
cliché: afficher_image()

compte_rendu_medical: mot_de_passe
compte_rendu_medical: texte
compte_rendu_medical: id_compteRendu
compte_rendu_medical: patient
compte_rendu_medical: creer_mdp()

application: liste_radiographie
application: connexion()
application: charger_liste_radios()
application: sauvegarder_liste_radios()
application: trier_liste()
application: afficher_liste(trier_liste())

examen: radiographie
examen: compte_rendu_medical

profil: nom
profil: prenom
profil: id

profil: consulter()

patient: age
patient: sexe
patient: consulter()

medecin: ajouter()
medecin: consulter()
```
