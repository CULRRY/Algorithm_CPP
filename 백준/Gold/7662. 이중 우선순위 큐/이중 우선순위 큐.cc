#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        multiset<int> s;
        int n;
        cin >> n;
        while (n--)
        {
            char cmd;
            int val;
            cin >> cmd >> val;
            if (cmd == 'D')
            {
                if (s.empty())
                {
                }
                else
                {
                    if (val == 1)
                    {
                        s.erase(--s.end());
                    }
                    if (val == -1)
                    {
                        s.erase(s.begin());
                    }
                }
            }
            else
            {
                s.insert(val);
            }
        }
        if (!s.empty())
        {
            auto min = s.begin();
            auto max = --s.end();
            cout << *max << " " << *min << "\n";
        }
        else
        {
            cout << "EMPTY"
                 << "\n";
        }
    }

    return 0;
}