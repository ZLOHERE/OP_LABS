#include "position.h"

position::position()
{
	x = 0;
	y = 0;
}

position::position(int corx, int cory)
{
	x = corx;
	y = cory;
}

position::~position()
{
}

void position::change(int corx, int cory)
{
	x = corx;
	y = cory;
}

int position::getx()
{
	return this->x;
}

int position::gety()
{
	return this->y;
}
