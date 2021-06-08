#include <stdio.h>
#include "FoncAdherent.h"
#include "FoncAuxiliaires.h"
#include "FoncListe.h"
void ajouter_adherent(adherent *adh){
    FILE *flot=ouvrir_fichier("adherents_biblio.txt","a+");
    int num,nbre_emprunts,test=0;
    char adress[40],email[40],nom[40],prenom[40];
    while((fscanf(flot,"%d%s%s%s%s%d",&num,nom,prenom,email,adress,&nbre_emprunts))!=EOF) //tester si l'adherent à ajouter existe déjà dans le fichier
    {
         if(adh->num_adh==num){test=1 ; break;}
     }
     if(!test){ //l'adherent n'existe pas dans le fichier
        fprintf(flot,"%d %s %s %s %s %d\n",adh->num_adh,adh->nom_adh,adh->prenom_adh,adh->email_adh,adh->adress_adh,adh->nbre_emprunts_adh);
        printf("********L'ajout est termine*********\n");
     }
     else{printf("********Cet adherent existe déjà!!********\n");
      }
      fclose(flot);
}

void modifier_adherent(int numero){
     FILE *flot=ouvrir_fichier("adherents_biblio.txt","r");
     adherent Adherents[1000];
     int num,nbre_emprunts,i=0;
     char adress[100],email[50],nom[40],prenom[40];
     int taille=charger_adherents_tab(Adherents,flot);
     fclose(flot);
     int j=0;
     while((j<taille)&&(Adherents[j].num_adh!=numero)){j++; }
     if(j>=taille){printf("********Cet adhrent n'existe pas!!********"); }
     else{    // la modification du jème élément du tableau
         printf("entrer le nouveau numero: "); scanf("%d",&num);
         printf("le nouveau nom: "); scanf("%s" , nom);
         printf("le nouveau prenom: "); scanf("%s" , prenom);
         printf("le nouveau email: "); scanf("%s" ,email);
         printf("la nouvelle adresse: "); scanf("%s" , adress);
         printf("le nouveau nombre d'emprunts: "); scanf("%d",&nbre_emprunts);
         Adherents[j].num_adh=num;
         strcpy(Adherents[j].adress_adh,adress);
         strcpy(Adherents[j].email_adh,email);
         strcpy(Adherents[j].nom_adh,nom);
         strcpy(Adherents[j].prenom_adh,prenom);
         Adherents[j].nbre_emprunts_adh=nbre_emprunts;
         flot=fopen("adherents_biblio.txt","w+"); // réouvrir le fichier pour supprimer son contenu
         for(int k=0;k<taille;k++){              //charger le contenu du tableau dans le fichier
            fprintf(flot,"%d %s %s %s %s %d\n",Adherents[k].num_adh,Adherents[k].nom_adh,Adherents[k].prenom_adh,Adherents[k].email_adh,Adherents[k].adress_adh,Adherents[k].nbre_emprunts_adh);
         }
         fclose(flot);
         printf("******La modification est terminée******");

     }
}

void supprimer_adherent(int numero){
     FILE *flot=ouvrir_fichier("adherents_biblio.txt","r");
     int num,nbre_emprunts;
     char adress[40],email[40],nom[40],prenom[40];
     adh_node *tete=NULL;
     while((fscanf(flot,"%d%s%s%s%s%d",&num,adress,email,nom,prenom,&nbre_emprunts))!=EOF) // cette boucle est pour charger le contenu du fichier dans une liste chainée
     {
         adherent *adh=Malloc(adherent);
         strcpy(adh->nom_adh,nom);
         strcpy(adh->prenom_adh,prenom);
         adherent *d=creerAdherent(num,adress,email,nom,prenom,nbre_emprunts);
         tete=insererAdherent(d,tete);
     }
     fclose(flot);
     tete=supprimerAdherent(numero,tete);
     flot=fopen("Adherents_biblio.txt","w"); // réouvrir le fichier en mode "w" pour supprimer son contenu
     adh_node *p=tete;
     while(p)     //charger le contenu de la liste chainée dans le fichier
     {
            fprintf(flot,"%d %s %s %s %s %d\n",p->infos->num_adh,p->infos->adress_adh,p->infos->email_adh,p->infos->nom_adh,p->infos->prenom_adh,p->infos->nbre_emprunts_adh);
            p=p->suivant;
            }
     fclose(flot) ;
}

void rechercher_adherent(char nom[],char prenom[])
{
    FILE *flot=ouvrir_fichier("adherents_biblio.txt","a+");
    int num,nbre_emprunts,test=0;
    char adress[40],email[40],nom_adh[40],prenom_adh[40];
    while((fscanf(flot,"%d%s%s%s%s%d",&num,nom_adh,prenom_adh,&email,&adress,&nbre_emprunts))!=EOF)
    {
         if((strcmp(nom,nom_adh)==0)&&(strcmp(prenom,prenom_adh)==0)){test=1 ; break;}
     }
     if(test){   // si l'adherent  est trouvé
        printf("le résultat de votre recherche :\n");
        printf("le nom et le prenom de l'adherent  : %s %s\n",nom,prenom);
        printf("le numero : %d\n",num);
        printf("l'adresse : %s\n",adress);
        printf("l'email  : %s\n",email);
        printf("le numero d'emprunts : %d\n",nbre_emprunts);
     }
     else printf("********La recherche n'a renvoyé aucun résultat!!********\n"); //si l'adherent à rechercher n'existe pas
     fclose(flot);
}
