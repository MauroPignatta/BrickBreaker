#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

	void initTable(char Table[MaxY][MaxX] , ST_Ship ship, ST_Ball ball);

	void refreshTable(char Table[MaxY][MaxX] , ST_Ship ship, ST_Ball ball);

	void Draw( char Table[MaxY][MaxX] );
	
#endif //TABLE_H