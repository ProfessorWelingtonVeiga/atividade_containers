#include "containers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


Navio* adicionar_navio(Navio *lista_navios, Navio *navio) {
    // 1 - Ponteiro para apontar para o começo da lista
    Navio *aux = lista_navios;

    // 2 - Se a lista está vazia, o elemento enviado é o primeiro.
    if (lista_navios == NULL) {
        lista_navios = navio;
    } else {
        // 3 - Se existem elementos, vamos procurar o último.
        while (aux->prox!=NULL){
            aux = aux->prox;
        }
        // 4 - Ao encontrar o último vamos fazer com que o nó inserido aponte pra ele
        // e garantir que ele aponta para NULL, para manter a lista encadeada consistete.
        aux->prox = navio;
    }

    if (navio != NULL)
        navio->prox = NULL;

    return lista_navios;
}


void imprimir(Navio *lista_navios) {
    // 1 - Ponteiro para apontar para o começo da lista
    Navio *aux = lista_navios;

    if (aux==NULL) {
        // 2 - Caso não exista nenhum elemento, vamos imprimir que a lista está vazia.
        printf("Nenhum navio encontrado.");
    } else {
        // 3 - Para cada elemento da lista, vamos imprimir seu conteudo.
        while (aux != NULL) {
            printf("Navio #%d | Nacionalidade %s | Tamanaho %.2fm | Nome: %s\n",
                   aux->codigo,
                   aux->nacionalidade,
                   aux->cumprimento,
                   aux->nome);

            aux = aux->prox;
        }
    }
}