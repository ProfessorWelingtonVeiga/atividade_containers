// main.c
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/* Função para limpar buffer de entrada no linux, no windows basta usar o fflush(stdin)*/
void clear (void) {
    while ( getchar() != '\n' );
}

int main() {
    /* 1 -  Variável para salvar a opção do menu selecionada para o usuário.*/
    int opcao = 1;

    /* 2 -  Vamos definir o locale para poder utilizar acentos e cedilha (é obrigatório o #incluse <localhe.h> antes)*/
    setlocale(LC_ALL,"");

    /* 3 - Enquanto o usuário não escolher a opção 0 (Sair) vamos repetir o programa */
    while (opcao != 0) {

        /* 4 - Imprima o menu */
        printf( "███╗   ███╗███████╗███╗   ██╗██╗   ██╗\n"
                        "████╗ ████║██╔════╝████╗  ██║██║   ██║\n"
                        "██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║\n"
                        "██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║\n"
                        "██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝\n"
                        "╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ \n"
                        "------------------------------------------\n"
                        "Selecione a opção desejada:\n"
                        "------------------------------------------\n"
                        "(1) Add Navio (2) Imprimir Navios (0) Sair\n");

        /* 5 - Leia a opção selecionada pelo usuário e limpe a tela */
        scanf("%d", &opcao);
        system("clear");

        /* 6 - Execute a ação correta de acordo com a opção desejada vamos */
        switch(opcao)
        {
            case 1:
                printf( "Adicionar Navio\n");
                break;

            case 2:
                printf( "A opção B foi selecionada...\n");
                break;

            case 0:
                printf( "A opção sair foi selecionada, o programa será finalizado.\n");
                break;

            default:
                printf("Esta nao e uma opção válida, por favor digite uma opção válida.\n");
        }

        /* 7 - Aguardando o usuário digitarantes do programa continuar, para que ele tenha tempo de ler as saídas. */
        printf( "\nPrecione um TECLA para continuar...\n");
        clear();
        getchar();
    }


    return EXIT_SUCCESS;

}
