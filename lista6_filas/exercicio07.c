#include "entrada.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Fila *espera = fila_cria();
    if (espera == NULL) return EXIT_FAILURE;
    int proximaSenha = 1;
    for (;;) {
        puts("\n1. Gerar senha | 2. Chamar proxima | 3. Consultar proxima | 4. Quantidade | 0. Sair");
        int opcao;
        int leitura = lerInteiro("Opcao: ", &opcao);
        if (leitura == 0 || (leitura == 1 && opcao == 0)) break;
        if (leitura != 1) { puts("Entrada invalida."); continue; }
        Elem atual;
        switch (opcao) {
            case 1:
                enqueue(espera, (Elem){proximaSenha});
                printf("Senha gerada: %d\n", proximaSenha++);
                break;
            case 2:
                if (!empty(espera)) printf("Chamando senha: %d\n", dequeue(espera).valor);
                else puts("Nao ha senhas aguardando.");
                break;
            case 3:
                if (fila_primeiro(espera, &atual)) printf("Proxima senha: %d\n", atual.valor);
                else puts("Nao ha senhas aguardando.");
                break;
            case 4:
                printf("Pessoas aguardando: %d\n", size(espera));
                break;
            default:
                puts("Opcao invalida.");
        }
    }
    fila_libera(espera);
    return 0;
}
