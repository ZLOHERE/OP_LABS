#include <iostream>
#include <string>
#include<vector>
using namespace std;

struct people {
	string surname;
	string name;
	int age;
};
template<typename T>
void sort(T*& temp, int maxi) {
	T per;
	for (int j = 0; j < maxi; j++)
	{
		for (int i = 0; i < maxi - j - 1; i++)
		{
			if (temp[i] > temp[i + 1])
			{
				per = temp[i];
				temp[i] = temp[i + 1];
				temp[i + 1] = per;
			}
		}
	}
}
template<typename T>
void print(T*& temp, int maxi) {
	for (int i = 0; i < maxi; i++)
	{
		cout << temp[i] << " ";
	}
	cout << endl;
}
void print_struct(people*& temp, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << temp[i].surname << " " << temp[i].name << " " << temp[i].age << endl;
	}
}

int main()
{
	while (true)
	{
		cout << "Choice sort\n 1.Any internal type\n 2.Identify information\n 3.another for exit\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Choice sort\n 1.string\n 2.int\n 3.double\n 4.char\n";
			cin >> choice;
			switch (choice)
			{
			case 1: {
				cout << "Input count of values:";
				int axel;
				cin >> axel;
				string* str = new string[axel];
				cout << "Input values:";
				for (int i = 0; i < axel; i++)
				{
					cin >> str[i];
				}
				sort(str, axel);
				print(str, axel);
				delete[] str;
				break;
			}
			case 2: {
				cout << "Input count of values:";
				int axel;
				cin >> axel;
				int* str = new int[axel];
				cout << "Input values:";
				for (int i = 0; i < axel; i++)
				{
					cin >> str[i];
				}
				sort(str, axel);
				print(str, axel);
				delete[] str;
				break;
			}
			case 3: {
				cout << "Input count of values:";
				int axel;
				cin >> axel;
				double* str = new double[axel];
				cout << "Input values:";
				for (int i = 0; i < axel; i++)
				{
					cin >> str[i];
				}
				sort(str, axel);
				print(str, axel);
				delete[] str;
				break;
			}
			case 4: {
				cout << "Input count of values:";
				int axel;
				cin >> axel;
				char* str = new char[axel];
				cout << "Input values:";
				for (int i = 0; i < axel; i++)
				{
					cin >> str[i];
				}
				sort(str, axel);
				print(str, axel);
				delete[] str;
				break;
			}
			default:
				break;
			}
		break;
		}
		case 2:
		{
			cout << "Input count of people:";
			int axel;
			cin >> axel;
			people* mus = new people[axel];
			cout << "Input surname, name, age: ";
			for (int i = 0; i < axel; i++)
			{
				cin >> mus[i].surname;
				cin >> mus[i].name;
				cin >> mus[i].age;
			}
			cout << "Choise data\n 1. Surname\n 2. Name\n 3. Age\n";
			int data;
			cin >> data;
			switch (data)
			{
			case 1: {
				string per;
				int per2;
				for (int j = 0; j < axel; j++)
				{
					for (int i = 0; i < axel - j - 1; i++)
					{
						if (mus[i].surname > mus[i + 1].surname)
						{
							per = mus[i].surname;
							mus[i].surname = mus[i + 1].surname;
							mus[i + 1].surname = per;
							per = mus[i].name;
							mus[i].name = mus[i + 1].name;
							mus[i + 1].name = per;
							per2 = mus[i].age;
							mus[i].age = mus[i + 1].age;
							mus[i + 1].age = per2;
						}
					}
				}
				print_struct(mus, axel);
				delete[] mus;
				break;
			}
			case 2: {
				string per;
				int per2;
				for (int j = 0; j < axel; j++)
				{
					for (int i = 0; i < axel - j - 1; i++)
					{
						if (mus[i].name > mus[i + 1].name)
						{
							per = mus[i].surname;
							mus[i].surname = mus[i + 1].surname;
							mus[i + 1].surname = per;
							per = mus[i].name;
							mus[i].name = mus[i + 1].name;
							mus[i + 1].name = per;
							per2 = mus[i].age;
							mus[i].age = mus[i + 1].age;
							mus[i + 1].age = per2;
						}
					}
				}
				print_struct(mus, axel);
				delete[] mus;
				break;
			}
			case 3: {
				string per;
				int per2;
				for (int j = 0; j < axel; j++)
				{
					for (int i = 0; i < axel - j - 1; i++)
					{
						if (mus[i].age > mus[i + 1].age)
						{
							per = mus[i].surname;
							mus[i].surname = mus[i + 1].surname;
							mus[i + 1].surname = per;
							per = mus[i].name;
							mus[i].name = mus[i + 1].name;
							mus[i + 1].name = per;
							per2 = mus[i].age;
							mus[i].age = mus[i + 1].age;
							mus[i + 1].age = per2;
						}
					}
				}
				print_struct(mus, axel);
				delete[] mus;
				break;
			}
			default:
				break;
			}
			break;
		}
		default:
			return 0;
		}
	}
}
