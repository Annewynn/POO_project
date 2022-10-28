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