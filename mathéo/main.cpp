#include <iostream>
#include "librairie_config.h"
#include "librairie_fonc_img.h"
#include "png_io.h"

// on prend les indices au lieu de chercher la clee dans le tableau de clee, de récupérer son indice puis d'aller cherche la donner avec cette un d'indice

int main(int argc, char **argv){
	
	if (argc < 2) { // affiche une erreur s'il n'y a pas suffisamment d'arguments
     cerr << "Manque l'argument fichier config, veuillez réexecuter le programme avec un fichier .txt en argument impérativement";
     return -1;
  }
	Configuration config;
	int nb_images,ratio,delay,loop;
	string nom_img_1,nom_img_2;
	
    stocker_config(argv[1], config );
    
	cout << "fonction appeler: " << config.fonction << endl;
	cout << "nom de l'image 1 : " << config.valeur_chaine[0] << endl;
	cout << "nom de l'image 2 : " << config.valeur_chaine[1] << endl;
	cout << "nombre d'images intermédiaires: " << config.valeur_entier[0] << endl;
	cout << "delay entre images: " << config.valeur_entier[1] << endl;
	cout << "nombre de loop: " << config.valeur_entier[2] << endl;
	
	
	nb_images = config.valeur_entier[0];
	nom_img_1 = config.valeur_chaine[0];
	nom_img_2 = config.valeur_chaine[1];
	delay = config.valeur_entier[1];
	loop = config.valeur_entier[2];
	
	//taux de la décrémentation des valeurs des pixels  
	
	ratio = 255 / nb_images;
	for (int cpt = 1 ; cpt <= nb_images ; cpt++){
		//assombrir_image(charger_PNG(nom_img_1), ratio * cpt,cpt);
		//bruiter_image(charger_PNG(nom_img_1), cpt);
		//transi_avec_fondu_image(charger_PNG(nom_img_1), charger_PNG(nom_img_2), ratio * cpt,cpt);
		
	}
	bruiter_image(charger_PNG(nom_img_1), 2);
	
	generer_GIF("./result/", nom_img_1, 1,nb_images,delay,loop);
}


