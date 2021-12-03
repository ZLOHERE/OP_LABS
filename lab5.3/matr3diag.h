#pragma once  
#ifndef matr3diag
#define matr3diag
#include <iostream>
using namespace std;
class Matr3diag
{
private:
	int size;
	double* elem;
public:
	Matr3diag();
	Matr3diag(int count_elem);
	Matr3diag(const Matr3diag& temp);
	~Matr3diag();


	int tr();
	double get_elem(int i, int j) const;
	void input();
	void input(int size_of_matr);
	void print();
	int columns();
	void operator+=(Matr3diag& temp);
	void operator-=(Matr3diag& temp);
	void operator=(Matr3diag temp);

	Matr3diag operator-();
	double det();



	friend std::ostream& operator << (std::ostream& out, const Matr3diag& temp);

	friend istream& operator>>(istream& in, Matr3diag& temp);
	friend Matr3diag operator+(Matr3diag& temp, Matr3diag& temp1);
	friend Matr3diag operator-(Matr3diag& temp, Matr3diag& temp1);
	friend Matr3diag operator*(Matr3diag& temp, int j);
	friend Matr3diag operator*(Matr3diag& temp, Matr3diag& temp1);

};

#endif