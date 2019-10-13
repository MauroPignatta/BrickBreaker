all: arkanoid

SRC = src/table.c src/logic.c src/games.c src/Arkanoid.c

LIB = lib/table.h lib/logic.h lib/games.h

CFLAGS = -Ilib -pthread

CC = gcc

arkanoid: $(LIB) $(SRC)
	$(CC) $(CFLAGS) -o bin/arkanoid $(SRC)