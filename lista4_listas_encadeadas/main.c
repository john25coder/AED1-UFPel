#include "lista.h"
#include <assert.h>
#include <stdio.h>

static void preencher(Head *l, const int *v, int n) {
    for (int i = 0; i < n; i++) inserirFinal(l, (Info){v[i]});
}
static void verificar(Head *l, const int *v, int n) {
    assert(contarElementos(l) == n);
    for (int i = 0; i < n; i++) {
        int valor;
        assert(valorNaPosicao(l, i, &valor));
        assert(valor == v[i]);
    }
}
int main(void) {
    Head *l = criaLista();
    assert(listaVazia(l));
    assert(!removerInicio(l));
    assert(!removerFinal(l));
    inserirInicio(l, (Info){20});
    inserirInicio(l, (Info){10});
    inserirFinal(l, (Info){30});
    const int original[] = {10,20,30};
    verificar(l, original, 3);
    Info encontrado;
    assert(buscar(l, 20, &encontrado) && encontrado.valor == 20);
    assert(!buscar(l, 99, NULL));
    assert(removerInicio(l)); assert(removerFinal(l));
    const int unico[] = {20}; verificar(l, unico, 1);
    assert(removerFinal(l)); assert(listaVazia(l));

    const int v[] = {1,2,3,2,4,5}; preencher(l, v, 6);
    assert(contarMaioresQue(l, 3) == 2);
    removerValor(l, 2);
    const int sem2[] = {1,3,4,5}; verificar(l, sem2, 4);
    inverterLista(l);
    const int inv[] = {5,4,3,1}; verificar(l, inv, 4);
    inverterPrimeirosN(l, 3);
    const int inv3[] = {3,4,5,1}; verificar(l, inv3, 4);
    Head *copia = copiarLista(l);
    verificar(copia, inv3, 4);
    removerPares(l);
    const int imp[] = {3,5,1}; verificar(l, imp, 3);
    verificar(copia, inv3, 4); /* prova independencia */

    Head *outro = criaLista();
    const int v2[] = {10,20}; preencher(outro, v2, 2);
    incorporar(l, outro);
    const int acrescido[] = {3,5,1,10,20}; verificar(l, acrescido, 5);
    assert(listaVazia(outro));
    const int paresExtras[] = {8,9,11}; preencher(outro, paresExtras, 3);
    intercalarListas(l, outro);
    const int mesclado[] = {3,8,5,9,1,11,10,20}; verificar(l, mesclado, 8);
    assert(listaVazia(outro));

    Head *posImp = criaLista(), *posPar = criaLista();
    separarPosicoes(l, posImp, posPar);
    const int pImp[] = {3,5,1,10};
    const int pPar[] = {8,9,11,20};
    verificar(posImp, pImp, 4); verificar(posPar, pPar, 4);
    assert(listaVazia(l));
    printf("Todas as verificacoes da lista simplesmente encadeada passaram.\n");
    printf("Posicoes impares: "); imprimirLista(posImp);
    printf("Posicoes pares: "); imprimirLista(posPar);
    liberaLista(l); liberaLista(outro); liberaLista(copia);
    liberaLista(posImp); liberaLista(posPar);
    return 0;
}
