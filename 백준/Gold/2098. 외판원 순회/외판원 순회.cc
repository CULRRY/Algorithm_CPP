#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

constexpr int INF = 1'000'000'000;

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<vector<int>> w(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
            if (w[i][j] == 0)
            {
                w[i][j] = INF;
            }
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(1 << n, INF)));

    for (int i = 0; i < n; i++)
    {
        dp[i][i][1 << i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < (1 << n); k++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                if ((k | 1 << j) == k) continue;
                int offset = k | 1 << j;
                for (int p = 0; p < n; p++)
                {
                    
                    dp[i][j][offset] = std::min(dp[i][p][k] + w[p][j], dp[i][j][offset]);
                }
            }
        }
    }

    int min = INF;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            min = std::min(min, dp[i][j][(1 << n) - 1] + w[j][i]);
    }
    cout << min;
    return 0;
}