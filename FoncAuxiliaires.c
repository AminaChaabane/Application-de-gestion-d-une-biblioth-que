#include <stdio.h>
#include "FoncAuxiliaires.h"

FILE *ouvrir_fichier(char nom_fichier[],char mode[])
{
    FILE *flot;
    flot=fopen(nom_fichier,mode);
    if(flot==NULL)
     {
          printf("probleme d'ouverture de fichier\n");
          getch();
          exit(-1);
     }
     return flot;
}

int charger_livres_tab(livre Livres[],FILE *flot)
{
     int num,emprunteur,taille=0,i=0;
     char titre[40],categ[40],nom[40],prenom[40];
     while((fscanf(flot,"%d%s%s%s%s%d",&num,titre,categ,nom,prenom,&emprunteur))!=EOF) //charger le contenu du fichier dans un tableau
     {
         Livres[i].num_liv=num;
         strcpy(Livres[i].titre_liv,titre);
         strcpy(Livres[i].categ_liv,categ);
         strcpy(Livres[i].auteur_liv.nom_aut,nom);
         strcpy(Livres[i].auteur_liv.prenom_aut,prenom);
         Livres[i].emprunteur_liv=emprunteur;
         taille++;
         i++;
     }
     return taille;  // le nombre des livres
}

int charger_adherents_tab(adherent Adherents[],FILE *flot)
{
     int num,nbre_emprunts,taille=0,i=0;
     char adress[100],email[50],nom[40],prenom[40];
     while((fscanf(flot,"%d%s%s%s%s%d",&num,nom,prenom,email,adress,&nbre_emprunts))!=EOF) //charger le contenu du fichier dans un tableau
     {
         Adherents[i].num_adh=num;
         strcpy(Adherents[i].adress_adh,adress);
         strcpy(Adherents[i].email_adh,email);
         strcpy(Adherents[i].nom_adh,nom);
         strcpy(Adherents[i].prenom_adh,prenom);
         Adherents[i].nbre_emprunts_adh=nbre_emprunts;
         taille++;
         i++;
     }
     return taille; // le nombre des adhérents
}


