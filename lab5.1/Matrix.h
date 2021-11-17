#pragma once
#ifndef Matr
#define Matr
class Matrix
{
private:
	short row;
	short col;
	int* elem;
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(int rows, int cols, int*& arr);
	Matrix(const Matrix& temp);

	~Matrix();
	Matrix sum(const Matrix& mat2);
	Matrix mult(int*& arr, int razm);
	Matrix sum(int*& arr, int razm);
	Matrix mult(const Matrix& mat2);
	Matrix mult_by_num(double num);
	void input();
	void input(int i, int j);
	void input(int i, int j, int*& arr);
	void print();
	int get_columns();
	int get_rows();
	double get_elem(int i, int j) const;
	double trace();
};


#endif
