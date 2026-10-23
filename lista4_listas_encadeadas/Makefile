CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g

all: lista_simples lista_dupla

lista_simples: main.o lista.o
	$(CC) $(CFLAGS) -o $@ $^

lista_dupla: main_dupla.o lista_dupla.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c lista.h
	$(CC) $(CFLAGS) -c $<

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c $<

main_dupla.o: main_dupla.c lista_dupla.h
	$(CC) $(CFLAGS) -c $<

lista_dupla.o: lista_dupla.c lista_dupla.h
	$(CC) $(CFLAGS) -c $<

test: all
	./lista_simples
	./lista_dupla

clean:
	rm -f *.o lista_simples lista_dupla

.PHONY: all test clean
