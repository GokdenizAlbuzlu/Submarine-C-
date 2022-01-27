/*
 * Humidite.h
 *
 *  Created on: 18 sept. 2021
 *      Author: gokde
 */

#ifndef HUMIDITE_H_
#define HUMIDITE_H_
#include "Sensor.h"

//l'humidite est pourcentage pour le rendu Intermediaire.
class Humidite : public Sensor<float>{
private:

	float m_humiditeMaxi;		//pour le rendu final humidite est de type float
	float m_humiditeMini;
public:
	Humidite();
	Humidite(const Humidite & autre_p);
	Humidite &operator=(const Humidite &);
	virtual ~Humidite();

	float getHumiditeMaxi();
	float getHumiditeMini();


};

#endif /* HUMIDITE_H_ */
