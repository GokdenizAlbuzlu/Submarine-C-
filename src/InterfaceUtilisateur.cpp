//============================================================================
// Name        : AP4A.cpp
// Author      : GOKDENIZ ALBUZLU
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <fstream>
#include <random>
#include <cstdlib>
#include "Sensor.h"
#include "Temperature.h"
#include "Pression.h"
#include "Server.h"
#include "Luminosite.h"
#include "Humidite.h"
#include "Scheduler.h"
#include <direct.h>

int main(){

	Server serv1;
	int choix;
	cout<<"Bonjour et bienvenue sur la plateforme de moniteur du sous marin. "<<endl;
	cout<<"que souhaitez vous faire ?  ; \n 1) afficher les données du sous marin et les écrire dans des fichiers \n 2) afficher uniquement les données du sous marin sans les écrire\n 3) quitter \n\n"<<endl;

		cin>>choix;
		while ((choix!=1) && (choix !=2) && (choix!=3)) {
			cerr << " Veullez rentrer Uniquement 1 ou 2 ou 3 !"<<endl;
			cin>>choix;
		}
		if(choix==3){
			exit(0);
		}
		if (choix==1){
			cout<<"en activant l'écriture sur les fichiers, un dossier nommée C:/Support_Projet_AP4A sera crée sur votre pc.\n \nAcceptez vous cette condition ?\nRépondez par 1 (oui) ou 0 (non)\nSi le dossier existe déjà sur votre PC appuyez sur 1 \n"<<endl;
			cin>>choix;
			if(choix==0){
				cout<<"Vous n'avez pas accepté que le dossier soit créer de manière automatique\n\nVous devrez donc créer manuellement le dossier C:/Support_Projet_AP4A\nune fois que vous avez crée le dossier appuyez sur 0"<<endl;
				cin>>choix;
			}else{
				_mkdir("C:\\Support_Projet_AP4A");
				}
			serv1.setconsolActivation(true);
			serv1.setlogActivation(true);
		}else{
			serv1.setconsolActivation(true);
			serv1.setlogActivation(false);
		}

	int temps_temperature,temps_pression,temps_humidite,temps_luminosite,temps_global=0;
	cout<<"saisir la durée d'affichage des capteurs (cette durée est la durée totale de votre programme) :"<<endl;
	cin>> temps_global;

	cout<<"saisir le temps d'intervalle pour la temperature : "<<endl;
	cin>>temps_temperature;
	cout<<"saisir le temps d'intervalle pour la pression : "<<endl;
	cin>>temps_pression;
	cout<<"saisir le temps d'intervalle pour l'humidité : "	<<endl;
	cin>>temps_humidite;
	cout<<"saisir le temps d'intervalle pour la luminosité : "<<endl;
	cin>>temps_luminosite;

	Scheduler S1;
	S1.transmetFinal(serv1,temps_global,temps_temperature,temps_pression,temps_humidite,temps_luminosite);

}

