#include <stdio.h>
#include <stdlib.h>
int *copia_vetor(int *v, int n) {
    if (n <= 0) return NULL;
    int *copia = malloc((size_t)n * sizeof *copia);
    if (copia == NULL) return NULL;
    for (int i = 0; i < n; i++) copia[i] = v[i];
    return copia;
}
int main(void) {
    int v[] = {10, 20, 30};
    int *copia = copia_vetor(v, 3);
    if (!copia) return 1;
    copia[0] = 99;
    printf("Original: %d | Copia: %d\n", v[0], copia[0]);
    free(copia);
    return 0;
}
