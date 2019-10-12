#include "../lib/table.h"

void initTable(char Table[MaxY][MaxX], ST_Ship ship)
{
	int flag = 0;
	for(int i = 0; i < MaxY; i ++)
	{
		for(int j = 0; j < MaxX; j ++)
		{
			if (i == 0 || i == MaxY -1)
				Table[i][j] = '#';
			else if(j == 0 || j == MaxX -1)
				Table[i][j] = '#';
			else if (ship.len > 0 && flag || (ship.posY == i && ship.posX == j) )
			{
				Table[i][j] = ship.letter;
				flag = 1;
				ship.len--;
			}
			else
				Table[i][j] = ' ';
		}
	}
}

void Draw(char Table[MaxY][MaxX])
{
	printf("\n");
	for(int i = 0; i < MaxY; i ++)
	{
		for(int j = 0; j < MaxX; j ++)
		{
			printf("%c",Table[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void refreshTable(char Table[MaxY][MaxX], ST_Ship ship)
{
	int i = ship.posY;
	int flag = 0;
	for(int j = 0; j < MaxX; j++)
	{
		if (j == 0 || j == MaxX -1)
		{
			Table[i][j] = '#';
		}
		else if (ship.len > 0 && flag || ship.posX == j )
		{
			Table[i][j] = ship.letter;
			flag = 1;
			ship.len--;
		}
		else
			Table[i][j] = ' ';
	}
}