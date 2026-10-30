#include "pilha_strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void descartar_restante(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main(void) {
    PilhaStrings *historico = pilhaStrings_cria();
    if (historico == NULL) return EXIT_FAILURE;
    char entrada[512];
    int executando = 1;
    while (executando) {
        puts("1 - Visitar pagina\n2 - Voltar\n3 - Pagina atual\n4 - Historico\n0 - Sair");
        if (fgets(entrada, sizeof entrada, stdin) == NULL) break;
        char *fim;
        long opcao = strtol(entrada, &fim, 10);
        if (fim == entrada || (*fim != '\n' && *fim != '\0')) {
            puts("Opcao invalida.");
            continue;
        }
        switch (opcao) {
            case 1:
                printf("Pagina: ");
                if (fgets(entrada, sizeof entrada, stdin) == NULL) {
                    executando = 0;
                    break;
                }
                if (strchr(entrada, '\n') == NULL && !feof(stdin)) {
                    descartar_restante();
                    puts("Nome da pagina muito longo.");
                    break;
                }
                entrada[strcspn(entrada, "\n")] = '\0';
                if (entrada[0] == '\0') { puts("Pagina vazia."); break; }
                if (!pushString(historico, entrada)) {
                    fputs("Falha de memoria.\n", stderr);
                    executando = 0;
                }
                break;
            case 2:
                if (pilhaStrings_vazia(historico)) {
                    puts("Nao ha pagina para voltar.");
                } else {
                    (void)popString(historico);
                    const char *pagina = topString(historico);
                    if (pagina != NULL) printf("Pagina atual: %s\n", pagina);
                    else puts("Historico vazio.");
                }
                break;
            case 3: {
                const char *pagina = topString(historico);
                if (pagina != NULL) printf("Pagina atual: %s\n", pagina);
                else puts("Historico vazio.");
                break;
            }
            case 4: printStrings(historico); break;
            case 0: executando = 0; break;
            default: puts("Opcao invalida."); break;
        }
    }
    pilhaStrings_libera(historico);
    return EXIT_SUCCESS;
}
