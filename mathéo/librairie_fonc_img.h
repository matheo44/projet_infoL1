#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
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

//-----------------------
// transition d'image par le fondu au noir

void transition_pixel(RVB& pixel_img1, RVB pixel_img2,int valeur_assombrissement){

	
    if (pixel_img1.rouge > valeur_assombrissement) {
   	 pixel_img1.rouge = static_cast<Composante>(pixel_img1.rouge - valeur_assombrissement);
    } else {
   	 pixel_img1.rouge = pixel_img2.rouge;
    }
    
    if (pixel_img1.vert > valeur_assombrissement) {
   	 pixel_img1.vert = static_cast<Composante>(pixel_img1.vert - valeur_assombrissement);
    } else {
   	 pixel_img1.vert = pixel_img2.vert;
    }
    
    if (pixel_img1.bleu > valeur_assombrissement) {
   	 pixel_img1.bleu = static_cast<Composante>(pixel_img1.bleu - valeur_assombrissement);
    } else {
   	 pixel_img1.bleu = pixel_img2.bleu;
    }
}

void transi_avec_fondu_image(Image_PNG img1, Image_PNG img2, int val_assomb, int etape){
	//Variables
	int ligne, colone;
	//Début
	for (ligne = 0 ; ligne < static_cast<int>(img1.largeur) ; ++ligne){
    		for (colone = 0 ; colone < static_cast<int>(img1.hauteur) ; ++colone){
        		transition_pixel(img1.pixels[colone][ligne], img2.pixels[colone][ligne],val_assomb);
    	}
	}
	sauver_PNG("./result/"+std::to_string(etape)+".png", img1);  
	

}


//-----------------------------------------------
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
	int ligne, colone;
	//Début
	for (ligne = 0 ; ligne < static_cast<int>(img.largeur) ; ++ligne){
    		for (colone = 0 ; colone < static_cast<int>(img.hauteur) ; ++colone){
        		bruiter_pixel(img.pixels[ligne][colone]);
    	}
	}
	sauver_PNG("./result/"+std::to_string(etape)+".png", img);  
	

}


//-----------------------------------------------
//transition image avec bruitage

void transition_pixel(RVB& pixel_img1, RVB pixel_img2,ratio){
	
	if (pixel_img1.rouge > pixel_img2.rouge) {
		
   	 pixel.rouge = static_cast<Composante>(pixel.rouge + ratio);
   	 
    }else if(pixel_img1.rouge < pixel_img2.rouge){
		pixel.rouge = static_cast<Composante>(pixel.rouge - ratio);
	}else {
   	 pixel_img1.rouge = pixel_img2.rouge;
    }
    
    if (pixel_img1.vert > pixel_img2.vert) {
		
   	 pixel.vert = static_cast<Composante>(pixel.vert + ratio);
   	 
    }else if(pixel_img1.vert < pixel_img2.vert){
		pixel.vert = static_cast<Composante>(pixel.vert - ratio);
	}else {
   	 pixel_img1.vert = pixel_img2.vert;
    }
    
    if (pixel_img1.bleu > pixel_img2.bleu) {
		
   	 pixel.bleu = static_cast<Composante>(pixel.bleu + ratio);
   	 
    }else if(pixel_img1.bleu < pixel_img2.bleu){
		pixel.bleu = static_cast<Composante>(pixel.bleu - ratio);
	}else {
   	 pixel_img1.bleu = pixel_img2.bleu;
    }
    
    
	}


void transi_bruiter_image(Image_PNG& img1, Image_PNG img1, int etapes){
	//Variables
	int ligne, colone ratio;
	//Début
	ratio = 255/etapes;
	
	for (ligne = 0 ; ligne < static_cast<int>(img1.largeur) ; ++ligne){
    		for (colone = 0 ; colone < static_cast<int>(img1.hauteur) ; ++colone){
        		bruiter_pixel(img1.pixels[ligne][colone]);
    	}
	}
	sauver_PNG("./result/1.png", img1);  
	
	for( int etape = 1 ; cpt <= etapes ; etape++){
		
		for (ligne = 0 ; ligne < static_cast<int>(img.largeur) ; ++ligne){
    		for (colone = 0 ; colone < static_cast<int>(img.hauteur) ; ++colone){
        		transition_pixel(img1.pixels[ligne][colone],img2.pixels[ligne][colone],ratio);
    	}
	}
	sauver_PNG("./result/"+std::to_string(etape)+".png", img1); 
	}
	

}











