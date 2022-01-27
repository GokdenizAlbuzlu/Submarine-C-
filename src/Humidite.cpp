/*
 * Humidite.cpp
 *
 *  Created on: 18 sept. 2021
 *      Author: gokde
 */

#include "Humidite.h"

Humidite::Humidite():m_humiditeMaxi(70),m_humiditeMini(40) {

}

Humidite :: Humidite(const Humidite & autre_p){
	m_humiditeMaxi=autre_p.m_humiditeMaxi;
	m_humiditeMini=autre_p.m_humiditeMini;
}

Humidite& Humidite :: operator=(const Humidite & autre_p){
	m_humiditeMaxi=autre_p.m_humiditeMaxi;
	m_humiditeMini=autre_p.m_humiditeMini;
	return *this;
}

float Humidite :: getHumiditeMaxi(){
	return m_humiditeMaxi;
}

float Humidite :: getHumiditeMini(){
	return m_humiditeMini;
}

Humidite::~Humidite() {
	// TODO Auto-generated destructor stub
}

