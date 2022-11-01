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
        
        int min = 9999999;
        if (i % 3 == 0)
        {
            if (min > dp[i / 3])
                min = dp[i / 3];
        }
        if (i % 2 == 0)
        {
            if (min > dp[i / 2])
                min = dp[i / 2];
        }
        if (min > dp[i - 1])
            min = dp[i - 1];
        
        dp[i] = min + 1;
    }

    cout << dp[N];
    

    return 0;
}