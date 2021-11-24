#include "matr3diag.h"
#include <iostream>
#include<fstream>
using namespace std;

Matr3diag::Matr3diag()
{
	this->size = 0;
	this->elem = nullptr;
}

Matr3diag::Matr3diag(int count_elem)
{
	this->size = count_elem;
	this->elem = nullptr;
}

Matr3diag::Matr3diag(const Matr3diag& temp)
{
	this->size = temp.size;
	this->elem = new double[3*temp.size];
	for (int i = 0; i < 3*temp.size; i++)
	{
		this->elem[i] = temp.elem[i];
	}
}

Matr3diag::~Matr3diag()
{
	if (this->elem!=nullptr)
	{
		delete[]this->elem;
	}
}

int Matr3diag::tr()
{
	int cnt=0;
	for (int i = this->elem[this->size]; i < this->elem[2*this->size-1] ; i++)
	{
		cnt += i;
	}
	return cnt ;
}

double Matr3diag::get_elem(int i, int j) const
{
	if (i == j)
		return this->elem[this->size + i];
	else if (i == j + 1)
		return this->elem[2 * this->size + i];
	else if (i == j - 1)
		return this->elem[i];
	else
		return 0;
}

void Matr3diag::input()
{
	cout << "Input Matrix\n";
	for (int i = 0; i < 3*this->size; i++)
	{
		cin >> this->elem[i];
	}
}

void Matr3diag::input(int size_of_matr)
{
	this->size = size_of_matr;
	if (this->elem != nullptr)
		delete[]this->elem;
	this->elem = new double[3 * this->size];
		for (int i = 0; i < 3*this->size; i++)
		{
			this->elem[i] = i + 1;
		}
	this->elem[this->size - 1] = 0;
	this->elem[2 * this->size] = 0;
}

void Matr3diag::print()
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			cout << this->get_elem(i, j) << "\t";
		}
		cout << endl;
	}
}

int Matr3diag::columns()
{
	return this->size;
}

std::ostream& operator<<(std::ostream& out, const Matr3diag& temp)
{
	for (int i = 0; i < temp.size; i++)
	{
		for (int j = 0; j < temp.size; j++)
		{
			cout << temp.get_elem(i, j) << "\t";
		}
		cout << endl;
	}
	return out;
}
