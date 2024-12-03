#include <iostream>
#include <fstream>

using namespace std;


struct Configuration {
	static const int N = 10;
	string fonction;
	int nb_parametre_entier, nb_parametre_chaine;
	int valeur_entier[N];
	string valeur_chaine[N];
	string cle_entier[N], cle_chaine[N];
};


//-----------------------------------------------
// Fonction permettant de récupérer l'indice d'une clé (clé des entiers) dans un tableau en le parcourant.
// Entrée : une configuration et une clé
// Sortie : l'indice de la clé
// Préconditions : le tableau ne doit pas contenir 2 fois la même clé
// La fonction ne fonctionne qu'avec le tableau de clé chaine

int recup_ind_cle_entier(Configuration config, string nom_cle){
    //Variable
    int i;
    
    //Début
   	for (i=0 ; i<config.nb_parametre_entier ; ++i){
   		if (config.cle_entier[i] == nom_cle){
   			return i;
   		}
   	}
    return -1;
}

//-----------------------------------------------
// Fonction permettant de récuprérer l'indice d'une clé (clé des chaines) dans un tableau en le parcourant.
// Entrée : une configuration et une clé
// Sortie : l'indice de la clé
// Préconditions : le tableau ne doit pas contenir 2 fois la même clé
// La fonction ne fonctionne qu'avec le tableau de clé chaine

int recup_ind_cle_chaine(Configuration config, string nom_cle){
    //Variable
    int i;
    
    //Début
   	for (i=0 ; i<config.nb_parametre_chaine ; ++i){
   		if (config.cle_chaine[i] == nom_cle){
   			return i;
   		}
   	}
    return -1;
}

//-----------------------------------------------
// Fontion rendant un entier associée à une clé
// Entrée : une configuration et le nom d'une clé
// Sortie : La valeur associée à la clé
// Cette fonction utlise la fonction de recherche d'indice de clé

int recup_valeur_entier(Configuration config, string nom_cle){
   //Début
   return config.valeur_entier[recup_ind_cle_entier(config, nom_cle)];
 }
 
//-----------------------------------------------
// Fontion rendant une chaine associée à une clé
// Entrée : une configuration et le nom d'une clé
// Sortie : La valeur associée à la clé
// Cette fontction utlise la fonction de recherche d'indice de clé

 string recup_valeur_chaine(Configuration config, string nom_cle){
   //Début
   return config.valeur_chaine[recup_ind_cle_chaine(config, nom_cle)];
 }

//-----------------------------------------------
// Retourne une configuration avec la valeur de la clé "nom_cle" possède la valeur "nouvelle_valeur" (pour les clés de type entier)
Configuration modif_valeur_entier(Configuration& config, string nom_cle, int nouvelle_valeur) {
    //variable
    int index_cle = -1;
    
    //debut
    index_cle = recup_ind_cle_entier(config, nom_cle);
    config.valeur_entier[index_cle] = nouvelle_valeur;
    return config;
}

//-----------------------------------------------
// Retourne une configuration avec la valeur de la clé "nom_cle" possède la valeur "nouvelle_valeur" (pour les clés de type chaine)
Configuration modif_valeur_chaine(Configuration& config, string nom_cle, string nouvelle_valeur) {
    //variable
    int index_cle = -1;
    
    //debut
    index_cle = recup_ind_cle_chaine(config, nom_cle);
    config.valeur_chaine[index_cle] = nouvelle_valeur;
    //recup_valeur_entier(config,recup_valeur_chaine(co
    return config;
}

//-----------------------------------------------
// Lance la fonction compris dans le fichier configuration.
void appel_fonction(Configuration& config) {
    //debut
    if (config.fonction == "recup_valeur_entier") {
   	 // Afin d'exécuter recup_valeur_entier() le fichier config doit avoir une cle chaine nommee "S_nom_cle_a_recup"
   	 recup_valeur_entier(config, recup_valeur_chaine(config, "S_nom_cle_a_recup"));
   	 
    } else if (config.fonction == "recup_valeur_chaine") {
   	 // Afin d'exécuter recup_valeur_chaine() le fichier config doit avoir une cle chaine nommee "S_nom_cle_a_recup"
   	 recup_valeur_chaine(config, recup_valeur_chaine(config, "S_nom_cle_a_recup"));
   	 
    } else if (config.fonction == "modif_valeur_entier") {
   	 // Afin d'exécuter modif_valeur_entier() le fichier config doit avoir une cle chaine nommee "S_nom_cle_a_modif" et une clé entier nommee "E_nouvelle_valeur"
modif_valeur_entier(config, recup_valeur_chaine(config, "S_nom_cle_a_modif"), recup_valeur_entier(config, "E_nouvelle_valeur"));
   	 
    } else if (config.fonction == "modif_valeur_chaine") {
   	 // Afin d'exécuter modif_valeur_chaine() le fichier config doit avoir 2 cles chaine nommee respectivement "S_nom_cle_a_modif" et "S_nouvelle_valeur"
modif_valeur_chaine(config, recup_valeur_chaine(config, "S_nom_cle_a_modif"), recup_valeur_chaine(config, "S_nouvelle_valeur"));
   	 
    }
}


struct clee_valeur{
	string clee,valeur;
};

	
void stocker_config(string nom_fichier_config, Configuration& config){
	
	config.nb_parametre_chaine = 0;
	config.nb_parametre_entier = 0;
	//ouverture du fichier 
	fstream fichier_config;
	fichier_config.open(nom_fichier_config, ios::in); 
    string ignore;
	if(!fichier_config.is_open()){
		cerr << "Le fichier n'a pas pu être ouvert ): ... Veuillez réexecuter le programme avec un fichier txt impérativement ";
		return;
	}

		fichier_config >> ignore; // a refactoriser func pas tjrs 1ere
		fichier_config >> ignore;
		fichier_config >> config.fonction;

		clee_valeur c_v;

	while( fichier_config.good()){

		
		
		if( c_v.clee == "S_img_input"){  // test sur 1er char
			
			config.cle_chaine[config.nb_parametre_chaine] = c_v.clee;
			
			config.valeur_chaine[config.nb_parametre_chaine] = c_v.valeur;
			config.nb_parametre_chaine = config.nb_parametre_chaine + 1;
			
		}
		else if( c_v.clee == "E_nbsteps"){	
						string str = c_v.valeur;
			
			config.cle_entier[config.nb_parametre_entier] = c_v.clee;
			config.valeur_entier[config.nb_parametre_entier] = stoi(str);
			config.nb_parametre_entier = config.nb_parametre_entier + 1;
			
			}
	
		
		fichier_config >> c_v.clee;
		fichier_config >> ignore;
		fichier_config >> c_v.valeur;
	}
	}




