#include "../lib/table.h"

void initTable(char Table[MaxY][MaxX], ST_Ship ship, ST_Ball ball)
{
	int flag = 0;
	int changeBrick = 1;
	char brick;
	for(int i = 0; i < MaxY; i ++)
	{
		for(int j = 0; j < MaxX; j ++)
		{
			if (i == 0)
				Table[i][j] = '#';
			else if(j == 0 || j == MaxX -1)
				Table[i][j] = '#';
			else if (i > 3 && i < MaxY/2 && j > 0 && j < MaxX -1)
			{
				if(changeBrick)
				{
					brick = '+';
					Table[i][j++] = brick;
					Table[i][j++] = brick;
					Table[i][j] = brick;
					changeBrick = 0;
				}
				else 
				{
					brick = '*';
					Table[i][j++] = brick;
					Table[i][j++] = brick;
					Table[i][j] = brick;
					changeBrick = 1;
				}
			}
			else if (ship.len > 0 && flag || (ship.posY == i && ship.posX == j) )
			{
				Table[i][j] = ship.letter;
				flag = 1;
				ship.len--;
			}
			else if(ball.posY == i && ball.posX ==j)
				Table[i][j] = ball.letter;
			else 
				Table[i][j] = ' ';
		}
	}
}

void refreshTable(char Table[MaxY][MaxX] , ST_Ship ship, ST_Ball ball)
{
	int flag = 0;
	
	for (int i = 0; i < MaxY ; i++)
	{
		for(int j = 0; j < MaxX -1; j++)
		{
			if (ship.len > 0 && flag || ship.posY == i && ship.posX == j)
			{
				Table[i][j] = ship.letter;
				flag = 1;
				ship.len--;
			}
			else if (ball.posY == i && ball.posX == j)
			{
				Table[ball.posY][ball.posX] = ball.letter;
			}
			else if (Table[i][j] == '*' || Table[i][j] == '+' || Table[i][j] == '#')
			{

			}
			else
				Table[i][j] = ' ';

		}
	}
	
}

void Draw(char Table[MaxY][MaxX])
{
	printf("Arkanoid Game\n");
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
