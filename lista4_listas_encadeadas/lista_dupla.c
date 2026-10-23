#include "lista_dupla.h"
#include <stdio.h>
#include <stdlib.h>

ListaDupla *duplaCriar(void) {
    ListaDupla *l = malloc(sizeof *l);
    if (!l) { fputs("Erro de alocacao\n", stderr); exit(EXIT_FAILURE); }
    l->inicio = l->fim = NULL;
    return l;
}
void duplaInserirFinal(ListaDupla *l, int valor) {
    if (!l) return;
    NodoDuplo *novo = malloc(sizeof *novo);
    if (!novo) { fputs("Erro de alocacao\n", stderr); exit(EXIT_FAILURE); }
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = l->fim;
    if (l->fim) l->fim->prox = novo;
    else l->inicio = novo;
    l->fim = novo;
}
/* Exercicios 12 e 13: trata remocao da cabeca, cauda e meio. */
int duplaRemoverPrimeiraOcorrencia(ListaDupla *l, int valor) {
    if (!l) return 0;
    for (NodoDuplo *p = l->inicio; p; p = p->prox) {
        if (p->valor == valor) {
            if (p->ant) p->ant->prox = p->prox;
            else l->inicio = p->prox;
            if (p->prox) p->prox->ant = p->ant;
            else l->fim = p->ant;
            free(p);
            return 1;
        }
    }
    return 0;
}
/* Exercicio 14: O(n) tempo, O(1) espaco adicional. */
int duplaPalindromo(const ListaDupla *l) {
    if (!l) return 1;
    NodoDuplo *esq = l->inicio, *dir = l->fim;
    while (esq && dir && esq != dir && esq->ant != dir) {
        if (esq->valor != dir->valor) return 0;
        esq = esq->prox;
        dir = dir->ant;
    }
    return 1;
}
void duplaImprimir(const ListaDupla *l) {
    if (l) for (NodoDuplo *p = l->inicio; p; p = p->prox) printf("[%d] <-> ", p->valor);
    puts("NULL");
}
void duplaLiberar(ListaDupla *l) {
    if (!l) return;
    NodoDuplo *p = l->inicio;
    while (p) { NodoDuplo *seguinte = p->prox; free(p); p = seguinte; }
    free(l);
}
