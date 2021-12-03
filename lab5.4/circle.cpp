#include "circle.h"

circle::circle()
{
	radius = 0;
}

circle::circle(int corx, int cory, int size):position(corx,cory)
{
	radius = size;
}

circle::circle(circle& temp):position(temp)
{
	this->radius = temp.radius;
}

circle::~circle()
{
}

double circle::per()
{
	return 2*radius*3,14;
}

double circle::area()
{
	return 3.14*radius*radius;
}

int circle::getrad()
{
	return this->radius;
}
