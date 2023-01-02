#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;
constexpr int MOD = 1'000'000'000;
long long dp[101][10][1 << 10];

int main()
{
    FASTIO;

    int n;
    cin >> n;
    long long sum = 0;
    
    for (int i = 1; i <= 9; i++)
    {
        dp[1][i][1 << i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k < (1 << 10); k++)
            {
                if (j == 0)
                {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)]  + dp[i-1][j+1][k]) % MOD;
                }
                else if (j == 9)
                {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i-1][j-1][k]) % MOD;
                }
                else
                {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i-1][j+1][k] + dp[i-1][j-1][k]) % MOD;
                }
            }
        }
    }

    for (int i = 0; i <= 9; i++)
    {
        sum = (sum + dp[n][i][(1 << 10) - 1]) % MOD;
    }

    cout << sum % MOD;
    

    return 0;
}