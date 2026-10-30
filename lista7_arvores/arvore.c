#include "arvore.h"
#include <stdlib.h>
No *arvore_criar_no(int valor) {
    No *no = malloc(sizeof *no);
    if (no != NULL) {
        no->valor = valor;
        no->esq = NULL;
        no->dir = NULL;
    }
    return no;
}
void arvore_liberar(No *raiz) {
    if (raiz != NULL) {
        arvore_liberar(raiz->esq);
        arvore_liberar(raiz->dir);
        free(raiz);
    }
}
