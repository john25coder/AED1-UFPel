#include "pilha_strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo_string {
    char *pagina;
    struct nodo_string *prox;
} NodoString;

struct pilha_strings {
    NodoString *topo;
};

PilhaStrings *pilhaStrings_cria(void) {
    PilhaStrings *pilha = malloc(sizeof *pilha);
    if (pilha != NULL) pilha->topo = NULL;
    return pilha;
}

int pilhaStrings_vazia(const PilhaStrings *pilha) {
    return pilha == NULL || pilha->topo == NULL;
}

int pushString(PilhaStrings *pilha, const char *pagina) {
    if (pilha == NULL || pagina == NULL) return 0;
    NodoString *novo = malloc(sizeof *novo);
    if (novo == NULL) return 0;
    novo->pagina = malloc(strlen(pagina) + 1);
    if (novo->pagina == NULL) { free(novo); return 0; }
    strcpy(novo->pagina, pagina);
    novo->prox = pilha->topo;
    pilha->topo = novo;
    return 1;
}

int popString(PilhaStrings *pilha) {
    if (pilhaStrings_vazia(pilha)) return 0;
    NodoString *no = pilha->topo;
    pilha->topo = no->prox;
    free(no->pagina);
    free(no);
    return 1;
}

const char *topString(const PilhaStrings *pilha) {
    return pilhaStrings_vazia(pilha) ? NULL : pilha->topo->pagina;
}

void printStrings(const PilhaStrings *pilha) {
    if (pilhaStrings_vazia(pilha)) { puts("Historico vazio."); return; }
    for (NodoString *no = pilha->topo; no != NULL; no = no->prox)
        printf("%s\n", no->pagina);
}

void pilhaStrings_libera(PilhaStrings *pilha) {
    if (pilha == NULL) return;
    while (popString(pilha)) { }
    free(pilha);
}
