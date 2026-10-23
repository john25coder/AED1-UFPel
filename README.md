# Algoritmos e Estruturas de Dados I — Resoluções em C

**Aluno:** João Victor Rutz Crespo  
**Matrícula:** 22103178  
**Instituição:** Universidade Federal de Pelotas (UFPel)

Projeto de estudo organizado a partir das sete listas de exercícios fornecidas em PDF. A implementação segue o enunciado de cada lista, com os arquivos, assinaturas e restrições pedidos; quando algum comportamento não é especificado, a escolha fica documentada.

## Entregas implementadas

| Pasta | Lista | Material |
| --- | --- | --- |
| `lista1_ponteiros/` | 1 — Ponteiros | Questões 1–3 e respostas da 4 em Markdown; executáveis de demonstração da 4 à 15. |
| `lista2_complexidade/` | 2 — Complexidade | Questões 1–2 resolvidas e 8 funções da questão 3 em C. |
| `lista3_tad_personagem/` | 3 — TAD Personagem | `personagem.h`, `personagem.c`, `main.c`, Makefile. |
| `lista4_listas_encadeadas/` | 4 — Listas Encadeadas | Lista simples: questões 1–11; lista dupla: questões 12–14; testes e Makefile. |

**Listas 5, 6 e 7** estão previstas para publicações posteriores; ainda não constam nesta entrega.

## Como verificar

Requer GCC e `make` em ambiente Linux/macOS (ou adaptado para Windows).

```sh
make test
```

O teste compila os arquivos C com `-Wall -Wextra -Wpedantic -Werror`, executa os programas de exemplo e valida saídas selecionadas. Também há um workflow de GitHub Actions em `.github/workflows/ci.yml` para executar `make test` a cada push ou pull request. **Esses testes não substituem avaliação com entradas adversas, análise de memória ou revisão do professor.**

Para executar as listas 3 e 4 manualmente:

```sh
cd lista3_tad_personagem && make && ./programa && make clean
cd ../lista4_listas_encadeadas && make test && make clean
```

### Observações

- Os exercícios de ponteiros com funções possuem um `main` demonstrativo, conforme orientação do enunciado.
- Na Lista 2, o custo exato T(n) depende da definição de operação básica, especificada no documento de respostas.
- No TAD Personagem, a cura restaura 20 pontos por chamada, pois o enunciado define somente o limite de 100 pontos, não um incremento específico.
- Na Lista 4, `removerInicio` e `removerFinal` retornam 1 para remoção bem-sucedida e 0 para lista vazia (o enunciado não define a semântica do retorno).
- A implementação da lista dupla é separada para evitar conflitos de tipos com a lista simples.

## Publicação no GitHub

Os quatro primeiros commits locais correspondem às Listas 1 a 4. Um quinto commit acrescenta a integração contínua e a documentação para publicação. O remoto `origin` já está configurado para `john25coder/AED1-UFPel`, mas **o repositório remoto precisa ser criado e o envio requer autenticação**. Após criar um repositório vazio com esse nome, execute:

```sh
git remote -v
git push -u origin main
```

O comando `git push` depende de autenticação e permissões do repositório. Não publique senhas ou tokens no código.


## Critérios de qualidade

- Seguir as assinaturas e os nomes de arquivos exigidos por cada lista (por exemplo, `personagem.h`, `personagem.c`, `main.c` e `Makefile`).
- Encapsular os dados internos dos TADs quando o enunciado exigir.
- Liberar toda memória alocada dinamicamente; evitar acesso a memória liberada e vazamentos.
- Exercícios com listas mantêm a ordem e os casos-limite definidos no enunciado.
- Testar e compilar cada entrega antes de criar commits; não incluir executáveis no repositório.
- Registrar decisões em pontos não especificados, como o incremento de cura do personagem.
- Não publicar as Listas 5, 6 e 7 antes de estarem efetivamente resolvidas e testadas.
