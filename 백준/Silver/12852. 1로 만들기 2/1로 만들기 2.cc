#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    vector<int> memo(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int min = INT_MAX;
        if (i % 3 == 0)
        {
            int tmp = dp[i / 3] + 1;
            if (min > tmp)
            {
                min = tmp;
                memo[i] = i / 3;
            }
        }

        if (i % 2 == 0)
        {
            int tmp = dp[i / 2] + 1;
            if (min > tmp)
            {
                min = tmp;
                memo[i] = i / 2;
            }
        }

        int tmp = dp[i - 1] + 1;
        if (min > tmp)
        {
            min = tmp;
            memo[i] = i - 1;
        }

        dp[i] = min;
    }

    cout << dp[n] << "\n" ;

    int o = n;
    while (o >= 1)
    {
        cout << o << " ";
        o = memo[o];
    }

    return 0;
}