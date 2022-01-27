/*
 * Scheduler.cpp
 *
 *  Created on: 26 sept. 2021
 *      Author: gokde
 */

#include "Scheduler.h"
#include <unistd.h>
#include <time.h>




//il faut choisir la fonction Sleep en fonction de votre système d'exploitation (voir ligne 80)



Scheduler::Scheduler(){

}
Scheduler :: Scheduler(const Scheduler & autre_p){

		m_temperature=autre_p.m_temperature;
		m_pression=autre_p.m_pression;
		m_humidite=autre_p.m_humidite;
		m_luminosite=autre_p.m_luminosite;


}
Scheduler & Scheduler :: operator=(const Scheduler & autre_p){
	m_temperature=autre_p.m_temperature;
	m_pression=autre_p.m_pression;
	m_humidite=autre_p.m_humidite;
	m_luminosite=autre_p.m_luminosite;

	return *this;

}

void Scheduler ::transmetFinal(Server & serverTransmet_p,int temps_p,int temps_temperature_p, int temps_pression_p,int temps_humidite_p,int temps_luminosite_p){
	srand(time(0));		//on initialise une fois notre fonction random pour pouvoir utiliser la fonction aleaGenVal de manière indépendante

	int variable_temperature,variable_pression,variable_humidite,variable_luminosite,variable_temps=time(0);	//création des variables de temps pour chaque capteur qui vont nous permettre de vérifier les différents temps d'intervalles.

	m_temperature.setMax(m_temperature.getTemperatureMaxiCelsius());		//on fixe les bornes min et max de notre capteur de temperature
	m_temperature.setMin(m_temperature.getTemperatureMiniCelsius());

	m_pression.setMax(m_pression.getPressionMaxiPascal());					//on fixe les bornes min et max de notre capteur de pression
	m_pression.setMin(m_pression.getPressionMiniPascal());

	m_humidite.setMax(m_humidite.getHumiditeMaxi());						//on fixe les bornes min et max de notre capteur d'humidité
	m_humidite.setMin(m_humidite.getHumiditeMini());

	m_luminosite.setMax(m_luminosite.getLuminositeMaxi());					//on fixe les bornes min et max de notre capteur de luminosité
	m_luminosite.setMin(m_luminosite.getLuminositeMini());

while(time(0)-variable_temps <= temps_p){									// le programme fonctionne pendant	"temps_p" secondes

	if((time(0) - variable_temperature) >= temps_temperature_p){			//tout les "temps_temperature_p" seconde, on transmet à l'utilisateur les données de temperature
		serverTransmet_p.dataReceive(m_temperature.getData(),serverTransmet_p,1);
		m_temperature.setMax(m_temperature.getValue()+0.4);					//rétrécissement de la plage temperature en fonction de la première valeur aléatoire générée
		m_temperature.setMin(m_temperature.getValue()-0.4);					//cela nous permet de générer des valeurs cohérentes
		variable_temperature=time(0);
		}

	if((time(0)-variable_pression)>=temps_pression_p){						//tout les "temps_pression_p",on transmet à l'utilisateur les données de pressions
		serverTransmet_p.dataReceive(m_pression.getData(),serverTransmet_p,0);
		m_pression.setMax(m_pression.getValue()+20);
		m_pression.setMin(m_pression.getValue()-20);
		variable_pression=time(0);
	}
	if((time(0)-variable_humidite)>= temps_humidite_p){
		serverTransmet_p.dataReceive(m_humidite.getData(),serverTransmet_p,4);	//tout les "temps_humidite_p", on transmet à l'utilsiateur les données d'humidité
		m_humidite.setMax(m_humidite.getValue()+1);
		m_humidite.setMin(m_humidite.getValue()-1);
		variable_humidite=time(0);
	}
	if((time(0)-variable_luminosite)>=temps_luminosite_p){
		serverTransmet_p.dataReceive(m_luminosite.getData(),serverTransmet_p,0);	//tout les "temps_luminosite_p", on transmet à l'utilisateur les données de luminosité
		m_luminosite.setMax(m_luminosite.getValue());
		m_luminosite.setMin(m_luminosite.getValue());
		variable_luminosite=time(0);
	}
	}

}

Scheduler::~Scheduler() {
	// TODO Auto-generated destructor stub
}
