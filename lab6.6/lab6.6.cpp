#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	map<string, int> word;
	string words;
	double cnt = 0;
	while (true)
	{
		cin >> words;
		if (words.rfind(".") != string::npos )
		{
			words.pop_back();
			if (words!="")
			{
				cnt += 1;
				if (word.find(words) != word.end())
				{
					word.find(words)->second += 1;
				}
				else
				{
					word.emplace(pair<string, int>(words, 1));
				}
			}
			break;
		}
		cnt += 1;
		if (word.find(words)!=word.end())
		{
			word.find(words)->second += 1;
		}
		else
		{
			word.emplace(pair<string, int>(words, 1));
		}
	}
	for (auto it = word.begin(); it != word.end(); it++)
	{
		cout << it->first << " " << (it->second)/cnt << endl;
	}
}

