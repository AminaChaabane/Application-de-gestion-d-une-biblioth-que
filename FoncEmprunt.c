#include <stdio.h>
#include "FoncEmprunt.h"
#include "FoncAuxiliaires.h"

void emprunter(int num_adh,int num_liv)
{
     FILE *flot1=ouvrir_fichier("adherents_biblio.txt","r");
     FILE *flot2=ouvrir_fichier("livres_biblio.txt","r");
     adherent Adherents[2000];
     int taille1=charger_adherents_tab(Adherents,flot1);
     fclose(flot1);
     int j=0;
     while((j<taille1)&&(Adherents[j].num_adh!=num_adh)){j++; }
     if(j>=taille1){printf("********Cet adherent n'existe pas!!********"); }
     else{
        if(Adherents[j].nbre_emprunts_adh==3){printf("********Vous ne pouvez pas emprunter !!********\n"); }
        else{
            livre Livres[8000];
            int taille2=charger_livres_tab(Livres,flot2);
            fclose(flot2);
            int l=0;
            while((l<taille2)&&(Livres[l].num_liv!=num_liv)){l++; }
            if(l>=taille2){printf("********Ce livre n'existe pas!!********\n");  }
            else{
                if(Livres[l].emprunteur_liv!=0){printf("Ce livre est déjà emprunté!"); }
                else{                                       // emprunteur_liv=0 càd le livre est non emprunté
                    Livres[l].emprunteur_liv=num_adh;
                    Adherents[j].nbre_emprunts_adh++;
                    flot1=fopen("Adherents_biblio.txt","w+"); // réouvrir le fichier des adherents pour supprimer son contenu
                    flot2=fopen("livres_biblio.txt","w+"); // réouvrir le fichier des livres pour supprimer son contenu
                    for(int m=0;m<taille1;m++){   //charger le contenu du tableau dans le fichier
                        fprintf(flot1,"%d %s %s %s %s %d\n",Adherents[m].num_adh,Adherents[m].nom_adh,Adherents[m].prenom_adh,Adherents[m].email_adh,Adherents[m].adress_adh,Adherents[m].nbre_emprunts_adh);
                    }
                    for(int n=0;n<taille2;n++){   //charger le contenu du tableau dans le fichier
                        fprintf(flot2,"%d %s %s %s %s %d\n",Livres[n].num_liv,Livres[n].titre_liv,Livres[n].categ_liv,Livres[n].auteur_liv.nom_aut,Livres[n].auteur_liv.prenom_aut,Livres[n].emprunteur_liv);
                    }
                    fclose(flot1);
                    fclose(flot2);
                    printf("********TERMINE!!********\n");
                }
            }
        }
     }
}

void rendre_livre(int num_adh,int num_liv)
{
     FILE *flot1=ouvrir_fichier("adherents_biblio.txt","r");
     FILE *flot2=ouvrir_fichier("livres_biblio.txt","r");
     adherent Adherents[2000];
     int taille1=charger_adherents_tab(Adherents,flot1);
     fclose(flot1);
     int j=0;
     while((j<taille1)&&(Adherents[j].num_adh!=num_adh)){j++; }
     if(j>=taille1){printf("********Cet adherent n'existe pas!!********"); }
     else{
          livre Livres[8000];
          int taille2=charger_livres_tab(Livres,flot2);
          fclose(flot2);
          int l=0;
          while((l<taille2)&&(Livres[l].num_liv!=num_liv)){l++; }
          if(l>=taille2){printf("********Ce livre n'existe pas!!********"); }
          else{
                Livres[l].emprunteur_liv=0;
                Adherents[j].nbre_emprunts_adh--;
                flot1=fopen("Adherents_biblio.txt","w+"); // réouvrir le fichier des adherents pour supprimer son contenu
                flot2=fopen("livres_biblio.txt","w+"); // réouvrir le fichier des livres pour supprimer son contenu
                for(int m=0;m<taille1;m++){   //charger le contenu du tableau dans le fichier
                    fprintf(flot1,"%d %s %s %s %s %d\n",Adherents[m].num_adh,Adherents[m].nom_adh,Adherents[m].prenom_adh,Adherents[m].email_adh,Adherents[m].adress_adh,Adherents[m].nbre_emprunts_adh);
                }
                for(int n=0;n<taille2;n++){   //charger le contenu du tableau dans le fichier
                    fprintf(flot2,"%d %s %s %s %s %d\n",Livres[n].num_liv,Livres[n].titre_liv,Livres[n].categ_liv,Livres[n].auteur_liv.nom_aut,Livres[n].auteur_liv.prenom_aut,Livres[n].emprunteur_liv);
                }
                fclose(flot1);
                fclose(flot2);
                printf("********TERMINE!********\n");
          }
     }
}

void liste_emprunts()
{
    FILE *flot=ouvrir_fichier("livres_biblio.txt","r");
    printf("Numero*****Titre*****Categorie*****Auteur*****Empruteur\n\n");
    int num,emprunteur;
    char titre[40],categ[40],nom[40],prenom[40];
    while((fscanf(flot,"%d%s%s%s%s%d",&num,titre,categ,nom,prenom,&emprunteur))!=EOF)
    {
         if(emprunteur!=0){printf("%d   %s   %s  %s %s   %d\n",num,titre,categ,nom,prenom,emprunteur); }
     }
}

void liste_emprunteurs()
{
    FILE *flot=ouvrir_fichier("adherents_biblio.txt","r");
    printf("Numero*****Nom*****Prenom*****Email*****Adresse*****Nombre des emprunts\n\n");
    int num,nbre_emprunts;
    char adress[100],email[50],nom[40],prenom[40];
    while((fscanf(flot,"%d%s%s%s%s%d",&num,nom,prenom,email,adress,&nbre_emprunts))!=EOF) //tester si l'adherent à ajouter existe déjà dans le fichier
    {
         if(nbre_emprunts!=0){printf("%d   %s   %s   %s   %s   %d\n",num,nom,prenom,email,adress,nbre_emprunts); }
     }
}
