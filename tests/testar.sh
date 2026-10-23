#!/bin/sh
set -eu
cd "$(dirname "$0")/.."
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"; make -C lista3_tad_personagem clean >/dev/null; make -C lista4_listas_encadeadas clean >/dev/null' EXIT

printf '%s\n' '[Lista 1] Compilando e executando os 12 programas...'
for arquivo in lista1_ponteiros/*.c; do
  nome="$(basename "$arquivo" .c)"
  gcc -std=c11 -Wall -Wextra -Wpedantic -Werror "$arquivo" -o "$TMP/$nome"
  case "$nome" in
    exercicio10) printf '10\n20\n-1\n' | "$TMP/$nome" > "$TMP/saida" ; grep -q 'Quantidade: 2' "$TMP/saida" ;;
    exercicio15) printf '2\n1 2\n3 4\n' | "$TMP/$nome" > "$TMP/saida" ; grep -q 'Soma da diagonal: 5' "$TMP/saida" ;;
    *) "$TMP/$nome" > "$TMP/saida" ;;
  esac
done
"$TMP/exercicio04" > "$TMP/resposta4"
printf '2\n6\n8\n3\n10\n' | diff - "$TMP/resposta4"
"$TMP/exercicio13" | grep -q 'Vetor vazio: sim'

printf '%s\n' '[Lista 2] Compilando e testando os algoritmos...'
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror lista2_complexidade/exercicio03.c -o "$TMP/lista2"
"$TMP/lista2" > "$TMP/saida"
grep -q 'f) Soma: 10' "$TMP/saida"
grep -q 'h) Produto: \[\[4,4\],\[10,8\]\]' "$TMP/saida"

printf '%s\n' '[Lista 3] Testando o TAD Personagem...'
make -s -C lista3_tad_personagem CFLAGS='-std=c11 -Wall -Wextra -Wpedantic -Werror' all
./lista3_tad_personagem/programa > "$TMP/saida"
grep -q 'Bruno esta vivo? 0' "$TMP/saida"

printf '%s\n' '[Lista 4] Testando listas simples e duplas...'
make -s -C lista4_listas_encadeadas CFLAGS='-std=c11 -Wall -Wextra -Wpedantic -Werror' test > "$TMP/saida"
grep -q 'Todas as verificacoes' "$TMP/saida"
grep -q 'Testes de lista duplamente' "$TMP/saida"

printf '%s\n' 'TODOS OS TESTES PASSARAM.'
