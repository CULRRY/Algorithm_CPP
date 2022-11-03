#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i <= 2)
            dp[i] = i;
        else 
            dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    cout << dp[n];

    return 0;
}