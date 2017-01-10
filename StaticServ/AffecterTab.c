#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PrototipeStatic.h"

#define TAILLE_MAX 1000

void affecter(Ttab** tab, char* nomDuFichier)
{
    FILE* fichier = NULL;

    char chaine[TAILLE_MAX] = "";
    char chaineAnex[TAILLE_MAX] = "";
    const char t='#'; //Constantes permettant le filtrage des caractère du pbm
    const char m='P'; //Constantes permettant le filtrage des caractère du pbm

    int ent,y =0;    //valeur sortie du pbm et ajouté au tableau
    int tb[2] = {0};
    int i=0, j=0, l=0, c=0, repetition =0;

    const char s[100] = " ";//Pour mettre le nombre d'espaces
    char *token; //chaine temporaire pour diviser


    fichier = fopen(nomDuFichier, "r");
    initialisationStruct(tab);

    if (fichier != NULL)
    {
        while(fgets(chaine, TAILLE_MAX, fichier)!= NULL)
        {
            if (!strchr(chaine, m))
            {
                strcpy(chaineAnex,chaine);

                if (!strchr(chaine, t))
                {
                    strcpy(chaineAnex,chaine);
                    token = strtok(chaineAnex, s);

                    while(token!=NULL)
                    {
                        ent = atoi(token);
                        token = strtok(NULL, s);

                        if (ent>1)
                        {
                            tb[y]=ent;
                            y++;
                        }

                        l=tb[1];
                        c=tb[0];

                        if(l!=0 && c!=0 && ent<2)
                        {
                            if(repetition == 0)
                            {
                                allocation(tab, c, l);
                                (*tab)->colonnes = c;
                                (*tab)->lignes = l;
                                //printf("\n%d %d \n",l,c); //permet d'afficher les lignes et colonnes récupérée
                                repetition =1;
                            }

                            switch(ent)
                            {
                                case 1:
                                    ent = 219;
                                    break;

                                case 0:
                                    ent = 32;
                                    break;
                            }


                            (*tab)->tableau[i][j] = ent;

                            //printf("%c", (*tab)->tableau[i][j]); //Permet de tester la récupération ds caractères dans le tableauprintf("%c", (*tab)->tableau[i][j]);

                            if(j<=l-1)
                            {
                                if(i==c-1)
                                {
                                    //printf("<-i=%d et j=%d", i, j);
                                    j++;
                                    i=0;
                                    //printf("\n");

                                }
                                else
                                {
                                    //printf("<-i=%d et j=%d", i, j);
                                    i++;
                                }
                            }
                        }
                    }
                }
            }
        }
        //permet de virifé le schémas récupéré dans le tableau
/*
        for(int k=0; k<=(c-1); k++)
        {
            for(int m=0; m<=(l); m++)
            {
                printf("%c", (*tab)->tableau[m][k]); //Permet de tester la récupération ds caractères dans le tableauprintf("%c", (*tab)->tableau[i][j]);
            }

            printf("\n");
        }
*/
        fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("\n Impossible d'ouvrir le fichier test.txt\n");
    }
}
