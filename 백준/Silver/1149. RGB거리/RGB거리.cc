#include <bits/stdc++.h>
using namespace std;
enum color
{
    R, G, B,
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> cost;
    cost.assign(3, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = R; j <= B; j++)
            cin >> cost[j][i];
    }

    vector<vector<int>> dp;
    dp.assign(3, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int color = R; color <= B; color++)
        {
            if (i == 0)
            {
                dp[R][i] = cost[R][i];
                dp[G][i] = cost[G][i];
                dp[B][i] = cost[B][i];
            }
            else
            {
                dp[color][i] = dp[(color + 1) % 3][i - 1] < dp[(color + 2) % 3][i - 1] ? dp[(color + 1) % 3][i - 1] : dp[(color + 2) % 3][i - 1];
                dp[color][i] += cost[color][i];
            }

        }
    }

    int min = INT_MAX;
    for (int color = R; color <= B; color++)
    {
        if(min > dp[color][n-1])
            min = dp[color][n-1];
    }

    cout << min << "\n";




    

    return 0;
}