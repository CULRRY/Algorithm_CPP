#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using ull = unsigned long long;

#define MOD 987654321

using namespace std;

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<ull> dp(n+1, 0);
    dp[0] = 1;
    dp[2] = 1;
    
    for (int i = 4; i <= n; i+= 2)
    {
        for (int j = 0; j <= i-2; j += 2)
        {
            dp[i] += (dp[j] % MOD * dp[i - j - 2] % MOD) % MOD;
            dp[i] %= MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}