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
    
    vector<int> L(n);
    vector<int> J(n);
    for (int& i : L)
        cin >> i;
    for (int & i : J)
        cin >> i;

    vector<vector<int>> dp(n+1, vector<int>(101, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (j - L[i-1] <= 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j - L[i-1]] + J[i-1]);
        }
    }

    cout << dp[n][100];
    return 0;
}