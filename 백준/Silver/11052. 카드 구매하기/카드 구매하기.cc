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
    vector<int> cost(n+1, 0);
    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    vector<int> dp(n+1, 0);


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = std::max(dp[i], dp[i-j] + cost[j]);
        }
    }

    cout << dp[n];

    return 0;
}