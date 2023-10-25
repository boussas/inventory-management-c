#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fcts.h"

void modifierPrix(prd *produits,int indice){
int newprice;
printf("Entrer le nouveau prix:\n");
scanf("%d",&newprice);
produits[indice].prix=newprice;
}

void modifierPrixpourcentage(prd *produits,int indice){
float percent;
printf("Entrer le pourcentage de reduction % (ex: pour une reduction de 60 pourcent entrer 0.6 :\n");
scanf("%f",&percent);
produits[indice].prix=produits[indice].prix*(1-percent);
}
void modifierFournisseur(prd *produits,int Index){
printf("Entrer le nom du nouveau fournisseur: \n");
scanf("%s", &produits[Index].fournisseur);
}
int main() {
int n,choix;
char name[30];
printf("Entrer la taille du tableau de produits:\n");
scanf("%d", &n);
prd *produits = malloc(n * sizeof(prd));
printf("Ajout des produits:\n");
for(int i=0;i<n;i++){
    ajouterProduit(&produits[i]);
};
    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un produit\n");
        printf("2. Afficher l'inventaire\n");
        printf("3. Rechercher un produit\n");
        printf("4. Ajouter du stock\n");
        printf("5. Modifier le prix d'un produit\n");
        printf("6. Effectuer une reduction en pourcentage d'un produit\n");
        printf("7. Modifier le fournisseur d'un produit\n");
        printf("0. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouterProduit(&produits[n]);
                n++;
                break;
            case 2:
                printf("Affichage des produits a l'inventaire:\n");
                for (int i = 0; i < n; i++) {
                    afficherProduit(produits[i]);
                    printf("\n");
                }
                break;
            case 3:
                printf("Entrer le nom du produit a chercher:\n");
                scanf("%s", name);
                int index = rechercherProduit(name, produits, n);
                if (index != -1) {
                    printf("Indice du produit %s: %d\n", name, index);
                } else {
                    printf("Le produit %s n'existe pas dans la liste.\n", name);
                }
                break;
            case 4:
                printf("Entrer le nom du produit pour ajouter du stock:\n");
                scanf("%s", name);
                int stockIndex = rechercherProduit(name, produits, n);
                if (stockIndex != -1) {
                    ajouterStock(produits, stockIndex);
                    printf("Stock du produit %s mis a jour.\n", name);
                } else {
                    printf("Le produit %s n'existe pas dans la liste.\n", name);
                }
                break;
            case 5:
                printf("Entrer le nom du produit pour modifier le prix:\n");
                scanf("%s", name);
                int Indice = rechercherProduit(name, produits, n);
                if (Indice != -1) {
                    modifierPrix(produits, Indice);
                    printf("Prix du produit %s mis a jour.\n", name);
                } else {
                    printf("Le produit %s n'existe pas dans la liste.\n", name);
                }
                break;
            case 6:
                printf("Entrer le nom du produit pour modifier le prix:\n");
                scanf("%s", name);
                int Indi = rechercherProduit(name, produits, n);
                if (Indi != -1) {
                    modifierPrixpourcentage(produits, Indi);
                    printf("Reduction du produit %s mis a jour par une reduction du pourcentage entre.\n", name);
                } else {
                    printf("Le produit %s n'existe pas dans la liste.\n", name);
                }
                break;
            case 7:
                printf("Entrer le nom du produit pour modifier le fournisseur: \n");
                scanf("%s", name);
                int Index = rechercherProduit(name, produits, n);
                if (Index != -1) {
                    modifierFournisseur(produits, Index);
                    printf("Modification du fournisseur du produit %s mis a jour par le nouveau fournisseur entre.\n", name);
                } else {
                    printf("Le produit %s n'existe pas dans la liste.\n", name);
                }
                break;
            case 0:
                printf("Bye!\n");
                break;
            default:
                printf("Option invalide. Veuillez choisir a nouveau.\n");
        }
    } while (choix != 0);
    return 0;
}
