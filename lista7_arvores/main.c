#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

static No *exemplo(void) {
    No *raiz = arvore_criar_no(10);
    if (raiz == NULL) return NULL;
    raiz->esq = arvore_criar_no(5);
    raiz->dir = arvore_criar_no(20);
    if (raiz->esq == NULL || raiz->dir == NULL) {
        arvore_liberar(raiz);
        return NULL;
    }
    raiz->esq->esq = arvore_criar_no(3);
    raiz->esq->dir = arvore_criar_no(7);
    raiz->dir->esq = arvore_criar_no(15);
    raiz->dir->dir = arvore_criar_no(30);
    if (raiz->esq->esq == NULL || raiz->esq->dir == NULL
        || raiz->dir->esq == NULL || raiz->dir->dir == NULL) {
        arvore_liberar(raiz);
        return NULL;
    }
    return raiz;
}
int main(void) {
    No *raiz = exemplo();
    if (raiz == NULL) {
        fputs("Falha ao criar arvore.\n", stderr);
        return EXIT_FAILURE;
    }
    int maior;
    printf("Ex. 01 - Nos: %zu\n", arvore_contar_nos(raiz));
    printf("Ex. 02 - Soma: %lld\n", arvore_somar_valores(raiz));
    if (arvore_maior(raiz, &maior)) printf("Ex. 03 - Maior: %d\n", maior);
    printf("Ex. 04 - Altura: %d\n", arvore_altura(raiz));
    printf("Ex. 05 - Dois filhos: %zu\n", arvore_contar_dois_filhos(raiz));
    puts("Ex. 06 - Internos e externos:");
    arvore_imprimir_internos_folhas(raiz);
    printf("Ex. 07 - Soma 18 em raiz-folha: %s\n",
           arvore_existe_soma_caminho(raiz, 18) ? "sim" : "nao");
    printf("Ex. 08 - Cheia: %s\n", arvore_eh_cheia(raiz) ? "sim" : "nao");
    printf("Ex. 09 - Perfeita: %s\n", arvore_eh_perfeita(raiz) ? "sim" : "nao");
    printf("Ex. 10 - Completa: %s\n", arvore_eh_completa(raiz) ? "sim" : "nao");
    printf("Ex. 11 - Identica a si mesma: %s\n",
           arvore_identicas(raiz, raiz) ? "sim" : "nao");
    puts("Ex. 12 - Soma por nivel:");
    arvore_imprimir_soma_niveis(raiz);
    puts("Ex. 13 - Caminho ate o valor 15:");
    (void)arvore_imprimir_caminho(raiz, 15);
    No *lca = arvore_lca(raiz, 3, 7);
    if (lca != NULL) printf("Ex. 14 - LCA de 3 e 7: %d\n", lca->valor);
    arvore_liberar(raiz);
    return EXIT_SUCCESS;
}
