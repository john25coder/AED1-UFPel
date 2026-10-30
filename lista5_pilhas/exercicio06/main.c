#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Pilha *pilha = pilha_cria();
    if (pilha == NULL) return EXIT_FAILURE;
    const float valores[] = {1.0f, 2.5f, 3.0f, 2.5f, 4.0f};
    for (size_t i = 0; i < sizeof valores / sizeof valores[0]; ++i)
        push(pilha, valores[i]);
    puts("Antes (topo -> base):");
    print(pilha);
    remover(pilha, 2.5f);
    puts("Depois (topo -> base):");
    print(pilha);
    printf("Quantidade: %d\n", size(pilha));
    pilha_libera(pilha);
    return EXIT_SUCCESS;
}
