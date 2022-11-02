#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        vector<long long> dp(N+1);

        for (int j = 1; j <= N; j++)
        {
            if (j == 1 || j == 2 || j == 3)
                dp[j] = 1;
            else if (j == 4 || j == 5)
                dp[j] = 2;
            else
                dp[j] = dp[j-1] + dp[j-5];
        }
        cout << dp[N] << "\n";
    }

    return 0;
}