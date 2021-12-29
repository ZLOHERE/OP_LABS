#include <iostream>
#include <unordered_set>
#include <queue>
#include<string>
using namespace std;
int main()
{
    queue<string> login;
    unordered_set<string> link;
    queue<int> password;
    int last_size, pass, cnt;
    string log;
    last_size = login.size();
    cout << "Input count of logins";
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
 /*       cout << "Input login: ";*/
        cin >> log;
        if (link.find(log) == link.end()) {
            login.push(log);
            link.insert(log);
        }
      /*  cout << "input password: ";*/
        cin >> pass;
        if (last_size!=(login.size()))
        {
            password.push(pass);
            last_size = login.size();
        }
    }
    for (int i = 0; i < last_size; i++)
    {
        cout << login.front() << "\t";
        login.pop();
    }
    cout << endl;
    for (int i = 0; i < last_size; i++)
    {
        cout << password.front() <<"\t";
        password.pop();
    }

}
