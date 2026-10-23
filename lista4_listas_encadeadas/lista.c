#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

static Nodo *novoNodo(Info dado) {
    Nodo *p = malloc(sizeof *p);
    if (!p) { fputs("Erro de alocacao\n", stderr); exit(EXIT_FAILURE); }
    p->info = dado;
    p->prox = NULL;
    return p;
}

Head *criaLista(void) {
    Head *lista = malloc(sizeof *lista);
    if (!lista) { fputs("Erro de alocacao\n", stderr); exit(EXIT_FAILURE); }
    lista->pFirst = NULL;
    return lista;
}
int listaVazia(Head *lista) { return !lista || !lista->pFirst; }
void inserirInicio(Head *lista, Info dado) {
    if (!lista) return;
    Nodo *p = novoNodo(dado);
    p->prox = lista->pFirst;
    lista->pFirst = p;
}
void inserirFinal(Head *lista, Info dado) {
    if (!lista) return;
    Nodo *p = novoNodo(dado);
    Nodo **fim = &lista->pFirst;
    while (*fim) fim = &(*fim)->prox;
    *fim = p;
}
int removerInicio(Head *lista) {
    if (listaVazia(lista)) return 0;
    Nodo *p = lista->pFirst;
    lista->pFirst = p->prox;
    free(p);
    return 1;
}
int removerFinal(Head *lista) {
    if (listaVazia(lista)) return 0;
    Nodo **fim = &lista->pFirst;
    while ((*fim)->prox) fim = &(*fim)->prox;
    free(*fim);
    *fim = NULL;
    return 1;
}
int buscar(Head *lista, int valor, Info *resultado) {
    if (!lista) return 0;
    for (Nodo *p = lista->pFirst; p; p = p->prox) {
        if (p->info.valor == valor) {
            if (resultado) *resultado = p->info;
            return 1;
        }
    }
    return 0;
}
void imprimirLista(Head *lista) {
    if (lista) for (Nodo *p = lista->pFirst; p; p = p->prox) printf("[%d] -> ", p->info.valor);
    puts("NULL");
}
void liberaLista(Head *lista) {
    if (!lista) return;
    while (lista->pFirst) removerInicio(lista);
    free(lista);
}

/* Exercicio 2 */
int contarElementos(Head *lista) {
    int total = 0;
    if (lista) for (Nodo *p = lista->pFirst; p; p = p->prox) total++;
    return total;
}
/* Exercicio 3 */
int contarMaioresQue(Head *lista, int valor) {
    int total = 0;
    if (lista) for (Nodo *p = lista->pFirst; p; p = p->prox) if (p->info.valor > valor) total++;
    return total;
}
/* Exercicio 4: suporta remocoes na cabeca e em sequencia. */
void removerValor(Head *lista, int valor) {
    if (!lista) return;
    Nodo **p = &lista->pFirst;
    while (*p) {
        if ((*p)->info.valor == valor) {
            Nodo *apagar = *p;
            *p = apagar->prox;
            free(apagar);
        } else p = &(*p)->prox;
    }
}
/* Exercicio 5: apenas religa ponteiros, sem vetor. */
void inverterLista(Head *lista) {
    if (!lista) return;
    Nodo *anterior = NULL, *atual = lista->pFirst;
    while (atual) {
        Nodo *seguinte = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = seguinte;
    }
    lista->pFirst = anterior;
}
/* Exercicio 6: assume 0 < n <= comprimento, como no enunciado. */
void inverterPrimeirosN(Head *lista, int n) {
    if (!lista || n <= 1 || !lista->pFirst) return;
    Nodo *inicio = lista->pFirst;
    Nodo *anterior = NULL, *atual = inicio;
    for (int i = 0; i < n && atual; i++) {
        Nodo *seguinte = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = seguinte;
    }
    inicio->prox = atual;
    lista->pFirst = anterior;
}
/* Exercicio 7: move os nos, nao os copia. */
void incorporar(Head *destino, Head *origem) {
    if (!destino || !origem || destino == origem) return;
    Nodo **fim = &destino->pFirst;
    while (*fim) fim = &(*fim)->prox;
    *fim = origem->pFirst;
    origem->pFirst = NULL;
}
/* Exercicio 8: usa os nos existentes e preserva ambas as ordens. */
void intercalarListas(Head *primeira, Head *segunda) {
    if (!primeira || !segunda || primeira == segunda) return;
    Nodo *a = primeira->pFirst, *b = segunda->pFirst, *inicio = NULL;
    Nodo **fim = &inicio;
    while (a || b) {
        if (a) {
            Nodo *seguinte = a->prox;
            *fim = a;
            fim = &a->prox;
            a = seguinte;
        }
        if (b) {
            Nodo *seguinte = b->prox;
            *fim = b;
            fim = &b->prox;
            b = seguinte;
        }
    }
    *fim = NULL;
    primeira->pFirst = inicio;
    segunda->pFirst = NULL;
}
/* Exercicio 9: destinos devem ser listas vazias. */
void separarPosicoes(Head *origem, Head *impares, Head *pares) {
    if (!origem || !impares || !pares || origem == impares || origem == pares ||
        impares == pares || !listaVazia(impares) || !listaVazia(pares)) return;
    Nodo **fimImpares = &impares->pFirst, **fimPares = &pares->pFirst;
    int posicao = 1;
    Nodo *p = origem->pFirst;
    while (p) {
        Nodo *seguinte = p->prox;
        p->prox = NULL;
        if (posicao % 2 == 1) { *fimImpares = p; fimImpares = &p->prox; }
        else { *fimPares = p; fimPares = &p->prox; }
        p = seguinte;
        posicao++;
    }
    origem->pFirst = NULL;
}
/* Exercicio 10: copia profunda dos nodos. */
Head *copiarLista(Head *origem) {
    Head *copia = criaLista();
    Nodo **fim = &copia->pFirst;
    if (origem) for (Nodo *p = origem->pFirst; p; p = p->prox) {
        *fim = novoNodo(p->info);
        fim = &(*fim)->prox;
    }
    return copia;
}
/* Exercicio 11 */
void removerPares(Head *lista) {
    if (!lista) return;
    Nodo **p = &lista->pFirst;
    while (*p) {
        if ((*p)->info.valor % 2 == 0) {
            Nodo *apagar = *p;
            *p = apagar->prox;
            free(apagar);
        } else p = &(*p)->prox;
    }
}
int valorNaPosicao(Head *lista, int posicao, int *valor) {
    if (!lista || !valor || posicao < 0) return 0;
    Nodo *p = lista->pFirst;
    for (int i = 0; i < posicao && p; i++) p = p->prox;
    if (!p) return 0;
    *valor = p->info.valor;
    return 1;
}
