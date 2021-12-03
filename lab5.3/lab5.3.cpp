#include <iostream>   
#include "matr3diag.h"                                                                                                                                         
using namespace std;

int main()
{
	system("color 03");
	Matr3diag MatrA;
	Matr3diag MatrB;
	Matr3diag MatrC;
	MatrA.input(9);
	MatrB.input(9);
	//cout << MatrA;
	//cout<<MatrB;
	//MatrC = MatrB*MatrA;
	cout << MatrA;
	cout << MatrB;
	cout<<MatrA*MatrB;
	cout << MatrA.det();
	

	//cin >> MatrA;
	//MatrA.print();
	//cout<<MatrA.get_elem(0, 1);
	//cout << MatrA;

}