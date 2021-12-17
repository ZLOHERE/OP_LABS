#include <iostream>
#include<deque>
#include<string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	deque<char> deq;
	string str;
	cin>>str;
	char ch;
	for (int i = 0; i < str.size(); i++)
	{
		ch = str[i];
		if ((ch >= 'A') and (ch <= 'Z'))
		{
			ch += 32;
		}
		if (ch!=' ')
		{
			deq.push_front(ch);
		}
	}
	while (!deq.empty())
	{
		if (deq.size()==1)
		{
			deq.pop_front();
			break;
		}
		if (deq.front()==deq.back())
		{
			deq.pop_back();
			deq.pop_front();
		}
		else
		{
			cout << "это не палиндром";
			return 0;
		}
	}
	cout << "это палинром";
}

