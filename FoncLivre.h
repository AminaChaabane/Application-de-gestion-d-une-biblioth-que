#ifndef FONCLIVRE_H_INCLUDED
#define FONCLIVRE_H_INCLUDED
#include "structures.h"

void ajouter_livre(livre *liv);
void modifier_livre(int numero);
void supprimer_livre(int numero);
void ordonner_categ();
void rechercher_livre(char categorie[],char titre[]);
#endif // FONCLIVRE_H_INCLUDED
