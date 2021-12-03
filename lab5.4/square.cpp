#include "square.h"

square::square()
{
	len = 0;
}

square::square(int corx, int cory, int size):position(corx, cory)
{
	len = size;
}

square::square(square& temp):position(temp)
{
	this->len = temp.len;
}

square::~square()
{
}

int square::per()
{
	return this->len * 4;
}

int square::area()
{
	return this->len * this->len;
}

int square::getlen()
{
	return this->len;
}
