/*
 * Pression.h
 *
 *  Created on: 18 sept. 2021
 *      Author: gokde
 */

#ifndef PRESSION_H_
#define PRESSION_H_
#include "Sensor.h"

class Pression : public Sensor<int> {

private :

	int m_pressionMaxiPascal;		//les pressions sont de type int pour le projet final
	int m_pressionMiniPascal;
public:
	//forme canonique de Coplien
	Pression();	//constructeur
	Pression(const Pression & autre_p);	//constructeur par recopie
	Pression &operator=(const Pression &);	//opérateur d'affectation
	virtual ~Pression();		//destructeur

	int getPressionMaxiPascal();
	int getPressionMiniPascal();


};

#endif /* PRESSION_H_ */
