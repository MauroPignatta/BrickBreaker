#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
#include "player.h"

int main(int argc, char ** argv)
{

	system("clear");
	printf("Arkanoid Game\n");

	char Table[MaxY][MaxX];
	ST_Ship ship = initShip();

	initTable(Table, ship);

	Draw(Table);

	return 0;
}