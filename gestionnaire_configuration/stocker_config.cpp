// ROLE de stocker_config.cpp : 
// 								- Définir la struct Configuration 
// 								- prendre les données du fichier de configuration qui devra être un argument lors de l'execution du programe
//								- parser le ficher text pour que les données soit dans notre struct 
// 								- La configuration sera donc maintenant disponible par tout sous programe demandant la configuration

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Configuration{
	
	string fonction;		// effet sur l'image voulue (exemple fondu au noir )
	string S_img_input;     // chemin relatif ou absolue de l'image 
	int E_nbsteps;			// nombre de image pour une animation
	
};

// la struct clee_valeur nous aidera à parser deux à deux les valeurs du flux fichier config
struct clee_valeur{
	string clee,valeur;
};


void stocker_config(string nom_fichier_config, Configuration& config){

	//ouverture du fichier 
	fstream fichier_config;
	fichier_config.open(nom_fichier_config, ios::in); 

	if(!fichier_config.is_open()){
		cerr << "Le fichier n'a pas pu être ouvert ): ... Veuillez réexecuter le programme avec un fichier txt impérativement ";
		return;
	}

	// afectation de toutes les données disponibles du fichier config
	
	clee_valeur clee_valeur;

	while( fichier_config.good()){

		fichier_config >> clee_valeur.clee;
		fichier_config >> clee_valeur.valeur;

		if( clee_valeur.clee == "fonction" ){
			config.fonction = clee_valeur.valeur;
		}
		else if( clee_valeur.clee == "S_img_input"){
			config.S_img_input = clee_valeur.valeur;
		}
		else if( clee_valeur.clee == "E_nbsteps"){			// /!\ attention il faut convertir le nombre chaine -> entier
			string str = clee_valeur.valeur;

			config.E_nbsteps = stoi(str); 				    //la fonction stoi convertie une chaine en entier
		}
	}
}

int main(int argc, char **argv){
	
	if (argc < 2) { // affiche une erreur s'il n'y a pas suffisamment d'arguments
     cerr << "Manque l'argument fichier config, veuillez réexecuter le programme avec un fichier .txt en argument impérativement";
    }

	Configuration config;
     
     stocker_config(argv[1], config );
	cout << config.fonction << endl;
	cout << config.S_img_input << endl;
	cout << config.E_nbsteps << endl;
}


// Amélioration possible:
//						 - la vérification de la véraciter des donnes.