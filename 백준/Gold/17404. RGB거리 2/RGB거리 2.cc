#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

enum : int
{
    R = 0,
    G = 1,
    B = 2,
};

int main()
{
    FASTIO;

    int n;
    cin >> n;

    vector<vector<int>> v(3, vector<int>(n + 1, 0));
    vector<vector<int>> dp(3, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        cin >> v[R][i] >> v[G][i] >> v[B][i];
    }


    int min = INT_MAX;
    for (int c = R; c <= B; c++)
    {

        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                for (int color = R; color <= B; color++)
                {
                    if (color == c)
                        dp[color][i] = v[color][i];
                    else
                        dp[color][i] = 988877766;
                }
            }
            else if (i == n)
            {
                for (int color = R; color <= B; color++)
                {
                    if (color == c)
                        dp[color][i] = 988877766;
                    else
                    {
                        dp[color][i] = std::min(dp[(color + 1) % 3][i - 1], dp[(color + 2) % 3][i - 1]);
                        dp[color][i] += v[color][i];
                    }
                }
            }
            else
            {
                for (int color = R; color <= B; color++)
                {
                    dp[color][i] = std::min(dp[(color + 1) % 3][i - 1], dp[(color + 2) % 3][i - 1]);
                    dp[color][i] += v[color][i];
                }
            }
        }

        int localMin = INT_MAX;
        for (int color = R; color <= B; color++)
        {
            localMin = std::min(localMin, dp[color][n]);
        }

        min = std::min(localMin, min);
    }

    cout << min << "\n";

    return 0;
}