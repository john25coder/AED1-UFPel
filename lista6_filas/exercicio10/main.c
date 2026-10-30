#include "../entrada.h"
#include "fila_documentos.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FilaDocumentos *fila = documentos_cria();
    if (fila == NULL) return EXIT_FAILURE;
    int proximoId = 1;
    for (;;) {
        puts("\n1. Adicionar documento | 2. Imprimir proximo | 3. Exibir fila | 0. Sair");
        int opcao;
        int leitura = lerInteiro("Opcao: ", &opcao);
        if (leitura == 0 || (leitura == 1 && opcao == 0)) break;
        if (leitura != 1) { puts("Entrada invalida."); continue; }
        Documento doc;
        switch (opcao) {
            case 1: {
                int ok = lerTexto("Nome do documento: ", doc.nome, sizeof doc.nome);
                if (ok == 0) goto sair;
                if (ok != 1) { puts("Nome invalido."); break; }
                ok = lerInteiro("Numero de paginas: ", &doc.paginas);
                if (ok == 0) goto sair;
                if (ok != 1 || doc.paginas <= 0) { puts("Numero de paginas invalido."); break; }
                doc.id = proximoId++;
                enqueueDocumento(fila, doc);
                printf("Documento adicionado: ID=%d, Nome=\"%s\", Paginas=%d\n", doc.id, doc.nome, doc.paginas);
                break;
            }
            case 2:
                if (dequeueDocumento(fila, &doc))
                    printf("Imprimindo: %s (%d paginas).\n", doc.nome, doc.paginas);
                else puts("Nenhum documento aguardando.");
                break;
            case 3:
                printDocumentos(fila);
                break;
            default:
                puts("Opcao invalida.");
        }
    }
sair:
    documentos_libera(fila);
    return 0;
}
