#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    

    int tc;
    cin >> tc;
    while (tc--)
    {
        deque<char> dq;
        stack<char> st;

        string s;
        cin >> s;

        for (char c : s)
        {
            if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') || (c <= '9' && c >= '0'))
            {
                dq.push_back(c);
                continue;
            }

            if (c == '<')
            {
                if (dq.empty())
                    continue;
                
                st.push(dq.back());
                dq.pop_back();
            }
            else if (c == '>')
            {
                if (st.empty())
                    continue;
                
                dq.push_back(st.top());
                st.pop();
            }
            else
            {
                if (dq.empty())
                    continue;
                    
                dq.pop_back();
            }
        }
        string ans = "";
        while (!dq.empty())
        {
            ans += dq.front();
            dq.pop_front();
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        cout << ans << endl;
        
        
    }
    

    return 0;
}