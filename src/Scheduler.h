/*
 * Scheduler.h
 *
 *  Created on: 26 sept. 2021
 *      Author: gokde
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include "Sensor.h"
#include "Temperature.h"
#include "Pression.h"
#include "Server.h"
#include "Luminosite.h"
#include "Humidite.h"


class Scheduler {

public:
	Server m_Server;				//création du serveur sur lequel les données seront transmises

	Temperature m_temperature;		//création des différents capteurs
	Pression m_pression;
	Humidite m_humidite;
	Luminosite m_luminosite;


											//forme canonique de coplien
	Scheduler();							//constructeur par défaut
	Scheduler(const Scheduler & autre_p);	//constructeur de recopie
	Scheduler &operator=(const Scheduler &);//opérateur d'affectation
	virtual ~Scheduler();					//Destructeur



	/****
	 * transmetFinal qui prend en paramètre 1 serveur et 5 entier de temps qui sont respectivement pour
	 * la durée globale du programme, le temps d'intervalle de la temperature,le temps d'intervalle de la pression, le temps d'intervalle de l'humidite et le temps d'intervalle de la luminosite
	 * transmetFinal Récupère les données depuis les capteurs (sensor) et les retourne au serveur en utilisant la fonction dataReceive.
	 * permet d'envoyer les données au serveur dans les délais précisées par l'utilisateur.
	 */

	void transmetFinal(Server & serverTransmet_p,int temps_p,int temps_temperature_p,int temps_pression_p,int temps_humidite_p,int temps_luminosite_p);





};

#endif /* SCHEDULER_H_ */
