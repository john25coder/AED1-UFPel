#!/bin/sh
set -eu
cd "$(dirname "$0")/.."
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT
P=lista5_pilhas
CFLAGS='-std=c11 -Wall -Wextra -Wpedantic -Werror'

printf '%s\n' '[Lista 5] TAD de caracteres e exercicios 2 a 5, 7 e 8...'
gcc $CFLAGS "$P/tests/testar_tad.c" "$P/pilha.c" -o "$TMP/tad"
"$TMP/tad"

printf 'ESTRUTURA DE DADOS\n' | "$P/exercicio02" | grep -Fq 'Invertida: SODAD ED ARUTURTSE'
printf '\n' | "$P/exercicio02" | grep -Fq 'Invertida:'
printf 'ARARA\n' | "$P/exercicio03" | grep -Fq 'ARARA: palindromo'
printf 'RADAR\n' | "$P/exercicio03" | grep -Fq 'RADAR: palindromo'
printf 'CASA\n' | "$P/exercicio03" | grep -Fq 'CASA: nao e palindromo'
printf '(3 + 5) * (7 - 2)\n' | "$P/exercicio04" | grep -Fxq 'Expressao balanceada.'
printf '([{}])\n' | "$P/exercicio04" | grep -Fxq 'Expressao balanceada.'
printf '(2 * (4 + 3)\n' | "$P/exercicio04" | grep -Fxq 'Expressao nao balanceada.'
printf '([)]\n' | "$P/exercicio04" | grep -Fxq 'Expressao nao balanceada.'
printf ')\n' | "$P/exercicio04" | grep -Fxq 'Expressao nao balanceada.'
printf 'AAABBBCCDAA\n' | "$P/exercicio05" | grep -Fxq 'Resultado: ABCDA'
printf 'AABBA\n' | "$P/exercicio05" | grep -Fxq 'Resultado: ABA'
printf 'ESTRUTURAS DE DADOS\n' | "$P/exercicio07" | grep -Fxq 'Resultado: SARUTURTSE ED SODAD'
printf '  AB   CD  \n' | "$P/exercicio07" | grep -Fxq 'Resultado:   BA   DC  '
printf '3 5 +\n' | "$P/exercicio08" | grep -Fxq 'Resultado: 8'
printf '5 1 2 + 4 * + 3 -\n' | "$P/exercicio08" | grep -Fxq 'Resultado: 14'
printf '5 2 - 4 * 6 2 / +\n' | "$P/exercicio08" | grep -Fxq 'Resultado: 15'
printf '3 4 + 5 *\n' | "$P/exercicio08" | grep -Fxq 'Resultado: 35'
printf '4 2 /\n' | "$P/exercicio08" | grep -Fxq 'Resultado: 2'
printf '2 3 -\n' | "$P/exercicio08" | grep -Fxq 'Resultado: -1'
if printf '3 0 /\n' | "$P/exercicio08" > "$TMP/saida" 2>&1; then echo 'Falha: divisao por zero aceita'; exit 1; fi
if printf '1 +\n' | "$P/exercicio08" > "$TMP/saida" 2>&1; then echo 'Falha: operandos insuficientes'; exit 1; fi
if printf '1 2\n' | "$P/exercicio08" > "$TMP/saida" 2>&1; then echo 'Falha: operandos excedentes'; exit 1; fi

printf '%s\n' '[Lista 5] Remocao de float e preservacao de ordem...'
gcc $CFLAGS "$P/tests/testar_remover.c" "$P/exercicio06/pilha.c" "$P/exercicio06/remover.c" -o "$TMP/remover"
"$TMP/remover"
"$P/exercicio06/programa" | grep -Fq 'Quantidade: 3'

printf '%s\n' '[Lista 5] Historico de navegacao e liberacao...'
gcc $CFLAGS "$P/tests/testar_strings.c" "$P/exercicio09/pilha_strings.c" -o "$TMP/strings"
"$TMP/strings"
printf '1\ngoogle.com\n1\nufpel.edu.br\n1\nwikipedia.org\n2\n3\n2\n3\n0\n' | "$P/exercicio09/programa" > "$TMP/saida"
grep -Fq 'Pagina atual: ufpel.edu.br' "$TMP/saida"
grep -Fq 'Pagina atual: google.com' "$TMP/saida"
printf '%s\n' '[Lista 5] Todos os 9 exercicios passaram nos testes.'
