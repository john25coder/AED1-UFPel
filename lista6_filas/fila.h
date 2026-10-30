#ifndef FILA_H
#define FILA_H

typedef struct {
    int valor;
} Elem;

typedef struct fila Fila;

/* Criacao e destruicao: necessarias porque a representacao e opaca. */
Fila *fila_cria(void);
void fila_libera(Fila *fila);

/* Operacoes exigidas no exercicio 1. */
void reset(Fila *fila);
int empty(Fila *fila);
int size(Fila *fila);
void enqueue(Fila *fila, Elem elem);
Elem dequeue(Fila *fila);
void front(Fila *fila);
void clear(Fila *fila);
void print(Fila *fila);

/* Consulta sem remover, para exercicios com menus. Retorna 1 se existir. */
int fila_primeiro(Fila *fila, Elem *resultado);

#endif
