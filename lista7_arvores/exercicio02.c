#include "arvore.h"
long long arvore_somar_valores(const No *raiz) {
    return raiz == NULL ? 0LL : (long long)raiz->valor
                                + arvore_somar_valores(raiz->esq)
                                + arvore_somar_valores(raiz->dir);
}
