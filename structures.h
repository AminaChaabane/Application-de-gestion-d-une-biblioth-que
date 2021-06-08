#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct{
   int num_adh;
   char nom_adh[40];
   char prenom_adh[40];
   char email_adh[50];
   char adress_adh[100];
   int nbre_emprunts_adh;
}adherent;

typedef struct {
    char nom_aut[40];
    char prenom_aut[40];
}auteur;

typedef struct {
      int num_liv;
      char titre_liv[40];
      char categ_liv[40];
      auteur auteur_liv;
      int emprunteur_liv;
  } livre;

#endif // STRUCTURES_H_INCLUDED
