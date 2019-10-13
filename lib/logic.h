#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int len;
	char letter;
	int posX;
	int posY;
}ST_Ship;

typedef struct
{
	char letter;
	int posX;
	int posY;
}ST_Ball;

typedef struct 
{
	int letter;
	int size;
	int posX;
	int posY;
}ST_Brick;

	ST_Ship initShip();

	ST_Ball initBall();


#endif /* PLAYER_H */