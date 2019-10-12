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
	printf("Arkanoid Game\n");

	char Table[MaxY][MaxX];
	ST_Ship ship = initShip();

	initTable(Table, ship);
	Draw(Table);

	while (1)
	{
		if (Movement == 'a' || Movement == 'A')
		{
			if(ship.posX > 1)
			{
				ship.posX -- ;
			}
		}
		if (Movement == 'd' || Movement == 'D')
		{
			if(ship.posX < MaxX - ship.len -1)
			{
				ship.posX ++ ;
			}
		}
		Movement = ' ';
		refreshTable(Table, ship);
		Sleep(100);
		clearScreen;
		Draw(Table);
	}
	


	pthread_join(MovementThread, NULL);
	return 0;
}