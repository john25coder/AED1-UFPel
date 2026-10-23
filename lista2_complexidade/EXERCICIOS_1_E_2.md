# Lista 2 — Noções de Complexidade de Algoritmos

## Exercício 1: T(n) e Big-O

Convenção usada para calcular **uma** equação T(n): cada inicialização, comparação, incremento, atribuição/atualização, operação aritmética explicitamente separada e chamada de `printf` conta 1 operação. Uma expressão composta pode receber custo diferente conforme a convenção, mas a classe Big-O permanece a mesma. Para simplificar, `soma += i` e `i=i/2` contam como 1 atualização cada. Na letra c, a multiplicação `i*j` conta separadamente.

| Item | Contagem T(n), para n >= 1 | Big-O | Justificativa |
|---|---|---|---|
| a | `3n + 4` | **O(n)** | Um laço de n iterações, uma soma por iteração. |
| b | `3n² + 4n + 2` | **O(n²)** | Dois laços aninhados de n iterações. |
| c | `44n + 2` | **O(n)** | O laço interno executa exatamente 10 vezes por execução do externo. |
| d | `3⌊log₂(n)⌋ + 2` | **O(log n)** | n é dividido por 2 a cada passagem (para n >= 2). |
| e | `3n² + 7n + 4` | **O(n²)** | Laço simples O(n) seguido de dois laços aninhados O(n²). |

**Observação:** a contagem detalhada depende do que é definido como operação básica. Por exemplo, se cada `i++` for contado como uma soma e uma atribuição, os coeficientes mudam, mas o Big-O não.

## Exercício 2: dois elementos cuja soma é x

| Pergunta | `dois_soma_1` | `dois_soma2` |
|---|---|---|
| a) Tempo (pior caso) | **O(n²)** | **O(n)** |
| b) Espaço adicional | **O(1)** | **O(1)** |

**c)** A versão 2 é mais eficiente no pior caso: usa dois ponteiros (índices), um no início e outro no fim, e descarta uma posição a cada iteração. A versão 1 examina até `n(n-1)/2` pares.

**d)** A versão 2 depende de o vetor estar **ordenado em ordem crescente** (não decrescente). Isso permite concluir se é necessário mover o índice inicial ou o final. A versão 1 não depende da ordenação.
