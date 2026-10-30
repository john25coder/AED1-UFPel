#include "operacoes.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Fila *a = fila_cria(), *b = fila_cria();
    if (a == NULL || b == NULL) return EXIT_FAILURE;
    for (int i = 1; i <= 3; i++) {
        enqueue(a, (Elem){i * 10});
        enqueue(b, (Elem){i * 10 + 30});
    }
    Fila *resultado = intercalarFilas(a, b);
    if (resultado == NULL) return EXIT_FAILURE;
    puts("Resultado:"); print(resultado);
    fila_libera(a); fila_libera(b); fila_libera(resultado);
    return 0;
}
