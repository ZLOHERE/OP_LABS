#include <iostream>
#include <string>
#include<vector>
using namespace std;

struct people {
	string surname;
	string name;
	int age;
};
ostream& operator<<(ostream& out, const people& temp) {

	out << temp.surname << " " << temp.name << " " << temp.age << endl;
	return out;

}
template<typename T>
void sort(T* temp, int maxi) {
	T per, mid;
	int first, last, znach;
	first = 0;
	last = maxi - 1;
	mid = temp[maxi / 2];
	while (last>=first)
	{
		while (temp[first]<mid) first++;

		while (temp[last]>mid) last--;
		if (last>=first)
		{
			per = temp[last];
			temp[last] = temp[first];
			temp[first] = per;
			first++;
			last--;
		}
	}
	if (last>0) sort(temp, last + 1);
	if (first < maxi) sort(&temp[first], maxi - first);
}
template<typename T>
void print(T*& temp, int maxi) {
	for (int i = 0; i < maxi; i++)
	{
		cout << temp[i] << " ";
	}
	cout << endl;
}
template<typename T>
void sort(T* temp, int maxi, string mode)
{
	T per, mid;
	int first, last, znach;
	first = 0;
	last = maxi - 1;
	znach = maxi / 2;
	mid = temp[znach];

	while (last >= first)
	{

		if (mode == "surname") {
			while (temp[first].surname < mid.surname)
			{
				first++;
			}
			while (temp[last].surname > mid.surname)
			{
				last--;
			}
		}
		if (mode == "name") {
			while (temp[first].name < mid.name)
			{
				first++;
			}
			while (temp[last].name > mid.name)
			{
				last--;
			}
		}
		if (mode == "age") {
			while (temp[first].age < mid.age)
			{
				first++;
			}
			while (temp[last].age > mid.age)
			{
				last--;
			}
		}
		if (last >= first)
		{
			per = temp[last];
			temp[last] = temp[first];
			temp[first] = per;
			first++;
			last--;
		}
	}
	if (last > 0)
	{
		if (mode == "surname") {
			sort(temp, last + 1, "surname");
		}
		if (mode == "name") {
			sort(temp, last + 1, "name");
		}
		if (mode == "age") {
			sort(temp, last + 1, "age");
		}
	}
	if (first < maxi)
	{
		if (mode == "surname") {
			sort(&temp[first], maxi - first, "surname");
		}
		if (mode == "name") {
			sort(&temp[first], maxi - first, "name");
		}
		if (mode == "age") {
			sort(&temp[first], maxi - first, "age");
		}
	}
}

template<typename T>
void sort_of_internal(T temp)
{
	cout << "Input count of values:";
	int axel;
	cin >> axel;
	T* str = new T[axel];
	cout << "Input values:";
	for (int i = 0; i < axel; i++)
	{
		cin >> str[i];
	}
	sort(str, axel);
	print(str, axel);
	delete[] str;
	
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
				string t="";
				sort_of_internal(t);
				break;
			}
			case 2: {
				int t=0;
				sort_of_internal(t);
				break;
			}
			case 3: {
				double t=0.0;
				sort_of_internal(t);
				break;
			}
			case 4: {
				char t='a';
				sort_of_internal(t);
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
				sort(mus, axel, "surname");
				print(mus, axel);
				delete[] mus;
				break;
			}
			case 2: {
				sort(mus, axel, "name");
				print(mus, axel);
				delete[] mus;
				break;
			}
			case 3: {
				sort(mus, axel, "age");
				print(mus, axel);
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
