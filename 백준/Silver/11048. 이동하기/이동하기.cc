#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = std::max(dp[i-1][j-1], dp[i][j-1]);
            dp[i][j] = std::max(dp[i][j], dp[i-1][j]);

            dp[i][j] += board[i][j];
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}