#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#include "Prototypes.h"
#include "PrototipeStatic.h"


void PosIniTableauCentre(int* Colonnetab, int* Lignetab)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);


    *Colonnetab = (w.ws_col - *Colonnetab)/2 ;
    *Lignetab = (w.ws_row - *Lignetab)/2 ;

    //printf("%d %d\n \n", Colonnetab, Lignetab);

}


