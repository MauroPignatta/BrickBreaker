#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //tolower

#define MaxY 40
#define MaxX 50
#define LEFT 'a'
#define RIGHT 'd'

typedef enum BALL_DIRECTION{NE , NW , SE, SW}BALL_DIR;

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
	BALL_DIR direction;
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

	void shipMovement(ST_Ship *ship, char *direction);

	void ballMovement (ST_Ball *ball);

	void hitboxBall(ST_Ball *ball, char Table[MaxY][MaxX]);

#endif /* PLAYER_H */