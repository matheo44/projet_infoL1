#include <iostream>
#include "librairie_config.h"
#include "librairie_fonc_img.h"
#include "png_io.h"

int main(int argc, char **argv){
	
	if (argc < 2) { // affiche une erreur s'il n'y a pas suffisamment d'arguments
     cerr << "Manque l'argument fichier config, veuillez réexecuter le programme avec un fichier .txt en argument impérativement";
     return -1;
  }
  // on creer une configuration qui recupere les informations du fichier config
	Configuration config;
	int nb_images,ratio;
     stocker_config(argv[1], config );
	cout << config.fonction << endl;
	cout << config.valeur_chaine[0] << endl;
	cout << config.valeur_entier[0] << endl;
	nb_images = config.valeur_entier[0];
	
	cout << charger_PNG(config.valeur_chaine[0]).hauteur << endl;
	//taux de la décrémentation des valeurs des pixels  
	ratio = 255 / nb_images;
	for (int cpt = 1 ; cpt <= nb_images ; cpt++){
		assombrir_image(charger_PNG(config.valeur_chaine[0]), ratio * cpt,cpt);
		
	}
	
	generer_GIF("./result/", "yo", 1,nb_images,5,5);
}


/*
TODO

 -renvoyer cpt le nom de d'image 
 -continuer genere gif : 
*/
