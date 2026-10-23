#include <stdio.h>
#include <stdlib.h>
int soma_diagonal(int **mat, int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) soma += mat[i][i];
    return soma;
}
int main(void) {
    int n;
    printf("Ordem da matriz: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int **mat = calloc((size_t)n, sizeof *mat);
    if (!mat) return 1;
    for (int i = 0; i < n; i++) {
        mat[i] = malloc((size_t)n * sizeof **mat);
        if (!mat[i]) { for (int k = 0; k < i; k++) free(mat[k]); free(mat); return 1; }
    }
    printf("Digite %d inteiros, linha por linha:\n", n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &mat[i][j]) != 1) {
                for (int k = 0; k < n; k++) free(mat[k]);
                free(mat); return 1;
            }
        }
    }
    puts("Matriz:");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d%c", mat[i][j], j == n - 1 ? '\n' : ' ');
    }
    printf("Soma da diagonal: %d\n", soma_diagonal(mat, n));
    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
    return 0;
}
