#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char palavra[1024];
    if (fgets(palavra, sizeof palavra, stdin) == NULL) return EXIT_FAILURE;
    palavra[strcspn(palavra, "\n")] = '\0';
    Pilha *pilha = pilha_cria();
    if (pilha == NULL) return EXIT_FAILURE;
    size_t n = strlen(palavra);
    for (size_t i = 0; i < n; ++i) push(pilha, (Elem){palavra[i]});
    int palindromo = 1;
    for (size_t i = 0; i < n; ++i) {
        if (palavra[i] != pop(pilha).carac) palindromo = 0;
    }
    printf("%s: %s\n", palavra, palindromo ? "palindromo" : "nao e palindromo");
    pilha_libera(pilha);
    return EXIT_SUCCESS;
}
