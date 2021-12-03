#pragma once
#include "square.h"
#include "circle.h"
#include <iostream>
using namespace std;
class circleinsquare :
    public square, public circle

{public:
    circleinsquare();
    circleinsquare(circleinsquare& temp);
    circleinsquare(int x, int y, int rad);
    ~circleinsquare();
};

