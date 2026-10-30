#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    double valor;
    struct nodo *prox;
} Nodo;

typedef struct {
    Nodo *topo;
    int tamanho;
} PilhaNumerica;

static int empilhar(PilhaNumerica *pilha, double valor) {
    Nodo *novo = malloc(sizeof *novo);
    if (novo == NULL) return 0;
    novo->valor = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    ++pilha->tamanho;
    return 1;
}

static int desempilhar(PilhaNumerica *pilha, double *resultado) {
    if (pilha->topo == NULL) return 0;
    Nodo *removido = pilha->topo;
    *resultado = removido->valor;
    pilha->topo = removido->prox;
    --pilha->tamanho;
    free(removido);
    return 1;
}

static void limpar(PilhaNumerica *pilha) {
    double descartado;
    while (desempilhar(pilha, &descartado)) { }
}

static int avaliar(char *expressao, double *resultado) {
    PilhaNumerica pilha = {NULL, 0};
    int valido = 1;
    /* strtod permite numeros inteiros, reais e negativos, separados por espacos. */
    char *token = strtok(expressao, " \t\r\n");
    while (token != NULL && valido) {
        if (strlen(token) == 1 && strchr("+-*/", token[0]) != NULL) {
            double direita, esquerda, valor;
            if (!desempilhar(&pilha, &direita) ||
                !desempilhar(&pilha, &esquerda)) {
                valido = 0;
                break;
            }
            switch (token[0]) {
                case '+': valor = esquerda + direita; break;
                case '-': valor = esquerda - direita; break;
                case '*': valor = esquerda * direita; break;
                default:
                    if (direita == 0.0) { valido = 0; valor = 0.0; }
                    else valor = esquerda / direita;
                    break;
            }
            if (valido && (!isfinite(valor) || !empilhar(&pilha, valor))) valido = 0;
        } else {
            char *fim;
            errno = 0;
            double numero = strtod(token, &fim);
            if (fim == token || *fim != '\0' || errno == ERANGE ||
                !isfinite(numero) || !empilhar(&pilha, numero)) valido = 0;
        }
        token = strtok(NULL, " \t\r\n");
    }
    if (pilha.tamanho != 1) valido = 0;
    if (valido) (void)desempilhar(&pilha, resultado);
    limpar(&pilha);
    return valido;
}

int main(void) {
    char expressao[2048];
    if (fgets(expressao, sizeof expressao, stdin) == NULL) return EXIT_FAILURE;
    double resultado;
    if (!avaliar(expressao, &resultado)) {
        fputs("Expressao pos-fixa invalida.\n", stderr);
        return EXIT_FAILURE;
    }
    printf("Resultado: %.10g\n", resultado);
    return EXIT_SUCCESS;
}
