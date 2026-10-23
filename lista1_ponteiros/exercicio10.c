#include <stdio.h>
#include <stdlib.h>
int main(void) {
    size_t n = 0;
    int *v = malloc(sizeof *v);
    if (!v) return 1;
    puts("Digite inteiros (-1 encerra):");
    while (1) {
        int numero;
        if (scanf("%d", &numero) != 1 || numero == -1) break;
        int *novo = realloc(v, (n + 1) * sizeof *v);
        if (!novo) { free(v); return 1; }
        v = novo;
        v[n++] = numero;
    }
    printf("Quantidade: %zu\nValores:", n);
    for (size_t i = 0; i < n; i++) printf(" %d", v[i]);
    putchar('\n');
    if (n) {
        int min = v[0], max = v[0];
        for (size_t i = 1; i < n; i++) {
            if (v[i] < min) min = v[i];
            if (v[i] > max) max = v[i];
        }
        printf("Menor: %d | Maior: %d\n", min, max);
    } else puts("Nenhum valor armazenado.");
    free(v);
    return 0;
}
