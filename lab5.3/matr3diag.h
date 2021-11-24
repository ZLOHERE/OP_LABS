#pragma once
#ifndef matr3diag
#define matr3diag
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
	

	friend std::ostream& operator << (std::ostream& out, const Matr3diag& temp);
};

#endif