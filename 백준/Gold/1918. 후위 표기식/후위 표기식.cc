#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    stack<char> s;
    for (size_t i = 0; i < input.size(); i++)
    {
        char token = input[i];

        if (token >= 'A' && token <= 'Z')
        {
            cout << token;
        }
        else
        {
            if (s.empty())
            {
                s.push(token);
                continue;
            }

            if (token == '(')
            {
                s.push(token);
                continue;
            }

            if (token == ')')
            {
                while (s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }

                s.pop();
                continue;
            }

            if (token == '*' || token == '/')
            {
                while (!s.empty() && s.top() != '+' && s.top() != '-' && s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }

                s.push(token);
                continue;
            }

            if (token == '+' || token == '-')
            {
                while (!s.empty() && s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }
                s.push(token);
                continue;
            }
        }
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}