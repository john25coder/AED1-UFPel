CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g
PROGRAMAS = exercicio01 exercicio02 exercicio03 exercicio04 exercicio05 exercicio07 exercicio08

.PHONY: all clean test
all: $(PROGRAMAS)

exercicio01: main.c pilha.c pilha.h
	$(CC) $(CFLAGS) main.c pilha.c -o $@

exercicio02 exercicio03 exercicio04 exercicio05 exercicio07: %: %.c pilha.c pilha.h
	$(CC) $(CFLAGS) $< pilha.c -o $@

exercicio08: exercicio08.c
	$(CC) $(CFLAGS) $< -o $@

test: all
	$(MAKE) -C exercicio06 all
	$(MAKE) -C exercicio09 all
	../tests/testar_lista5.sh

clean:
	rm -f $(PROGRAMAS)
	$(MAKE) -C exercicio06 clean
	$(MAKE) -C exercicio09 clean
