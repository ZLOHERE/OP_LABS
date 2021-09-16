

#include <iostream>
using namespace std;

int main()
{
    cout << "Tushentsov Alexandr Alexandrovich, 211-353\n\n";
    cout << "min int = " << (int)0b10000000000000000000000000000000 << ", max int = " << (int)0b01111111111111111111111111111111 << ", size of int = " << sizeof(int) << endl;
    cout << "min unsigned int = " << (unsigned int)0 << ", max unsigned int = " << (unsigned int)0b11111111111111111111111111111111 << ", size of unsigned int = " << sizeof(unsigned int) << endl;
    cout << "min short = " << (short)0b1000000000000000 << ", max short = " << (short)0b0111111111111111 << ", size of short = " << sizeof(short) << endl;
    cout << "min unsigned short = " << (unsigned short)0 << ", max unsigned short = " << (unsigned short)0b1111111111111111 << ", size of unsigned short = " << sizeof(unsigned short) << endl;
    cout << "min long = " << (long)0b10000000000000000000000000000000 << ", max long = " << (long)0b01111111111111111111111111111111 << ", size of long = " << sizeof(long) << endl;
    cout << "min long long = " << (long long)0b1000000000000000000000000000000000000000000000000000000000000000 << ", max long long = " << (long long)0b0111111111111111111111111111111111111111111111111111111111111111 << ", size of long long = " << sizeof(long long) << endl;
    cout << "min double = -" << (double)0b1000000000000000000000000000000000000000000000000000000000000000 << ", max double = " << (double)0b0111111111111111111111111111111111111111111111111111111111111111 << ", size of double = " << sizeof(double) << endl;
    cout << "min char = " << (char)0b10000000 << ", max char = " << (char)0b01111111 << ", size of char = " << sizeof(char) << endl;
    cout << "min bool = " << (bool)0 << ", max bool = " << (bool)0b01111111 << ", size of bool = " << sizeof(bool) << endl << endl;
    cout << "Input number:" << endl;
    int osnov_znach,bin=0,sch=1;
    cin >> osnov_znach;
    int hhex = osnov_znach;
    while (osnov_znach) {
        bin +=(osnov_znach % 2)*sch;
        sch *= 10;
        osnov_znach /= 2;
        
        
    }
    cout << "binary: " << bin << endl;
    cout << "hexagen:";
    cout << hex << hhex << endl;



}
