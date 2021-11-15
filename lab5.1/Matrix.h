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
	Matrix(const Matrix& temp);

	~Matrix();
	Matrix sum(Matrix mat2);
	Matrix mult(Matrix mat2);
	Matrix mult_by_num(double num);
	void input();
	void print();
	int get_columns();
	int get_rows();
	double get_elem(int i, int j);
	double trace();
};


#endif
