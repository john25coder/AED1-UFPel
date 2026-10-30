#include "operacoes.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Fila *fila = fila_cria();
    if (fila == NULL) return EXIT_FAILURE;
    int valores[] = {3, 8, 3, 5, 3, 9};
    for (size_t i = 0; i < sizeof valores / sizeof valores[0]; i++)
        enqueue(fila, (Elem){valores[i]});
    remover(fila, 3);
    puts("Apos remover o valor 3:"); print(fila);
    fila_libera(fila);
    return 0;
}
