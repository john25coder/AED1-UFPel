#include "../entrada.h"
#include "fila_circular.h"
#include <stdio.h>

int main(void) {
    FilaCircular fila;
    circular_inicializa(&fila);
    int proximoNumero = 1;
    for (;;) {
        puts("\n1. Cadastrar cliente | 2. Chamar proximo | 3. Consultar proximo | 4. Exibir fila | 0. Sair");
        int opcao;
        int leitura = lerInteiro("Opcao: ", &opcao);
        if (leitura == 0 || (leitura == 1 && opcao == 0)) break;
        if (leitura != 1) { puts("Entrada invalida."); continue; }
        Cliente cliente;
        switch (opcao) {
            case 1: {
                if (circular_cheia(&fila)) { puts("Fila cheia: nao e possivel cadastrar cliente."); break; }
                int ok = lerTexto("Nome: ", cliente.nome, sizeof cliente.nome);
                if (ok == 0) return 0;
                if (ok != 1) { puts("Nome invalido."); break; }
                cliente.numero = proximoNumero++;
                circular_enqueue(&fila, cliente);
                printf("Cliente cadastrado: %d - %s\n", cliente.numero, cliente.nome);
                break;
            }
            case 2:
                if (circular_dequeue(&fila, &cliente))
                    printf("Atendendo: %d - %s\n", cliente.numero, cliente.nome);
                else puts("Nenhum cliente aguardando.");
                break;
            case 3:
                if (circular_front(&fila, &cliente))
                    printf("Proximo cliente: %d - %s\n", cliente.numero, cliente.nome);
                else puts("Nenhum cliente aguardando.");
                break;
            case 4:
                circular_print(&fila);
                break;
            default:
                puts("Opcao invalida.");
        }
    }
    return 0;
}
