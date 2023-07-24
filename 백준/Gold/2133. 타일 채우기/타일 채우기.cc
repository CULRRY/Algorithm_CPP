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

    vector<int> dp(n+1, 0);

    dp[0] = 1;
    dp[2] = 3;
    

    for (int i = 4; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = (dp[i-2] * 3);
            for (int j = 4; j <= i; j += 2)
            {
                dp[i] += dp[i-j] * 2;
            }
        }
    }


    cout << dp[n];
    return 0;
}