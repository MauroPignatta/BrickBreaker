#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "../lib/games.h"
#include "../lib/table.h"
#include "../lib/logic.h"

char Movement = ' ';

void shipMove()
{
	while(1)
	{
		if (kbhit())
		{
			Movement = getchar();
		}
	}
}

int main(int argc, char ** argv)
{
	pthread_t MovementThread;
	pthread_create(&MovementThread, NULL,(void *) shipMove, NULL);

	system("clear");

	char Table[MaxY][MaxX];
	ST_Ship ship = initShip();
	ST_Ball ball = initBall();

	initTable(Table, ship, ball);
	Draw(Table);
	int tick = 0;
	while (1)
	{
		shipMovement(&ship, &Movement);
		if (tick == 2)
		{
			tick = 0;
			ballMovement(&ball);
		}
		initTable(Table, ship, ball);
		Sleep(100);
		clearScreen;
		Draw(Table);
		tick++;
	}

	pthread_join(MovementThread, NULL);
	return 0;
}