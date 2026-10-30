#include "operacoes.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Fila *fila = fila_cria();
    if (fila == NULL) return EXIT_FAILURE;
    for (int i = 10; i <= 40; i += 10) enqueue(fila, (Elem){i});
    puts("Antes:"); print(fila);
    inverterFila(fila);
    puts("Depois:"); print(fila);
    fila_libera(fila);
    return 0;
}
