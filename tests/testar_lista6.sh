#!/bin/sh
set -eu
cd "$(dirname "$0")/.."
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT
P=lista6_filas
CFLAGS='-std=c11 -Wall -Wextra -Wpedantic -Werror'

printf '%s\n' '[Lista 6] TAD, operacoes e casos-limite...'
gcc $CFLAGS "$P/tests/testar_fila.c" "$P/fila.c" "$P/operacoes.c" "$P/pilha_int.c" -o "$TMP/testar_fila"
"$TMP/testar_fila"

gcc $CFLAGS "$P/tests/testar_tipos.c" "$P/fila_clientes.c" "$P/exercicio09/fila_circular.c" "$P/exercicio10/fila_documentos.c" -o "$TMP/testar_tipos"
"$TMP/testar_tipos"

printf '%s\n' '[Lista 6] Exemplos dos exercicios 1 a 6...'
"$P/exercicio01" | grep -Fq 'Vazia apos reset: sim'
"$P/exercicio02" | grep -Fq 'Maior: 31'
"$P/exercicio03" | grep -Fq '40 -> 30 -> 20 -> 10'
"$P/exercicio04" | grep -Fq '10 -> 20 -> 30'
"$P/exercicio04" | grep -Fq '15 -> 7'
"$P/exercicio05" | grep -Fq '8 -> 5 -> 9'
"$P/exercicio06" | grep -Fq '10 -> 40 -> 20 -> 50 -> 30 -> 60'

printf '%s\n' '[Lista 6] Menus: senhas, clinica, banco e impressao...'
printf '1\n1\n3\n4\n2\n3\n0\n' | "$P/exercicio07" > "$TMP/saida"
grep -Fq 'Senha gerada: 1' "$TMP/saida"
grep -Fq 'Senha gerada: 2' "$TMP/saida"
grep -Fq 'Proxima senha: 1' "$TMP/saida"
grep -Fq 'Pessoas aguardando: 2' "$TMP/saida"
grep -Fq 'Chamando senha: 1' "$TMP/saida"
grep -Fq 'Proxima senha: 2' "$TMP/saida"

printf '1\nAna Silva\n1\nJoao Souza\n3\n2\n3\n4\n0\n' | "$P/exercicio08" > "$TMP/saida"
grep -Fq 'Paciente cadastrado: 101 - Ana Silva' "$TMP/saida"
grep -Fq 'Paciente cadastrado: 102 - Joao Souza' "$TMP/saida"
grep -Fq 'Proximo paciente: 101 - Ana Silva' "$TMP/saida"
grep -Fq 'Atendendo: 101 - Ana Silva' "$TMP/saida"
grep -Fq 'Proximo paciente: 102 - Joao Souza' "$TMP/saida"

printf '1\nA\n1\nB\n1\nC\n1\nD\n1\nE\n1\nF\n2\n1\nF\n3\n4\n0\n' | "$P/exercicio09/programa" > "$TMP/saida"
grep -Fq 'Fila cheia: nao e possivel cadastrar cliente.' "$TMP/saida"
grep -Fq 'Atendendo: 1 - A' "$TMP/saida"
grep -Fq 'Cliente cadastrado: 6 - F' "$TMP/saida"
grep -Fq 'Proximo cliente: 2 - B' "$TMP/saida"

printf '1\nRelatorio.pdf\n5\n1\nResumo.pdf\n2\n1\nO Hobbit.pdf\n328\n3\n2\n3\n0\n' | "$P/exercicio10/programa" > "$TMP/saida"
grep -Fq 'Documento adicionado: ID=1, Nome="Relatorio.pdf", Paginas=5' "$TMP/saida"
grep -Fq 'Imprimindo: Relatorio.pdf (5 paginas).' "$TMP/saida"
grep -Fq 'ID=2, Nome="Resumo.pdf", Paginas=2' "$TMP/saida"
grep -Fq 'ID=3, Nome="O Hobbit.pdf", Paginas=328' "$TMP/saida"

printf '%s\n' '[Lista 6] Todos os 10 exercicios passaram nos testes.'
