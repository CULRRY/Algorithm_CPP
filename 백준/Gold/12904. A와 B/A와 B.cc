#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    string s;
    string t;
    cin >> s >> t;

    while (s.length() != t.length())
    {
        if (t.back() == 'A')
        {
            t.pop_back();
        }
        else
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }

    if (s == t)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}