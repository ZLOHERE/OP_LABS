#include <iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
    string str;
	stack<char> arc;
    cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i]=='[') or (str[i] == '(') or (str[i] == '{'))
		{
			arc.push(str[i]);
		}
		if (str[i] == ']')
		{
			if (arc.top()=='[')
			{
				arc.pop();
			}
			else
			{
				cout << "скобки введены некорректно" << endl;
				return 0;
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
				return 0;
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
				return 0;
			}
		}
	}
	if (arc.empty()==1)
	{
		cout << "скобки введены корректно"<<endl;
	}
	else
	{
		cout << "скобки введены некорректно" << endl;
	}
	return 0;
}
