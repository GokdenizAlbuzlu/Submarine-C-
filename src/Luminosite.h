/*
 * Luminosite.h
 *
 *  Created on: 18 sept. 2021
 *      Author: gokde
 */

#ifndef LUMINOSITE_H_
#define LUMINOSITE_H_
#include "Sensor.h"

class Luminosite : public Sensor<bool>{		//Pour le rendu final la luminosité est de type bool
private :
	int m_luminositeMaxi;
	int m_luminositeMini;
public:
	//forme canonique de Coplien
	Luminosite();	//constructeur
	Luminosite(const Luminosite & autre_p);//constructeur de recopie
	Luminosite &operator=(const Luminosite &);	//opérateur d'affectation
	virtual ~Luminosite();		//destructeur
/***
 * getters qui permettent d'acceder aux variable luminositeMaxi et luminositeMini
 *
 */
	int getLuminositeMaxi();
	int getLuminositeMini();


};

#endif /* LUMINOSITE_H_ */
