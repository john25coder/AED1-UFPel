#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int elemento(const int v[], int n, int i);
int maior(const int v[], int n);
void trocar_metades(int v[], int n);
int *concatenar(const int a[], int m, const int b[], int n);
int soma_matriz(int n, const int a[n][n]);
int **alocar_matriz(int n);
void liberar_matriz(int **m, int n);
int **transposta(int **a, int n);
int **multiplicar(int **a, int **b, int n);

int main(void) {
    int v[] = {-8, -2, -9, -4};
    assert(elemento(v, 4, 0) == -8 && elemento(v, 4, 3) == -4);
    assert(maior(v, 4) == -2);
    trocar_metades(v, 4);
    assert(v[0] == -9 && v[1] == -4 && v[2] == -8 && v[3] == -2);
    int b[] = {7};
    int *uniao = concatenar(v, 4, b, 1);
    assert(uniao && uniao[0] == -9 && uniao[3] == -2 && uniao[4] == 7);
    free(uniao);
    const int matriz[2][2] = {{2, -1}, {0, 5}};
    assert(soma_matriz(2, matriz) == 6);
    int **a = alocar_matriz(2), **d = alocar_matriz(2);
    assert(a && d);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    d[0][0] = 2; d[0][1] = 0; d[1][0] = 1; d[1][1] = 2;
    int **t = transposta(a, 2), **p = multiplicar(a, d, 2);
    assert(t && p);
    assert(t[0][0] == 1 && t[0][1] == 3 && t[1][0] == 2 && t[1][1] == 4);
    assert(p[0][0] == 4 && p[0][1] == 4 && p[1][0] == 10 && p[1][1] == 8);
    assert(a[0][1] == 2 && a[1][0] == 3);
    liberar_matriz(a, 2); liberar_matriz(d, 2);
    liberar_matriz(t, 2); liberar_matriz(p, 2);
    puts("TESTES_COMPLEXIDADE_OK");
    return 0;
}
