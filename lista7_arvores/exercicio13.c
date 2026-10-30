#include "arvore.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
static int buscar(const No *raiz, int valor, const No **caminho,
                  size_t profundidade, size_t *quantidade) {
    if (raiz == NULL) {
        return 0;
    }
    caminho[profundidade] = raiz;
    if (raiz->valor == valor) {
        *quantidade = profundidade + 1;
        return 1;
    }
    return buscar(raiz->esq, valor, caminho, profundidade + 1, quantidade)
        || buscar(raiz->dir, valor, caminho, profundidade + 1, quantidade);
}
int arvore_imprimir_caminho(const No *raiz, int alvo) {
    if (raiz == NULL) {
        return 0;
    }
    size_t n = arvore_contar_nos(raiz);
    if (n > SIZE_MAX / sizeof(const No *)) {
        return 0;
    }
    const No **caminho = malloc(n * sizeof *caminho);
    if (caminho == NULL) {
        return 0;
    }
    size_t quantidade = 0;
    int achou = buscar(raiz, alvo, caminho, 0, &quantidade);
    if (achou) {
        for (size_t i = 0; i < quantidade; ++i) {
            printf("%s%d", i ? " -> " : "", caminho[i]->valor);
        }
        putchar('\n');
    }
    free(caminho);
    return achou;
}
