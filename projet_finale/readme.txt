Guide d'utilisation des fonctionnalités 

fonction fondu au noir qui assombrit une image

entrées requises

 fonction = fondu_au_noir  nom de la fonction
 S_img_input = image.png   chemin de l'image impérativement en png
 E_nbsteps = 10 		   nombres d'images intermédiaires pour le gif 
 E_delay = 50			   délais entre chaque image
 E_loop = 3				   nombres de répétition du gif
 
 
fonction bruiter qui brouille une image

entrées requises

 fonction = bruiter  nom de la foncion
 S_img_input = image.png   chemin de l'image impérativement en png
 E_nbsteps = 10 		   nombres d'images intermedières pour le gif 
 E_delay = 50			   delais entres chaques images
 E_loop = 3				   nombres de répétition du gif


fonction flouter qui floute une image

entrées requises

 fonction = flouter  nom de la foncion
 S_img_input = image.png   chemin de l'image impérativement en png
 E_nbsteps = 10 		   nombres d'images intermedières pour le gif 
 E_taux_floutage = 3	   vitesse du floutage 
 
les fonctions masquer persienne et classique 

 fonction = masquer_classique ou masquer_persienne
 S_img_input = image.png chemin de l'image impérativement en png
 E_rouge = 23	couleur du masque en RGB
 E_vert = 45
 E_bleu = 43
 (E_intervalle = 60) uniquement pour masquer persienne


 la fonction transi_top_to_bot fait une transition du bas vers le haut

entrées requises

 fonction = transi_top_to_bot
 S_img_input = image1.png
 S_img2_input = image2.png
 
 
 toutes les fonctions ci-dessus ont cette sortie attendu :

toutes les image intermediere sont dans le fichier result_img
le gif est disponible dans le fichier result_img

 
