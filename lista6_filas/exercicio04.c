#include "operacoes.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Fila *original = fila_cria();
    Fila *pares = fila_cria();
    Fila *impares = fila_cria();
    if (original == NULL || pares == NULL || impares == NULL) return EXIT_FAILURE;
    int valores[] = {10, 15, 20, 7, 30};
    for (size_t i = 0; i < sizeof valores / sizeof valores[0]; i++)
        enqueue(original, (Elem){valores[i]});
    separarParesImpares(original, pares, impares);
    puts("Pares:"); print(pares);
    puts("Impares:"); print(impares);
    fila_libera(original); fila_libera(pares); fila_libera(impares);
    return 0;
}
