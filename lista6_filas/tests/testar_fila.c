#include "../fila.h"
#include "../operacoes.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>

static Fila *nova(void) {
    Fila *fila = fila_cria();
    assert(fila != NULL);
    return fila;
}

static void colocar(Fila *fila, const int *valores, int n) {
    for (int i = 0; i < n; i++) enqueue(fila, (Elem){valores[i]});
}

static void conferir(Fila *fila, const int *esperados, int n) {
    assert(size(fila) == n);
    for (int i = 0; i < n; i++) assert(dequeue(fila).valor == esperados[i]);
    assert(empty(fila));
}

int main(void) {
    Fila *fila = nova();
    assert(empty(fila) && size(fila) == 0);
    assert(!fila_primeiro(fila, NULL));
    enqueue(fila, (Elem){INT_MIN});
    enqueue(fila, (Elem){INT_MAX});
    Elem frente;
    assert(fila_primeiro(fila, &frente) && frente.valor == INT_MIN);
    assert(dequeue(fila).valor == INT_MIN);
    assert(dequeue(fila).valor == INT_MAX);
    assert(empty(fila));
    enqueue(fila, (Elem){42});
    reset(fila);
    assert(empty(fila));
    enqueue(fila, (Elem){17});
    assert(dequeue(fila).valor == 17);
    clear(fila);
    fila_libera(fila);

    fila = nova();
    int maior = 123;
    assert(!maiorElemento(fila, &maior) && maior == 123);
    int negativos[] = {-5, -1, -9};
    colocar(fila, negativos, 3);
    assert(maiorElemento(fila, &maior) && maior == -1);
    conferir(fila, negativos, 3);
    colocar(fila, (int[]){INT_MIN}, 1);
    assert(maiorElemento(fila, &maior) && maior == INT_MIN);
    assert(dequeue(fila).valor == INT_MIN);
    fila_libera(fila);

    fila = nova();
    inverterFila(fila);
    assert(empty(fila));
    colocar(fila, (int[]){10,20,30,40}, 4);
    inverterFila(fila);
    conferir(fila, (int[]){40,30,20,10}, 4);
    colocar(fila, (int[]){5}, 1);
    inverterFila(fila);
    conferir(fila, (int[]){5}, 1);
    fila_libera(fila);

    fila = nova();
    Fila *pares = nova(), *impares = nova();
    colocar(fila, (int[]){10,15,20,7,30,-3,-4,0}, 8);
    separarParesImpares(fila, pares, impares);
    conferir(pares, (int[]){10,20,30,-4,0}, 5);
    conferir(impares, (int[]){15,7,-3}, 3);
    conferir(fila, (int[]){10,15,20,7,30,-3,-4,0}, 8);
    fila_libera(fila); fila_libera(pares); fila_libera(impares);

    fila = nova();
    remover(fila, 9);
    assert(empty(fila));
    colocar(fila, (int[]){3,8,3,5,3,9}, 6);
    remover(fila, 3);
    conferir(fila, (int[]){8,5,9}, 3);
    colocar(fila, (int[]){4,4,4}, 3);
    remover(fila, 4);
    assert(empty(fila));
    colocar(fila, (int[]){1,2}, 2);
    remover(fila, 99);
    conferir(fila, (int[]){1,2}, 2);
    fila_libera(fila);

    Fila *a = nova(), *b = nova();
    Fila *resultado = intercalarFilas(a, b);
    assert(resultado != NULL && empty(resultado));
    fila_libera(resultado);
    colocar(a, (int[]){10,20,30}, 3);
    colocar(b, (int[]){40,50}, 2);
    resultado = intercalarFilas(a, b);
    assert(empty(a) && empty(b));
    conferir(resultado, (int[]){10,40,20,50,30}, 5);
    fila_libera(resultado);
    colocar(b, (int[]){7,8}, 2);
    resultado = intercalarFilas(a, b);
    conferir(resultado, (int[]){7,8}, 2);
    fila_libera(resultado);
    assert(intercalarFilas(a, a) == NULL);
    fila_libera(a); fila_libera(b);

    puts("Lista 6: TAD e exercicios 2-6 aprovados.");
    return 0;
}
