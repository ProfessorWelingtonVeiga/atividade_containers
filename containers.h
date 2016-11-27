#ifndef TESTE_PONTO_H
#define TESTE_PONTO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct scontainer {
    int numero;
    char tipo; // A - Alimento, E - Eletrônicos, Q - Equipamentos
    float peso;
    float valor;
    struct scontainer *prox;
} Container;

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
    float pesoCargaTotal; // Calculado
    float valorCargaTotal; // Calculado
    struct scontainer *containers;
    struct snavio *prox;
} Navio;

/**
 * Adicionar um navio na lista de navios, e retorna um ponteiro para
 * a lista alterada.
 */
Navio* adicionar_navio(Navio *lista_navios, Navio *navio);

/**
 * Adicionar um navio na lista de navios, e retorna um ponteiro para
 * a lista alterada.
 */
Navio* encontrar_navio(Navio *lista_navios, int codigo);

/**
 * Adicionar um navio na lista de navios, e retorna um ponteiro para
 * a lista alterada.
 */
void adicionar_container(Navio *navio, Container *container);

/**
 * Imprime todos os navios de uma lista
 */
void imprimir(Navio *lista_navios);

/**
 * Imprime todos os containers.
 */
void imprimir_containers(Navio *lista_navios);

/*
 *  Imprime apenas os navios mais pesados que certo peso.
 */

void imprimir_mais_pesados_que(Navio *lista_navios, float peso);

/*
 *  Imprime apenas os navios mais valiosos que certo valor.
 */
void imprimir_mais_valiosos_que(Navio *lista_navios, float valor);

#endif //TESTE_PONTO_H
