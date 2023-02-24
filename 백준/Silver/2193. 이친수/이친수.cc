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
    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];

    return 0;
}