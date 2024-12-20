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
	sauver_PNG("./result_img/"+std::to_string(etape)+".png", img);  
	

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
	sauver_PNG("./result_img/"+std::to_string(etape)+".png", img1);  
	

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
	for (ligne = 0 ; ligne < static_cast<int>(img.hauteur) ; ++ligne){
    		for (colone = 0 ; colone < static_cast<int>(img.largeur) ; ++colone){
        		bruiter_pixel(img.pixels[ligne][colone]);
    	}
	}
	sauver_PNG("./result_img/"+std::to_string(etape)+".png", img);  
	

}

RVB recup_pixel_moyen(Image_PNG img, int pos_pixel_x, int pos_pixel_y, int puissance_floutage){
	//Variables
	int decalage_x, decalage_y, hauteur_img, largeur_img, pix_rouge, pix_vert, pix_bleu, quantite_obtenu, axe_x, axe_y;
	RVB pix_sortie;
	quantite_obtenu = 0;
	pix_rouge = 0;
	pix_vert = 0;
	pix_bleu = 0;
	hauteur_img = static_cast<int>(img.hauteur);
	largeur_img = static_cast<int>(img.largeur);
	//Début
	for (decalage_x = puissance_floutage*-1 ; decalage_x <= puissance_floutage ; ++decalage_x){
		for (decalage_y = puissance_floutage*-1 ; decalage_y <= puissance_floutage ; ++decalage_y){
			
			axe_x = pos_pixel_x + decalage_x;
			axe_y = pos_pixel_y + decalage_y;
			
			if (axe_x >= 0 and axe_y >= 0 and axe_x < largeur_img and axe_y < hauteur_img){
				
				pix_rouge += img.pixels[axe_y][axe_x].rouge;
				pix_vert += img.pixels[axe_y][axe_x].vert;
				pix_bleu += img.pixels[axe_y][axe_x].bleu;
				
				++quantite_obtenu;
			}
			
		}
	}
	if (quantite_obtenu == 0){ quantite_obtenu=1; }
	pix_sortie.rouge = static_cast<Composante>(pix_rouge/quantite_obtenu);
	pix_sortie.vert = static_cast<Composante>(pix_vert/quantite_obtenu);
	pix_sortie.bleu = static_cast<Composante>(pix_bleu/quantite_obtenu);
	return pix_sortie;
}


void flouter_image(Image_PNG& img, int puissance_floutage, int num_etape){
	//Variables
	int hauteur_img, largeur_img, num_colonne, num_ligne;
	Image_PNG copie_img = img;
	hauteur_img = static_cast<int>(img.hauteur);
	largeur_img = static_cast<int>(img.largeur);
	
	//Début
	for (num_ligne = 0 ; num_ligne < hauteur_img ; ++num_ligne){
		for (num_colonne = 0 ; num_colonne < largeur_img ; ++num_colonne){
			img.pixels[num_ligne][num_colonne] = recup_pixel_moyen(copie_img, num_colonne, num_ligne, puissance_floutage);
		}
	}
	sauver_PNG("./result_img/"+std::to_string(num_etape)+".png", img);
}

//-----------------------------------------------
//Programme qui appelle en boucle flouter_image, et en créé un gif. S'arrête au bout de "repetition" itérations.

void gif_flouter_image(Image_PNG img, int repetition, int puissance_floutage){
	//Variables
    int i;
    //Début
    sauver_PNG("./result_img/0.png", img);
    for (i = 0 ; i < repetition ; ++i){
		flouter_image(img, puissance_floutage, i+1);
	}
	generer_GIF("./result_img/", "./result_gif/flouter_image_result.gif", 0, repetition, 0, 0);
}

void changer_pixel(RVB& pixel, int rouge, int vert, int bleu){
	pixel.rouge = static_cast<Composante>(rouge);
	pixel.vert = static_cast<Composante>(vert);
	pixel.bleu = static_cast<Composante>(bleu);
}


//-----------------------------------------------
// Ajoute une ligne toutes les K lignes sur une image donnée.

