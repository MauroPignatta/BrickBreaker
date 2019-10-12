#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

#define MaxY 40
#define MaxX 50

	void initTable( char Table[MaxY][MaxX] , ST_Ship ship);

	void Draw( char Table[MaxY][MaxX] );
	
	void refreshTable(char Table[MaxY][MaxX], ST_Ship ship);

#endif //TABLE_H