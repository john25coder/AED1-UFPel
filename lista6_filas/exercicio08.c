#include "entrada.h"
#include "fila_clientes.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FilaClientes *fila = clientes_cria();
    if (fila == NULL) return EXIT_FAILURE;
    int proximoNumero = 101;
    for (;;) {
        puts("\n1. Cadastrar paciente | 2. Chamar proximo | 3. Consultar proximo | 4. Exibir fila | 0. Sair");
        int opcao;
        int leitura = lerInteiro("Opcao: ", &opcao);
        if (leitura == 0 || (leitura == 1 && opcao == 0)) break;
        if (leitura != 1) { puts("Entrada invalida."); continue; }
        Cliente cliente;
        switch (opcao) {
            case 1: {
                int ok = lerTexto("Nome: ", cliente.nome, sizeof cliente.nome);
                if (ok == 0) goto sair;
                if (ok != 1) { puts("Nome invalido."); break; }
                cliente.numero = proximoNumero++;
                enqueueCliente(fila, cliente);
                printf("Paciente cadastrado: %d - %s\n", cliente.numero, cliente.nome);
                break;
            }
            case 2:
                if (dequeueCliente(fila, &cliente))
                    printf("Atendendo: %d - %s\n", cliente.numero, cliente.nome);
                else puts("Nenhum paciente aguardando.");
                break;
            case 3:
                if (frontCliente(fila, &cliente))
                    printf("Proximo paciente: %d - %s\n", cliente.numero, cliente.nome);
                else puts("Nenhum paciente aguardando.");
                break;
            case 4:
                printClientes(fila);
                break;
            default:
                puts("Opcao invalida.");
        }
    }
sair:
    clientes_libera(fila);
    return 0;
}
