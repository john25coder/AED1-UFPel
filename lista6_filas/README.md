# Lista 6 — Filas

**Disciplina:** Algoritmos e Estruturas de Dados I — UFPel
**Aluno:** João Victor Rutz Crespo — **Matrícula:** 22103178
**Linguagem:** C11

## Exercícios

| Nº | Implementação | Observação |
| --- | --- | --- |
| 1 | `fila.h`, `fila.c`, `main.c` | TAD de fila simplesmente encadeada; representação oculta em `fila.c`; interface exigida preservada. |
| 2 | `exercicio02.c`, `operacoes.c` | Maior elemento; fila preservada, O(n) em tempo e O(1) em espaço extra. |
| 3 | `exercicio03.c`, `operacoes.c`, `pilha_int.*` | Inversão com pilha auxiliar encadeada, O(n) em tempo e espaço. |
| 4 | `exercicio04.c`, `operacoes.c` | Separação de pares e ímpares, preservando a ordem relativa em cada destino. A fila original também é preservada. |
| 5 | `exercicio05.c`, `operacoes.c` | `void remover(Fila *, int)`, apenas com operações públicas da fila, O(n) em tempo. |
| 6 | `exercicio06.c`, `operacoes.c` | Intercalação de duas filas; consome as duas filas de origem e retorna uma terceira. |
| 7 | `exercicio07.c` | Menu de senhas FIFO; números gerados sequencialmente. |
| 8 | `exercicio08.c`, `fila_clientes.*`, `cliente.h` | Atendimento de clínica com nome e número; TAD de clientes separado. |
| 9 | `exercicio09/` | Fila circular de clientes, vetor fixo de 6 posições, capacidade útil de 5. |
| 10 | `exercicio10/` | Fila de documentos, com ID, nome e páginas; impressão FIFO. |

## Compilar e testar

```sh
make -C lista6_filas
make -C lista6_filas test
make -C lista6_filas clean
```

Também é possível executar `make test` na raiz do repositório, incluindo as Listas 1 a 6.

## Decisões de implementação

- O enunciado pede `typedef struct fila Fila;` no cabeçalho e oculta sua estrutura. Portanto, foram acrescentadas `fila_cria()` e `fila_libera()` para permitir instanciar e destruir a fila sem violar o encapsulamento. As funções exigidas (`reset`, `empty`, `size`, `enqueue`, `dequeue`, `front`, `clear`, `print`) permanecem com as assinaturas originais.
- A função `fila_primeiro()` é uma consulta adicional sem remoção, útil para os menus.
- A fila de caracteres da Lista 5 não pode armazenar inteiros sem alterar seu TAD. O exercício 3 utiliza uma pilha **de inteiros** independente (`pilha_int.*`).
- A operação `dequeue()` em fila vazia informa o erro e devolve `Elem{0}`; os programas clientes verificam `empty()` antes de removê-la. Para clientes e documentos, as operações de remoção retornam um indicador de sucesso.
- No exercício 4, as filas `pares` e `impares` recebem cópias dos **valores** por meio do TAD; a fila original permanece inalterada, e as filas de destino devem ser distintas.
- No exercício 6, os elementos são **retirados** das filas de entrada, como determina o enunciado; os nós internos não são expostos nem compartilhados.
- Os exercícios 8 a 10 usam estruturas próprias sem modificar `Elem` nem o TAD original. `cliente.h` é compartilhado pelos exercícios 8 e 9.
- No exercício 9, a condição de fila cheia é exatamente `(fim + 1) % CAPACIDADE_VETOR == inicio`. Assim, o vetor tem 6 posições e comporta até 5 clientes simultâneos, com reutilização circular dos índices.
- Entradas inválidas são tratadas nos menus. Nomes não podem ser vazios; documentos devem ter quantidade de páginas positiva.

## Testes

`tests/testar_lista6.sh` executa verificações unitárias para os TADs, para a preservação de ordem, para os casos-limite e para a fila circular, além de testes de interação com os menus. O script compila com `-std=c11 -Wall -Wextra -Wpedantic -Werror`.
