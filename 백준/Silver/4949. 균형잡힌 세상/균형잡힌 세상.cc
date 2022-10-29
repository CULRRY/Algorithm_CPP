#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    while (true)
    {
        stack<char> stk;
        stk.push('Q');
        getline(cin, s);
        if (s == ".")
            break;
        
        bool isBalance = true;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                stk.push(s[i]);
            }
            else if (s[i] == '[')
            {
                stk.push(s[i]);
            }
            else if (s[i] == ']')
            {
                if (stk.top() != '[')
                {
                    isBalance = false;
                    break;
                }
                stk.pop();
            }
            else if (s[i] == ')')
            {
                if (stk.top() != '(')
                {
                    isBalance = false;
                    break;
                }    
                stk.pop();
            }
        }
        int a = stk.size();
        if ((stk.size() == 1) && isBalance)
        {
            cout << "yes" << "\n";
        }
        else
        {
            cout << "no" << "\n";
        }
    }

    return 0;
}