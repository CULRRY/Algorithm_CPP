#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl "\n"

using namespace std;
using ll = unsigned long long;
constexpr ll MOD = 1'000'000'007;

int main()
{
    FASTIO;

    int n, t;
    cin >> n >> t;
    vector<int> k(n+1);
    vector<int> s(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i] >> s[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(t+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (j - k[i] < 0)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j - k[i]] + s[i]);
            }
        }
    }

    cout << dp[n][t];

    return 0;
}