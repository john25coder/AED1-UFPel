#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Fila *fila = fila_cria();
    if (fila == NULL) return EXIT_FAILURE;
    enqueue(fila, (Elem){10});
    enqueue(fila, (Elem){20});
    enqueue(fila, (Elem){30});
    puts("Exercicio 1 - TAD Fila");
    print(fila);
    front(fila);
    printf("Removido: %d\n", dequeue(fila).valor);
    printf("Quantidade: %d\n", size(fila));
    reset(fila);
    printf("Vazia apos reset: %s\n", empty(fila) ? "sim" : "nao");
    fila_libera(fila);
    return 0;
}
