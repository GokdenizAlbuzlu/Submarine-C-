/*
 * Luminosite.cpp
 *
 *  Created on: 18 sept. 2021
 *      Author: gokde
 */

#include "Luminosite.h"

Luminosite::Luminosite():m_luminositeMaxi(1),m_luminositeMini(0){
	// TODO Auto-generated constructor stub

}

Luminosite :: Luminosite(const Luminosite & autre_p){
	m_luminositeMaxi=autre_p.m_luminositeMaxi;
	m_luminositeMini=autre_p.m_luminositeMini;
}

Luminosite& Luminosite :: operator=(const Luminosite & autre_p){
	m_luminositeMaxi=autre_p.m_luminositeMaxi;
	m_luminositeMini=autre_p.m_luminositeMini;
	return *this;
}

int Luminosite :: getLuminositeMaxi(){
	return m_luminositeMaxi;
}

int Luminosite :: getLuminositeMini(){
	return m_luminositeMini;
}

Luminosite::~Luminosite() {
	// TODO Auto-generated destructor stub
}

