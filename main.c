// main.c
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "containers.h"
#include "entrada_saida.h"


Navio *criar_navio(Navio *lista) {
    // 1 - Criando espaço para o novo Navio.
    Navio *navio  = (Navio*) malloc(sizeof(Navio));

    // 2 - Solicitando ao usuário dados do Navio.
    printf( "Inserir Navio\nDigite as informações do Navio:\n");

    printf( "código              : ");
    scanf("%d", &navio->codigo);

    printf( "nome                : ");
    ler_string(navio->nome, 101);

    printf( "nacionalidade       : ");
    ler_string(navio->nacionalidade, 4);

    printf( "cumprimento         : ");
    scanf("%f", &navio->cumprimento);

    // 3 - Adiciona o navio na lista, utilizando a função definida no containers.h/.c
    return adicionar_navio(lista, navio);
}


Navio *criar_container(Navio *lista) {

    Navio *navio = NULL;
    Container *container = NULL;
    int codigo;

    // 1 - Precisamos saber em qual Navio adicionaremos o container.
    printf( "Digite o código do navio onde deve ser inserido o container: ");
    scanf("%d", &codigo);

    // 2 - Vamos encontrar o navio onde vamos inserir o container.
    navio = encontrar_navio(lista, codigo);

    if (navio != NULL) {
        // 3 - Criando espaço para o novo Container.
        container = (Container*) malloc(sizeof(Container));

        // 4 - Lendo as informações do conteiner do usuário.
        printf( "Número              : ");
        scanf("%d", &container->numero);

        getchar();
        printf( "Tipo  (A/E/Q)       : ");
        scanf("%c", &container->tipo);

        printf( "Peso                : ");
        scanf("%f", &container->peso);

        printf( "Valor               : ");
        scanf("%f", &container->valor);

        // 5 - Adicionar o container no navio
        adicionar_container(navio, container);

    } else {
        printf( "Nenhum navio com o código %d foi encontrado, a operação foi cancelada.\n", codigo);
    }

    return lista;
}


int main() {
    /* 1 -  Variável para salvar a opção do menu selecionada para o usuário.*/
    int opcao = 1;

    /* Criando lista de Navios */
    Navio *lista_navios = NULL;

    /* 2 -  Vamos definir o locale para poder utilizar acentos e cedilha (é obrigatório o #incluse <localhe.h> antes)*/
    setlocale(LC_ALL,"");

    /* 3 - Enquanto o usuário não escolher a opção 0 (Sair) vamos repetir o programa */
    while (opcao != 0) {

        /* 4 - Imprima o menu */
        printf(         "MENU\n"
                        "------------------------------------------\n"
                        "Selecione a opção desejada:\n"
                        "------------------------------------------\n"
                        "(1) Add Navio (2) Imprimir Navios (3) Adicionar Container (4) Imprimir containers (5) Imprimir navios mais pesados que 1 tonelada (6) imprimir navios mais valiosos que 500 milhões (0) Sair\n");

        /* 5 - Leia a opção selecionada pelo usuário*/
        scanf("%d", &opcao);

        /* 6 - Execute a ação correta de acordo com a opção desejada vamos */
        switch(opcao)
        {
            case 1:
                lista_navios = criar_navio(lista_navios);
                break;

            case 2:
                imprimir(lista_navios);
                break;

            case 3:
                lista_navios = criar_container(lista_navios);
                break;

            case 4:
                imprimir_containers(lista_navios);
                break;

            case 5:
                imprimir_mais_pesados_que(lista_navios, 1000000);
                break;

            case 6:
                imprimir_mais_valiosos_que(lista_navios, 500000000);
                break;

            case 0:
                printf( "A opção sair foi selecionada, o programa será finalizado.\n");
                break;

            default:
                printf("Esta nao e uma opção válida, por favor digite uma opção válida.\n");
        }

        /* 7 - Aguardando o usuário digitarantes do programa continuar, para que ele tenha tempo de ler as saídas
         * em seguida limpe a tela. */
        printf( "\nPrecione um TECLA para continuar...\n");
        clear();
        getchar();
        system("cls");
    }


    return EXIT_SUCCESS;

}



