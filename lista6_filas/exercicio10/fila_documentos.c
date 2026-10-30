#include "fila_documentos.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_documento {
    Documento dado;
    struct nodo_documento *prox;
} NodoDocumento;

struct fila_documentos {
    NodoDocumento *inicio;
    NodoDocumento *fim;
    int quantidade;
};

FilaDocumentos *documentos_cria(void) {
    FilaDocumentos *fila = malloc(sizeof *fila);
    if (fila == NULL) return NULL;
    fila->inicio = fila->fim = NULL;
    fila->quantidade = 0;
    return fila;
}

void documentos_libera(FilaDocumentos *fila) {
    if (fila == NULL) return;
    while (fila->inicio != NULL) {
        NodoDocumento *removido = fila->inicio;
        fila->inicio = removido->prox;
        free(removido);
    }
    free(fila);
}

void enqueueDocumento(FilaDocumentos *fila, Documento documento) {
    if (fila == NULL) {
        fputs("Erro: fila de documentos nao inicializada.\n", stderr);
        exit(EXIT_FAILURE);
    }
    NodoDocumento *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fputs("Erro: memoria insuficiente.\n", stderr);
        exit(EXIT_FAILURE);
    }
    novo->dado = documento;
    novo->prox = NULL;
    if (fila->fim != NULL) fila->fim->prox = novo;
    else fila->inicio = novo;
    fila->fim = novo;
    fila->quantidade++;
}

int dequeueDocumento(FilaDocumentos *fila, Documento *resultado) {
    if (fila == NULL || fila->inicio == NULL || resultado == NULL) return 0;
    NodoDocumento *removido = fila->inicio;
    *resultado = removido->dado;
    fila->inicio = removido->prox;
    if (fila->inicio == NULL) fila->fim = NULL;
    fila->quantidade--;
    free(removido);
    return 1;
}

int frontDocumento(const FilaDocumentos *fila, Documento *resultado) {
    if (fila == NULL || fila->inicio == NULL || resultado == NULL) return 0;
    *resultado = fila->inicio->dado;
    return 1;
}

int sizeDocumento(const FilaDocumentos *fila) {
    return fila == NULL ? 0 : fila->quantidade;
}

void printDocumentos(const FilaDocumentos *fila) {
    if (fila == NULL || fila->inicio == NULL) { puts("Nenhum documento aguardando."); return; }
    for (NodoDocumento *p = fila->inicio; p != NULL; p = p->prox)
        printf("ID=%d, Nome=\"%s\", Paginas=%d\n", p->dado.id, p->dado.nome, p->dado.paginas);
}
