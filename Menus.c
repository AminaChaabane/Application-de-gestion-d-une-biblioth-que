#include <stdio.h>
#include "structures.h"
#include "FoncAdherent.h"
#include "FoncLivre.h"
#include "FoncEmprunt.h"
#define Malloc(type)(type*)malloc(sizeof(type))
void gestion_adh()
{
    int choix=1;
    while(choix!=5){
       system("cls");
       printf("\t************GESTION DES ADHERENTS************\n\n");
       printf("1 - Ajouter un adherent \n");
       printf("2 - Modifier un adherent \n");
       printf("3 - Supprimer un adherent \n");
       printf("4 - Rechercher un adherent par son nom \n");
       printf("5 - Retour au menu principal \n");
       printf("Tapez la touche de votre choix\n");
       scanf("%d",&choix);
       switch(choix){
           case 1: {
                      int nbre_emprunts,num;
                      char adress[100],email[50],nom[40],prenom[40];
                      printf("entrer le numero: ");  scanf("%d",&num);
                      printf("l'adresse: ");scanf("%s" ,adress);
                      printf("l'email: ");scanf("%s",email);
                      printf("le nom: ");scanf("%s" ,nom);
                      printf("le prenom: ");scanf("%s" ,prenom);
                      printf("le nombre d'emprunts:  ");scanf("%d",&nbre_emprunts);
                      adherent *adh=Malloc(adherent);
                      adh->num_adh=num;
                      adh->nbre_emprunts_adh=nbre_emprunts;
                      strcpy(adh->adress_adh,adress);
                      strcpy(adh->email_adh,email);
                      strcpy(adh->nom_adh,nom);
                      strcpy(adh->prenom_adh,prenom);
                      ajouter_adherent(adh);
                      getchar();
                      free(adh);
                      break;
                   }
            case 2:{ int numero;
                     printf("Donner le numero de l'adherent a modifier: ");
                     scanf("%d",&numero);
                     modifier_adherent(numero);
                     getchar(); break;
                   }
            case 3: { int numero;
                      printf("Donner Le numero de l'adherent a supprimer: ");
                      scanf("%d",&numero);
                      supprimer_adherent(numero);getchar(); break;
                    }
            case 4: { char nom[40],prenom[40];
                      printf("Entrer le nom: "); scanf("%s",nom);
                      printf("Entrer le prenom: "); scanf("%s",prenom);
                      rechercher_adherent(nom,prenom);getchar(); break;
                    }
            case 5: system("cls"); break;
            default : printf("********Choix invalide!!********\n");getchar(); break;
       }
       getchar();
       continue;
    }
}

void gestion_livre()
{
    int choix=1;
    while(choix!=6){
       system("cls");
       printf("\t************GESTION DES LIVRES************\n\n");
       printf("1 - Ajouter un livre \n");
       printf("2 - Modifier un livre \n");
       printf("3 - Supprimer un livre \n");
       printf("4 - Ordonner les livres par categorie \n");
       printf("5 - Rechercher un livre par titre et categorie \n");
       printf("6 - Retour au menu principal \n");
       printf("Tapez la touche de votre choix\n");
       scanf("%d",&choix);
       switch(choix){
            case 1: {int num,emprunteur;
                     char titre[40],categ[40],nom[40],prenom[40];
                     printf("entrer le numero: "); scanf("%d",&num);
                     printf("le titre: ");scanf("%s" ,titre);
                     printf("la catégorie: ");scanf("%s",categ);
                     printf("le nom: ");scanf("%s" ,nom);
                     printf("le prenom: ");scanf("%s" ,prenom);
                     printf("le numero de l'emprunteur: "); scanf("%d",&emprunteur);
                     livre *liv=Malloc(livre);
                     liv->num_liv=num;
                     strcpy(liv->titre_liv,titre);
                     strcpy(liv->categ_liv,categ);
                     strcpy(liv->auteur_liv.nom_aut,nom);
                     strcpy(liv->auteur_liv.prenom_aut,prenom);
                     liv->emprunteur_liv=emprunteur;
                     ajouter_livre(liv);
                     getchar();
                     free(liv); break;
                   }
            case 2: {
                    int numero;
                    printf("Donner le numero du livre à modifier: ");
                    scanf("%d",&numero);
                    modifier_livre(numero);
                    getchar(); break;
                    }
            case 3: {
                     int numero;
                     printf("Le numero du livre à supprimer: ");
                     scanf("%d",&numero);
                     supprimer_livre(numero);
                     getchar(); break;
                    }
            case 4: {
                     ordonner_categ();
                     getchar(); break;
                    }
            case 5 : {
                        char categorie[40],titre[40];
                        printf("Entrer le titre: "); scanf("%s",titre);
                        printf("Entrer la categorie: "); scanf("%s",categorie);
                        rechercher_livre(categorie,titre);
                        getchar(); break;
                     }
            case 6 : system("cls"); break;
            default : printf("********Choix invalide!!********\n");getchar(); break;
       }
       getchar();
       continue;
    }
}

void gestion_emprunts()
{
    int choix=1;
    while(choix!=5){
       system("cls");
       printf("\t************GESTION DES EMPRUNTS************\n\n");
       printf("1 - Emprunter un livre \n");
       printf("2 - Afficher liste des livres empruntes \n");
       printf("3 - Afficher liste des adherents emprunteurs de livre \n");
       printf("4 - Rendre un livre \n");
       printf("5 - Retour au menu principal \n");
       printf("Tapez la touche de votre choix\n");
       scanf("%d",&choix);
       switch(choix){
            case 1: {
                      int num_adh,num_liv;
                      printf("Entrer le numero de l'adherent: "); scanf("%d",&num_adh);
                      printf("Entrer le numero de livre a emprunter: "); scanf("%d",&num_liv);
                      emprunter(num_adh,num_liv);
                      getchar(); break;
                    }
            case 2 :{
                       liste_emprunts();
                       getchar(); break;
                    }
            case 3 :{
                      liste_emprunteurs();
                      getchar(); break;
                   }
            case 4 :{
                      int num_adh,num_liv;
                      printf("Entrer le numero de l'adherent: "); scanf("%d",&num_adh);
                      printf("Entrer le numero de livre a rendre: "); scanf("%d",&num_liv);
                      rendre_livre(num_adh,num_liv);
                      getchar(); break;
                    }
            case 5 : system("cls"); break;
            default : printf("********Choix invalide!!********\n");getchar(); break;
       }
       getchar();
       continue;
    }
}
