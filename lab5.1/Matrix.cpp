#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix()
{
	this->row = 0;
	this->col = 0;
	this->elem = nullptr;
}

Matrix::Matrix(const Matrix& temp)
{
	this->row = temp.row;
	this->col = temp.col;
	this->elem = new int[this->row * this->col];
	for (int i = 0; i < this->row * this->col; i++)
		this->elem[i] = temp.elem[i];
}

Matrix::Matrix(int rows, int cols)
{
	this->row = rows;
	this->col = cols;
	this->elem = new int [rows*cols];
	for (int i = 0; i < this->col * this->row; i++)
	{
		this->elem[i] = 0;
	}
}

Matrix::~Matrix()
{
	if (this->elem!=nullptr)
	{
		delete[]this->elem;
	}
}

Matrix Matrix::sum(Matrix mat2)
{
	if ((this->col!=mat2.col)or(this->row != mat2.row))
	{
		cout << "Error, different sizes";
		return Matrix();
	}
	for (int i = 0; i < this->col*this->row; i++)
	{
		this->elem[i] += mat2.elem[i];
	}
	return Matrix();
}

Matrix Matrix::mult(Matrix mat2)
{
	if (this->col != mat2.row)
	{
		cout << "Error, different sizes of matrix";
		return Matrix();
	}
	Matrix result(this->row, mat2.col);
	int cnt, cnt1, cnt2 = 0;
	for (int p = 0; p < mat2.col; p++)
	{
		cnt1 = p;
		cnt2 = 0;

	for (int n = cnt1; n < mat2.col * mat2.row; n += mat2.col)
	{
		cnt = p;
		for (int i = cnt2; i < this->col * this->row; i += this->col)
		{
			result.elem[cnt] += mat2.elem[n] * this->elem[i];
			cnt += result.col;
		}
		cnt2 += 1;
	}
	
}
	this->col = result.col;
	this->row = result.row;
	for (int i = 0; i < this->col * this->row; i++)
	{
		this->elem[i] = result.elem[i];
	}
	
	return Matrix();
}	

Matrix Matrix::mult_by_num(double num)
{
	for (int i = 0; i < this->col*this->row; i++)
	{
		this->elem[i] = this->elem[i] * num;
	}
	return Matrix();
}

void Matrix::input()
{
	cout << "Input matrix:\n";
	for (int i = 0; i < this->row*this->col; i++)
	{
		cin >> this->elem[i];
	}
	return;
}

void Matrix::print()
{
	short counter = 0;
	for (int i = 0; i < this->col*this->row; i++)
	{
		cout << this->elem[i]<<" ";
		counter++;
		if (counter%this->col==0)
		{
			cout << "\n";
		}
	}
	return;
}

int Matrix::get_columns()
{
	return this->col;
}

int Matrix::get_rows()
{
	return this->row;
}

double Matrix::get_elem(int i, int j)
{
	return this->elem[i*this->col+j];
}
