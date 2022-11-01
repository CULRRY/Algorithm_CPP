#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> dp(N+1);
    dp[1] = 0; dp[2] = 1, dp[3] = 1;
    for (int i = 4; i <= N; i++)
    {
        
        vector<int> nextDp;
        if (i % 3 == 0)
        {
            nextDp.push_back(dp[i / 3] + 1);
        }
        if (i % 2 == 0)
        {
            nextDp.push_back(dp[i / 2] + 1);
        }
        nextDp.push_back(dp[i - 1] + 1);
        dp[i] = *min_element(nextDp.begin(), nextDp.end());
    }

    cout << dp[N];
    

    return 0;
}