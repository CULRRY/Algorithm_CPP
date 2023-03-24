#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int t, w;

int main()
{
    FASTIO;

    cin >> t >> w;

    vector<int> seq(t+1, 0);
    for (int i = 1; i <= t; i++)
    {
        cin >> seq[i];
    }

    int dp[1001][32][3];

    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= w + 1; j++)
        {
            if (seq[i] == 1)
            {
                dp[i][j][1] = std::max(dp[i-1][j][1] + 1, dp[i-1][j-1][2] + 1);
                dp[i][j][2] = std::max(dp[i-1][j-1][1], dp[i-1][j][2]);
            }
            else
            {
                if (i == 1 && j == 1)
                    continue;
                
                dp[i][j][1] = std::max(dp[i-1][j][1], dp[i-1][j-1][2]);
                dp[i][j][2] = std::max(dp[i-1][j-1][1] + 1, dp[i-1][j][2] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= w + 1; i++)
    {
        ans = std::max(ans, std::max(dp[t][i][1], dp[t][i][2]));
    }

    cout << ans;
    return 0;
}