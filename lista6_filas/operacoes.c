#include "operacoes.h"
#include "pilha_int.h"
#include <stdio.h>
#include <stdlib.h>

int maiorElemento(Fila *fila, int *maior) {
    if (empty(fila) || maior == NULL) return 0;
    int n = size(fila);
    for (int i = 0; i < n; i++) {
        Elem atual = dequeue(fila);
        if (i == 0 || atual.valor > *maior) *maior = atual.valor;
        enqueue(fila, atual);
    }
    return 1;
}

void inverterFila(Fila *fila) {
    if (fila == NULL) return;
    PilhaInt *pilha = pilha_int_cria();
    if (pilha == NULL) {
        fputs("Erro: memoria insuficiente.\n", stderr);
        exit(EXIT_FAILURE);
    }
    while (!empty(fila)) pilha_int_empilha(pilha, dequeue(fila).valor);
    int valor;
    while (pilha_int_desempilha(pilha, &valor)) enqueue(fila, (Elem){valor});
    pilha_int_libera(pilha);
}

void separarParesImpares(Fila *origem, Fila *pares, Fila *impares) {
    if (origem == NULL || pares == NULL || impares == NULL ||
        origem == pares || origem == impares || pares == impares) return;
    int n = size(origem);
    for (int i = 0; i < n; i++) {
        Elem atual = dequeue(origem);
        if (atual.valor % 2 == 0) enqueue(pares, atual);
        else enqueue(impares, atual);
        enqueue(origem, atual);
    }
}

void remover(Fila *fila, int valor) {
    if (fila == NULL) return;
    int n = size(fila);
    for (int i = 0; i < n; i++) {
        Elem atual = dequeue(fila);
        if (atual.valor != valor) enqueue(fila, atual);
    }
}

Fila *intercalarFilas(Fila *primeira, Fila *segunda) {
    if (primeira == NULL || segunda == NULL || primeira == segunda) return NULL;
    Fila *resultado = fila_cria();
    if (resultado == NULL) return NULL;
    while (!empty(primeira) || !empty(segunda)) {
        if (!empty(primeira)) enqueue(resultado, dequeue(primeira));
        if (!empty(segunda)) enqueue(resultado, dequeue(segunda));
    }
    return resultado;
}
