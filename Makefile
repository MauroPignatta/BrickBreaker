all: arkanoid

arkanoid: table.h player.h table.c player.c Arkanoid.c
	gcc -o arkanoid table.c player.c Arkanoid.c