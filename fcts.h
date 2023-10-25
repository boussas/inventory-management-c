#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct produit {
    char nom[50];
    float prix;
    float quantite;
    char fournisseur[50];
}prd;

void ajouterProduit(prd *produit) {
    printf("Entrer le nom du produit:\n");
    scanf("%s", produit->nom);
    printf("Entrer le prix unitaire du produit:\n");
    scanf("%f", &produit->prix);
    printf("Entrer la quantite en stock du produit:\n");
    scanf("%f", &produit->quantite);
    printf("Entrer le fournisseur du produit:\n");
    scanf("%s", produit->fournisseur);
}

void afficherProduit(prd produit) {
    printf("Nom du produit:%s\nPrix du produit: %.2f\nQuantite du produit: %.2f\nLe fournisseur du produit: %s.\n",
           produit.nom, produit.prix, produit.quantite, produit.fournisseur);
}

int rechercherProduit(char nom[], prd *produits, int taille) {
    for (int i=0;i<taille;i++) {
        if (strcmp(produits[i].nom,nom)==0){
            return i;}}
    return -1;
}

void ajouterStock(prd *produits,int indice) {
    float quant;
    printf("Entrer la nouvelle quantite a ajouter:\n");
    scanf("%f", &quant);
    produits[indice].quantite = produits[indice].quantite + quant;
}
