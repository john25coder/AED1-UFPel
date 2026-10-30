#include "fila_clientes.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_cliente {
    Cliente cliente;
    struct nodo_cliente *prox;
} NodoCliente;

struct fila_clientes {
    NodoCliente *inicio;
    NodoCliente *fim;
    int quantidade;
};

FilaClientes *clientes_cria(void) {
    FilaClientes *fila = malloc(sizeof *fila);
    if (fila == NULL) return NULL;
    fila->inicio = fila->fim = NULL;
    fila->quantidade = 0;
    return fila;
}

void clientes_libera(FilaClientes *fila) {
    if (fila == NULL) return;
    while (fila->inicio != NULL) {
        NodoCliente *removido = fila->inicio;
        fila->inicio = removido->prox;
        free(removido);
    }
    free(fila);
}

void enqueueCliente(FilaClientes *fila, Cliente cliente) {
    if (fila == NULL) {
        fputs("Erro: fila de clientes nao inicializada.\n", stderr);
        exit(EXIT_FAILURE);
    }
    NodoCliente *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fputs("Erro: memoria insuficiente.\n", stderr);
        exit(EXIT_FAILURE);
    }
    novo->cliente = cliente;
    novo->prox = NULL;
    if (fila->fim != NULL) fila->fim->prox = novo;
    else fila->inicio = novo;
    fila->fim = novo;
    fila->quantidade++;
}

int dequeueCliente(FilaClientes *fila, Cliente *resultado) {
    if (fila == NULL || fila->inicio == NULL || resultado == NULL) return 0;
    NodoCliente *removido = fila->inicio;
    *resultado = removido->cliente;
    fila->inicio = removido->prox;
    if (fila->inicio == NULL) fila->fim = NULL;
    fila->quantidade--;
    free(removido);
    return 1;
}

int frontCliente(const FilaClientes *fila, Cliente *resultado) {
    if (fila == NULL || fila->inicio == NULL || resultado == NULL) return 0;
    *resultado = fila->inicio->cliente;
    return 1;
}

int sizeCliente(const FilaClientes *fila) {
    return fila == NULL ? 0 : fila->quantidade;
}

void printClientes(const FilaClientes *fila) {
    if (fila == NULL || fila->inicio == NULL) {
        puts("Nenhum paciente aguardando.");
        return;
    }
    for (NodoCliente *p = fila->inicio; p != NULL; p = p->prox)
        printf("%d - %s\n", p->cliente.numero, p->cliente.nome);
}
