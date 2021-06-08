#ifndef FONCADHERENT_H_INCLUDED
#define FONCADHERENT_H_INCLUDED
#include "structures.h"

void ajouter_adherent(adherent *adh);
void modifier_adherent(int numero);
void supprimer_adherent(int numero);
void rechercher_adherent(char nom[],char prenom[]);
#endif // FONCADHERENT_H_INCLUDED
