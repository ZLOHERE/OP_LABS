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
	znach = maxi / 2;
	mid = temp[znach];
	while (last>=first)
	{
		while (temp[first]<=mid)
		{
			first++;
			if (first==maxi)
			{
				break;
			}
		}
		while (temp[last]>=mid)
		{
			last--;
			if (last == -1)
			{
				break;
			}
		}
		if (last>=first)
		{
			per = temp[last];
			temp[last] = temp[first];
			temp[first] = per;
			first++;
			last--;
		}
		else
		{
			if (maxi==2)
			{
				if (temp[0] > temp[1]) {
					per = temp[0];
					temp[0] = temp[1];
					temp[1] = per;
				}
				continue;
			}
			if (((last==-1 and first==0)or(first==maxi and last==maxi-1)))
			{
				first = 0;
				last = maxi - 1;
				if (znach!=0)
				{
					znach--;
				}
				else
				{
					znach = maxi - 1;
				}
				mid = temp[znach];

			}
		}
	}
	if (last>0)
	{
		sort(temp, last + 1);
	}
	if (first < maxi)
	{
		sort(&temp[first], maxi - first);
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
				string per;
				int per2;
				sort(&mus[0].surname, axel);
				print(mus, axel);
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
				print(mus, axel);
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
