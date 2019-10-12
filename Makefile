all: arkanoid

SRC = src/table.c src/logic.c src/Arkanoid.c src/games.c

LIB = lib/table.h lib/logic.h lib/games.h

CFLAGS = -Ilib -pthread

CC = gcc

arkanoid: $(LIB) $(SRC)
	$(CC) $(CFLAGS) -o arkanoid $(SRC)