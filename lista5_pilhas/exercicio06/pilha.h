#ifndef PILHA_FLOAT_H
#define PILHA_FLOAT_H

/* Versao numerica independente: o exercicio 6 exige float,
   enquanto o exercicio 1 define Elem com char. */
typedef struct pilha Pilha;
Pilha *pilha_cria(void);
void pilha_libera(Pilha *pilha);
int empty(Pilha *pilha);
int size(Pilha *pilha);
void push(Pilha *pilha, float valor);
float pop(Pilha *pilha);
void print(Pilha *pilha);
void remover(Pilha *pilha, float valor);

#endif
