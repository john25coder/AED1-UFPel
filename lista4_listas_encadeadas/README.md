# Lista 4 — Listas Encadeadas

- Exercício 1: interface `lista.h`, implementação `lista.c`, demonstração/testes `main.c`.
- Exercícios 2 a 11: funções adicionais documentadas em `lista.h`, testadas pelo `main.c`.
- Exercícios 12 a 14: variante `lista_dupla.h`, `lista_dupla.c` e `main_dupla.c`.
- `incorporar`, `intercalarListas` e `separarPosicoes` **transferem os nós existentes** entre listas; não fazem cópias.
- `copiarLista` aloca nós independentes. A separação exige listas de destino vazias.
- As funções de inversão fazem apenas religação de ponteiros.
- `duplaPalindromo` percorre simultaneamente do início e fim em tempo O(n) e espaço O(1).

```sh
make
make test
make clean
```

Os testes usam `assert`, operações da interface e cobrem listas vazias, remoção da cabeça/cauda, preservação de ordem e independência de cópia.
