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
	cout<<"que souhaitez vous faire ?  ; \n 1) afficher les donn�es du sous marin et les �crire dans des fichiers \n 2) afficher uniquement les donn�es du sous marin sans les �crire\n 3) quitter \n\n"<<endl;

		cin>>choix;
		while ((choix!=1) && (choix !=2) && (choix!=3)) {
			cerr << " Veullez rentrer Uniquement 1 ou 2 ou 3 !"<<endl;
			cin>>choix;
		}
		if(choix==3){
			exit(0);
		}
		if (choix==1){
			cout<<"en activant l'�criture sur les fichiers, un dossier nomm�e C:/Support_Projet_AP4A sera cr�e sur votre pc.\n \nAcceptez vous cette condition ?\nR�pondez par 1 (oui) ou 0 (non)\nSi le dossier existe d�j� sur votre PC appuyez sur 1 \n"<<endl;
			cin>>choix;
			if(choix==0){
				cout<<"Vous n'avez pas accept� que le dossier soit cr�er de mani�re automatique\n\nVous devrez donc cr�er manuellement le dossier C:/Support_Projet_AP4A\nune fois que vous avez cr�e le dossier appuyez sur 0"<<endl;
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
	cout<<"saisir la dur�e d'affichage des capteurs (cette dur�e est la dur�e totale de votre programme) :"<<endl;
	cin>> temps_global;

	cout<<"saisir le temps d'intervalle pour la temperature : "<<endl;
	cin>>temps_temperature;
	cout<<"saisir le temps d'intervalle pour la pression : "<<endl;
	cin>>temps_pression;
	cout<<"saisir le temps d'intervalle pour l'humidit� : "	<<endl;
	cin>>temps_humidite;
	cout<<"saisir le temps d'intervalle pour la luminosit� : "<<endl;
	cin>>temps_luminosite;

	Scheduler S1;
	S1.transmetFinal(serv1,temps_global,temps_temperature,temps_pression,temps_humidite,temps_luminosite);

}