void ajout_ligne_simultanee(Image_PNG& img, int num_etape, int K, int rouge, int vert, int bleu){
    //Variables
    int i, num_ligne;
    //Début
    for (num_ligne = 0 ; num_ligne < static_cast<int>(img.hauteur) ; ++num_ligne){
		if ((num_ligne % (K + 1)) == (K - num_etape)){
			for (i = 0 ; i < static_cast<int>(img.largeur) ; ++i){
				changer_pixel(img.pixels[num_ligne][i], rouge, vert, bleu);
			}
		}
	}
    sauver_PNG("./result_img/"+std::to_string(num_etape)+".png", img);  
}

//-----------------------------------------------
// Programme qui applique l'effet masque persien

void masquer_persienne(Image_PNG img, int rouge, int vert, int bleu, int K){
    //Variables
    int i;
    //Début
    for (i = 0 ; i <= K ; ++i){
		ajout_ligne_simultanee(img, i, K, rouge, vert, bleu);
	} 
	generer_GIF("./result_img/", "./result_gif/masquer_persienne_result.gif", 0, K, 0, 0);
}

void ajout_ligne_classique(Image_PNG& img, int num_ligne, int rouge, int vert, int bleu){
    //Variables
    int num_colonne;
    //Début
	for (num_colonne = 0 ; num_colonne < static_cast<int>(img.largeur) ; ++num_colonne){
		changer_pixel(img.pixels[num_ligne][num_colonne], rouge, vert, bleu);
	}
    sauver_PNG("./result_img/"+std::to_string(num_ligne)+".png", img);  
}

//-----------------------------------------------

void masquer_classique(Image_PNG img, int rouge, int vert, int bleu){
    //Variables
    int i;
    //Début
    for (i = 0 ; i < static_cast<int>(img.hauteur) ; ++i){
		ajout_ligne_classique(img, i, rouge, vert, bleu);
	}
	generer_GIF("./result_img/", "./result_gif/masquer_classique_result.gif", 0, static_cast<int>(img.hauteur)-1, 0, 0);
}



//-----------------------------------------------
//Décaler image

void importer_pixel(Image_PNG & img_1, Image_PNG img_2, int col, int cpt){
    //variables
    int i;
    //Début
    //cout << "test feur" << "\n";
    for (i = 0 ; i < static_cast<int>(img_1.hauteur)  ; ++i){
        img_1.pixels[i][col - 1] = img_2.pixels[i][img_2.largeur - cpt];

    }
}

void decaler_pixel(Image_PNG & img_1, int col){
    //Variables
    int i;
    //Début
        for (i = 0 ; i < static_cast<int>(img_1.hauteur) ; ++i){
            img_1.pixels[i][col] = img_1.pixels[i][col-1];
        }
}


void decaler_image(Image_PNG & img_1, Image_PNG img_2, int etape){
    //Variable
    int i, cpt;
    //Début {} []
    //for (cpt = 0 ; cpt < img_1.largeur ; ++cpt)
    cpt = 0;
    
        for (i = static_cast<int>(img_1.largeur); i > 0 ; --i){
            if (i <= etape){
                cpt += 1;
                importer_pixel(img_1, img_2, i, cpt);
            }
            else{
                decaler_pixel(img_1, i);
            }
           sauver_PNG("./result_img/"+std::to_string(cpt)+".png", img_1);
        }
    //cout << cpt << "in feur \n";
    

}


void rideau_etapeactu(int ligne_actu, Image_PNG imga,Image_PNG imgb){

    for (int y = 0; y < ligne_actu ; y = y + 4) { // Parcours des lignes (longueur)
        for (int x = 0; x < imga.largeur; ++x) { // Parcours des colonnes
            imga.pixels[ligne_actu-1][x]    = imgb.pixels[ligne_actu][x];
            
        }
    }

    sauver_PNG("./result_img/"+std::to_string(ligne_actu)+".png", imga);

}


void rideau(Image_PNG imga,Image_PNG imgb){
    for (int ligne_actu = 0; ligne_actu < imga.hauteur ; ++ligne_actu) {
        rideau_etapeactu(ligne_actu, imga, imgb);
    }
    sauver_PNG("./result_img/"+std::to_string(imga.hauteur)+".png", imgb);
    
    generer_GIF("./result_img/", "./result_gif/transition_rideau", 0, imga.hauteur, 0, 0);
}









