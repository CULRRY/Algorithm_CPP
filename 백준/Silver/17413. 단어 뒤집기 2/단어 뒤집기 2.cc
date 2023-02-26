#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    bool canReverse = true;

    string input;
    getline(cin, input);

    stack<char> s;

    for (char c : input)
    {
        if (c == '<')
        {
            while (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << '<';
            canReverse = false;
            continue;
        }
        else if (c == '>')
        {
            cout << c;
            canReverse = true;
            continue;
        }
        else if (c == ' ')
        {
            while (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << ' ';
            continue;
        }

        if (canReverse == true)
        {
            s.push(c);
        }
        else
        {
            cout << c;
        }
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}