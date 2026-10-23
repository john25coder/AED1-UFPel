CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g
TARGET = programa
OBJS = main.o personagem.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.c personagem.h
	$(CC) $(CFLAGS) -c main.c

personagem.o: personagem.c personagem.h
	$(CC) $(CFLAGS) -c personagem.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
