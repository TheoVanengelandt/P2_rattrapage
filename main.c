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

	if(argv[0]=="stat")
	{
		system("./historique/log");
	}
	else
	{
		TypeDeFond=0; //rand()%3; //renvoi une valeur pseudo-aléatoire (0, 1 ou 2), correspondant au type d'ecrande veille a exec.
    		pid_t pid_fils;

	    	do {
			pid_fils = fork();
		} while ((pid_fils == -1) && (errno == EAGAIN));

	    	if (pid_fils == -1) {
			perror("fork");
		}
	    	else if (TypeDeFond == 0) {
			printf("test1\n");
			system("./static");
	    	}
	   	else if (TypeDeFond == 1) {
			printf("test2");
			system("./dynamic");
	    	}
	    	else if (TypeDeFond == 2) {
			printf("test3");
			system("./interractif");
	   	}
	    	else {
			printf("error, program down \n");

			if (wait(NULL) == -1) {
		    		perror("wait :");
			}
	    	}
		quit();
		printf("Le processus ne c'est pas arrêté"); //vérifie l'arrêt du processus
	}
	return 0;
}
