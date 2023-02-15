#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    string base;
    cin >> base;
    string token;
    while (cin >> token)
    {
        stack<string> s;
        string var = "";
        for (int i = 0; i < token.length() - 1; i++)
        {
            if (token[i] >= 'a' && token[i] <= 'z' || token[i] >= 'A' && token[i] <= 'Z')
                var += token[i];
            else
            {
                if (token[i] == '[')
                {
                    s.push("[]");
                    i++;
                }
                else
                {
                    string str = "";
                    str += token[i];
                    s.push(str);
                }
            }
        }
        cout << base;
        while (!s.empty())
        {
            cout << s.top();
            s.pop();
        }
        cout << " ";
        cout << var;
        cout << ";" << endl;


    }

    return 0;
}