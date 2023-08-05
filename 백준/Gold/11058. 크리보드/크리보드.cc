#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

enum
{
    P, A, C, V
};

int main()
{
    FASTIO;
    int n;
    cin >> n;

    vector<long long> dp(n+1, 0);


    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1] + 1;
        for (int j = 3; j <= i; j++)
        {
            dp[i] = std::max(dp[i], (j-1) * dp[i-j]);
        }
    }

    cout << dp[n] << endl;


    return 0;
}