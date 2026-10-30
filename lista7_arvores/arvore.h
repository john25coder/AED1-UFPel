#ifndef AED1_ARVORE_H
#define AED1_ARVORE_H

#include <stddef.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No *arvore_criar_no(int valor);
void arvore_liberar(No *raiz);

size_t arvore_contar_nos(const No *raiz);
long long arvore_somar_valores(const No *raiz);
int arvore_maior(const No *raiz, int *saida);
int arvore_altura(const No *raiz);
size_t arvore_contar_dois_filhos(const No *raiz);
void arvore_contar_internos_folhas(const No *raiz, size_t *internos, size_t *folhas);
void arvore_imprimir_internos_folhas(const No *raiz);
int arvore_existe_soma_caminho(const No *raiz, long long alvo);
int arvore_eh_cheia(const No *raiz);
int arvore_eh_perfeita(const No *raiz);
int arvore_eh_completa(const No *raiz);
int arvore_identicas(const No *primeira, const No *segunda);
void arvore_imprimir_soma_niveis(const No *raiz);
int arvore_imprimir_caminho(const No *raiz, int alvo);
No *arvore_lca(No *raiz, int primeiro, int segundo);

#endif
