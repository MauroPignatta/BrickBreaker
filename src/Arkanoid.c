#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "../lib/games.h"
#include "../lib/table.h"
#include "../lib/logic.h"

char Movement = ' ';

void getInput()
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
	pthread_create(&MovementThread, NULL,(void *) getInput, NULL);

	clearScreen;

	char Table[MaxY][MaxX];
	ST_Ship ship = initShip();
	ST_Ball ball = initBall();

	initTable(Table, ship, ball);
	Draw(Table);

	int tick = 0;
	int score = 0;
	while (ball.posY != MaxY - 1)
	{
		shipMovement(&ship, &Movement);
		if (tick == 2)
		{
			tick = 0;
			ballMovement(&ball);
			hitboxBall(&ball, Table);
			if(brickDestoyed(ball, Table))
				score += 100;
		}
		refreshTable(Table, ship, ball);
		usleep(40*1000);
		clearScreen;
		Draw(Table);
		tick++;
		printf("\nScore: %d\n", score);
	}
	printf("You Lost\n");
	pthread_join(MovementThread, NULL);
	return 0;
}