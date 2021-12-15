#include <iostream>
#include<stack>
#include<string>
using namespace std;
void proverka(string str);
int main()
{
	setlocale(LC_ALL, "ru");
	string str;
	getline(cin, str);
	proverka(str);	
}
void proverka(string str) {
	stack<char> arc;
	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i] == '[') or (str[i] == '(') or (str[i] == '{'))
		{
			arc.push(str[i]);
		}
		if (str[i] == ']')
		{
			if (arc.top() == '[')
			{
				arc.pop();
			}
			else
			{
				cout << "скобки введены некорректно" << endl;
				return;
			}
		}
		if (str[i] == ')')
		{
			if (arc.top() == '(')
			{
				arc.pop();
			}
			else
			{
				cout << "скобки введены некорректно" << endl;
				return;
			}
		}
		if (str[i] == '}')
		{
			if (arc.top() == '{')
			{
				arc.pop();
			}
			else
			{
				cout << "скобки введены некорректно" << endl;
				return;
			}
		}
	}
	if (arc.empty() == 1)
	{
		cout << "скобки введены корректно" << endl;
		return;
	}
	else
	{
		cout << "скобки введены некорректно" << endl;
		return;
	}
}