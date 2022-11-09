## Compilation du main
main: main.cpp application.o cliche.o compte_rendu_medical.o examen.o medecin.o patient.o profil.o radiographie.o
	g++ -o main main.cpp application.o cliche.o compte_rendu_medical.o examen.o medecin.o patient.o profil.o radiographie.o

## Compilation des classes
application.o: application.cpp
	g++ -c application.cpp
cliche.o: cliche.cpp
	g++ -c cliche.cpp
compte_rendu_medical.o: compte_rendu_medical.cpp
	g++ -c compte_rendu_medical.cpp
examen.o: examen.cpp
	g++ -c examen.cpp
medecin.o: medecin.cpp
	g++ -c medecin.cpp
patient.o: patient.cpp
	g++ -c patient.cpp
profil.o: profil.cpp
	g++ -c profil.cpp
radiographie.o: radiographie.cpp
	g++ -c radiographie.cpp