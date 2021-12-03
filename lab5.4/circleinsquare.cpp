#include "circleinsquare.h"

circleinsquare::circleinsquare()
{
}

circleinsquare::circleinsquare(circleinsquare& temp):position(temp),square(temp),circle(temp)
{

}

circleinsquare::circleinsquare(int x, int y,int rad):position(x,y),square(x,y,rad*2),circle(x,y,rad)
{

}



circleinsquare::~circleinsquare()
{
}
