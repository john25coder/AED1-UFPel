#ifndef PILHA_INT_H
#define PILHA_INT_H

typedef struct pilha_int PilhaInt;
PilhaInt *pilha_int_cria(void);
void pilha_int_empilha(PilhaInt *pilha, int valor);
int pilha_int_desempilha(PilhaInt *pilha, int *valor);
void pilha_int_libera(PilhaInt *pilha);

#endif
