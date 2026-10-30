#ifndef ENTRADA_H
#define ENTRADA_H

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Retorna 1 para entrada valida, 0 para EOF e -1 para entrada invalida. */
static inline int lerInteiro(const char *mensagem, int *resultado) {
    char linha[128];
    if (mensagem != NULL) fputs(mensagem, stdout);
    if (fgets(linha, sizeof linha, stdin) == NULL) return 0;
    if (strchr(linha, '\n') == NULL && !feof(stdin)) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return -1;
    }
    char *fim;
    errno = 0;
    long valor = strtol(linha, &fim, 10);
    if (fim == linha || errno == ERANGE || valor < INT_MIN || valor > INT_MAX)
        return -1;
    while (isspace((unsigned char)*fim)) fim++;
    if (*fim != '\0') return -1;
    *resultado = (int)valor;
    return 1;
}

static inline int lerTexto(const char *mensagem, char *destino, size_t capacidade) {
    if (destino == NULL || capacidade < 2) return -1;
    if (mensagem != NULL) fputs(mensagem, stdout);
    if (fgets(destino, capacidade, stdin) == NULL) return 0;
    char *quebra = strchr(destino, '\n');
    if (quebra != NULL) *quebra = '\0';
    else if (!feof(stdin)) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return -1;
    }
    return destino[0] == '\0' ? -1 : 1;
}

#endif
