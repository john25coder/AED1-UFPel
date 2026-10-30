#include "pilha_int.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_int {
    int valor;
    struct nodo_int *prox;
} NodoInt;

struct pilha_int {
    NodoInt *topo;
};

PilhaInt *pilha_int_cria(void) {
    PilhaInt *pilha = malloc(sizeof *pilha);
    if (pilha != NULL) pilha->topo = NULL;
    return pilha;
}

void pilha_int_empilha(PilhaInt *pilha, int valor) {
    if (pilha == NULL) {
        fputs("Erro: pilha nao inicializada.\n", stderr);
        exit(EXIT_FAILURE);
    }
    NodoInt *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fputs("Erro: memoria insuficiente.\n", stderr);
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int pilha_int_desempilha(PilhaInt *pilha, int *valor) {
    if (pilha == NULL || pilha->topo == NULL || valor == NULL) return 0;
    NodoInt *removido = pilha->topo;
    *valor = removido->valor;
    pilha->topo = removido->prox;
    free(removido);
    return 1;
}

void pilha_int_libera(PilhaInt *pilha) {
    if (pilha == NULL) return;
    int descartado;
    while (pilha_int_desempilha(pilha, &descartado)) {}
    free(pilha);
}
