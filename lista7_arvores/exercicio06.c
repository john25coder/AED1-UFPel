#include "arvore.h"
#include <stdio.h>
static void contar(const No *raiz, size_t *internos, size_t *folhas) {
    if (raiz == NULL) {
        return;
    }
    if (raiz->esq == NULL && raiz->dir == NULL) {
        ++*folhas;
    } else {
        ++*internos;
    }
    contar(raiz->esq, internos, folhas);
    contar(raiz->dir, internos, folhas);
}
void arvore_contar_internos_folhas(const No *raiz, size_t *internos, size_t *folhas) {
    size_t ni = 0;
    size_t nf = 0;
    contar(raiz, &ni, &nf);
    if (internos != NULL) {
        *internos = ni;
    }
    if (folhas != NULL) {
        *folhas = nf;
    }
}
void arvore_imprimir_internos_folhas(const No *raiz) {
    size_t internos, folhas;
    arvore_contar_internos_folhas(raiz, &internos, &folhas);
    printf("Nos internos: %zu\nNos externos (folhas): %zu\n", internos, folhas);
}
