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
	Server m_Server;				//cr�ation du serveur sur lequel les donn�es seront transmises

	Temperature m_temperature;		//cr�ation des diff�rents capteurs
	Pression m_pression;
	Humidite m_humidite;
	Luminosite m_luminosite;


											//forme canonique de coplien
	Scheduler();							//constructeur par d�faut
	Scheduler(const Scheduler & autre_p);	//constructeur de recopie
	Scheduler &operator=(const Scheduler &);//op�rateur d'affectation
	virtual ~Scheduler();					//Destructeur



	/****
	 * transmetFinal qui prend en param�tre 1 serveur et 5 entier de temps qui sont respectivement pour
	 * la dur�e globale du programme, le temps d'intervalle de la temperature,le temps d'intervalle de la pression, le temps d'intervalle de l'humidite et le temps d'intervalle de la luminosite
	 * transmetFinal R�cup�re les donn�es depuis les capteurs (sensor) et les retourne au serveur en utilisant la fonction dataReceive.
	 * permet d'envoyer les donn�es au serveur dans les d�lais pr�cis�es par l'utilisateur.
	 */

	void transmetFinal(Server & serverTransmet_p,int temps_p,int temps_temperature_p,int temps_pression_p,int temps_humidite_p,int temps_luminosite_p);





};

#endif /* SCHEDULER_H_ */
