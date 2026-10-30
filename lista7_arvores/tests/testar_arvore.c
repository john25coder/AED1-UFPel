#include "../arvore.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>

static No *novo(int v) {
    No *no = arvore_criar_no(v);
    assert(no != NULL);
    return no;
}
static void vazia(void) {
    int maior = 77;
    size_t internos = 8, folhas = 8;
    assert(arvore_contar_nos(NULL) == 0);
    assert(arvore_somar_valores(NULL) == 0);
    assert(!arvore_maior(NULL, &maior) && maior == 77);
    assert(arvore_altura(NULL) == -1);
    assert(arvore_contar_dois_filhos(NULL) == 0);
    arvore_contar_internos_folhas(NULL, &internos, &folhas);
    assert(internos == 0 && folhas == 0);
    assert(!arvore_existe_soma_caminho(NULL, 0));
    assert(arvore_eh_cheia(NULL) && arvore_eh_perfeita(NULL) && arvore_eh_completa(NULL));
    assert(arvore_identicas(NULL, NULL));
    assert(!arvore_imprimir_caminho(NULL, 5));
    assert(arvore_lca(NULL, 1, 2) == NULL);
    arvore_imprimir_soma_niveis(NULL);
}
static void um_no(void) {
    No *r = novo(-10);
    int maior;
    size_t internos, folhas;
    assert(arvore_contar_nos(r) == 1);
    assert(arvore_somar_valores(r) == -10);
    assert(arvore_maior(r, &maior) && maior == -10);
    assert(!arvore_maior(r, NULL));
    assert(arvore_altura(r) == 0);
    assert(arvore_contar_dois_filhos(r) == 0);
    arvore_contar_internos_folhas(r, &internos, &folhas);
    assert(internos == 0 && folhas == 1);
    assert(arvore_existe_soma_caminho(r, -10));
    assert(!arvore_existe_soma_caminho(r, 0));
    assert(arvore_eh_cheia(r) && arvore_eh_perfeita(r) && arvore_eh_completa(r));
    assert(arvore_identicas(r, r));
    assert(arvore_lca(r, -10, -10) == r);
    assert(arvore_lca(r, -10, 100) == NULL);
    arvore_liberar(r);
}
static void perfeita(void) {
    No *r = novo(10);
    r->esq = novo(5);
    r->dir = novo(20);
    r->esq->esq = novo(3);
    r->esq->dir = novo(7);
    r->dir->esq = novo(15);
    r->dir->dir = novo(30);
    int maior;
    size_t internos, folhas;
    assert(arvore_contar_nos(r) == 7);
    assert(arvore_somar_valores(r) == 90);
    assert(arvore_maior(r, &maior) && maior == 30);
    assert(arvore_altura(r) == 2);
    assert(arvore_contar_dois_filhos(r) == 3);
    arvore_contar_internos_folhas(r, &internos, &folhas);
    assert(internos == 3 && folhas == 4);
    assert(arvore_existe_soma_caminho(r, 18));
    assert(arvore_existe_soma_caminho(r, 60));
    assert(!arvore_existe_soma_caminho(r, 15));
    assert(!arvore_existe_soma_caminho(r, 999));
    assert(!arvore_imprimir_caminho(r, 999));
    assert(arvore_eh_cheia(r) && arvore_eh_perfeita(r) && arvore_eh_completa(r));
    assert(arvore_lca(r, 3, 7) == r->esq);
    assert(arvore_lca(r, 3, 30) == r);
    assert(arvore_lca(r, 5, 3) == r->esq);
    assert(arvore_lca(r, 20, 20) == r->dir);
    assert(arvore_lca(r, 20, 999) == NULL);
    No *c = novo(10);
    c->esq = novo(5);
    c->dir = novo(20);
    c->esq->esq = novo(3);
    c->esq->dir = novo(7);
    c->dir->esq = novo(15);
    c->dir->dir = novo(30);
    assert(arvore_identicas(r, c));
    c->dir->dir->valor = 31;
    assert(!arvore_identicas(r, c));
    c->dir->dir->valor = 30;
    arvore_liberar(c->dir->dir);
    c->dir->dir = NULL;
    assert(!arvore_identicas(r, c));
    assert(!arvore_identicas(r, NULL));
    arvore_liberar(c);
    arvore_liberar(r);
}
static void formatos(void) {
    No *r = novo(1);
    r->esq = novo(2);
    assert(arvore_altura(r) == 1);
    assert(!arvore_eh_cheia(r) && !arvore_eh_perfeita(r));
    assert(arvore_eh_completa(r));
    r->dir = novo(3);
    assert(arvore_eh_cheia(r) && arvore_eh_perfeita(r));
    r->esq->esq = novo(4);
    r->esq->dir = novo(5);
    assert(arvore_eh_cheia(r) && !arvore_eh_perfeita(r));
    assert(arvore_eh_completa(r));
    r->dir->esq = novo(6);
    assert(!arvore_eh_cheia(r) && arvore_eh_completa(r));
    r->dir->dir = novo(7);
    assert(arvore_eh_perfeita(r) && arvore_eh_completa(r));
    r->esq->esq->dir = novo(8);
    assert(!arvore_eh_completa(r));
    arvore_liberar(r);
    r = novo(1);
    r->dir = novo(2);
    assert(!arvore_eh_completa(r) && !arvore_eh_cheia(r));
    arvore_liberar(r);
    r = novo(1);
    r->esq = novo(2);
    r->dir = novo(3);
    r->dir->esq = novo(4);
    assert(!arvore_eh_completa(r));
    arvore_liberar(r);
}
static void negativos_e_nao_ordenada(void) {
    No *r = novo(-5);
    r->esq = novo(20);
    r->dir = novo(-2);
    r->esq->dir = novo(-9);
    r->dir->esq = novo(7);
    assert(arvore_somar_valores(r) == 11);
    assert(arvore_existe_soma_caminho(r, 6));
    assert(arvore_existe_soma_caminho(r, 0));
    assert(arvore_lca(r, -9, 7) == r);
    assert(arvore_lca(r, 20, -9) == r->esq);
    assert(arvore_lca(r, -9, 999) == NULL);
    arvore_liberar(r);
}
static void limites(void) {
    No *r = novo(INT_MAX);
    r->esq = novo(INT_MAX);
    r->dir = novo(INT_MIN);
    assert(arvore_somar_valores(r) == (long long)INT_MAX * 2 + INT_MIN);
    assert(arvore_existe_soma_caminho(r, (long long)INT_MAX * 2));
    assert(arvore_existe_soma_caminho(r, -1LL));
    arvore_liberar(r);
}
int main(void) {
    vazia();
    um_no();
    perfeita();
    formatos();
    negativos_e_nao_ordenada();
    limites();
    puts("TESTES_ARVORE_OK");
    return 0;
}
