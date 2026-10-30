#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    Elem dado;
    struct nodo *prox;
} Nodo;

struct fila {
    Nodo *inicio;
    Nodo *fim;
    int quantidade;
};

Fila *fila_cria(void) {
    Fila *fila = malloc(sizeof *fila);
    if (fila == NULL) return NULL;
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->quantidade = 0;
    return fila;
}

void clear(Fila *fila) {
    if (fila == NULL) return;
    while (fila->inicio != NULL) {
        Nodo *removido = fila->inicio;
        fila->inicio = removido->prox;
        free(removido);
    }
    fila->fim = NULL;
    fila->quantidade = 0;
}

void reset(Fila *fila) {
    clear(fila);
}

void fila_libera(Fila *fila) {
    if (fila == NULL) return;
    clear(fila);
    free(fila);
}

int empty(Fila *fila) {
    return fila == NULL || fila->inicio == NULL;
}

int size(Fila *fila) {
    return fila == NULL ? 0 : fila->quantidade;
}

void enqueue(Fila *fila, Elem elem) {
    if (fila == NULL) {
        fputs("Erro: fila nao inicializada.\n", stderr);
        exit(EXIT_FAILURE);
    }
    Nodo *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fputs("Erro: memoria insuficiente.\n", stderr);
        exit(EXIT_FAILURE);
    }
    novo->dado = elem;
    novo->prox = NULL;
    if (fila->fim != NULL) fila->fim->prox = novo;
    else fila->inicio = novo;
    fila->fim = novo;
    fila->quantidade++;
}

Elem dequeue(Fila *fila) {
    Elem vazio = {0};
    if (empty(fila)) {
        fputs("Erro: tentativa de dequeue em fila vazia.\n", stderr);
        return vazio;
    }
    Nodo *removido = fila->inicio;
    Elem resultado = removido->dado;
    fila->inicio = removido->prox;
    if (fila->inicio == NULL) fila->fim = NULL;
    fila->quantidade--;
    free(removido);
    return resultado;
}

int fila_primeiro(Fila *fila, Elem *resultado) {
    if (empty(fila) || resultado == NULL) return 0;
    *resultado = fila->inicio->dado;
    return 1;
}

void front(Fila *fila) {
    Elem elem;
    if (fila_primeiro(fila, &elem)) printf("Inicio: %d\n", elem.valor);
    else puts("Fila vazia.");
}

void print(Fila *fila) {
    if (empty(fila)) {
        puts("Fila vazia.");
        return;
    }
    printf("Inicio -> ");
    for (Nodo *p = fila->inicio; p != NULL; p = p->prox)
        printf("%d%s", p->dado.valor, p->prox == NULL ? "" : " -> ");
    puts(" -> Fim");
}
