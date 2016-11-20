#include "entrada_saida.h"
/* Função para limpar buffer de entrada no linux, no windows basta usar o fflush(stdin)*/
void clear (void) {
    char c;
    do {
        c = (char) getchar();
        //printf("%c\n", c);
    } while (  c != '\n' );
}

void ler_string(char *buffer, int tamanho) {
    int i= -1;
    char c;

    do {
        c = (char) getc(stdin);
        if (c != '\n') {
            i++;
            buffer[i] = c;
        }
    } while(i<0 || (i<tamanho-1 && c != '\n'));

    buffer[i+1] = '\0';
}
