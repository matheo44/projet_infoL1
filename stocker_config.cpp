#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// creation du type configuration :)

struct Configuration{
	static const int N = 10;
	string fonction;
	int nb_parametre_chaine, nb_parametre_entier;// initialiser !!
	
	string cle_entier[N];
	string cle_chaine[N];
	
	int valeur_entier[N];
	string valeur_chaine[N];
	// vive les ratons laveurs 

	
};

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
	
	int main(int argc, char **argv){
	
	if (argc < 2) { // affiche une erreur s'il n'y a pas suffisamment d'arguments
     cerr << "Manque l'argument fichier config, veuillez réexecuter le programme avec un fichier .txt en argument impérativement";
    }

	Configuration config;
     
     stocker_config(argv[1], config );
	cout << config.fonction << endl;
	cout << config.valeur_entier[0] << endl;

}
