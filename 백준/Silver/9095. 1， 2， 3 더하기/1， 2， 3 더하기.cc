#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int k = 0; k < T; k++)
    {
        int n;
        cin >> n;

        vector<int> dp(n+1, 0);
        
        
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                dp[i] += dp[i-j];
            }
        }

        cout << dp[n] << "\n";
    }

    return 0;
}