#include "arvore.h"
size_t arvore_contar_nos(const No *raiz) {
    return raiz == NULL ? 0 : 1 + arvore_contar_nos(raiz->esq) + arvore_contar_nos(raiz->dir);
}
