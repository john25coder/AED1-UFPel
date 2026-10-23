#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct NodoDuplo {
    int valor;
    struct NodoDuplo *ant;
    struct NodoDuplo *prox;
} NodoDuplo;
typedef struct {
    NodoDuplo *inicio;
    NodoDuplo *fim;
} ListaDupla;

ListaDupla *duplaCriar(void);
void duplaInserirFinal(ListaDupla *lista, int valor);
int duplaRemoverPrimeiraOcorrencia(ListaDupla *lista, int valor);
int duplaPalindromo(const ListaDupla *lista);
void duplaImprimir(const ListaDupla *lista);
void duplaLiberar(ListaDupla *lista);

#endif
