#ifndef PILHA_H
#define PILHA_H

typedef struct {
    char carac;
} Elem;

typedef struct pilha Pilha;

/* Funcoes adicionais necessarias para criar e destruir o TAD opaco. */
Pilha *pilha_cria(void);
void pilha_libera(Pilha *pilha);

/* Interface solicitada no exercicio 1. */
void reset(Pilha *pilha);
int empty(Pilha *pilha);
int size(Pilha *pilha);
void push(Pilha *pilha, Elem elem);
Elem pop(Pilha *pilha);
void top(Pilha *pilha);
void clear(Pilha *pilha);
void print(Pilha *pilha);

#endif
