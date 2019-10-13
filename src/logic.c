#include "../lib/logic.h"

ST_Ship initShip()
{
	ST_Ship ship;
	ship.len = 8;
	ship.letter = '@';
	ship.posX = 21;
	ship.posY = 37;
	return ship;
}

ST_Ball initBall()
{
	ST_Ball ball;
	ball.letter = 'o';
	ball.direction = NW;
	ball.posY = 36;
	ball.posX = 25;
	return ball;
}

void shipMovement(ST_Ship *ship, char *direction)
{
	*direction = tolower(*direction);
	if (*direction == LEFT)
	{
		if(ship->posX > 1)
		{
			ship->posX -- ;
		}
	}
	if (*direction == RIGHT)
	{
		if(ship->posX < 50 - ship->len -1)
		{
			ship->posX ++ ;
		}
	}
	*direction = ' ';
}

void hitboxBall(ST_Ball *ball)
{

}

void ballMovement (ST_Ball *ball)
{
	switch (ball->direction)
	{
		case NE:
			ball->posX ++;
			ball->posY --;
			break;
		case NW:
			ball->posX --;
			ball->posY --;
			break;
		case SW:
			ball->posX ++;
			ball->posY ++;
			break;
		case SE:
			ball->posX --;
			ball->posY ++;
			break;
	}
}