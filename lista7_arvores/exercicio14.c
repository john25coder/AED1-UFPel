#include "arvore.h"
static int contem(const No *raiz, int valor) {
    return raiz != NULL
        && (raiz->valor == valor || contem(raiz->esq, valor)
                                  || contem(raiz->dir, valor));
}
static No *ancestral_rec(No *raiz, int primeiro, int segundo) {
    if (raiz == NULL || raiz->valor == primeiro || raiz->valor == segundo) {
        return raiz;
    }
    No *esquerdo = ancestral_rec(raiz->esq, primeiro, segundo);
    No *direito = ancestral_rec(raiz->dir, primeiro, segundo);
    if (esquerdo != NULL && direito != NULL) {
        return raiz;
    }
    return esquerdo != NULL ? esquerdo : direito;
}
No *arvore_lca(No *raiz, int primeiro, int segundo) {
    if (!contem(raiz, primeiro) || !contem(raiz, segundo)) {
        return NULL;
    }
    return ancestral_rec(raiz, primeiro, segundo);
}
