#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;
int n, m;


int main()
{
    FASTIO;
    cin >> n >> m;
    vector<int> memory(n + 1);
    vector<int> cost(n + 1);

    for (int i = 1; i <= n; i++) cin >> memory[i];
    for (int i = 1; i <= n; i++) cin >> cost[i];

    vector<vector<int>> dp(n+1, vector<int>(10001, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 10000; j++)
        {
            if (j - cost[i] >= 0)
            {
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j - cost[i]] + memory[i]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    for (int i = 0; i < 10001; i++)
    {
        if (dp[n][i] >= m)
        {
            cout << i;
            break;
        }
    }

    return 0;
}