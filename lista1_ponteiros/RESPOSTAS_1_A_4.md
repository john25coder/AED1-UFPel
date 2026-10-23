# Lista 1 — Exercícios 1 a 4

**Exercício 1:** com `i=3`, `j=5`, `p=&i`, `q=&j`: a) `*p=3`; b) `*p-*q=-2`; c) `**&p=3`; d) `3 - 3/5 + 7 = 10` (divisão inteira).

**Exercício 2:** cada item parte do estado inicial, independentemente.
- a) `*p=*q;` => `i=5`, `j=5`, `p=&i`, `q=&j`.
- b) `p=q;` => `i=3`, `j=5`, `p=&j`, `q=&j`.
- c) `*p=*p+*q;` => `i=8`, `j=5`, `p=&i`, `q=&j`.
- d) `q=&i; *q=100;` => `i=100`, `j=5`, `p=&i`, `q=&i`.

**Exercício 3:**
- a) `p=v;` válida, aponta para `v[0]`.
- b) `p=&v;` incompatível: `&v` tem tipo `int (*)[5]`, e `p` tem tipo `int *`; requer diagnóstico do compilador (não é atribuição válida entre tipos compatíveis).
- c) `p=&v[0];` válida, aponta para `v[0]`.
- d) `v=p;` inválida: nome do vetor não é lvalue modificável.
- e) `p=v+2;` válida, aponta para `v[2]`.

**Exercício 4:** os `printf` exibem, na ordem: `2`, `6`, `8`, `3`, `10`.
Execute `exercicio04.c` para conferir.
