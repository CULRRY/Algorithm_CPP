#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int k;
vector<int> files;
int minimum;


int main()
{
    FASTIO;

    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> k;
        minimum = INT_MAX;
        files = vector<int>(k+1);
        vector<vector<int>> dp(k+1, vector<int>(k+1, 0));
        vector<int> sum(k+1, 0);
        for (int i = 1; i <= k; i++)
        {
            cin >> files[i];
            sum[i] = sum[i-1] + files[i];
        }
        
        for (int i = 1; i < k; i++)
        {
            dp[i][i+1] = files[i] + files[i+1];
        }
        for (int d = 2; d <= k; d++)
        {
            for (int i = 1; i <= k - d; i++)
            {
                int j = i + d;
                dp[i][j] = INT_MAX;
                for (int p = i; p < j; p++)
                {
                    dp[i][j] = std::min(dp[i][j], dp[i][p] + dp[p+1][j] + sum[j] - sum[i-1]);
                }
            }
        }

        cout << dp[1][k] << endl;
    }

    return 0;
}