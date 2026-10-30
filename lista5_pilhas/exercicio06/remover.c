#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void remover(Pilha *pilha, float valor) {
    if (pilha == NULL) return;
    Pilha *auxiliar = pilha_cria();
    if (auxiliar == NULL) {
        fputs("Memoria insuficiente.\n", stderr);
        exit(EXIT_FAILURE);
    }
    while (!empty(pilha)) {
        float atual = pop(pilha);
        if (atual != valor) push(auxiliar, atual);
    }
    while (!empty(auxiliar)) push(pilha, pop(auxiliar));
    pilha_libera(auxiliar);
}
