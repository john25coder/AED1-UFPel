#include <stdio.h>
#include <stdlib.h>
int *inserir(int *v, int *n, int valor) {
    if (!n || *n < 0) return v;
    int *novo = realloc(v, (size_t)(*n + 1) * sizeof *v);
    if (!novo) return v;
    novo[(*n)++] = valor;
    return novo;
}
int main(void) {
    int n = 3;
    int *v = malloc((size_t)n * sizeof *v);
    if (!v) return 1;
    v[0] = 10; v[1] = 20; v[2] = 30;
    int *novo = inserir(v, &n, 40);
    v = novo;
    if (n != 4) { free(v); return 1; }
    for (int i = 0; i < n; i++) printf("%d%c", v[i], i == n - 1 ? '\n' : ' ');
    free(v);
    return 0;
}
