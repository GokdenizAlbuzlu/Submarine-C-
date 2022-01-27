/*
 * Temperature.cpp
 *
 *  Created on: 18 sept. 2021
 *      Author: gokde
 */

#include "Temperature.h"
#include <iostream>

Temperature :: Temperature(): m_temperatureMaxiCelsius(26),m_temperatureMiniCelsius(18){
}

Temperature :: Temperature(const Temperature & autre_p){
	m_temperatureMaxiCelsius=autre_p.m_temperatureMaxiCelsius;
	m_temperatureMiniCelsius=autre_p.m_temperatureMiniCelsius;
}

Temperature & Temperature :: operator=(const Temperature & autre_p){
	m_temperatureMaxiCelsius=autre_p.m_temperatureMaxiCelsius;
	m_temperatureMiniCelsius=autre_p.m_temperatureMiniCelsius;
	return *this;
}

float Temperature :: getTemperatureMaxiCelsius(){
	return m_temperatureMaxiCelsius;
}

float Temperature :: getTemperatureMiniCelsius(){
	return m_temperatureMiniCelsius;
}

Temperature::~Temperature() {
	// TODO Auto-generated destructor stub
}



