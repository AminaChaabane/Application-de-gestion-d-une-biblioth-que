#ifndef FONCAUXILIAIRES_H_INCLUDED
#define FONCAUXILIAIRES_H_INCLUDED
#include "structures.h"

FILE *ouvrir_fichier(char nom_fichier[],char mode[]);
int charger_livres_tab(livre Livres[],FILE *flot);
int charger_adherents_tab(adherent Adherents[],FILE *flot);
#endif // FONCAUXILIAIRES_H_INCLUDED
