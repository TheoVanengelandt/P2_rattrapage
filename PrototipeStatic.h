#ifndef PROTOTIPESTATIC_H_INCLUDED
#define PROTOTIPESTATIC_H_INCLUDED

typedef struct {
    int **tableau; // Tableau qui contient des int
    int lignes; // Nombre de lignes
    int colonnes; // Nombre de colonnes
} Ttab;

void initialisationStruct(Ttab** LeTab);

void allocation(Ttab** LeTab, int taille1, int taille2);

void affecter(Ttab** tab, char* nomDuFichier);

void PosIniTableauCentre(int* Colonnetab, int* Lignetab);

int Affichetableau(Ttab** tab);

#endif // PROTOTIPESTATIC_H_INCLUDED
