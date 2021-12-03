#pragma once
#include "position.h"
class square :
    public virtual position
{
private:
    int len;
public:
    square();
    square(int corx, int cory, int size);
    square(square& temp);
    ~square();

    int per();
    int area();
    int getlen();
};

