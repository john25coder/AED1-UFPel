CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g
.PHONY: all clean
all: programa
programa: main.c remover.c pilha.c pilha.h
	$(CC) $(CFLAGS) main.c remover.c pilha.c -o $@
clean:
	rm -f programa
