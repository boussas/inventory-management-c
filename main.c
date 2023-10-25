#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fcts.h"

int main() {
int n;
char name[30];
printf("Entrer la taille du tableau de produits:\n");
scanf("%d", &n);
prd *produits = malloc(n * sizeof(prd));

// Ajout des produits
printf("Ajout des produits:\n");
for(int i=0;i<n;i++){
    ajouterProduit(&produits[i]);
}

// Affichage des produits à l'inventaire
printf("Affichage des produits a l'inventaire:\n");
for (int i=0;i<n;i++){
    afficherProduit(produits[i]);
    printf("\n");}

// Recherche d'un produit
printf("Entrer le nom du produit a trouver:\n");
scanf("%s",name);
int indice=rechercherProduit(name,produits,n);
    if(indice!=-1){
    printf("Indice du produit %s: %d\n", name, indice);
    } else {
    printf("Le produit %s n'existe pas dans la liste.\n", name);
    };

ajouterStock(produits,indice);
printf("Affichage du produit mis a jour:\n");
printf("\n");
afficherProduit(produits[indice]);
printf("\n");

//Tri
for(int i=0;i<n;i++){
    int maxIndex=i;
    for(int j=i+1;j<n;j++) {
        if(produits[j].prix>produits[maxIndex].prix){
        maxIndex = j;}}

    prd temp = produits[i];
    produits[i] = produits[maxIndex];
    produits[maxIndex] = temp;
    };

//Affichage des produits à l'inventaire après tri
    printf("Affichage des produits a l'inventaire apres Tri par ordre croissant selon le prix:\n");
    for (int i = 0; i < n; i++) {
        afficherProduit(produits[i]);
        printf("\n");}

    return 0;
}
