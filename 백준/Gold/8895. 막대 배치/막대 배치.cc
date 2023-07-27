#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;
using ull = unsigned long long;
ull dp[21][21][21];
int main()
{
    FASTIO;

    int tc;
    cin >> tc;
    dp[1][1][1] = 1;
    for (int i = 2; i <= 20; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= i; k++)
            {
                dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2);
            }
        }
    }
    while (tc--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        cout << dp[n][l][r] << endl;

    }
    

    return 0;
}