#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    stack<int> s;
    vector<int> v(n);
    vector<char> log;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int j = 0;
    int i = 1;
    while (j < n)
    {
        if (s.empty())
        {
            s.push(i++);
            log.push_back('+');
        }
        if (s.top() < v[j])
        {
            while (s.top() != v[j])
            {
                s.push(i++);
                log.push_back('+');
            }
            continue;
        }

        if (s.top() == v[j])
        {
            s.pop();
            log.push_back('-');
            j++;
            continue;
        }
        else if (s.top() > v[j])
        {
            cout << "NO";
            return 0;
        }
    }

    for (char v : log)
    {
        cout << v << "\n";
    }

    return 0;
}