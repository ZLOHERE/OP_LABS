#pragma once
#include "position.h"
class circle :
    public virtual position
{
private:
    int radius;
public:
    circle();
    circle(int corx, int cory, int size);
    circle(circle& temp);
    ~circle();

    double per();
    double area();
    int getrad();
};

