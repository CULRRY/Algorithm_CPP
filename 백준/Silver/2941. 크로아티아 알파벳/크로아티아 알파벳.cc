#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    vector<string> two = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    string s;
    cin >> s;
    int ans = 0;

    for (string alpha : two)
    {
        int idx = 0;

        while ((idx = s.find(alpha)) != EOF)
        {
            ans++;
            for (int i = 0; i < alpha.size(); i++)
            {
                s[idx + i] = '*';
            }
        }
    }

    for (char c : s)
    {
        if (c != '*')
            ans++;
    }

    cout << ans << endl;

    return 0;
}