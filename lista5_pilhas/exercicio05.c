#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char texto[1024];
    char resultado[1024];
    if (fgets(texto, sizeof texto, stdin) == NULL) return EXIT_FAILURE;
    texto[strcspn(texto, "\n")] = '\0';
    Pilha *pilha = pilha_cria();
    if (pilha == NULL) return EXIT_FAILURE;
    for (size_t i = 0; texto[i] != '\0'; ++i) {
        if (i == 0 || texto[i] != texto[i - 1])
            push(pilha, (Elem){texto[i]});
    }
    size_t n = (size_t)size(pilha);
    resultado[n] = '\0';
    while (n > 0) resultado[--n] = pop(pilha).carac;
    printf("Resultado: %s\n", resultado);
    pilha_libera(pilha);
    return EXIT_SUCCESS;
}
