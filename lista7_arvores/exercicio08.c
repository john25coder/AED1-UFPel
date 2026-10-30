#include "arvore.h"
int arvore_eh_cheia(const No *raiz) {
    if (raiz == NULL || (raiz->esq == NULL && raiz->dir == NULL)) {
        return 1;
    }
    if (raiz->esq == NULL || raiz->dir == NULL) {
        return 0;
    }
    return arvore_eh_cheia(raiz->esq) && arvore_eh_cheia(raiz->dir);
}
