#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    int counter = 1;
    while (!q.empty())
    {
        if (counter == k)
        {
            v.push_back(q.front());
            q.pop();
            counter = 0;
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
        counter++;

    }
    cout << "<";
    for (int i = 0; i < n; i++)
    {
        if (i == (n - 1))
            cout << v[i];
        else
            cout << v[i] << ", ";
    }
    cout << ">";

    return 0;
}