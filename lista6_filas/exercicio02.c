#include "operacoes.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Fila *fila = fila_cria();
    if (fila == NULL) return EXIT_FAILURE;
    int valores[] = {-8, 12, 4, 31, 5};
    for (size_t i = 0; i < sizeof valores / sizeof valores[0]; i++)
        enqueue(fila, (Elem){valores[i]});
    int maior;
    if (maiorElemento(fila, &maior)) printf("Maior: %d\n", maior);
    print(fila);
    fila_libera(fila);
    return 0;
}
