#include <iostream>   
#include "matr3diag.h"                                                                                                                                         
using namespace std;

int main()
{
	system("color 03");
	Matr3diag MatrA;
	Matr3diag MatrB;
	Matr3diag MatrC;
	MatrA.input(10);
	MatrB.input(10);
	//cout << MatrA;
	//cout<<MatrB;
	//MatrC = MatrB*MatrA;
	//cout << MatrC;
	cout << MatrA;
	cout << MatrB;
	cout<<MatrA*MatrB;
	//cout << MatrC;
	cout << MatrA.det();
	

	//cin >> MatrA;
	//MatrA.print();
	//cout<<MatrA.get_elem(0, 1);
	//cout << MatrA;

}