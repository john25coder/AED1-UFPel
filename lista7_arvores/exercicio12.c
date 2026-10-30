#include "arvore.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
void arvore_imprimir_soma_niveis(const No *raiz) {
    if (raiz == NULL) {
        return;
    }
    size_t n = arvore_contar_nos(raiz);
    if (n > SIZE_MAX / sizeof(const No *)) {
        return;
    }
    const No **fila = malloc(n * sizeof *fila);
    if (fila == NULL) {
        return;
    }
    size_t inicio = 0;
    size_t fim = 0;
    size_t nivel = 0;
    fila[fim++] = raiz;
    while (inicio < fim) {
        size_t elementos = fim - inicio;
        long long soma = 0;
        for (size_t i = 0; i < elementos; ++i) {
            const No *atual = fila[inicio++];
            soma += (long long)atual->valor;
            if (atual->esq != NULL) {
                fila[fim++] = atual->esq;
            }
            if (atual->dir != NULL) {
                fila[fim++] = atual->dir;
            }
        }
        printf("Nivel %zu: %lld\n", nivel++, soma);
    }
    free(fila);
}
