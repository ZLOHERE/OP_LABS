#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q2;
    queue<int> q3;
    queue<int> q5;
    queue<int> res;
    q2.push(2);
    q3.push(3);
    q5.push(5);
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int minimum;
        minimum = min(q5.front(), min(q2.front(), q3.front()));
        if ((minimum==q2.front()) or (minimum == q3.front()) or (minimum == q5.front()))
        {
            q2.push(minimum * 2);
            q3.push(minimum * 3);
            q5.push(minimum * 5);
        }
        if (minimum==q2.front())
        {
            q2.pop();
        }
        if (minimum == q3.front())
        {
            q3.pop();
        }
        if (minimum == q5.front())
        {
            q5.pop();
        }
        res.push(minimum);
    }
    int sizeqe = res.size();
    for (int i = 0; i < sizeqe; i++)
    {
        cout << res.front()<<" ";
        res.pop();
    }
}
