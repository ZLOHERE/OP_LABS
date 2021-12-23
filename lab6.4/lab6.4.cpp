#include <iostream>
#include <unordered_set>
#include <queue>
#include<string>
using namespace std;
int main()
{
    unordered_set<string> login;
    queue<int> password;
    int last_size, pass, cnt;
    string log;
    last_size = login.size();
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> log;
        login.insert(log);
        cin >> pass;
        if (last_size!=(login.size()))
        {
            password.push(pass);
            last_size = login.size();
        }
    }
    for (auto it = login.begin(); it != login.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
    for (int i = 0; i < last_size; i++)
    {
        cout << password.front() <<"\t";
        password.pop();
    }

}
