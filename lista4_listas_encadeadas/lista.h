#ifndef LISTA_H
#define LISTA_H

typedef struct { int valor; } Info;
typedef struct Nodo {
    Info info;
    struct Nodo *prox;
} Nodo;
typedef struct { Nodo *pFirst; } Head;

/* Exercicio 1: interface obrigatoria. Remocoes retornam 1 quando feitas. */
Head *criaLista(void);
int listaVazia(Head *lista);
void inserirInicio(Head *lista, Info dado);
void inserirFinal(Head *lista, Info dado);
int removerInicio(Head *lista);
int removerFinal(Head *lista);
int buscar(Head *lista, int valor, Info *resultado);
void imprimirLista(Head *lista);
void liberaLista(Head *lista);

/* Exercicios 2 a 11. */
int contarElementos(Head *lista);
int contarMaioresQue(Head *lista, int valor);
void removerValor(Head *lista, int valor);
void inverterLista(Head *lista);
void inverterPrimeirosN(Head *lista, int n);
void incorporar(Head *destino, Head *origem);
void intercalarListas(Head *primeira, Head *segunda);
void separarPosicoes(Head *origem, Head *impares, Head *pares);
Head *copiarLista(Head *origem);
void removerPares(Head *lista);

/* Consulta somente para testar, sem manipulacao de nos no main. */
int valorNaPosicao(Head *lista, int posicao, int *valor);
#endif
