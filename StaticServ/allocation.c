#include <stdio.h>
#include <stdlib.h>
#include "PrototipeStatic.h"


void allocation(Ttab** LeTab, int taille1, int taille2)
{
    if((*LeTab) == NULL)
    {
        exit(EXIT_FAILURE);
    }


    (*LeTab)->tableau = malloc(taille1*sizeof(int*)); //on alloue la premiere dimension

    if((*LeTab)->tableau == NULL)
    {
        exit(EXIT_FAILURE);
    }


    for(int k=0; k<taille1; k++)
    {
        (*LeTab)->tableau[k] = malloc(taille2*sizeof(int*)); //on alloue la second dimension du tableau


        if((*LeTab)->tableau[k] == NULL)
        {
            for(k = k-1; k >=0; k--)//on parcourt la boucle dans l'ordre inverse
            {
                 free((*LeTab)->tableau[k]);   //Libération de la deuxième dimension
            }

            free((*LeTab)->tableau);   //Libération de la première dimension

            (*LeTab)->tableau = NULL; //Par mesure de securité

            exit(EXIT_FAILURE);
        }
    }
}



