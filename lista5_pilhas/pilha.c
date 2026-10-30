#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    Elem dado;
    struct nodo *prox;
} Nodo;

struct pilha {
    Nodo *topo;
    int quantidade;
};

Pilha *pilha_cria(void) {
    Pilha *pilha = malloc(sizeof *pilha);
    if (pilha == NULL) return NULL;
    pilha->topo = NULL;
    pilha->quantidade = 0;
    return pilha;
}

void clear(Pilha *pilha) {
    if (pilha == NULL) return;
    while (pilha->topo != NULL) {
        Nodo *removido = pilha->topo;
        pilha->topo = removido->prox;
        free(removido);
    }
    pilha->quantidade = 0;
}

void reset(Pilha *pilha) {
    clear(pilha);
}

void pilha_libera(Pilha *pilha) {
    if (pilha == NULL) return;
    clear(pilha);
    free(pilha);
}

int empty(Pilha *pilha) {
    return pilha == NULL || pilha->topo == NULL;
}

int size(Pilha *pilha) {
    return pilha == NULL ? 0 : pilha->quantidade;
}

void push(Pilha *pilha, Elem elem) {
    if (pilha == NULL) {
        fprintf(stderr, "Erro: pilha nao inicializada.\n");
        exit(EXIT_FAILURE);
    }
    Nodo *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "Erro: memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    novo->dado = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->quantidade++;
}

Elem pop(Pilha *pilha) {
    Elem vazio = {'\0'};
    if (empty(pilha)) {
        fprintf(stderr, "Erro: tentativa de pop em pilha vazia.\n");
        return vazio;
    }
    Nodo *removido = pilha->topo;
    Elem resultado = removido->dado;
    pilha->topo = removido->prox;
    pilha->quantidade--;
    free(removido);
    return resultado;
}

void top(Pilha *pilha) {
    if (empty(pilha)) {
        puts("Pilha vazia.");
    } else {
        printf("Topo: %c\n", pilha->topo->dado.carac);
    }
}

void print(Pilha *pilha) {
    if (empty(pilha)) {
        puts("Pilha vazia.");
        return;
    }
    for (Nodo *atual = pilha->topo; atual != NULL; atual = atual->prox)
        printf("[%c] ", atual->dado.carac);
    putchar('\n');
}
