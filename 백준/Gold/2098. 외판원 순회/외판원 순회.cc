#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

constexpr int INF = 1'000'000'000;

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<vector<int>> w(n + 1, vector<int>(n + 1, 0));
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

    vector<vector<int>> dp(n, vector<int>(1 << n, INF));

    dp[0][1] = 0;
    for (int k = 0; k < (1 << n); k++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((k | 1 << j) == k)
                continue;
            int offset = k | 1 << j;
            for (int p = 0; p < n; p++)
            {

                dp[j][offset] = std::min(dp[p][k] + w[p][j], dp[j][offset]);
            }
        }
    }

    int min = INF;

    for (int j = 0; j < n; j++)
        min = std::min(min, dp[j][(1 << n) - 1] + w[j][0]);

    cout << min;
    return 0;
}