#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#include "../cliente.h"

/* Uma posicao fica reservada para distinguir cheio de vazio. */
#define CAPACIDADE_VETOR 6
#define CAPACIDADE_UTIL (CAPACIDADE_VETOR - 1)

typedef struct {
    Cliente dados[CAPACIDADE_VETOR];
    int inicio;
    int fim;
} FilaCircular;

void circular_inicializa(FilaCircular *fila);
int circular_vazia(const FilaCircular *fila);
int circular_cheia(const FilaCircular *fila);
int circular_quantidade(const FilaCircular *fila);
int circular_enqueue(FilaCircular *fila, Cliente cliente);
int circular_dequeue(FilaCircular *fila, Cliente *resultado);
int circular_front(const FilaCircular *fila, Cliente *resultado);
void circular_print(const FilaCircular *fila);

#endif
