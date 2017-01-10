#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "PrototipeStatic.h"


// Affiche la matrice passée en paramètre
void Affichetableau(Ttab** tab)
{

    int nbrColonnes = (*tab)->colonnes;
    int nbrLignes = (*tab)->lignes;
    int debutX = nbrColonnes;
    int debutY = nbrLignes;

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    int valeur, a, b;

    PosIniTableauCentre(&debutX, &debutY);    //position initial du tableau en X et Y

    system("clear");

    //permet de verifier les valeurs obtenues
    //printf("\n x = %d, y = %d, nbrLigne= %d, nbrColonnes = %d  \n", debutX, debutY, nbrLignes, nbrColonnes);



	for(int j=0; j<w.ws_row; j++)
	{
		for(int i=0; i<(nbrColonnes+debutX); i++)
		{
			valeur = 0;
			//printf("a=%d et b=%d ", i, j);
			if(debutX<=i && i<(nbrColonnes+debutX))
			{
				if(debutY<=j && j<(nbrLignes+debutY))
				{
                    			a = i-debutX;
                    			b = j-debutY;
                    			valeur = (*tab)->tableau[a][b];
                		}
            		}
            		printf("%c ", valeur);
        	}
        	printf("\n");
    	}
	while()
	{
		printf("condition de fermeture");
	}
    	printf("\n");
}
