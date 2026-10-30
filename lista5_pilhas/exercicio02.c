#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char texto[1024];
    if (fgets(texto, sizeof texto, stdin) == NULL) return EXIT_FAILURE;
    texto[strcspn(texto, "\n")] = '\0';
    Pilha *pilha = pilha_cria();
    if (pilha == NULL) return EXIT_FAILURE;
    printf("Original: %s\n", texto);
    for (size_t i = 0; texto[i] != '\0'; ++i) push(pilha, (Elem){texto[i]});
    printf("Invertida: ");
    while (!empty(pilha)) putchar(pop(pilha).carac);
    putchar('\n');
    pilha_libera(pilha);
    return EXIT_SUCCESS;
}
