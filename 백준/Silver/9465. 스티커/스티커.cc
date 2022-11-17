#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int N;
        cin >> N;
        vector<vector<int>> v;
        vector<vector<int>> dp;
        v.assign(3, vector<int>(N, 0));
        dp.assign(3, vector<int>(N, 0));

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == 0)
                {
                    v[i][j] = 0;
                }
                else
                    cin >> v[i][j];
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 0)
                {
                    dp[j][i] = v[j][i];
                }
                else
                {
                    if (j == 0)
                    {
                        dp[j][i] = std::max(dp[j+1][i-1], dp[j+2][i-1]);
                    }
                    else if (j == 1)
                    {
                        dp[j][i] = std::max(dp[0][i-1] + v[1][i], dp[2][i-1] + v[1][i]);
                    }
                    else
                    {
                        dp[j][i] = std::max(dp[0][i - 1] + v[2][i], dp[1][i - 1] + v[2][i]);
                    }
                }
            }
        }

        int max = 0;
        for (int i = 0; i < 3; i++)
        {
            if (dp[i][N-1] > max)
                max = dp[i][N-1];
        }

        cout << max << "\n";
    }

    return 0;
}