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

    vector<int> wine(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> wine[i];
    }

    vector<int> dp(n+1, 0);

    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    for (int i = 3; i <= n; i++)
    {
        dp[i] = std::max(dp[i - 1], std::max(dp[i-3] + wine[i-1] + wine[i], dp[i-2] + wine[i]));
    }

    cout << dp[n];

    return 0;
}