CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g
.PHONY: all clean
all: programa
programa: main.c pilha_strings.c pilha_strings.h
	$(CC) $(CFLAGS) main.c pilha_strings.c -o $@
clean:
	rm -f programa
