#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int dp[1001][1001];

int main()
{
    FASTIO;

    int ans = 0;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mat[i][j] != 0)
                continue;
            
            dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]) +1;
            ans = std::max(dp[i][j], ans);
        }
    }


    cout << ans << endl;

    return 0;
}