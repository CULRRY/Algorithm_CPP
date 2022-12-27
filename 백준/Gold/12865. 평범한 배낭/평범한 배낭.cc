#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    FASTIO;

    int n, k;
    cin >> n >> k;
    vector<int> w(n+1);
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (j - w[i] >= 0)
            {
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][k];

    return 0;
}