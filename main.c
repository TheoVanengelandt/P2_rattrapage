
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h> 	//Ne pas oublier d'inclure le fichier time.h
#include "Prototypes.h"


int main (int argc, char *argv[])
{
	int TypeDeFond;

	if(argc >= 2 && argv[1]== "-stat")
	{
		system("./historique/log");
	}
	else
	{
		TypeDeFond=0; //rand()%3; //renvoi une valeur pseudo-aléatoire (0, 1 ou 2), correspondant au type d'ecrande veille a exec.
    		pid_t pid_fils;
		char *ParamList[] = {"test", NULL};

	    	pid_fils = fork();
		//printf("pid = %d\n\n", pid_fils);

		if (pid_fils == -1)
		{
			printf("Erreur de création du nouveau processus!");
			quit();
		}
		else if (pid_fils ==  0)	// child process
		{
			//printf("processus fils\n");

		    	if (TypeDeFond == 0)
			{
				//printf("Program static\n");
				execv("/home/theo/Bureau/P2_rattrapage-master/test", ParamList);
		    	}
		   	else if (TypeDeFond == 1)
			{
				printf("test2");
				system("./dynamic");
		    	}
		    	else
			{
				printf("test3");
				system("./interractif");
	   		}
		}
	    	else	// parent process
		{
			//waitpid(pid_fils, NULL, 0);
			wait(NULL);
			printf("le programme c'est finis correctement\n ^^\n");
		}

	    	quit();
		printf("Le processus ne c'est pas arrêté"); //vérifie l'arrêt du processus
	}
}
