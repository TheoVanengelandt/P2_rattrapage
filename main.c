#include <stdlib.h>
#include <stdio.h>
#include <time.h> 	//Ne pas oublier d'inclure le fichier time.h
#include "Prototypes.h"

int maint (int argc, char *argv[])
{
	if(argv[0]=="stat")
	{
		system("./historique/log");
	}
	else
	{
		int TypeDeFond;
		TypeDeFond=0; //rand()%3; //renvoi une valeur pseudo-aléatoire (0, 1 ou 2), correspondant au type d'ecrande veille a exec.

		switch(TypeDeFond)
		{
			case 0:
				system("./StaticServ/static");
				break;
			case 1:
				//exec program static
				break;
			case 2:
				//exec program static
				break;
		}
	}	
	quit();
	printf("Le processus ne c'est pas arrêté"); //vérifie l'arrêt du processus
	return 0;
}
