#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void inverter(int *v, int n);
int soma(int *v, int n);
void troca_vizinhos(int *a, int *b);
void min_max(int *v, int n, int *min, int *max);
int *copia_vetor(int *v, int n);
int *concatenar(int *v1, int n1, int *v2, int n2, int *n3);
int *inserir(int *v, int *n, int valor);
int remover(int **v, int *n, int posicao);
int *intercalar(int *v1, int *v2, int n, int *n3);
int soma_diagonal(int **mat, int n);

int main(void) {
    int v[] = {4, -2, 9, 0};
    inverter(v, 4);
    assert(v[0] == 0 && v[1] == 9 && v[2] == -2 && v[3] == 4);
    assert(soma(v, 4) == 11 && soma(v, 0) == 0);
    troca_vizinhos(&v[0], &v[1]);
    assert(v[0] == 9 && v[1] == 0);
    int minimo = 0, maximo = 0;
    min_max(v, 4, &minimo, &maximo);
    assert(minimo == -2 && maximo == 9);
    int *copia = copia_vetor(v, 4);
    assert(copia && copia != v && copia[2] == -2);
    copia[2] = 50;
    assert(v[2] == -2);
    free(copia);
    assert(copia_vetor(v, 0) == NULL);

    int *a = malloc(2 * sizeof *a), *b = malloc(sizeof *b);
    assert(a && b);
    a[0] = 10; a[1] = 20; b[0] = 30;
    int tamanho = 0;
    int *uniao = concatenar(a, 2, b, 1, &tamanho);
    assert(uniao && tamanho == 3);
    assert(uniao[0] == 10 && uniao[1] == 20 && uniao[2] == 30);
    uniao[0] = 99;
    assert(a[0] == 10);
    free(a); free(b); free(uniao);

    int n = 0;
    int *dinamico = NULL;
    assert(!remover(&dinamico, &n, 0));
    dinamico = inserir(dinamico, &n, 10);
    assert(dinamico && n == 1 && dinamico[0] == 10);
    dinamico = inserir(dinamico, &n, 20);
    assert(n == 2 && dinamico[1] == 20);
    int *antes = dinamico;
    assert(!remover(&dinamico, &n, -1));
    assert(!remover(&dinamico, &n, 2));
    assert(dinamico == antes && n == 2 && dinamico[0] == 10 && dinamico[1] == 20);
    assert(remover(&dinamico, &n, 0));
    assert(n == 1 && dinamico[0] == 20);
    assert(remover(&dinamico, &n, 0));
    assert(n == 0 && dinamico == NULL);

    int x[] = {1, 3}, y[] = {2, 4};
    int *mescla = intercalar(x, y, 2, &tamanho);
    assert(mescla && tamanho == 4);
    assert(mescla[0] == 1 && mescla[1] == 2 && mescla[2] == 3 && mescla[3] == 4);
    free(mescla);
    assert(intercalar(x, y, 0, &tamanho) == NULL && tamanho == 0);
    int linha1[] = {2, 9}, linha2[] = {8, -3};
    int *matriz[] = {linha1, linha2};
    assert(soma_diagonal(matriz, 2) == -1);
    puts("TESTES_PONTEIROS_OK");
    return 0;
}
