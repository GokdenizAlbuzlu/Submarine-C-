# Submarine-C++



## Bienvenue sur Le readMe du projet final

### **Fichier InterfaceUtilisateur.cpp**

* Pour lancer le programme il faut utiliser le fichier __InterfaceUtilisateur.cpp__ car c'est dans cette fichier que se trouve le main()

* On propose à l'utilisateur s'il souhaite d'écrire sur le console et/ou sur des fichiers logs (.txt)

* Un fichier nommée C:\Support_Projet_AP4A est crée avec l'accord de l'utilisateur.

* On demande ensuite à l'utilisateur de fournir la durée totale de fonctionnement du programme ainsi que les temps d'intervalles pour __chaque type de capteurs__


### **Classe Server**

* La Classe server propose 3 fonctions Template qui vont nous servir d'écrire sur le console et sur les fichiers log

* Dans les fonctions fileWrite et consolWrite la fonction is_same<T,type> a été fortement utilisé pour pouvoir personnaliser la sortie de chaque capteurs (unité,nom..) 

* les fichiers log sont crées de manière automatique


### **Classe Sensor**

* La classe Sensor est une classe de forme **Template**. de ce fait elle ne possède pas un fichier d'implémentation (.cpp).C'est à dire que les fonctions sont définies dans le fichier Sensor.h

* Dans la fonction aleaGenVal la fonction **is_same<T,type>** est utilisée pour faire la différence entre un nombre réel et un nombre entier.


### **Classe filles de Sensors (Temperature,Pression,Luminosité,Humidité)**

* **Ces 4 classes héritent de la classe Sensor**

* La **temperature retourne un réel** aléatoire compris entre 26°C et 18°C

* La **pression retorune un entier** aléatoire compris entre 105000 Pascal et 100000 Pascal

* L'**humidité retourne un réel** aléatoire compris entre 40% et 70%

* La **luminosité retourne un booléen**

### **Classe Scheduler**

* Utilise une fonction **TransmetFinal** qui récupère les données depuis la classe Sensor et les transmet dans un Serveur.

* des __variables locales de temps__ sont utilisé pour chaque type de capteur afin de retourner des valeurs a des temps d'intervalles différents.

* on fixe les bornes de notre fonction aleaGenVal en fonction de la première valeur générée. C'est ce qui permet d'obtenir des valeurs qui ne sont pas écartées.

* Un boucle While avec la durée globale (définie par l'utilisateur) du programme est utilisé. 




**ALBUZLU Gökdeniz**
