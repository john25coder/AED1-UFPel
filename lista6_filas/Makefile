CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror -g
PROGRAMAS = exercicio01 exercicio02 exercicio03 exercicio04 exercicio05 exercicio06 exercicio07 exercicio08 exercicio09/programa exercicio10/programa

.PHONY: all test clean
all: $(PROGRAMAS)

exercicio01: main.c fila.c fila.h
	$(CC) $(CFLAGS) main.c fila.c -o $@

exercicio02 exercicio03 exercicio04 exercicio05 exercicio06: %: %.c operacoes.c fila.c pilha_int.c operacoes.h fila.h pilha_int.h
	$(CC) $(CFLAGS) $< operacoes.c fila.c pilha_int.c -o $@

exercicio07: exercicio07.c fila.c fila.h entrada.h
	$(CC) $(CFLAGS) exercicio07.c fila.c -o $@

exercicio08: exercicio08.c fila_clientes.c fila_clientes.h cliente.h entrada.h
	$(CC) $(CFLAGS) exercicio08.c fila_clientes.c -o $@

exercicio09/programa: exercicio09/main.c exercicio09/fila_circular.c exercicio09/fila_circular.h cliente.h entrada.h
	$(CC) $(CFLAGS) exercicio09/main.c exercicio09/fila_circular.c -o $@

exercicio10/programa: exercicio10/main.c exercicio10/fila_documentos.c exercicio10/fila_documentos.h entrada.h
	$(CC) $(CFLAGS) exercicio10/main.c exercicio10/fila_documentos.c -o $@

test: all
	../tests/testar_lista6.sh

clean:
	rm -f $(PROGRAMAS)
