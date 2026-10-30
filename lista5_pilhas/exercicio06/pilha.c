#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    float valor;
    struct nodo *prox;
} Nodo;

struct pilha {
    Nodo *topo;
    int quantidade;
};

Pilha *pilha_cria(void) {
    Pilha *p = malloc(sizeof *p);
    if (p == NULL) return NULL;
    p->topo = NULL;
    p->quantidade = 0;
    return p;
}

int empty(Pilha *pilha) { return pilha == NULL || pilha->topo == NULL; }
int size(Pilha *pilha) { return pilha == NULL ? 0 : pilha->quantidade; }

void push(Pilha *pilha, float valor) {
    if (pilha == NULL) { fputs("Pilha invalida.\n", stderr); exit(EXIT_FAILURE); }
    Nodo *novo = malloc(sizeof *novo);
    if (novo == NULL) { fputs("Memoria insuficiente.\n", stderr); exit(EXIT_FAILURE); }
    novo->valor = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    ++pilha->quantidade;
}

float pop(Pilha *pilha) {
    if (empty(pilha)) { fputs("Pop em pilha vazia.\n", stderr); exit(EXIT_FAILURE); }
    Nodo *no = pilha->topo;
    float valor = no->valor;
    pilha->topo = no->prox;
    --pilha->quantidade;
    free(no);
    return valor;
}

void pilha_libera(Pilha *pilha) {
    if (pilha == NULL) return;
    while (!empty(pilha)) (void)pop(pilha);
    free(pilha);
}

void print(Pilha *pilha) {
    /* Exibe do topo para a base, sem alterar a pilha. */
    if (pilha == NULL) return;
    for (Nodo *no = pilha->topo; no != NULL; no = no->prox)
        printf("[%.2f] ", no->valor);
    putchar('\n');
}
