#!/bin/sh
set -eu
cd "$(dirname "$0")/.."
CC="${CC:-gcc}"
CFLAGS="${CFLAGS:--std=c11 -Wall -Wextra -Wpedantic -Werror}"
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"; make -C lista3_tad_personagem clean >/dev/null; make -C lista4_listas_encadeadas clean >/dev/null' EXIT

printf '%s\n' '[Lista 1] Compilando e executando os 12 programas...'
for arquivo in lista1_ponteiros/*.c; do
  nome="$(basename "$arquivo" .c)"
  "$CC" $CFLAGS "$arquivo" -o "$TMP/$nome"
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
"$CC" $CFLAGS lista2_complexidade/exercicio03.c -o "$TMP/lista2"
"$TMP/lista2" > "$TMP/saida"
grep -q 'f) Soma: 10' "$TMP/saida"
grep -q 'h) Produto: \[\[4,4\],\[10,8\]\]' "$TMP/saida"

printf '%s\n' '[Lista 3] Testando o TAD Personagem...'
make -s -C lista3_tad_personagem CC="$CC" CFLAGS="$CFLAGS" all
./lista3_tad_personagem/programa > "$TMP/saida"
grep -q 'Bruno esta vivo? 0' "$TMP/saida"

printf '%s\n' '[Lista 4] Testando listas simples e duplas...'
make -s -C lista4_listas_encadeadas CC="$CC" CFLAGS="$CFLAGS" test > "$TMP/saida"
grep -q 'Todas as verificacoes' "$TMP/saida"
grep -q 'Testes de lista duplamente' "$TMP/saida"

printf '%s\n' '[Regressao] Ponteiros, complexidade e regras do TAD Personagem...'
set --
for numero in 05 06 07 08 09 11 12 13 14 15; do
  "$CC" $CFLAGS -Dmain="exemplo_$numero" -c "lista1_ponteiros/exercicio$numero.c" -o "$TMP/ponteiros$numero.o"
  set -- "$@" "$TMP/ponteiros$numero.o"
done
"$CC" $CFLAGS tests/test_ponteiros.c "$@" -o "$TMP/test_ponteiros"
"$TMP/test_ponteiros"
"$CC" $CFLAGS -Dmain=exemplo_complexidade -c lista2_complexidade/exercicio03.c -o "$TMP/complexidade.o"
"$CC" $CFLAGS tests/test_complexidade.c "$TMP/complexidade.o" -o "$TMP/test_complexidade"
"$TMP/test_complexidade"
"$CC" $CFLAGS tests/test_personagem.c lista3_tad_personagem/personagem.c -o "$TMP/test_personagem"
"$TMP/test_personagem" > "$TMP/personagem"
printf '%s\n' 'Teste: vida=100, ataque=20, vivo=sim' \
  'Teste: vida=0, ataque=20, vivo=nao' 'Teste: vida=20, ataque=20, vivo=sim' \
  'Teste: vida=100, ataque=20, vivo=sim' 'TESTES_PERSONAGEM_OK' > "$TMP/personagem_esperado"
diff "$TMP/personagem_esperado" "$TMP/personagem"

printf '%s\n' 'TODOS OS TESTES PASSARAM.'
