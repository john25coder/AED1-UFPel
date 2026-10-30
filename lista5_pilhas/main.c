#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Pilha *pilha = pilha_cria();
    if (pilha == NULL) {
        fputs("Erro de alocacao.\n", stderr);
        return EXIT_FAILURE;
    }
    push(pilha, (Elem){'A'});
    push(pilha, (Elem){'B'});
    push(pilha, (Elem){'C'});
    printf("Quantidade: %d\n", size(pilha));
    print(pilha);
    top(pilha);
    printf("Removido: %c\n", pop(pilha).carac);
    printf("Quantidade apos pop: %d\n", size(pilha));
    reset(pilha);
    printf("Vazia apos reset: %d\n", empty(pilha));
    push(pilha, (Elem){'D'});
    clear(pilha);
    printf("Vazia apos clear: %d\n", empty(pilha));
    pilha_libera(pilha);
    return EXIT_SUCCESS;
}
