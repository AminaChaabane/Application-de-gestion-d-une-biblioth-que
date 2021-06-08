#ifndef FONCLISTE_H_INCLUDED
#define FONCLISTE_H_INCLUDED
#define Malloc(type)(type*)malloc(sizeof(type))
#include "structures.h"
// structure d'un noeud
typedef struct _liv_node
    {
       livre *infos;
       struct _liv_node *suivant;
	}liv_node;

typedef struct _adh_node
    {
       adherent *infos;
       struct _adh_node *suivant;
	}adh_node;

livre* creerLivre(int num,char titre[],char categ[],auteur auteur_liv,int emprunteur);
liv_node *insererLivre(livre *liv,liv_node *tete);
liv_node* supprimerLivre(int numero,liv_node *liste);
adherent* creerAdherent(int num,char adress[],char email[],char nom[],char prenom[],int nbre_emprunts );
adh_node *insererAdherent(adherent *adh,adh_node *tete);
adh_node* supprimerAdherent(int numero,adh_node *liste);
liv_node *insererLivre_ordre(livre *liv,liv_node *tete);

#endif // FONCLISTE_H_INCLUDED
