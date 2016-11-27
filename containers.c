#include "containers.h"



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

    // 5 - Vamos garantir a integridade das listas encadeadas.
    if (navio != NULL) {
        navio->prox = NULL;
        navio->containers = NULL;
    }

    return lista_navios;
}

Navio* encontrar_navio(Navio *lista_navios, int codigo) {
    Navio* aux = lista_navios;
    Navio* resultado = NULL;

    // 1 - Enquanto houver elementos a buscar e o resultado ainda não houver sido encontrado
    while (aux != NULL && resultado == NULL) {
        // 2 - Encontramos o código buscado?
        if (aux->codigo == codigo) {
            resultado = aux;
        }
        // 3 - Adiantamos o ponteiro.
        aux = aux->prox;
    }

    return resultado;
}

void adicionar_container(Navio *navio, Container *container) {

    Container *aux = NULL;

    // 1 - Caso haja Navio
    if (navio != NULL) {
        // 2 - Se ainda não existem containers, vamos adicionar na primeira posição.
        if (navio->containers == NULL) {
            navio->containers = container;
        } else {
            // 3 - Se houver containers, vamos adicionar após o último.
            aux = navio->containers;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = container;

            // 4 - E apontar para NULL, para manter a lista íntegra.
            container->prox = NULL;
        }
    }

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

void imprimir_containers(Navio *lista_navios) {
    Navio *aux = lista_navios;
    Container *auxcont = NULL;
    // 1 - Para cada Navio da lista,
    while (aux!=NULL) {
        // 2 - vamos buscar seus containers, e para cada container:
        auxcont = aux->containers;
        while (auxcont!=NULL){
            // 3 - Vamos imprimir os dados do container.
            printf("Código navio #%d | Número %d | Tipo %c | Peso %.2fkg | Preço: R$ %.2f\n",
                   aux->codigo,
                   auxcont->numero,
                   auxcont->tipo,
                   auxcont->peso,
                   auxcont->valor);

            auxcont = auxcont->prox;
        }
        aux = aux->prox;
    }
}