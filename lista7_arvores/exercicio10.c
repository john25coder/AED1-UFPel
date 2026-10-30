#include "arvore.h"
#include <stdint.h>
#include <stdlib.h>
int arvore_eh_completa(const No *raiz) {
    if (raiz == NULL) {
        return 1;
    }
    size_t n = arvore_contar_nos(raiz);
    if (n > SIZE_MAX / sizeof(const No *)) {
        return 0;
    }
    const No **fila = malloc(n * sizeof *fila);
    if (fila == NULL) {
        return 0;
    }
    size_t inicio = 0;
    size_t fim = 0;
    int lacuna = 0;
    int completa = 1;
    fila[fim++] = raiz;
    while (inicio < fim && completa) {
        const No *atual = fila[inicio++];
        if (atual->esq != NULL) {
            if (lacuna) {
                completa = 0;
                break;
            }
            fila[fim++] = atual->esq;
        } else {
            lacuna = 1;
        }
        if (atual->dir != NULL) {
            if (lacuna) {
                completa = 0;
                break;
            }
            fila[fim++] = atual->dir;
        } else {
            lacuna = 1;
        }
    }
    free(fila);
    return completa;
}
