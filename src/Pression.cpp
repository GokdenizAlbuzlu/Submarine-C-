/*
 * Pression.cpp
 *
 *  Created on: 18 sept. 2021
 *      Author: gokde
 */

#include "Pression.h"

Pression::Pression(): m_pressionMaxiPascal(105000),m_pressionMiniPascal(100000) {
	// TODO Auto-generated constructor stub

}

Pression :: Pression(const Pression & autre_p){
	m_pressionMaxiPascal=autre_p.m_pressionMaxiPascal;
	m_pressionMiniPascal=autre_p.m_pressionMiniPascal;
}

Pression & Pression :: operator=(const Pression & autre_p){
	m_pressionMaxiPascal=autre_p.m_pressionMaxiPascal;
	m_pressionMiniPascal=autre_p.m_pressionMiniPascal;
	return *this;
}

int Pression :: getPressionMaxiPascal(){
	return m_pressionMaxiPascal;
}

int Pression :: getPressionMiniPascal(){
	return m_pressionMiniPascal;
}

Pression::~Pression() {
	// TODO Auto-generated destructor stub
}


