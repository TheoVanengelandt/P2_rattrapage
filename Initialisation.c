#include <stdio.h>
#include <stdlib.h>
#include "PrototipeStatic.h"
//#include "PrototipeDynamic.h"

void initialisationStruct(Ttab** LeTab)
{
    (*LeTab) = malloc(sizeof(*LeTab));

    if((*LeTab) == NULL)
    {
        exit(EXIT_FAILURE);
    }

    (*LeTab)->colonnes = 0;
    (*LeTab)->lignes = 0;

    (*LeTab)->tableau = 0;
}

