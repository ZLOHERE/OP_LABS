#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    Matrix matrix1(2, 2);
    Matrix matrix2(2, 2);
    matrix1.input();
    matrix2.input();
    cout<<"Matrix trace:"<<matrix2.trace()<<endl;
    matrix1.mult(matrix2);
    matrix1.print();
    return 0;
}