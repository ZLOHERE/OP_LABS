#include <iostream>
#include "Matrix.h"
#include <iterator>

using namespace std;

int main()
{
    Matrix matrix1(2, 3);
    Matrix matrix2(3, 4);
    matrix1.input();
    matrix2.input();
    cout<<"Matrix trace:"<<matrix2.trace()<<endl;
    //matrix1.mult(matrix2);
    int k = 6;
    int* arr = new int[k];
    for (int i = 0; i < 6; i++)
    {
        arr[i] = 2;
    }
    matrix1.sum(arr, k);
    matrix2.input(3, 3);
    cout << "Matrix2:\n"; 
    matrix2.print();
    matrix2.input(2, 3, arr);
    cout << "Matrix2:\n";
    matrix2.print();
    Matrix matrix3(2,3, arr);
    matrix3.mult(arr,k);
    cout << "Matrix3:\n";
    matrix3.print();
    
    return 0;
}