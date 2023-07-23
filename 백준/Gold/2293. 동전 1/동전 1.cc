#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n, k;
    cin >> n >> k;
    vector<int> coins(n+1, 0);
    vector<int> dp(k+1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = coins[i]; j <= k; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[k];

    return 0;
}