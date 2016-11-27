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
        navio->pesoCargaTotal = 0;
        navio->valorCargaTotal= 0;
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

        // 5 Acumulando valores calculado
        navio->pesoCargaTotal += container->peso;
        navio->valorCargaTotal += container->valor;
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
            printf("Navio #%d | Nacionalidade %s | Tamanaho %.2fm | Carga Total: %.2f| Valor Total: %.2f | Nome: %s\n",
                   aux->codigo,
                   aux->nacionalidade,
                   aux->cumprimento,
                   aux->pesoCargaTotal,
                    aux->valorCargaTotal,
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

/*
 *  Imprime apenas os navios mais pesados que certo peso.
 */

void imprimir_mais_pesados_que(Navio *lista_navios, float peso) {
    // 1 - Ponteiro para apontar para o começo da lista
    Navio *aux = lista_navios;
    int imprimiu = 0;

    // 2 - Para cada elemento da lista,
    while (aux != NULL) {
        // 3 - Se estiver acima do valor desejado, imprima.
        if (aux->pesoCargaTotal > peso) {
            printf("Navio #%d | Nacionalidade %s | Tamanaho %.2fm | Carga Total: %.2f| Valor Total: %.2f | Nome: %s\n",
                   aux->codigo,
                   aux->nacionalidade,
                   aux->cumprimento,
                   aux->pesoCargaTotal,
                   aux->valorCargaTotal,
                   aux->nome);

            imprimiu++;
        }
        aux = aux->prox;
    }

    // 4 - Se nada for impresso, avise ao usuário:
    if (imprimiu == 0) {
        printf("Nenhum navio encontrado.");
    }
}

/*
 *  Imprime apenas os navios mais valiosos que certo valor.
 */
void imprimir_mais_valiosos_que(Navio *lista_navios, float valor) {
    // 1 - Ponteiro para apontar para o começo da lista
    Navio *aux = lista_navios;
    int imprimiu = 0;

    // 2 - Para cada elemento da lista,
    while (aux != NULL) {
        // 3 - Se estiver acima do valor desejado, imprima.
        if (aux->valorCargaTotal > valor) {
            printf("Navio #%d | Nacionalidade %s | Tamanaho %.2fm | Carga Total: %.2f| Valor Total: %.2f | Nome: %s\n",
                   aux->codigo,
                   aux->nacionalidade,
                   aux->cumprimento,
                   aux->pesoCargaTotal,
                   aux->valorCargaTotal,
                   aux->nome);

            imprimiu++;
        }
        aux = aux->prox;
    }

    // 4 - Se nada for impresso, avise ao usuário:
    if (imprimiu == 0) {
        printf("Nenhum navio encontrado.");
    }

}