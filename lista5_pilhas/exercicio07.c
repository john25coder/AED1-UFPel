#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char frase[2048];
    if (fgets(frase, sizeof frase, stdin) == NULL) return EXIT_FAILURE;
    frase[strcspn(frase, "\n")] = '\0';
    Pilha *pilha = pilha_cria();
    if (pilha == NULL) return EXIT_FAILURE;
    for (size_t i = 0; frase[i] != '\0'; ) {
        if (frase[i] == ' ' || frase[i] == '\t') {
            ++i;
            continue;
        }
        size_t inicio = i;
        while (frase[i] != '\0' && frase[i] != ' ' && frase[i] != '\t') {
            push(pilha, (Elem){frase[i]});
            ++i;
        }
        for (size_t j = inicio; j < i; ++j) frase[j] = pop(pilha).carac;
    }
    printf("Resultado: %s\n", frase);
    pilha_libera(pilha);
    return EXIT_SUCCESS;
}
