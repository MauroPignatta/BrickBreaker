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