#include <iostream>   
#include "matr3diag.h"                                                                                                                                         |
using namespace std;

int main()
{
	system("color 03");
	Matr3diag MatrA;
	Matr3diag MatrB;
	Matr3diag MatrC;
	MatrA.input(4);
	MatrB.input(3);
	//cout << MatrA;
	//cout<<MatrB;
	MatrC = MatrB*MatrA;
	cout << MatrA;
	cout << MatrB;
	cout << MatrC;
	cout << MatrA.det();
	

	//cin >> MatrA;
	//MatrA.print();
	//cout<<MatrA.get_elem(0, 1);
	//cout << MatrA;

}