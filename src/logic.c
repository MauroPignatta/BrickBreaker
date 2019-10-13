#include "../lib/logic.h"

ST_Ship initShip()
{
	ST_Ship ship;
	ship.len = 6;
	ship.letter = '@';
	ship.posX = MaxX/2 - ship.len/2;
	ship.posY = MaxY - 3;
	return ship;
}

ST_Ball initBall()
{
	ST_Ball ball;
	ball.letter = 'o';
	ball.direction = NE;
	ball.posY = MaxY - 4;
	ball.posX = MaxX/2;
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
		if(ship->posX < MaxX - ship->len -1)
		{
			ship->posX ++ ;
		}
	}
	*direction = ' ';
}

void hitboxBall(ST_Ball *ball, char Table[MaxY][MaxX])
{
	int i = ball->posY;
	int j = ball->posX;
	switch (ball->direction)
	{
		case NE:
			if (Table[i][j + 1] != ' ' && Table[i - 1][j] != ' ')  // choca justo en una esquina
				ball->direction = SE;
			else if ( Table[i - 1][j]  != ' ')  //choca con algo arriba
				ball->direction = SW;
			else if (Table[i][j + 1] != ' ')   //choca con algo a los lados
				ball->direction = NW;
			break;
		case NW:
			if (Table[i][j - 1] != ' ' && Table[i - 1][j] != ' ')  // choca justo en una esquina
				ball->direction = SW;
			else if ( Table[i - 1][j] != ' ')  //choca con algo arriba
				ball->direction = SE;
			else if (Table[i][j - 1] != ' ')   //choca con algo a los lados
				ball->direction = NE;
			break;
		case SW:
			if (Table[i][j + 1] != ' ' && Table[i + 1][j] != ' ')  // choca justo en una esquina
				ball->direction = NW;
			else if ( Table[i + 1][j] != ' ')  //choca con algo arriba
				ball->direction = NE;
			else if (Table[i][j + 1] != ' ')   //choca con algo a los lados
				ball->direction = SE;
			break;
		case SE:
			if (Table[i][j - 1] != ' ' && Table[i + 1][j] != ' ')  // choca justo en una esquina
				ball->direction = NE;
			else if (Table[i + 1][j] != ' ')  //choca con algo arriba
				ball->direction = NW;
			else if (Table[i][j - 1] != ' ')   //choca con algo a los lados
				ball->direction = SW;
			break;
	}
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

int brickDestoyed(ST_Ball ball,char Table[MaxY][MaxX] )
{
	int i = ball.posY;
	int j = ball.posX;
	char brickUP;
	char brickSIDE;
	int hitbrick = 0;
	if (Table[i - 1][j] != ' ' && Table[i - 1][j] != '#' && Table[i - 1][j] != '@')
	{
		if(Table[i - 1][j] == '+' || Table[i - 1][j] == '*')
		{
			brickUP = Table[i - 1][j];
			Table[i - 1][j] = ' ';
			if(Table[i - 1][j + 1] == brickUP)
				Table[i - 1][j + 1] = ' ';
			else
				Table[i - 1][j - 1] = ' ';
		}
		if(Table[i][j + 1] == '*' || Table[i][j + 1] == '+' || Table[i][j - 1] == '*' || Table[i][j - 1] == '+')
		{
			if (Table[i][j - 1] == '*' || Table[i][j - 1] == '+')
			{
				brickSIDE = Table[i][j - 1];
				Table[i][j - 1] = ' ';
				if(Table[i][j - 2] != '#')
					Table[i][j - 2] = ' ';
			}
			else 
			{
				brickSIDE = Table[i][j + 1];
				Table[i][j + 1] = ' ';
				if(Table[i][j + 2] != '#')
					Table[i][j + 2] = ' ';
			}
		}
		hitbrick = 1;
	}
	return hitbrick;
}