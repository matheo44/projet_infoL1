#include <iostream>
#include "librairie_config.h"
#include "librairie_fonc_img.h"
#include "png_io.h"




int main(int argc, char **argv){
	
	if (argc < 2) { // affiche une erreur s'il n'y a pas suffisamment d'arguments
     cerr << "Manque l'argument fichier config, veuillez réexecuter le programme avec un fichier .txt en argument impérativement";
     return -1;
  }
	Configuration config;
	int nb_images,ratio,delay,loop,taux_floutage;
	
	int rouge,vert,bleu, intervalle;
	
	string fonction, nom_img_1,nom_img_2;
	
    stocker_config(argv[1], config );
    
    fonction = config.fonction;
    nb_images = config.valeur_entier[0];
	nom_img_1 = config.valeur_chaine[0];
	nom_img_2 = config.valeur_chaine[1];
	delay = config.valeur_entier[1];
	loop = config.valeur_entier[2];
	taux_floutage = config.valeur_entier[2];
	
	rouge = config.valeur_entier[3];
	vert = config.valeur_entier[4];
	bleu = config.valeur_entier[5];
    intervalle = config.valeur_entier[6];
    
	cout << "fonction appeler: " << fonction << endl;
	cout << "nom de l'image 1 : " << nom_img_1 << endl;
	cout << "nom de l'image 2 : " << nom_img_2 << endl;
	cout << "nombre d'images intermédiaires: " << nb_images << endl;
	cout << "delai entre images: " << delay << endl;
	cout << "nombre de loop: " << loop << endl;
	cout << "taux de floutage entre images" << taux_floutage;
	
	if(fonction == "fondu_au_noir"){
			ratio = 255 / nb_images;
		for (int cpt = 1 ; cpt <= nb_images ; cpt++){
			assombrir_image(charger_PNG(nom_img_1), ratio * cpt,cpt);
		
		} 
		generer_GIF("./result_img/", "./result_gif/"+nom_img_1+'_'+fonction, 1,nb_images,delay,loop); 
	}
	else if(fonction == "bruiter"){
		
		for (int cpt = 1 ; cpt <= nb_images ; cpt++){
			bruiter_image(charger_PNG(nom_img_1), cpt);
		
		}
		generer_GIF("./result_img/", "./result_gif/"+nom_img_1+'_'+fonction, 1,nb_images,delay,loop); 
		
	}
	else if( fonction == "flouter"){
		
		gif_flouter_image(charger_PNG(nom_img_1), nb_images, taux_floutage);
	}
	else if( fonction == "masquer_persienne"){
		masquer_persienne(charger_PNG(nom_img_1), rouge,vert,bleu, intervalle);
	}
	else if( fonction == "masquer_classique"){
		masquer_classique(charger_PNG(nom_img_1), rouge,vert,bleu);
	}
	else if( fonction == "transition"){
		Image_PNG img_1;
		img_1 = charger_PNG(nom_img_1);
		decaler_image(img_1, charger_PNG(nom_img_2), nb_images);
		
		generer_GIF("./result_img/", "./result_gif/"+nom_img_2+'_'+fonction, 1,nb_images,delay,loop);
	}

}
