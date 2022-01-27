/*
 * Server.h
 *
 *  Created on: 18 sept. 2021
 *      Author: gokde
 */

#ifndef SERVER_H_
#define SERVER_H_
#include <iostream>
#include <fstream>
#include "Sensor.h"
#include "Temperature.h"
#include "Pression.h"
#include "Server.h"
#include "Luminosite.h"
#include "Humidite.h"
#include <type_traits>
#include <cstdint>


class Server {
private :

	bool m_consolActivation;
	bool m_logActivation;

	/***
	 * void consolWrite pour la partie finale prend en param�tre 1 valeur template, et un entier id (qui permet de diff�rencier humidit� et la temp�rature qui sont de m�me type)
	 * elle permet d'�crire les valeurs des 4 capteurs sur la console de l'utilisateur.
	 */

		template<class T>
		void consolWrite(T valeur_p,int id_p){
			time_t now = time(0);			//pour pouvoir utiliser le temps du syst�me.
			char* dt = ctime(&now);
			if(std::is_same<T, int>::value){
				std::cout << "La pression dans le sous marin est : " <<valeur_p<<" Pascal ------> "<<dt <<"\n"<<std::endl;
			}

			if((std::is_same<T,float>::value)&&(id_p==1)){
				std::cout << "La temperature du sous marin est : " <<valeur_p<<" �C -----> "<<dt <<"\n"<<std::endl;
			}

			if((std::is_same<T,float>::value) && (id_p==4)){
				std::cout<<"L'humidit� dans le sous marin est : "<<valeur_p<<" % -----> "<<dt<<"\n"<<std::endl;
			}

			if(std::is_same<T,bool>::value){
				 std::cout << std::boolalpha<<std::endl;
				 std::cout<<"la pr�sence du lumi�re est : "<<valeur_p<<" -----> "<<dt<<"\n"<<std::endl;
			}
		}

		/****
		 * void fileWrite pour la partie finale du projet qui prend en param�tre 1 valeur template et un entier id (qui permet de diff�rencier humidit� et la temp�rature qui sont de m�me type)
		 * elle permet d'�crire ces donn�es sur 4 fichiers .txt qui sont cr�e dans le dossier C:\Support_Projet_AP4A
		 */

		template<class T>
		void fileWrite(T valeur_p,int id_p){
			time_t now = time(0);			//pour pouvoir utiliser le temps du syst�me.
			char* dt = ctime(&now);

			if(std::is_same<T, int>::value){
				std::string const Pression("C:/Support_Projet_AP4A/Pression.txt");
				std::ofstream msgLog1(Pression.c_str(),std::ios::app);
				if(msgLog1){
					msgLog1 << "La pression � l'int�rieur du sous marin : "<<valeur_p<<" Pascal ------> "<<dt <<"\n"<<std::endl;
								}
					}

			if((std::is_same<T,float>::value)&&(id_p==1)){		//on utilise id_p pour diff�rencier l'humidit� et la temperature qui sont de m�me type
				std::string const Temperature("C:/Support_Projet_AP4A/Temperature.txt");
				std::ofstream msgLog2(Temperature.c_str(),std::ios::app);
				if(msgLog2){
					msgLog2 << "La temperature � l'int�rieur du sous marin : "<<valeur_p<<" �C ------> "<<dt <<"\n"<<std::endl;
								}
					}

			if(std::is_same<T,bool>::value){
				std::string const Luminosite("C:/Support_Projet_AP4A/Luminosite.txt");
				std::ofstream msgLog3(Luminosite.c_str(),std::ios::app);
				if(msgLog3){
					msgLog3 << "Luminosit� � l'int�rieur du sous marin: "<< valeur_p<<" ------> "<<dt <<"\n"<<std::endl;
						}
			}

			if((std::is_same<T,float>::value)&&(id_p==4)){		//on utilise id_p pour diff�rencier l'humidit� et la temperature qui sont de m�me type
				std::string const Temperature("C:/Support_Projet_AP4A/Humidite.txt");
				std::ofstream msgLog4(Temperature.c_str(),std::ios::app);
				if(msgLog4){
					msgLog4<< "L'humidit� � l'int�rieur du sous marin : "<<valeur_p<<"------> "<<dt <<"\n"<<std::endl;
					}
						}

			}


public:
//forme canonique de coplien
	Server(); 							//constructeur par d�faut
	Server(const Server &autre_p);		//constructeur de recopie
	Server &operator=(const Server&);	//operateur d'affectation
	virtual ~Server();					//Destructeur


	/***
	 *Les getters et les setters qui permettent d'acc�der aux 2 variable consolActivation et logActivation qui sont d�clar�s en private
	 * permettent de fixer ou de recuperer les valeurs de consolActivation et et logActivation
	 */
	bool getconsolActivation();
	bool getlogActivation();
	void setconsolActivation(bool consolActivation_p);
	void setlogActivation(bool loginActivation_p);

	/***
		 * dataReceive qui prend en param�tre 1 valeur Template, un serveur sur le quel les donn�es seront transmises et un entier id qui permet de diff�rencier humidit� et temeprature qui sont de m�me type)
		 * cette fonction est utilis�e dans le scheduler du programme, elle permet de transf�rer les donn�es r�cup�r�es sur le serveur.
		 * permet de lancer la fonction consolWrite et/ou fileWrite
		 */
	template<class T>
	void dataReceive(T valeur_p,Server&server_p,int id_p){
		consolWrite(valeur_p,id_p);
		if(server_p.m_logActivation==true){
			fileWrite(valeur_p,id_p);
			}
	}

};

#endif /* SERVER_H_ */
