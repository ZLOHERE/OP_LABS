#include <iostream>
#include<list>
#include<string>
using namespace std;
bool compare(pair<int, string> p1, pair<int, string> p2) 
{
	if (p1.first<p2.first)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	list<pair<int, string>> students;
	cout << "Input count of students" << endl;
	int cnt;
	cin >> cnt;
	int str;
	string str2;
	for (int i = 0; i < cnt; i++)
	{
		cin >> str;
		cin >> str2;
		students.push_back(make_pair(str,str2));
	}
	students.sort(compare);
	for (int i = 0; i < cnt; i++)
	{
		cout << students.front().first << " " << students.front().second << " " << endl;
		students.pop_front();
	}
}
