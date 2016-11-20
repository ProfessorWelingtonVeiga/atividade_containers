#ifndef TESTE_PONTO_H
#define TESTE_PONTO_H


/*
 * Modelando Navio com 3 informações:
 *  código (inteiro)
 *  nome (string de 100 posições)
 *  nacionalidade (string de 3 posições, exe: BRA, USE, GBR);
 *  cumprimento (float)
 */

typedef struct snavio {
    int codigo;
    char nome[101];
    char nacionalidade[4]; // BRA, USA...
    float cumprimento;
    struct snavio *prox;
} Navio;

/**
 * Adicionar um navio na lista de navios, e retorna um ponteiro para
 * a lista alterada.
 */
Navio* adicionar_navio(Navio *lista_navios, Navio *navio);


/**
 * Imprime todos os navios de uma lista
 */
void imprimir(Navio *lista_navios);

#endif //TESTE_PONTO_H
