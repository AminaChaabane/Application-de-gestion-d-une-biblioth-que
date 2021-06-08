#include <stdio.h>
#include "FoncListe.h"

livre* creerLivre(int num,char titre[],char categ[],auteur auteur_liv,int emprunteur) //cette fonction retourne un pointeur de type livre
{
     livre *liv = Malloc(livre);
     liv->num_liv=num;
     strcpy(liv->titre_liv,titre);
     strcpy(liv->categ_liv,categ);
     liv->auteur_liv=auteur_liv;
     liv->emprunteur_liv = emprunteur;
     return liv;
}

liv_node *insererLivre(livre *liv,liv_node *tete) // inserer au début de la liste
{
     liv_node*nouveau=Malloc(liv_node);
     nouveau->infos=liv;
     nouveau->suivant = tete;
     tete = nouveau;
     return tete;
}

liv_node* supprimerLivre(int numero,liv_node *liste) //supprimer un noeud de la liste
{    liv_node* p = liste;
     if(!p) // si la liste est vide (càd le fichier est vide)
     {   printf("********Le fichier est vide!!********\n");
          return liste;
     }
     if(p->infos->num_liv==numero) // si le noeud à supprimer se trouve au début de la liste
     {
           liste=p->suivant;
           free(p);
           printf("********La suppression est terminée********");
           return liste;
     }
     while(p->suivant) // p->suivant!=NULL
     {   if(p->suivant->infos->num_liv==numero)
       {   liv_node* q = p->suivant;
           p->suivant = (p->suivant)->suivant;
           free(q);
           printf("********La suppression est terminée********\n");
           return liste;
       }
       p=p->suivant;
     }
     printf("********Ce livre n'existe pas!!********\n");
     return liste;
}

adherent* creerAdherent(int num,char adress[],char email[],char nom[],char prenom[],int nbre_emprunts ) //cette fonction retourne un pointeur de type adherent
{
     adherent *adh = Malloc(adherent);
     adh->num_adh=num;
     strcpy(adh->adress_adh,adress);
     strcpy(adh->email_adh,email);
     strcpy(adh->nom_adh,nom);
     strcpy(adh->prenom_adh,prenom);
     adh->nbre_emprunts_adh = nbre_emprunts;
     return adh;
}
adh_node *insererAdherent(adherent *adh,adh_node *tete) // inserer au début de la liste
{
     adh_node*nouveau=Malloc(adh_node);
     nouveau->infos=adh;
     nouveau->suivant = tete;
     tete = nouveau;
     return tete;
}
adh_node* supprimerAdherent(int numero,adh_node *liste) //supprimer un noeud de la liste
{    adh_node* p = liste;
     if(!p) // si la liste est vide (càd le fichier est vide)
     {   printf("********Le fichier est vide!!********\n");
          return liste;
     }
     if(p->infos->num_adh==numero) // si le noeud à supprimer se trouve au début de la liste
     {
           liste=p->suivant;
           free(p);
           printf("********La suppression est terminée********");
           return liste;
     }
     while(p->suivant) // p->suivant!=NULL
     {   if(p->suivant->infos->num_adh==numero)
       {   adh_node* q = p->suivant;
           p->suivant = (p->suivant)->suivant;
           free(q);
           printf("********La suppression est terminée********\n");
           return liste;
       }
       p=p->suivant;
     }
     printf("********Cet adherent n'existe pas!!********\n");
     return liste;
}
liv_node *insererLivre_ordre(livre *liv,liv_node *tete)  //insérer dans l'ordre alphabétique de catégorie
{
    liv_node*nouveau=Malloc(liv_node);
    nouveau->infos=liv;
    liv_node *p =tete;
    if(!p || (strcmp(liv->categ_liv,p->infos->categ_liv)<=0))  // si la liste est vide ou le livre à insérer est inférieur alphabétiquemnt au premier élément
    {                                                          // ceci revient à insérer au début de la liste
        nouveau->suivant= p;
        tete=nouveau;
    }
    else
    {    while(p->suivant && (strcmp(nouveau->infos->categ_liv,p->suivant->infos->categ_liv)>0) )  { p=p->suivant; }
         nouveau->suivant=p->suivant;
         p->suivant=nouveau;
    }
    return tete;
}
