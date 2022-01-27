/*
 * Temperature.h
 *
 *  Created on: 18 sept. 2021
 *      Author: gokde
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_
#include "Sensor.h"

class Temperature : public Sensor<float> {
private:
	float m_temperatureMaxiCelsius;	//pour le rendu final les valeurs temperatures seront de type float
	float m_temperatureMiniCelsius;


public:
	//forme Canonique de Coplien
	Temperature();	//constructeur
	Temperature(const Temperature & autre_p);	//constructeur de recopie
	Temperature & operator=(const Temperature& autre_p);	//opérateur d'affectation
	virtual ~Temperature(); //destructeur

	float getTemperatureMaxiCelsius(); //les getters pour les variable m_temperatureMaxiCelsius et m_temperatrueMiniCelsius
	float getTemperatureMiniCelsius();



};

#endif /* TEMPERATURE_H_ */
