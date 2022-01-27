/*
 * Server.cpp
 *
 *  Created on: 18 sept. 2021
 *      Author: gokde
 */

#include "Server.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <type_traits>

Server::Server():m_consolActivation(false),m_logActivation(false) {		//constructeur par défaut pour la classe Server, on attribue par défaut la valeur false pour les 2 variables
}
Server::Server(const Server &autre_p){
	m_consolActivation=autre_p.m_consolActivation;
	m_logActivation=autre_p.m_logActivation;
}

Server & Server :: operator=(const Server &autre_p){
	m_consolActivation=autre_p.m_consolActivation;
	m_logActivation=autre_p.m_logActivation;
	return *this;
}
bool Server :: getconsolActivation(){
	return m_consolActivation;
}
bool Server :: getlogActivation(){
	return m_logActivation;
}
void Server :: setconsolActivation(bool consolActivation_p){
	m_consolActivation= consolActivation_p;
}
void Server :: setlogActivation(bool loginActivation_p){
	m_logActivation= loginActivation_p;
}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

