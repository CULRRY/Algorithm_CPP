#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    vector<vector<char>> v(5, vector<char>(15, '*'));

    for (int r = 0; r < 5; r++)
    {
        string s;
        cin >> s;

        for (int c = 0; c < s.length(); c++)
        {
            v[r][c] = s[c];
        }
    }

    for (int c = 0; c < 15; c++)
    {
        for (int r = 0; r < 5; r++)
        {
            if (v[r][c] == '*')
                continue;
            
            cout << v[r][c];
        }
    }

    return 0;
}