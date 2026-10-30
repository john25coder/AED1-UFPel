# Lista 5 — Pilhas

Resolucoes dos nove exercicios de **Algoritmos e Estruturas de Dados I** (UFPel), em C11.

| Exercicio | Arquivo(s) | O que implementa |
| --- | --- | --- |
| 1 | `pilha.h`, `pilha.c`, `main.c` | TAD opaco de caracteres, lista encadeada, `reset`, `empty`, `size`, `push`, `pop`, `top`, `clear`, `print`. |
| 2 | `exercicio02.c` | Inverte uma string usando pilha. |
| 3 | `exercicio03.c` | Verifica palindromo (comparacao exata, sensivel a maiusculas). |
| 4 | `exercicio04.c` | Valida o balanceamento de `()`, `{}`, `[]`. |
| 5 | `exercicio05.c` | Remove repeticoes consecutivas de caracteres usando pilha. |
| 6 | `exercicio06/` | `void remover(Pilha *pilha, float valor)`; preserva a ordem usando pilha auxiliar. |
| 7 | `exercicio07.c` | Inverte cada palavra, preservando os espacos. |
| 8 | `exercicio08.c` | Avalia expressoes pos-fixas com pilha numerica e valida erros. |
| 9 | `exercicio09/` | Historico de paginas com pilha de strings, menu e liberacao de memoria. |

## Decisoes sobre o enunciado

- **Exercicio 1:** `Pilha` e opaca em `pilha.h`, por isso foram adicionadas as funcoes `pilha_cria` e `pilha_libera` para gerenciar a instancia. Todas as oito assinaturas solicitadas foram mantidas. `reset` esvazia a pilha e `pop` retorna `{'\0'}` quando vazia, emitindo mensagem de erro.
- **Exercicio 6:** o enunciado solicita a assinatura `remover(Pilha *, float)`, mas o TAD do exercicio 1 usa `Elem` com `char` e os exemplos usam letras. Para preservar **a assinatura numerica solicitada**, este exercicio possui um TAD de `float` isolado em `exercicio06/`, sem modificar o TAD de caracteres do exercicio 1. A funcao `remover` utiliza apenas `empty`, `pop`, `push`, `pilha_cria` e `pilha_libera` da interface desse TAD. Os valores sao comparados por igualdade exata (`==`), adequada para a remocao do mesmo valor armazenado.
- **Exercicio 8:** operadores suportados: `+`, `-`, `*`, `/`; operandos inteiros ou reais separados por espacos. Verifica falta/excesso de operandos, tokens invalidos e divisao por zero. O resultado e `double`.
- **Exercicio 9:** foi criado um novo TAD de strings, independente do TAD de caracteres; as paginas sao copiadas para memoria dinamica.

## Compilacao e testes

```sh
make -C lista5_pilhas all
make -C lista5_pilhas/exercicio06 all
make -C lista5_pilhas/exercicio09 all
make -C lista5_pilhas test
```

A partir da raiz do repositorio, `make test` executa tambem os testes das Listas 1 a 4. O teste da Lista 5 verifica casos tipicos e de borda; compile com `-Wall -Wextra -Wpedantic -Werror` para checar avisos. Para apagar os executaveis, execute `make -C lista5_pilhas clean`.
