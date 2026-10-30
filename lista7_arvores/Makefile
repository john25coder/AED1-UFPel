CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Werror -O2
CPPFLAGS ?=
LDFLAGS ?=
LDLIBS ?=
EXERCICIOS := $(wildcard exercicio*.c)
FONTES := arvore.c $(EXERCICIOS)

.PHONY: all test clean
all: programa
programa: main.c $(FONTES) arvore.h
	$(CC) $(CPPFLAGS) $(CFLAGS) main.c $(FONTES) $(LDFLAGS) $(LDLIBS) -o $@
tests/testar_arvore: tests/testar_arvore.c $(FONTES) arvore.h
	$(CC) $(CPPFLAGS) $(CFLAGS) tests/testar_arvore.c $(FONTES) $(LDFLAGS) $(LDLIBS) -o $@
test: all tests/testar_arvore
	./tests/testar_arvore
	./programa > tests/ultima_saida.txt
	grep -q 'Ex. 14 - LCA de 3 e 7: 5' tests/ultima_saida.txt
	grep -q 'Nivel 2: 55' tests/ultima_saida.txt
	grep -q '10 -> 20 -> 15' tests/ultima_saida.txt
	@echo 'LISTA_7_OK'
clean:
	rm -f programa tests/testar_arvore tests/ultima_saida.txt
