#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int abre(char c) { return c == '(' || c == '[' || c == '{'; }
static int fecha(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']') ||
           (a == '{' && b == '}');
}

int main(void) {
    char expressao[2048];
    if (fgets(expressao, sizeof expressao, stdin) == NULL) return EXIT_FAILURE;
    expressao[strcspn(expressao, "\n")] = '\0';
    Pilha *pilha = pilha_cria();
    if (pilha == NULL) return EXIT_FAILURE;
    int correta = 1;
    for (size_t i = 0; expressao[i] != '\0'; ++i) {
        char c = expressao[i];
        if (abre(c)) {
            push(pilha, (Elem){c});
        } else if (c == ')' || c == ']' || c == '}') {
            if (empty(pilha) || !fecha(pop(pilha).carac, c)) {
                correta = 0;
                break;
            }
        }
    }
    if (!empty(pilha)) correta = 0;
    puts(correta ? "Expressao balanceada." : "Expressao nao balanceada.");
    pilha_libera(pilha);
    return EXIT_SUCCESS;
}
