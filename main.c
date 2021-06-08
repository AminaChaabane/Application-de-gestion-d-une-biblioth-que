#include <stdio.h>
#include <stdlib.h>
#include "FoncAdherent.h"
#include "FoncLivre.h"
#include "FoncEmprunt.h"

int main()
{
    int choix=1;
    while(choix!=4){
        system("cls");
        printf("\t************ BIENVENUE DANS LA BIBLIOTHEQUE ENSIAS ************\n\n");  //Menu principal
        printf(" 1- Gestion des adherents \n");
        printf(" 2- Gestion des livres \n");
        printf(" 3- Gestion des emprunts \n");
        printf(" 4- Quitter l'application \n");
        printf(" Tapez la touche de votre choix\n");
        scanf("%d",&choix);
        switch(choix){
            case 1 : gestion_adh();break;
            case 2: gestion_livre();break;
            case 3: gestion_emprunts();break;
            case 4: exit(-1);
            default: printf("*********choix invalide!!********");getchar();
        }
        getchar();
        continue;
    }

    return 0;
}
