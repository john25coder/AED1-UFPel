#include "fila_circular.h"
#include <stdio.h>

void circular_inicializa(FilaCircular *fila) {
    if (fila == NULL) return;
    fila->inicio = 0;
    fila->fim = 0;
}

int circular_vazia(const FilaCircular *fila) {
    return fila == NULL || fila->inicio == fila->fim;
}

int circular_cheia(const FilaCircular *fila) {
    return fila != NULL && (fila->fim + 1) % CAPACIDADE_VETOR == fila->inicio;
}

int circular_quantidade(const FilaCircular *fila) {
    if (fila == NULL) return 0;
    return (fila->fim - fila->inicio + CAPACIDADE_VETOR) % CAPACIDADE_VETOR;
}

int circular_enqueue(FilaCircular *fila, Cliente cliente) {
    if (fila == NULL || circular_cheia(fila)) return 0;
    fila->dados[fila->fim] = cliente;
    fila->fim = (fila->fim + 1) % CAPACIDADE_VETOR;
    return 1;
}

int circular_dequeue(FilaCircular *fila, Cliente *resultado) {
    if (circular_vazia(fila) || resultado == NULL) return 0;
    *resultado = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % CAPACIDADE_VETOR;
    return 1;
}

int circular_front(const FilaCircular *fila, Cliente *resultado) {
    if (circular_vazia(fila) || resultado == NULL) return 0;
    *resultado = fila->dados[fila->inicio];
    return 1;
}

void circular_print(const FilaCircular *fila) {
    if (circular_vazia(fila)) { puts("Nenhum cliente aguardando."); return; }
    for (int i = fila->inicio; i != fila->fim; i = (i + 1) % CAPACIDADE_VETOR)
        printf("%d - %s\n", fila->dados[i].numero, fila->dados[i].nome);
}
