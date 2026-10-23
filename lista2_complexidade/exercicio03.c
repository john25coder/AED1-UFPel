#include <stdio.h>
#include <stdlib.h>

/* a) Tempo O(1), espaco O(1). Assume i valido. */
int elemento(const int v[], int i) { return v[i]; }

/* b) Tempo O(n), espaco O(1). Assume n > 0. */
int maior(const int v[], int n) {
    int max = v[0];
    for (int i = 1; i < n; ++i) if (v[i] > max) max = v[i];
    return max;
}

/* c) Tempo O(n), espaco O(1), n par. */
void trocar_metades(int v[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = v[i];
        v[i] = v[i + n / 2];
        v[i + n / 2] = temp;
    }
}

/* d) Tempo O(m+n), espaco adicional O(m+n). */
int *concatenar(const int A[], int m, const int B[], int n) {
    if (m + n == 0) return NULL;
    int *C = malloc((size_t)(m + n) * sizeof *C);
    if (!C) return NULL;
    for (int i = 0; i < m; i++) C[i] = A[i];
    for (int i = 0; i < n; i++) C[m + i] = B[i];
    return C;
}

/* e) Tempo O(m*n), espaco O(1), desconsiderando a saida. */
void imprimir_pares(const int A[], int m, const int B[], int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            printf("(%d, %d)\n", A[i], B[j]);
}

/* f) Tempo O(n^2), espaco O(1). */
int soma_matriz(int n, const int A[n][n]) {
    int soma = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            soma += A[i][j];
    return soma;
}

/* Matriz criada com n linhas; cada linha possui n inteiros. */
int **alocar_matriz(int n) {
    int **M = calloc((size_t)n, sizeof *M);
    if (!M) return NULL;
    for (int i = 0; i < n; i++) {
        M[i] = calloc((size_t)n, sizeof **M);
        if (!M[i]) {
            for (int j = 0; j < i; j++) free(M[j]);
            free(M);
            return NULL;
        }
    }
    return M;
}
void liberar_matriz(int **M, int n) {
    if (!M) return;
    for (int i = 0; i < n; i++) free(M[i]);
    free(M);
}

/* g) Tempo O(n^2), espaco adicional O(n^2). */
int **transposta(int **A, int n) {
    int **T = alocar_matriz(n);
    if (!T) return NULL;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];
    return T;
}

/* h) Tempo O(n^3), espaco adicional O(n^2). */
int **multiplicar(int **A, int **B, int n) {
    int **C = alocar_matriz(n);
    if (!C) return NULL;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

int main(void) {
    int v[] = {3, 8, 5, 2};
    int B[] = {10, 20};
    printf("a) Elemento 2: %d\n", elemento(v, 2));
    printf("b) Maior: %d\n", maior(v, 4));
    trocar_metades(v, 4);
    printf("c) Metades trocadas: %d %d %d %d\n", v[0], v[1], v[2], v[3]);
    int *C = concatenar(v, 4, B, 2);
    if (!C) return 1;
    printf("d) Vetor concatenado: ");
    for (int i = 0; i < 6; i++) printf("%d%c", C[i], i == 5 ? '\n' : ' ');
    puts("e) Pares:");
    imprimir_pares(v, 4, B, 2);
    const int matriz[2][2] = {{1, 2}, {3, 4}};
    printf("f) Soma: %d\n", soma_matriz(2, matriz));
    int **A = alocar_matriz(2), **D = alocar_matriz(2);
    if (!A || !D) { free(C); liberar_matriz(A, 2); liberar_matriz(D, 2); return 1; }
    A[0][0]=1; A[0][1]=2; A[1][0]=3; A[1][1]=4;
    D[0][0]=2; D[0][1]=0; D[1][0]=1; D[1][1]=2;
    int **T = transposta(A, 2), **P = multiplicar(A, D, 2);
    if (!T || !P) {
        free(C); liberar_matriz(A, 2); liberar_matriz(D, 2);
        liberar_matriz(T, 2); liberar_matriz(P, 2); return 1;
    }
    printf("g) Transposta: [[%d,%d],[%d,%d]]\n",T[0][0],T[0][1],T[1][0],T[1][1]);
    printf("h) Produto: [[%d,%d],[%d,%d]]\n",P[0][0],P[0][1],P[1][0],P[1][1]);
    free(C);
    liberar_matriz(A, 2); liberar_matriz(D, 2);
    liberar_matriz(T, 2); liberar_matriz(P, 2);
    return 0;
}
