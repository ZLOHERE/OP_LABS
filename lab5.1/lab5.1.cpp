#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    Matrix matrix1(1, 1);
    Matrix matrix2(1, 1);
    matrix1.input();
    matrix2.input();
    matrix1.mult(matrix2);
    matrix1.print();
    return 0;
}