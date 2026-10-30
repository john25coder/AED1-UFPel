#include "arvore.h"
int arvore_identicas(const No *primeira, const No *segunda) {
    if (primeira == NULL || segunda == NULL) {
        return primeira == segunda;
    }
    return primeira->valor == segunda->valor
        && arvore_identicas(primeira->esq, segunda->esq)
        && arvore_identicas(primeira->dir, segunda->dir);
}
