#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n;
    cin >> n;

    vector<char> color(n);
    for (char& c : color)
        cin >> c;

    vector<int> dp(n, 0);
    dp[0] = 1;
    char norm = color[0];

    for (int i = 1; i < n; i++)
    {
        if (color[i] == color[i-1])
            dp[i] = dp[i-1];
        else
        {
            if (color[i] == norm)
                dp[i] = dp[i-1];
            else
                dp[i] = dp[i-1] + 1;
        }
    }

    cout << dp[n-1];
    return 0;
}