#ifndef OPERACOES_FILA_H
#define OPERACOES_FILA_H

#include "fila.h"

/* Exercicio 2: nao altera a ordem nem a quantidade de elementos. */
int maiorElemento(Fila *fila, int *maior);
/* Exercicio 3: inverte com uma pilha auxiliar. */
void inverterFila(Fila *fila);
/* Exercicio 4: copia a distribuicao, preservando a fila original. */
void separarParesImpares(Fila *origem, Fila *pares, Fila *impares);
/* Exercicio 5: utiliza exclusivamente as operacoes publicas do TAD Fila. */
void remover(Fila *fila, int valor);
/* Exercicio 6: consome as filas de entrada; retorna uma terceira fila. */
Fila *intercalarFilas(Fila *primeira, Fila *segunda);

#endif
