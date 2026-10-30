#include "arvore.h"
int arvore_existe_soma_caminho(const No *raiz, long long alvo) {
    if (raiz == NULL) {
        return 0;
    }
    long long restante = alvo - (long long)raiz->valor;
    if (raiz->esq == NULL && raiz->dir == NULL) {
        return restante == 0;
    }
    return arvore_existe_soma_caminho(raiz->esq, restante)
        || arvore_existe_soma_caminho(raiz->dir, restante);
}
