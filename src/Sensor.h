/*
 * Sensor.h
 *
 *  Created on: 18 sept. 2021
 *      Author: gokde
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>
#include <string>


template<class T>			//Sensor est une classe qui utilise Template
class Sensor {

private :
	T m_max;
	T m_min;
	T m_value;

protected:
		/***
		 * T aleaGenVal() fonction Template qui permet de génerer un entier aléatoire ou un réel aléatoire ou bien un booléen aléatoire pour la partie finale du projet
		 * peut retourner un entier,réel ou booléen(en fonction du capteur) compris entre un minimum et maximum
		 */

		T aleaGenVal(){

		if(std::is_same<T,int>::value){						//si T est de type entier alors
			m_value = rand()%(static_cast<int>(m_max)-static_cast<int>(m_min)+1) + static_cast<int>(m_min);
			return m_value;
		}

		if(std::is_same<T,bool>::value){					//Si T est de type booléen alors
			m_value = rand()%(static_cast<bool>(m_max)-static_cast<bool>(m_min) + 1) +static_cast<bool> (m_min);
			if(m_value==1){
				m_value=true;
			}
			if(m_value==0){
				m_value=false;
			}
			return m_value;
		}

		if(std::is_same<T,float>::value){					//si T est de type float alors
			m_value=(m_min + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(m_max-m_min))));
			return m_value;
		}
	}

public:
//forme canonique de coplien
	Sensor(){						//constructeur par défaut
		m_max=0;
		m_min=0;
		m_value=0;
	}

	Sensor(const Sensor & autre_p){	//constructeur de recopie
		m_max=autre_p.m_max;
		m_min=autre_p.m_min;
		m_value=autre_p.m_value;
	}

	Sensor &operator=(const Sensor &autre_p){	//operateur d'affectation
		m_max=autre_p.m_max;
		m_min=autre_p.m_min;
		m_value=autre_p.m_value;
			return *this;
	}
	virtual ~Sensor(){					//Destructeur
	}

/***
 * T getData() permet d'accéder à la fonction aleaGenVal qui est déclaré en protected
 * retourne la fonction T aleaGenVal
 */

	T getData(){
	return aleaGenVal();
	}
/***
 * les getters et les setters pour les 3 variables (m_max,m_min,m_value) de la classe Sensor
 * ces fonctions permettent d'acceder ou de modifier les valeurs des variables m_max,m_min et m_value
 */

	void setValue(T value_p){
	m_value=value_p;
	}

	T getValue(){
		return m_value;
	}

	T getMax(){

			return m_max;
	}

	T getMin(){
			return m_min;
	}

	void setMax(T max_p){
			m_max=max_p;
	}
	void setMin(T min_p){
				m_min=min_p;
	}
};

#endif /* SENSOR_H_ */
