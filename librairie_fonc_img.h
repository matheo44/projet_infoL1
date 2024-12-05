#include <iostream>
#include <fstream>
#include "png_io.h"
using namespace std;


// librairie assombrir : 

//-----------------------------------------------
// Fonction permettant d'assombrir un pixel donné par une valeur donné.
// Entrées : un pixel (type RVB) et la valeur d'assombrissement (type entier)
// Sortie : le pixel assombrit (type RVB)
// Préconditions : valeur_assombrissement > 0


void assombrir_pixel(RVB& pixel, int valeur_assombrissement){

	
    if (pixel.rouge > valeur_assombrissement) {
   	 pixel.rouge = static_cast<Composante>(pixel.rouge - valeur_assombrissement);
    } else {
   	 pixel.rouge = 0;
    }
    
    if (pixel.vert > valeur_assombrissement) {
   	 pixel.vert = static_cast<Composante>(pixel.vert - valeur_assombrissement);
    } else {
   	 pixel.vert = 0;
    }
    
    if (pixel.bleu > valeur_assombrissement) {
   	 pixel.bleu = static_cast<Composante>(pixel.bleu - valeur_assombrissement);
    } else {
   	 pixel.bleu = 0;
    }
}


//-----------------------------------------------
//assombrir image

void assombrir_image(Image_PNG img, int val_assomb, int etape){
	//Variables
	int i, j;
	//Début
	for (i = 0 ; i < static_cast<int>(img.largeur) ; ++i){
    		for (j = 0 ; j < static_cast<int>(img.hauteur) ; ++j){
        		assombrir_pixel(img.pixels[j][i], val_assomb);
    	}
	}
	sauver_PNG("./result/"+std::to_string(etape)+".png", img);  
	

}
//----------------------------------------------- Mathéo 05/12
//bruiter image

void bruiter_pixel(RVB& pixel){

	int random_number;
	random_number = rand() % 100- 9;
	
    if (pixel.rouge > pixel.rouge - random_number) {
   	 pixel.rouge = static_cast<Composante>(pixel.rouge - random_number);
    } 
    
    if (pixel.vert > pixel.vert - random_number) {
   	 pixel.vert = static_cast<Composante>(pixel.vert - random_number);
    } 
    
    if (pixel.bleu > pixel.bleu - random_number) {
   	 pixel.bleu = static_cast<Composante>(pixel.bleu - random_number);
    } 
    
}



void bruiter_image(Image_PNG img, int etape){
	//Variables
	int i, j;
	//Début
	for (i = 0 ; i < static_cast<int>(img.largeur) ; ++i){
    		for (j = 0 ; j < static_cast<int>(img.hauteur) ; ++j){
        		bruiter_pixel(img.pixels[j][i]);
    	}
	}
	sauver_PNG("./result/"+std::to_string(etape)+".png", img);  
	

}
