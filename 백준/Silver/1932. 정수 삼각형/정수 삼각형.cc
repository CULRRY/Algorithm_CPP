#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    vector<vector<int>> v;
    vector<vector<int>> dp;
    cin >> N;
    v.assign(N, vector<int>());
    dp.assign(N, vector<int>());
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int x;
            cin >> x;
            v[i - 1].push_back(x);
            dp[i - 1].push_back(0);
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            dp[i][i] = v[0][0];
        else
        {
            for (int j = 0; j < i; j++)
            {
                int now = dp[i - 1][j] + v[i][j];
                if (now > dp[i][j])
                    dp[i][j] = now;

                now = dp[i - 1][j] + v[i][j + 1];
                if (now > dp[i][j + 1])
                    dp[i][j+1] = now;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < N; i++)
    {
        if (dp[N-1][i] > max)
        {
            max = dp[N-1][i];
        }
    }

    cout << max;

    return 0;
}