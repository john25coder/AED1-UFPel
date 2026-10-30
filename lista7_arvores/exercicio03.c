#include "arvore.h"
static int maximo(int a, int b) { return a > b ? a : b; }
int arvore_maior(const No *raiz, int *saida) {
    if (raiz == NULL || saida == NULL) {
        return 0;
    }
    int maior = raiz->valor;
    int candidato;
    if (arvore_maior(raiz->esq, &candidato)) {
        maior = maximo(maior, candidato);
    }
    if (arvore_maior(raiz->dir, &candidato)) {
        maior = maximo(maior, candidato);
    }
    *saida = maior;
    return 1;
}
