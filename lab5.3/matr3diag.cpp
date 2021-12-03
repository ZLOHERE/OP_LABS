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
	if (this->elem!=nullptr)
	{
		delete[]this->elem;
	}
	cout << "input size: ";
	cin >> this->size;
	this->elem = new double[3 * this->size];
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

void Matr3diag::operator+=(Matr3diag& temp)
{
	for (int i = 0; i < 3*this->size; i++)
	{
		this->elem[i] += temp.elem[i];
	}
}

void Matr3diag::operator-=(Matr3diag& temp)
{
	for (int i = 0; i < 3 * this->size; i++)
	{
		this->elem[i] -= temp.elem[i];
	}
}

void Matr3diag::operator=(Matr3diag temp)
{
	this->size = temp.size;
	if (this->elem != nullptr)
		delete[]this->elem;
	this->elem = new double[3 * temp.size];
	for (int i = 0; i < 3*this->size; i++)
	{
		this->elem[i] = temp.elem[i];
	}

}



//Matr3diag Matr3diag::operator+(Matr3diag& temp)
//{
//	Matr3diag res(this->size);
//	res.elem = new double[3 * res.size];
//	for (int i = 0; i < 3*res.size; i++)
//	{
//		res.elem[i] = this->elem[i] + temp.elem[i];
//	}
//	
//	return res;
//}
//
//Matr3diag Matr3diag::operator-(Matr3diag& temp)
//{
//	Matr3diag res(this->size);
//	res.elem = new double[3 * res.size];
//	for (int i = 0; i < 3 * res.size; i++)
//	{
//		res.elem[i] = this->elem[i] - temp.elem[i];
//	}
//
//	return res;
//}

Matr3diag Matr3diag::operator-()
{
	for (int i = 0; i < 3 * this->size; i++)
	{
		this->elem[i] *=(-1);
	}
	Matr3diag res;
	res.size = this->size;
	res.elem = new double[3 * this->size];
	for (int i = 0; i < 3*this->size; i++)
	{
		res.elem[i] = this->elem[i];
	}
	return res;
}

//Matr3diag Matr3diag::operator*(int j)
//{
//	Matr3diag res(this->size);
//	res.elem = new double[3 * res.size];
//	for (int i = 0; i < 3 * res.size; i++)
//	{
//		res.elem[i] = this->elem[i] * j;
//	}
//
//	return res;
//}
//
//Matr3diag Matr3diag::operator*(Matr3diag& temp)
//{
//	if (this->size!=temp.size)
//	{
//		Matr3diag res(this->size);
//		res.elem = new double[3 * res.size]();
//		cout << "Warning: different sizes, result operation is 1st input Matrix!\n";
//		for (int i = 0; i < 3*res.size; i++)
//		{
//			res.elem[i] = this->elem[i];
//		}
//		return res;
//	}
//	
//	Matr3diag res(this->size);
//	res.elem = new double[3* res.size]();
//
//	for (int stolb = 0; stolb < res.size; stolb++)
//	{
//		for (int str2 = 0; str2 < res.size; str2++)
//		{
//			int k = 0;
//			for (int str = 0; str < res.size; str++)
//			{
//				res.elem[str2+stolb*res.size] += (this->get_elem(str2, str)*temp.get_elem(str, stolb));
//			}
//		}
//	}
//	return res;
//}

double Matr3diag::det()
{
	double k = this->get_elem(0, 0);
	double lambd = this->get_elem(0, 0);
	double rasch = 0;
	for (int i = 1; i < this->size; i++)
	{
		rasch = this->get_elem(i, i) - (this->get_elem(i, i - 1) * (this->get_elem(i - 1, i) / lambd));
		k *= rasch;
		lambd = rasch;
	}
	return k;
}



std::ostream& operator<<(std::ostream& out, const Matr3diag& temp)
{
	for (int i = 0; i < temp.size; i++)
	{
		for (int j = 0; j < temp.size; j++)
		{
			out << temp.get_elem(i, j) << "\t";
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Matr3diag& temp)
{
	if (temp.elem != nullptr)
	{
		delete[]temp.elem;
	}
	cout << "input size: ";
	cin >> temp.size;
	temp.elem = new double[3 * temp.size];
	cout << "Input Matrix\n";
	for (int i = 0; i < 3 * temp.size; i++)
	{
		in >> temp.elem[i];
	}
	
	
	return in;
}

Matr3diag operator+(Matr3diag& temp, Matr3diag& temp1)
{
	Matr3diag res(temp.size);
	res.elem = new double[3 * res.size];
	for (int i = 0; i < 3*res.size; i++)
	{
		res.elem[i] = temp.elem[i] + temp1.elem[i];
	}
	
	return res;
}

Matr3diag operator-(Matr3diag& temp, Matr3diag& temp1)
{
	Matr3diag res(temp.size);
	res.elem = new double[3 * res.size];
	for (int i = 0; i < 3 * res.size; i++)
	{
		res.elem[i] = temp.elem[i] - temp1.elem[i];
	}

	return res;
}

Matr3diag operator*(Matr3diag& temp, int j)
{
	Matr3diag res(temp.size);
	res.elem = new double[3 * res.size];
	for (int i = 0; i < 3 * res.size; i++)
	{
		res.elem[i] = temp.elem[i] * j;
	}

	return res;
}

Matr3diag operator*(Matr3diag& temp, Matr3diag& temp1)
{
	if (temp.size != temp1.size)
	{
		Matr3diag res(temp.size);
		res.elem = new double[res.size * res.size]();
		cout << "Warning: different sizes, result operation is 1st input Matrix!\n";
		for (int i = 0; i < res.size * res.size; i++)
		{
			res.elem[i] = temp.elem[i];
		}
		return res;
	}

	Matr3diag res(temp.size);
	res.elem = new double[res.size * res.size]();

	//for (int stolb = 0; stolb < res.size; stolb++)
	//{
	//	for (int str2 = 0; str2 < res.size; str2++)
	//	{
	//		int k = 0;
	//		for (int str = 0; str < res.size; str++)
	//		{
	//			res.elem[str2 + stolb * res.size] += (temp.get_elem(str2, str) * temp1.get_elem(str, stolb));
	//		}
	//	}
	//}
	int cnt, cnt1, cnt2 = 0;
	for (int p = 0; p < temp1.size; p++)
	{
		cnt1 = p;
		cnt2 = 0;

		for (int n = cnt1; n < temp1.size * 3; n += temp1.size)
		{
			cnt = p;
			for (int i = cnt2; i < 3 * temp.size; i += 3)
			{
				res.elem[cnt] += temp1.elem[n] * temp.elem[i];
				cnt += res.size;
			}
			cnt2 += 1;
		}
	}
	//int k = 0;
	//for (int i = 0; i < res.size*res.size; i++)
	//{
	//	if (res.elem[i]!=0)
	//	{
	//		res.elem[k++] = res.elem[i];
	//	}
	//}
	return res;
}


