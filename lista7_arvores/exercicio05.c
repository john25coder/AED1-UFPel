#include "arvore.h"
size_t arvore_contar_dois_filhos(const No *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return (size_t)(raiz->esq != NULL && raiz->dir != NULL)
         + arvore_contar_dois_filhos(raiz->esq)
         + arvore_contar_dois_filhos(raiz->dir);
}
