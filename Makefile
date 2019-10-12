all: arkanoid

SRC = src/table.c src/player.c src/Arkanoid.c

LIB = lib/table.h lib/player.h

CFLAGS = -Ilib

CC = gcc

arkanoid: $(LIB) $(SRC)
	$(CC) $(CFLAGS) -o arkanoid $(SRC)