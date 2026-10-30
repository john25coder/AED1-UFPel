#include "arvore.h"
static int folhas_mesma_profundidade(const No *raiz, int nivel, int altura) {
    if (raiz == NULL) {
        return 1;
    }
    if (raiz->esq == NULL && raiz->dir == NULL) {
        return nivel == altura;
    }
    return raiz->esq != NULL && raiz->dir != NULL
        && folhas_mesma_profundidade(raiz->esq, nivel + 1, altura)
        && folhas_mesma_profundidade(raiz->dir, nivel + 1, altura);
}
int arvore_eh_perfeita(const No *raiz) {
    return folhas_mesma_profundidade(raiz, 0, arvore_altura(raiz));
}
