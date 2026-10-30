#include "arvore.h"
int arvore_altura(const No *raiz) {
    if (raiz == NULL) {
        return -1;
    }
    int esquerda = arvore_altura(raiz->esq);
    int direita = arvore_altura(raiz->dir);
    return 1 + (esquerda > direita ? esquerda : direita);
}
