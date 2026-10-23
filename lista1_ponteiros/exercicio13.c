#include <stdio.h>
#include <stdlib.h>
int remover(int **v, int *n, int posicao) {
    if (!v || !n || posicao < 0 || posicao >= *n) return 0;
    for (int i = posicao; i < *n - 1; i++) (*v)[i] = (*v)[i + 1];
    --*n;
    if (*n == 0) { free(*v); *v = NULL; return 1; }
    int *novo = realloc(*v, (size_t)*n * sizeof **v);
    if (novo != NULL) *v = novo; /* se falhar, o vetor continua valido */
    return 1;
}
int main(void) {
    int n = 5;
    int *v = malloc((size_t)n * sizeof *v);
    if (!v) return 1;
    for (int i = 0; i < n; i++) v[i] = (i + 1) * 10;
    if (!remover(&v, &n, 2)) { free(v); return 1; }
    for (int i = 0; i < n; i++) printf("%d%c", v[i], i == n - 1 ? '\n' : ' ');
    while (n) remover(&v, &n, 0);
    printf("Vetor vazio: %s\n", v == NULL ? "sim" : "nao");
    return 0;
}
