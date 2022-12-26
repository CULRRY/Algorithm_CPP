#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);
constexpr int INF = INT_MAX;
using namespace std;

int main()
{
    FASTIO;
    int n;
    cin >> n;
    vector<int> d(n+1);
    cin >> d[0] >> d[1];

    for (int i = 0; i < n-1; i++)
    {
        int r, c;
        cin >> r >> c;
        d[i+2] = c;
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, INF));

    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    for (int diagonal = 1; diagonal <= n - 1; diagonal++)
    {
        for (int i = 1; i <= n - diagonal; i++)
        {
            int j = i + diagonal;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = std::min(dp[i][k] + dp[k+1][j] + d[i-1]*d[k]*d[j], dp[i][j]);
            }
        }
    }

    cout << dp[1][n];


    return 0;
}