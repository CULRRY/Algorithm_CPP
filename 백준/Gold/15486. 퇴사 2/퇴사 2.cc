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
    vector<int> t(n+1, 0);
    vector<int> p(n+1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
    }

    vector<int> dp(n+2, 0);

    for (int  i = 1; i <= n; i++)
    {
        if (dp[i] == 0) 
            dp[i] = dp[i-1];
        else
            dp[i] = std::max(dp[i], dp[i-1]);
        
        if (i + t[i] > n + 1)
            continue;

        if (dp[i + t[i]] == 0)
            dp[i + t[i]] = dp[i] + p[i];
        else
            dp[i + t[i]] = std::max(dp[i] + p[i], dp[i + t[i]]);
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}