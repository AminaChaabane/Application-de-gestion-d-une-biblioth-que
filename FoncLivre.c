#include <stdio.h>
#include "FoncLivre.h"
#include "FoncAuxiliaires.h"
#include "FoncListe.h"

void ajouter_livre(livre *liv){
    FILE *flot=ouvrir_fichier("livres_biblio.txt","a+");
    int num,emprunteur,test=0;
    char titre[40],categ[40],nom[40],prenom[40];
    while((fscanf(flot,"%d%s%s%s%s%d",&num,titre,&categ,&nom,&prenom,&emprunteur))!=EOF) //tester si le livre à ajouter existe déjà dans le fichier
    {
         if(liv->num_liv==num){test=1 ; break;}
     }
     if(!test){ //le livre n'existe pas dans le fichier
        fprintf(flot,"%d %s %s %s %s %d\n",liv->num_liv,liv->titre_liv,liv->categ_liv,liv->auteur_liv.nom_aut,liv->auteur_liv.prenom_aut,liv->emprunteur_liv);
        printf("********L'ajout est terminé*********\n");
        fclose(flot);
     }
     else{printf("********Ce livre existe déjà!!********\n");
         fclose(flot);
      }

}

void modifier_livre(int numero){
     FILE *flot=ouvrir_fichier("livres_biblio.txt","r");
     livre Livres[8000];
     int num,emprunteur;
     char titre[40],categ[40],nom[40],prenom[40];
     int taille=charger_livres_tab(Livres,flot);
     fclose(flot);
     int j=0;
     while((j<taille)&&(Livres[j].num_liv!=numero)){j++; }
     if(j>=taille){printf("*********Ce livre n'existe pas!!********"); }
     else{    // la modification du jème élément du tableau
         printf("entrer le nouveau numero: ");
         scanf("%d",&num);
         printf("le nouveau titre: "); scanf("%s" , titre);
         printf("la nouvelle catégorie: "); scanf("%s" ,categ);
         printf("le nouveau nom: "); scanf("%s" , nom);
         printf("le nouveau prenom: "); scanf("%s" , prenom);;
         printf("le nouveau numero de l'emprunteur: "); scanf("%d",&emprunteur);
         Livres[j].num_liv=num;
         strcpy(Livres[j].titre_liv,titre);
         strcpy(Livres[j].categ_liv,categ);
         strcpy(Livres[j].auteur_liv.nom_aut,nom);
         strcpy(Livres[j].auteur_liv.prenom_aut,prenom);
         Livres[j].emprunteur_liv=emprunteur;
         flot=fopen("livres_biblio.txt","w+"); // réouvrir le fichier pour supprimer son contenu
         for(int k=0;k<taille;k++){           //charger le contenu du tableau dans le fichier
            fprintf(flot,"%d %s %s %s %s %d\n",Livres[k].num_liv,Livres[k].titre_liv,Livres[k].categ_liv,Livres[k].auteur_liv.nom_aut,Livres[k].auteur_liv.prenom_aut,Livres[k].emprunteur_liv);
         }
         fclose(flot);
         printf("******La modification est terminée******");

     }
}

void supprimer_livre(int numero){
     FILE *flot=ouvrir_fichier("livres_biblio.txt","r");
     int num,emprunteur;
     char titre[40],categ[40],nom[40],prenom[40];
     auteur auteur_liv;
     liv_node *tete=NULL;
     while((fscanf(flot,"%d%s%s%s%s%d",&num,titre,categ,nom,prenom,&emprunteur))!=EOF) // cette boucle est pour charger le contenu du fichier dans une liste chainée
     {
         strcpy(auteur_liv.nom_aut,nom);
         strcpy(auteur_liv.prenom_aut,prenom);
         livre *l=creerLivre(num,titre,categ,auteur_liv,emprunteur);
         tete=insererLivre(l,tete);
     }
     fclose(flot);
     tete=supprimerLivre(numero,tete);
     flot=fopen("livres_biblio.txt","w"); // réouvrir le fichier en mode "w" pour supprimer son contenu
     liv_node *p=tete;
     while(p)     //charger le contenu de la liste chainée dans le fichier
     {
            fprintf(flot,"%d %s %s %s %s %d\n",p->infos->num_liv,p->infos->titre_liv,p->infos->categ_liv,p->infos->auteur_liv.nom_aut,p->infos->auteur_liv.prenom_aut,p->infos->emprunteur_liv);
            p=p->suivant;
            }
     fclose(flot) ;
}

void ordonner_categ()
{
     FILE *flot=ouvrir_fichier("livres_biblio.txt","r");
     int num,emprunteur;
     char titre[40],categ[40],nom[40],prenom[40];
     auteur auteur_liv;
     liv_node *tete=NULL;
     while((fscanf(flot,"%d%s%s%s%s%d",&num,titre,categ,nom,prenom,&emprunteur))!=EOF) // cette boucle est pour charger le contenu du fichier dans une liste chainée
     {
         strcpy(auteur_liv.nom_aut,nom);
         strcpy(auteur_liv.prenom_aut,prenom);
         livre *l=creerLivre(num,titre,categ,auteur_liv,emprunteur);
         tete=insererLivre_ordre(l,tete);
     }
     fclose(flot);
     flot=fopen("livres_biblio.txt","w"); // réouvrir le fichier en mode "w" pour supprimer son contenu
     liv_node *p=tete;
     while(p)     //charger le contenu de la liste chainée dans le fichier
     {
            fprintf(flot,"%d %s %s %s %s %d\n",p->infos->num_liv,p->infos->titre_liv,p->infos->categ_liv,p->infos->auteur_liv.nom_aut,p->infos->auteur_liv.prenom_aut,p->infos->emprunteur_liv);
            p=p->suivant;
            }
     fclose(flot) ;
     printf("******TERMINE!!******\n");
}

void rechercher_livre(char categorie[],char titre[])
{
    FILE *flot=ouvrir_fichier("livres_biblio.txt","a+");
    int num,emprunteur,test=0;
    char titre_liv[100],categ[40],nom[40],prenom[40];
    while((fscanf(flot,"%d%s%s%s%s%d",&num,titre_liv,&categ,&nom,&prenom,&emprunteur))!=EOF)
    {
         if((strcmp(categorie,categ)==0)&&(strcmp(titre,titre_liv)==0)){test=1 ; break;}
     }
     if(test){   // si le livre est trouvé
        printf("le résultat de votre recherche :\n");
        printf("le numero : %d\n",num);
        printf("le titre: %s\n",titre_liv);
        printf("la catégorie: %s\n",categ);
        printf("le nom de l'auteur : %s %s\n",nom,prenom);
        printf("le numero de l'emprunteur: %d\n",emprunteur);
     }
     else printf("********La recherche n'a renvoye aucun resultat!!********\n"); //si le livre à rechercher n'existe pas
     fclose(flot);
}
